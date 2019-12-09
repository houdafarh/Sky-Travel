#include <gtk/gtk.h> 

typedef struct
{char id_vol[50] ;
char type_vol[50]; 
char companie_aerienne[50]; 
char date_depart[50];
char date_retour[50];
char h_depart[50] ;
char prix_base[50];
char nb_voyageurs[50] ;
char duree[50];
char pays_depart[50];
char pays_arrivee[50]; 
}vol;

vol vs[100];

void info_vol(vol v);
void ajouter_vol(vol v);
void afficher_vols(GtkWidget *liste);
void afficher_volrec(GtkWidget *liste);
int controle_saisie_vol( vol tab[100],char identifiant[20]);
int tab_vols( vol t[100]);
