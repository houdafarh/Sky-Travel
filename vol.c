#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "vol.h"
#include <gtk/gtk.h>
//
int tab_vols( vol t[100])
  { int n=0;
    FILE *f;
    f=fopen("/home/houda/Desktop/testvoll/src/vols.txt","r");
    if (f!=NULL)
  { while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",t[n].id_vol, t[n].type_vol, t[n].companie_aerienne, t[n].date_depart, t[n].date_retour,
t[n].h_depart, t[n].prix_base, t[n].nb_voyageurs,t[n].duree,t[n].pays_depart,t[n].pays_arrivee)!= EOF)
 {n++;}
fclose(f);}
return n ;}


int controle_saisie_vol( vol tab[100],char identifiant[20])
{ int n=tab_vols(tab);
  int i;
for (i=0; i<n;i++)
if (strcmp(tab[i].id_vol,identifiant)==0)
return i;
return -1;}
//
void ajouter_vol(vol v)
{
FILE *f ;
f=fopen("/home/houda/Desktop/testvoll/src/vols.txt","a+");
if (f!=NULL) 
{fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",v.id_vol,v.type_vol,v.companie_aerienne,v.date_depart,v.date_retour,v.h_depart,v.prix_base,v.nb_voyageurs,v.duree,v.pays_depart,v.pays_arrivee);}
fclose(f);}

void info_vol(vol v)
{FILE *f ;
f=fopen("/home/houda/Desktop/testvoll/src/infovol.txt","w");
if (f!=NULL) 
{fprintf(f,"%s %s %s %s",v.pays_depart,v.pays_arrivee,v.date_depart,v.date_retour);}
fclose(f);}

enum
{
  ID_VOL,
  PAYS_DEPART,
  PAYS_ARRIVEE,
  TYPE_VOL,
  COMPANIE_AERIENNE,
  DATE_DEPART,
  DATE_RETOUR,
  HEURE_DEPART,
  DUREE,
  PRIX_BASE,
  NB_VOYAGEURS,
  COLUMNS
};

void afficher_vols(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   vol v;
   store=NULL;

   FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("id_vol", renderer, "text",ID_VOL, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("pays_depart", renderer, "text",PAYS_DEPART, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("pays_arrivee", renderer, "text",PAYS_ARRIVEE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("type_vol", renderer, "text",TYPE_VOL, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("companie_aerienne", renderer, "text",COMPANIE_AERIENNE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("date_depart", renderer, "text",DATE_DEPART, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("date_retour", renderer, "text",DATE_RETOUR, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("h_depart", renderer, "text",HEURE_DEPART, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("duree", renderer, "text",DUREE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prix_base", renderer, "text",PRIX_BASE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nb_voyageurs", renderer, "text",NB_VOYAGEURS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING );

  f = fopen("/home/houda/Desktop/testvoll/src/vols.txt", "r"); 

  if(f==NULL)
  {
    return;
   }
  else

  { f = fopen("/home/houda/Desktop/testvoll/src/vols.txt", "a+");
       while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",v.id_vol,v.type_vol,v.companie_aerienne,v.date_depart,v.date_retour,v.h_depart,v.prix_base,v.nb_voyageurs,v.duree,v.pays_depart,v.pays_arrivee)!=EOF)
    {
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,ID_VOL,v.id_vol,TYPE_VOL,v.type_vol,COMPANIE_AERIENNE,v.companie_aerienne,DATE_DEPART,v.date_depart,DATE_RETOUR,v.date_retour,HEURE_DEPART,v.h_depart,PRIX_BASE,v.prix_base,NB_VOYAGEURS,v.nb_voyageurs,DUREE,v.duree,PAYS_DEPART,v.pays_depart,PAYS_ARRIVEE,v.pays_arrivee,-1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}

/*void verifiervol()
{
vol i;
vol vs[100] ;
int n,j;
n=100;
FILE *f ;
FILE *g ;
FILE *k ;
k=fopen("/home/houda/Desktop/testvoll/src/infovol.txt","r");
fscanf(k,"%s %s %s %s %s",i.pays_depart,i.pays_arrivee,i.type_vol,i.date_depart,i.date_retour);
g=fopen("/home/houda/Desktop/testvoll/src/volrec.txt","w+");
f=fopen("/home/houda/Desktop/testvoll/src/vols.txt","r");
for(j=0;j<n;j++)
{fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",vs[j].id_vol,vs[j].type_vol,vs[j].companie_aerienne,vs[j].date_depart,vs[j].date_retour,vs[j].h_depart,vs[j].prix_base,&vs[j].nb_voyageurs,vs[j].duree,vs[j].pays_depart,vs[j].pays_arrivee);
if ((!(strcmp(i.pays_depart,vs[j].pays_depart))) && (!(strcmp(i.pays_arrivee,vs[j].pays_arrivee))) && (!(strcmp(i.date_depart,vs[j].date_depart))) && (!(strcmp(i.date_retour,vs[j].date_retour))) && (!(strcmp(i.id_vol,vs[j].id_vol))))
{fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s \n",vs[j].id_vol,vs[j].type_vol,vs[j].companie_aerienne,vs[j].date_depart,vs[j].date_retour,vs[j].h_depart,vs[j].prix_base,&vs[j].nb_voyageurs,vs[j].duree,vs[j].pays_depart,vs[j].pays_arrivee);}
else {continue;}}
fclose(f);
fclose(g);
fclose(k);
}*/

/*enum
{
  ID_VOL,
  PAYS_DEPART,
  PAYS_ARRIVEE,
  TYPE_VOL,
  COMPANIE_AERIENNE,
  DATE_DEPART,
  DATE_RETOUR,
  HEURE_DEPART,
  DUREE,
  PRIX_BASE,
  NB_VOYAGEURS,
  COLUMNS
};*/

void afficher_volrec(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   vol v;
   char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20];
   store=NULL;
   FILE *k;
   FILE *f;
   FILE *g;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("id_vol", renderer, "text",ID_VOL, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("pays_depart", renderer, "text",PAYS_DEPART, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("pays_arrivee", renderer, "text",PAYS_ARRIVEE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("type_vol", renderer, "text",TYPE_VOL, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("companie_aerienne", renderer, "text",COMPANIE_AERIENNE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("date_depart", renderer, "text",DATE_DEPART, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("date_retour", renderer, "text",DATE_RETOUR, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("h_depart", renderer, "text",HEURE_DEPART, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("duree", renderer, "text",DUREE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prix_base", renderer, "text",PRIX_BASE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nb_voyageurs", renderer, "text",NB_VOYAGEURS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING ); 
  g = fopen("/home/houda/Desktop/testvoll/src/infovol.txt","r");
  f = fopen("/home/houda/Desktop/testvoll/src/vols.txt", "a+");

 fscanf(g,"%s %s %s %s",ch1,ch2,ch4,ch5);
 fclose(g);
  if(f==NULL)
  {
    return;
   }
  else

  { f = fopen("/home/houda/Desktop/testvoll/src/vols.txt", "a+");
       while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",v.id_vol,v.type_vol,v.companie_aerienne,v.date_depart,v.date_retour,v.h_depart,v.prix_base,v.nb_voyageurs,v.duree,v.pays_depart,v.pays_arrivee)!= EOF)
if ((!(strcmp(ch1,v.pays_depart))) && (!(strcmp(ch2,v.pays_arrivee))) && (!(strcmp(ch4,v.date_depart))) && (!(strcmp(ch5,v.date_retour))))
    {
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,ID_VOL,v.id_vol,TYPE_VOL,v.type_vol,COMPANIE_AERIENNE,v.companie_aerienne,DATE_DEPART,v.date_depart,DATE_RETOUR,v.date_retour,HEURE_DEPART,v.h_depart,PRIX_BASE,v.prix_base,NB_VOYAGEURS,v.nb_voyageurs,DUREE,v.duree,PAYS_DEPART,v.pays_depart,PAYS_ARRIVEE,v.pays_arrivee,-1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}

