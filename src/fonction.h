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
