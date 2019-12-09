#include <gtk/gtk.h> 

typedef struct 
{ char id_res[50] ;
char id_vol[50] ;
char id_client[50] ; 
char nb_places[50] ;
char classe[50] ; 
}
res;

void afficher_reservations(GtkWidget *liste, char id[30]);
void ajouter_reservation(res res);
void supprimer_reservation(char id[30]);
