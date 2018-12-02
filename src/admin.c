#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ajouter(char login[], char password[],int role)
{
   
    FILE *f;

    f=fopen("users.txt","a");
    if (f!=NULL)
    {

   
    fprintf(f,"%s %s %d\n",login,password,role);
    fclose(f);
    }
    else printf("impossssible d'ouvrir\n");


   
   
}
//=============================================================================
void info(char *login, char *nom,char *prenom,int jour,int mois,int annee,char *id,char *tel,char *ville,char *mail,int role)
{
    FILE *f;

    f=fopen("info.txt","a");
    if (f!=NULL)
    {

   
    fprintf(f,"%s %s %s %d %d %d %s %s %s %s %d\n",login,nom,prenom,jour,mois,annee,id,ville,tel,mail,role);
    fclose(f);
    }
    else printf("impossssible d'ouvrir\n");
}


void afficher ()
{
   
    FILE* f;
    char r_login[30];char r_password[30];int r_role;
    f=fopen("listeusers.txt","r");
        while (!EOF)
        {
        fscanf(f,"%s %s %d",r_login,r_password,&r_role);
        }
}
