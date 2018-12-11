#include <gtk/gtk.h>

struct pr{
	char username[20];
	char password[20];
	char role[20];
	char nom[20];
	char prenom[20];
	int jour;
	char mois[20];
	int annee;
	char ville[20];
	char id[20];
	char tel[20];
	char mail[20];
};

typedef struct pr info;

int verifier(char username[],char password[]);
void ajouter(char username[], char password[],int role);
void information(info p);
void rechnom (char *username, char *nom, char *prenom);
int suppression(char username[]);
void modif(char username[],char nom[],char prenom[],int jour,char mois[],int annee,char ville[],char id[],char tel[],char mail[]);
void affichprof(GtkWidget *label470,GtkWidget *label467,GtkWidget *label468,GtkWidget *label469);
int rechrdv(char *useradh,char *usermed,int jour,char *mois,int annee,int hour);
int rechfiche (char *username);
/*------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------*/



/*struct FM{
char nom[100];
char Poids[12];
char Taille[12];
char Matin[10];
char Midi[10];
char Soir[10];
};
typedef struct FM FM;*/

int verifier(char username[],char password[]);
void ajouter(char username[], char password[],int role);
void information(info p);
void rechnom (char *username, char *nom, char *prenom);

void Modifierprofil(char ville[100], char email[100],char numtel[20]);
void AjouterRdv(char date[10],char mois[10],char annee[6], char heure[8], char username[100]);
void AjouterFicheMedicale(char nom[100], char Taille[5],char Poids[6]);
void ModifierFicheMedicales(char nom[100],char Taille[6],char Poids[7]);
void afficherFM(char NOm[100],GtkWidget *liste);
void AfficherRapport(char NOm[100],GtkWidget *liste);
void AfficherRdv(char NOm[100],GtkWidget *liste);
void supprimerFicheMedicale(char nom[100]);
void supprimerRdv(char nom[100]);
