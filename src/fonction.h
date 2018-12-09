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
