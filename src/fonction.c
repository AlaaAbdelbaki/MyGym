#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fonction.h"

int verifier(char username[],char password[])
{
	FILE *f;
	char entry1[30];
	char entry2[30];
	int role;
	int n=-1;

	f=fopen("users.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %d\n",entry1,entry2,&role)!=EOF)
			{
			if((strcmp(username,entry1)==0)&&(strcmp(password,entry2)==0))
			{
			n=role;
			}
			}

	fclose(f);
}
	return(n);
}



void ajouter(char username[], char password[],int role)
{
   
    FILE *f;

    f=fopen("users.txt","a");
    if (f!=NULL)
    {
    fprintf(f,"%s %s %d\n",username,password,role);
    fclose(f);
    }
    else printf("impossssible d'ouvrir\n");


   
   
}

void information(profil p)
{
    FILE *f=fopen("information.txt","a");
    if (!f)
    {
    fprintf(f,"%s %s %s %d %s %d %s %s %s %s\n",p.username,p.nom,p.prenom,p.jour,p.mois,p.annee,p.ville,p.id,p.tel,p.mail);
    }	
fclose(f);
}





