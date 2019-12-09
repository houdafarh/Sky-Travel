#include <stdio.h> 
#include <string.h> 
#include "res_hotel.h" 
#include <gtk/gtk.h>


enum
{
    NOM1, 
    N_RESERVATION1,
    HOTEL1,
    DESTINATION1, 
    NBRE_CHAMBRES1, 
    COLUMNS
};
//Ajouter 

void ajouter_resr(res_hotel r)
{

 FILE *f;
 f=fopen("/home/ahmed/Projects/projectfinale2/src/res_hotel.txt","a+"); 
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s\n",r.nom1,r.n_reservation1,r.hotel1,r.destination1,r.nbre_chambres1); 
 fclose(f);

}
}

//Afficher 


void afficher_resr(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   char nom1 [30];
   char n_reservation1 [30]; 
   char hotel1 [30];
   char destination1 [30]; 
   char nbre_chambres1[30]; 
   store=NULL;

   FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


      renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes(" nom1", renderer, "text",NOM1, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" n_reservation1", renderer, "text",N_RESERVATION1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("hotel1", renderer, "text",HOTEL1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("destination1", renderer, "text",DESTINATION1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" nbre_chambres1", renderer, "text",NBRE_CHAMBRES1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f = fopen("/home/ahmed/Projects/projectfinale2/src/res_hotel.txt", "r"); 

  if(f==NULL)
  {
    return;
  }
  else

  { f = fopen("/home/ahmed/Projects/projectfinale2/src/res_hotel.txt", "a+");
       while((fscanf(f,"%s %s %s %s %s \n",nom1,n_reservation1,hotel1,destination1,nbre_chambres1)!= EOF))
    {
  gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter, NOM1, nom1, N_RESERVATION1, n_reservation1, HOTEL1, hotel1,DESTINATION1,destination1, NBRE_CHAMBRES1,nbre_chambres1, -1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}

