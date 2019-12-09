#include <gtk/gtk.h> 

typedef struct
{

char nom1 [20]; 
char n_reservation1[20]; 
char hotel1[30];
char destination1[30];
char nbre_chambres1[10];

}res_hotel;

void ajouter_resr(res_hotel r);
void afficher_resr(GtkWidget *liste);
