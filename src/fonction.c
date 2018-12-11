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


/*-------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------*/





void Modifierprofil(char Ville[100], char email[100],char numtel[20])
{
char username[50],user[50],nom[50],prenom[50],jour[50],mois[50],annee[50],ville[50],id[50],tel[50],mail[50], b[2]="" ;
FILE* f;
FILE* f2;
FILE* f3;
f2=fopen("current.txt","r");
fscanf(f2,"%s",username);
f=fopen("profil.txt","r");
//f3=fopen("profil2.txt","a+");
//if(f2!=NULL){
//if(f!=NULL)
//{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",user,nom,prenom,jour,mois,annee,ville,id,tel,mail)!=EOF){
//if(strcmp(user,username)==0){
//while(fscanf(f,!=EOF){
f3=fopen("profil2.txt","a+");
if(strcmp(user,username)!=0){
fprintf(f3,"%s %s %s %s %s %s %s %s %s %s\n",user,nom,prenom,jour,mois,annee,ville,id,tel,mail);
fclose(f3);
}
else{
fprintf(f3,"%s %s %s %s %s %s %s %s %s %s\n",user,nom,prenom,jour,mois,annee,Ville,id,numtel,email);
fclose(f3);
}
//fclose(f3);
}
//fprintf(f,"%s %s %s %s %s %s %s %s %s %s\n",b,b,b,b,b,b,b,b,b,b);
fclose(f);
f=fopen("profil.txt","w");
fprintf(f,"%s %s %s %s %s %s %s %s %s %s\n",b,b,b,b,b,b,b,b,b,b);
fclose(f);
//fclose(f3);
f3=fopen("profil2.txt","r");
while(fscanf(f3,"%s %s %s %s %s %s %s %s %s %s\n",user,nom,prenom,jour,mois,annee,ville,id,tel,mail)!=EOF){
f=fopen("profil.txt","a");
fprintf(f,"%s %s %s %s %s %s %s %s %s %s\n",user,nom,prenom,jour,mois,annee,ville,id,tel,mail);
fclose(f);
}
//fclose(f);
//fprintf(f3,"%s %s %s %s %s %s %s %s %s %s",b,b,b,b,b,b,b,b,b,b);
fclose(f3);
f3=fopen("profil2.txt","w");
fprintf(f3,"%s %s %s %s %s %s %s %s %s %s\n",b,b,b,b,b,b,b,b,b,b);
fclose(f3);
//strcpy(ville,Ville);
//strcpy(tel,numtel);
//strcpy(mail,email);
//fprintf(f,"%s %s %s %s %s %s %s %s %s %s\n",user,nom,prenom,jour,mois,annee,Ville,id,numtel,email);

//}
//fclose(f);
//}
fclose(f2);

}


void AjouterRdv(char date[10],char mois[10],char annee[6], char heure[8], char username[100])
{
FILE*f3;
f3=fopen("rendez.txt","a+");
//if(f3!=NULL){
fprintf(f3,"%s %s %s %s %s\n",username,date,mois,annee,heure);
fclose(f3);
}
//}


void AjouterFicheMedicale(char nom[100], char Taille[5],char Poids[6])
{
char poids[6],taille[5], matin[7]="0",midi[7]="0",soir[7]="0";
int a=0;
char user[50],b[2]="" ;
FILE*F;
FILE *f;
F=fopen("fiche.txt","r");
//f=fopen("fiche2.txt","a+");
//if(F!=NULL)
//{
while(fscanf(F,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir)!=EOF){
if(strcmp(nom,user)==0){
a=1;
}
/*poids=Poids;
taille=Taille;
fprintf(F,"%s %d %d %d %d %d\n",nom,poids,taille,matin,midi,soir);*/
}
fclose(F);
if(a==0){
F=fopen("fiche.txt","a");
fprintf(F,"%s %s %s %s %s %s\n",nom,Poids,Taille,matin,midi,soir);
fclose(F);
}
else{
F=fopen("fiche.txt","r");
while(fscanf(F,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir)!=EOF){
if(strcmp(nom,user)!=0){
f=fopen("fiche2.txt","a");
fprintf(f,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir);
fclose(f);
}
else{
f=fopen("fiche2.txt","a");
fprintf(f,"%s %s %s %s %s %s\n",nom,Poids,Taille,matin,midi,soir);
fclose(f);
}
}
fclose(F);
F=fopen("fiche.txt","w");
fprintf(F,"%s %s %s %s %s %s\n",b,b,b,b,b,b);
fclose(F);
//fclose(f);
f=fopen("fiche2.txt","r");
while(fscanf(f,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir)!=EOF){
F=fopen("fiche.txt","a");
fprintf(F,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir);
fclose(F);
}
fclose(f);
}
f=fopen("fiche2.txt","w");
fprintf(f,"%s %s %s %s %s %s\n",b,b,b,b,b,b);
fclose(f);
//fclose(F);
//}
}



