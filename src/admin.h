#ifndef ADMIN_H
#define ADMIN_H
#include <stdio.h>
#include <string.h>

typedef struct Date 
{
	char jour[5];
	char mois[5];
	char annee[5];

}date;
typedef struct personnel
{
char nom[20];
char prenom[20];
char usernam[20];
char cin[20];
date date_naissance[20];
char mail[50];
char tel[20];
char role[2];
}personnel;

void ajouter_personnel(personnel *p);
int modifier_personnel(personnel *p,char cin[20]);
int supprimer_personnel(personnel *p,char cin2[20]);

void info(login,nom,prenom,jour,mois,annee,tel,ville,mail,role);
void ajouter(login,password,role);
#endif

