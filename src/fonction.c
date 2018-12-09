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

//************************************************************************************************//


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
//*******************************************************************************************************************/
void information(char nom[],char prenom[],char ville[],char id[],int jour,int mois,int annee,char tel[],char mail[])
{
    FILE *f;

    f=fopen("information.txt","a");
    if (f!=NULL)
    {
    fprintf(f,"%s %s %s %s %d %d %d %s %s\n",nom,prenom,ville,id,jour,mois,annee,tel,mail);
    }	
fclose(f);
}