void ModifierFicheMedicales(char nom[100],char Taille[6],char Poids[7])
{
char poids[7],taille[6], matin[7],midi[7],soir[7];
char user[50],b[2]="";
FILE *F;
FILE *f;
F=fopen("fiche.txt","r");
//f=fopen("fiche2.txt","a+");
//if(F!=NULL)
//{
while(fscanf(F,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir)!=EOF){
if(strcmp(nom,user)!=0){
f=fopen("fiche2.txt","a");
fprintf(f,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir);
fclose(f);
}
else{
f=fopen("fiche2.txt","a");
fprintf(f,"%s %s %s %s %s %s\n",nom,Poids,Taille,matin,midi,soir);
fclose(f);
}
}
fclose(F);
F=fopen("fiche.txt","w");
fprintf(F,"%s %s %s %s %s %s\n",b,b,b,b,b,b);
fclose(F);
//fclose(f);
f=fopen("fiche2.txt","r");
while(fscanf(f,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir)!=EOF){
F=fopen("fiche.txt","a");
fprintf(F,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir);
fclose(F);
}
fclose(f);
f=fopen("fiche2.txt","w");
fprintf(f,"%s %s %s %s %s %s\n",b,b,b,b,b,b);
fclose(f);
//}
//fclose(F);
}



void supprimerFicheMedicale(char nom[100])
{
char poids[7],taille[6], matin[7],midi[7],soir[7];
char user[50],b[2]="";
FILE *F;
FILE *f;
F=fopen("fiche.txt","r");
//f=fopen("fiche2.txt","a+");
//if(F!=NULL)
//{
while(fscanf(F,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir)!=EOF){
if(strcmp(nom,user)!=0){
f=fopen("fiche2.txt","a");
fprintf(f,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir);
fclose(f);
}
/*else{
f=fopen("fiche2.txt","a");
fprintf(f,"%s %s %s %s %s %s",b,b,b,b,b,b);
fclose(f);
}*/
}
fclose(F);
F=fopen("fiche.txt","w");
fprintf(F,"%s %s %s %s %s %s\n",b,b,b,b,b,b);
fclose(F);
//fclose(f);
f=fopen("fiche2.txt","r");
while(fscanf(f,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir)!=EOF){
F=fopen("fiche.txt","a");
fprintf(F,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir);
fclose(F);
}
fclose(f);
f=fopen("fiche2.txt","w");
fprintf(f,"%s %s %s %s %s %s\n",b,b,b,b,b,b);
fclose(f);
//}
//fclose(F);

}



void supprimerRdv(char nom[100])
{
char date[7],mois[15], annee[7],heure[7];
char user[50],b[2]="";
FILE *F;
FILE *f;
F=fopen("rendez.txt","r");
//f=fopen("rendez2.txt","a+");
//if(F!=NULL)
//{
while(fscanf(F,"%s %s %s %s %s\n",user,date,mois,annee,heure)!=EOF){
if(strcmp(nom,user)!=0){
f=fopen("rendez2.txt","a");
fprintf(f,"%s %s %s %s %s\n",user,date,mois,annee,heure);
fclose(f);
}
/*else{
f=fopen("rendez2.txt","a");
fprintf(f,"%s %s %s %s %s",b,b,b,b,b);
fclose(f);
}*/
}
fclose(F);
F=fopen("rendez.txt","w");
fprintf(F,"%s %s %s %s %s\n",b,b,b,b,b);
fclose(F);
//fclose(f);
f=fopen("rendez2.txt","r");
while(fscanf(f,"%s %s %s %s %s\n",user,date,mois,annee,heure)!=EOF){
F=fopen("rendez.txt","a");
fprintf(F,"%s %s %s %s %s\n",user,date,mois,annee,heure);
fclose(F);
}
fclose(f);
f=fopen("rendez2.txt","w");
fprintf(f,"%s %s %s %s %s\n",b,b,b,b,b);
fclose(f);
//}
//fclose(F);


}



