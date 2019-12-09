#include <gtk/gtk.h>
typedef struct
{
char nom [20];
char prenom[20];
char identifiant[20];
char typedepaiment[20];
char montanttotale[20];
} facture ;
void afficher_facture(GtkWidget *treeview5);
void supprimer_facture(char id1[10]);
void afficher_facture_a(GtkWidget *liste);
void ajouter_facture(facture o);
void ajouter_facture_a(facture o);
