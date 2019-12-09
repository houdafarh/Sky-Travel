#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reservation.h"


void ajouter_reservation( res r )
{
FILE *f;
f=fopen("/home/houda/Desktop/testres/src/res.txt","a+");
if(f!=NULL)
{ fprintf(f,"%s %s %s %s %s \n",r.id_res, r.id_vol,r.id_client,r.nb_places,r.classe);
fclose(f);}
}
 
void supprimer_reservation(char id[20])
{ res r;
  FILE *f,*g;
 f=fopen("/home/houda/Desktop/testres/src/res.txt","r");
 g=fopen("/home/houda/Desktop/testres/src/res1.txt","w");
while (fscanf(f,"%s %s %s %s %s \n",r.id_res, r.id_vol,r.id_client,r.nb_places,r.classe)!= EOF)
{ if (!strcmp(id,r.id_res))
{continue;}
else {fprintf(g,"%s %s %s %s %s \n",r.id_res, r.id_vol,r.id_client,r.nb_places,r.classe);
}
}
fclose(f);
fclose(g);
remove("/home/houda/Desktop/testres/src/res.txt");
rename("/home/houda/Desktop/testres/src/res1.txt","/home/houda/Desktop/testres/src/res.txt");
}




enum
{
  ID_RESERVATION,
  ID_VOL,
  ID_CLIENT,
  NB_PLACES,
  CLASSE,
  COLUMNS
};

void afficher_reservations(GtkWidget *liste,char id[30])
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   res r;
   store=NULL;

   FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("id_res", renderer, "text",ID_RESERVATION, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id_vol", renderer, "text",ID_VOL, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id_client", renderer, "text",ID_CLIENT, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nb_places", renderer, "text",NB_PLACES, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("classe", renderer, "text",CLASSE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING );

  f = fopen("/home/houda/Desktop/testres/src/res.txt", "r"); 

  if(f==NULL)
  {
    return;
   }
  else

  { f = fopen("/home/houda/Desktop/testres/src/res.txt", "a+");
       while((fscanf(f,"%s %s %s %s %s \n",r.id_res, r.id_vol,r.id_client,r.nb_places,r.classe)!= EOF)) 
if (!(strcmp(r.id_client,id)))
    {
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,ID_RESERVATION,r.id_res,ID_VOL,r.id_vol,ID_CLIENT,r.id_client,NB_PLACES,r.nb_places,CLASSE,r.classe,-1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}


