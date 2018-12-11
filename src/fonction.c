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
int rechfiche (char *username){
	FILE *f=fopen("fiche.txt","r");
	char user[20];
	int x1,x2,x3,x4,x5;
	while(fscanf(f,"%s %d %d %d %d %d\n",user,&x1,&x2,&x3,&x4,&x5)!=EOF){
		if(strcmp(user,username)==0){
			fclose(f);
			return 1;
		}
	}
	fclose(f);
	return 0;
}
int rechrdv(char *useradh,char *usermed,int jour,char *mois,int annee,int hour){
	FILE *f=fopen("Rendez.txt","r");
	char useradhx[20];
	char usermedx[20];
	int jourx;
	char moisx[20];
	int anneex;
	int hourx;
	while(fscanf(f,"%s %s %d %s %d %d\n",useradhx,usermedx,&jourx,moisx,&anneex,&hourx)!=EOF){
		if((((jour==jourx)&&(!strcmp(mois,moisx)))&&(anneex==annee))&&(hourx==hour)){
			if((!strcmp(useradh,useradhx))||(!strcmp(usermed,usermedx))){
				fclose(f);
				return 1;
			}
		}
	}
	fclose(f);
	return 0;
}
void affichprof(GtkWidget *label470,GtkWidget *label467,GtkWidget *label468,GtkWidget *label469){
  FILE *f=fopen("current.txt","r");
  char username[20];
  fscanf(f,"%s",username);
  fclose(f);

  f=fopen("information.txt","r");
  info p;
  while(fscanf(f,"%s %s %s %d %s %d %s %s %s %s\n",p.username,p.nom,p.prenom,&(p.jour),p.mois,&(p.annee),p.ville,p.id,p.tel,p.mail)!=EOF){
  	if(strcmp(p.username,username)==0){
		break;
	}
  }
  fclose(f);
  char date[20];
  sprintf(date,"%d/%s/%d",p.jour,p.mois,p.annee);

  gtk_label_set_text(label470,p.nom);
  gtk_label_set_text(label469,p.prenom);
  gtk_label_set_text(label468,date);
  gtk_label_set_text(label467,p.id);
}


int suppression(char username[])
{
	char nom1[30];char prenom1[30];char ville1[30];char username1[30];char mail1[30];char tel1[30];
	char id1[30];int jour1;char mois1[30];int annee1;
	int compteur=-1;

	FILE *f1;
	FILE *f2;

	f1=fopen("information.txt","r");
	f2=fopen("del.txt","a");

	if (f1!=NULL)
	{

	while (fscanf(f1,"%s %s %s %d %s %d %s %s %s %s\n",username1,nom1,prenom1,&jour1,mois1,&annee1,ville1,id1,tel1,mail1) != EOF)
	{
		if (strcmp(username,username1)!=0)
		{
			fprintf(f2,"%s %s %s %d %s %d %s %s %s %s\n",username1,nom1,prenom1,jour1,mois1,annee1,ville1,id1,tel1,mail1);

		}
		else
		{
		compteur=1;
		}
	}
	fclose(f1);
	fclose(f2);
	}

	remove("information.txt");
	rename("del.txt","information.txt");

	f1=fopen("users.txt","r");
	f2=fopen("del.txt","a");

	if (f1!=NULL)
	{

	while (fscanf(f1,"%s %s %d\n",username1,nom1,&jour1) != EOF)
	{
		if (strcmp(username,username1)!=0)
		{
			fprintf(f2,"%s %s %d\n",username1,nom1,jour1);

		}
		else
		{
		compteur=1;
		}
	}
	fclose(f1);
	fclose(f2);
	}

	remove("users.txt");
	rename("del.txt","users.txt");


}



void modif(char username[],char nom[],char prenom[],int jour,char mois[],int annee,char ville[],char id[],char tel[],char mail[])
{
	char nom1[30];char prenom1[30];char ville1[30];char role1[30];char tel1[30];
	char id1[30];int jour1;char mois1[30];int annee1;char username1[30];char mail1[30];


	FILE *f1;
	FILE *f2;

	f1=fopen("information.txt", "r");
	f2=fopen("modif.txt", "a");

	if (f1!=NULL)
	{

	while (fscanf(f1,"%s %s %s %d %s %d %s %s %s %s\n",username1,nom1,prenom1,&jour1,mois1,&annee1,ville1,id1,tel1,mail1) != EOF)
	{
		if(strcmp(username,username1)==0)
		{
			fprintf(f2,"%s %s %s %d %s %d %s %s %s %s\n",username,nom,prenom,jour,mois,annee,ville,id,tel,mail);
		}
		else
		{
			fprintf(f2,"%s %s %s %d %s %d %s %s %s %s\n",username1,nom1,prenom1,jour1,mois1,annee1,ville1,id1,tel1,mail1);
		}

	}
	fclose(f1);
  	fclose(f2);
	}

  	remove("information.txt");
  	rename("modif.txt","information.txt");


}
void supprdv(char username[])
{
	char user1[20];
	char user2[20];
	int jour;
	char mois[10];
	int annee;
	int heure;

	FILE *f1;
	FILE *f2;

	f1=fopen("rdv.txt","r");
	f2=fopen("nvrdv.txt","a");

	if (f1!=NULL)
	{

	while (fscanf(f1,"%s %s %d %s %d %d \n",user1,user2,&jour,mois,&annee,&heure) != EOF)
	{
		if (strcmp(username,user2)!=0)
		{
			fprintf(f2,"%s %s %d %s %d %d \n",user1,user2,jour,mois,annee,heure);

		}
	}
	fclose(f1);
	fclose(f2);
	}

	remove("rdv.txt");
	rename("nvrdv.txt","rdv.txt");
	}