enum
{
NOM,
POIDS,
TAILLE,
MATIN,
MIDI,
SOIR,
COLUMNS,
};


void afficherFM(char NOm[100],GtkWidget *liste)
{
//FM fiche;
//GtkWidget *liste;

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

	char nom [30];
	char poids [30];
	char taille [30];
	char matin [30];
        char midi[30];
	char soir[30];
        store=NULL;
FILE*f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" poids", renderer, "text",POIDS, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  taille", renderer, "text",TAILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  matin", renderer, "text",MATIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  midi", renderer, "text",MIDI, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  soir", renderer, "text",SOIR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


f=fopen("fiche.txt","r");
//char taille[12],poids[12],matin[10],midi[10],soir[10];

if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("fiche.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s \n",nom,poids,taille,matin,midi,soir)!=EOF)/*&&(strcmp(NOm,nom)!=0)*/
	{
gtk_list_store_append (store, &iter);
	//{
//if(strcmp(NOm,nom)==0){
gtk_list_store_set (store, &iter, NOM, nom, POIDS, poids, TAILLE, taille,MATIN,matin,MIDI,midi,SOIR,soir, -1);
//} 
}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

/*char user[100];
if(F!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s\n",user,poids,taille,matin,midi,soir)!=EOF){
if(strcmp(NOm,user)==0){
strcpy(fiche.nom,user);
strcpy(fiche.Poids,poids);
strcpy(fiche.Taille,taille);
strcpy(fiche.Matin,matin);
strcpy(fiche.Midi,midi);
strcpy(fiche.Soir,soir);
}
}
fclose(f);
}
//return fiche ;
}
}*/



enum
{
NOMs,
ANCIENP,
NOUVEAUP,
ANCIENT,
NOUVEAUT,
CMI,
COMMENT,
COLUMNSs,
};

void AfficherRapport(char NOm[100],GtkWidget *liste)
{
//GtkWidget *liste;

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

	char nom [30];
	char ancienp [30];
	char nouveaup [30];
	char ancient [30];
        char nouveaut[30];
	char cmi[30];
	char comment[30];
        store=NULL;
FILE*f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOMs, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" anciens_poids", renderer, "text",ANCIENP, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nouveau_poids", renderer, "text",NOUVEAUP, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  ancienne_taille", renderer, "text",ANCIENT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nouvelle_taille", renderer, "text",NOUVEAUT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  cmi", renderer, "text",CMI, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  commentaire", renderer, "text",COMMENT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}
store=gtk_list_store_new (COLUMNSs, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


f=fopen("rapport.txt","r");
//char taille[12],poids[12],matin[10],midi[10],soir[10];

if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("rapport.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s\n",nom,ancienp,nouveaup,ancient,nouveaut,cmi,comment)!=EOF)/*&&(strcmp(NOm,nom)!=0))*/
	{
gtk_list_store_append (store, &iter);
	//}
//if(strcmp(NOm,nom)==0){
gtk_list_store_set (store, &iter, NOMs, nom, ANCIENP, ancienp, NOUVEAUP, nouveaup,ANCIENT,ancient,NOUVEAUT,nouveaut,CMI,cmi,COMMENT,comment, -1); 
}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}


enum
{
NOMS,
DATE,
MOIS,
ANNEE,
HEURE,
//COLUMNS,
};

void AfficherRdv(char NOm[100],GtkWidget *liste)
{
//GtkWidget *liste;

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
	
	char nom[30];
	char date [30];
	char mois [30];
	char annee [30];
	char heure [30];
        store=NULL;
FILE*f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOMS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  annee", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


f=fopen("rendez.txt","r");
//char taille[12],poids[12],matin[10],midi[10],soir[10];

if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("rendez.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s\n",nom,date,mois,annee,heure)!=EOF)/*&&(strcmp(NOm,nom)!=0))*/
	{
gtk_list_store_append (store, &iter);
	//}
//if(strcmp(NOm,nom)==0){
gtk_list_store_set (store, &iter, NOMS, nom, DATE, date, MOIS, mois,ANNEE,annee,HEURE,heure, -1); 
}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
