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
   
    FILE *f=fopen("users.txt","a");
    if (f)
    {
    fprintf(f,"%s %s %d\n",username,password,role);
    }
    fclose(f);
}

void information(info p)
{
    FILE *f=fopen("information.txt","a");
    if (f)
    {
    fprintf(f,"%s %s %s %d %s %d %s %s %s %s\n",p.username,p.nom,p.prenom,p.jour,p.mois,p.annee,p.ville,p.id,p.tel,p.mail);
    }	
fclose(f);
}

void rechnom (char *username, char *nom, char *prenom){
	FILE *f=fopen("information.txt","r");
	char user[20];
	char ch[200];
	while(fscanf(f,"%s %s %s %s\n",user,nom,prenom,ch)!=EOF){
		if(strcmp(user,username)==0){
			break;
		}
	}
	fclose(f);
}





