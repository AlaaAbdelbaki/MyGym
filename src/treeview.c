#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "treeview.h"



enum
{
	USERNAME,
	PASSWORD,
	ROLE,
	NOM,
	PRENOM,
	JOUR,
	MOIS,
	ANNEE,
	VILLE,
	ID,
	TEL,
	MAIL,
	COLUMNS
};

void treeprofile(GtkWidget *liste)
{


GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

char username[50];char nom[50];char prenom[50];char password[50];char ville[50];char id[50];char mail[50];char jour[50];char mois[50];char annee[50];char tel[50];char role[50];
store=NULL;

FILE *f;



store = gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" username",renderer,"text",USERNAME,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" password",renderer,"text",PASSWORD,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" role",renderer,"text",ROLE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" ville",renderer,"text",VILLE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" tel",renderer,"text",TEL,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" mail",renderer,"text",MAIL,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);



	}

	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("information.txt","r");
	FILE *f1=fopen("users.txt","r");
	int role1;
	if(f==NULL)
	{

		return;
	}
	else
	{
 		//f = fopen("information.txt", "a+");

              while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",username,nom,prenom,jour,mois,annee,ville,id,tel,mail)!=EOF)
		{
			fscanf(f1,"%s %s %d",username,password,&role1);
			switch (role1){
				case 1:strcpy(role,"admin");
				break;
				case 2:strcpy(role,"coach");
				break;
				case 3:strcpy(role,"adherant");
				break;
				case 4:strcpy(role,"diet");
				break;
				case 5:strcpy(role,"kine");
				break;
				case 6:strcpy(role,"nutritionniste");

			}
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,USERNAME,username,PASSWORD,password,ROLE,role,NOM,nom,PRENOM,prenom,JOUR,jour,MOIS,mois,ANNEE,annee,VILLE,ville,ID,id,TEL,tel,MAIL,mail,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    		g_object_unref (store);
	}

}
enum
{
	NOMC,
	PRENOMC,
	TELC,
	MAILC,
	COLUMNSC
};

void treecoach(GtkWidget *liste)
{


GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

char username[50];
char nom[50];
char prenom[50];
char password[50];
char ville[50];
char id[50];
char mail[50];char jour[50];char mois[50];char annee[50];char tel[50];char role[50];
store=NULL;

FILE *f;
store = gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOMC,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOMC,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" tel",renderer,"text",TELC,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" mail",renderer,"text",MAILC,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}

	store = gtk_list_store_new(COLUMNSC,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("information.txt","r");
	if(f!=NULL)
	{


              while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",username,nom,prenom,jour,mois,annee,ville,id,tel,mail)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,NOM,nom,PRENOM,prenom,TEL,tel,MAIL,mail,-1);
		}
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
  	g_object_unref (store);
}
enum
{
	ADHERANTA,
	ATAILLE,
	NTAILLE,
	APOIDS,
	NPOIDS,
	COLUMNSR
};

void treerapp(GtkWidget *liste,char *user)
{


GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

char adherant[50];char ataille[50];char ntaille[50];char apoids[50];char npoids[50];
store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" adherant",renderer,"text",ADHERANTA,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Ancienne Taille",renderer,"text",ATAILLE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Nouvelle Taille",renderer,"text",NTAILLE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Ancien Poids",renderer,"text",APOIDS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Nouveau Poids",renderer,"text",NPOIDS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);





	}

	store = gtk_list_store_new(COLUMNSR,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("rapport.txt","r");
	if(f==NULL)
	{

		return;
	}
	else
	{
 		f = fopen("rapport.txt", "a+");

              while(fscanf(f,"%s %s %s %s %s\n",adherant,ataille,ntaille,apoids,npoids)!=EOF)
		{
			if(!strcmp(adherant,user)){
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,ADHERANTA,adherant,ATAILLE,ataille,NTAILLE,ntaille,APOIDS,apoids,NPOIDS,npoids,-1);
		}
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    		g_object_unref (store);
	}

}
enum
{
	ADHERANT,
	STAFF,
	JOURX,
	MOISX,
	ANNEEX,
	HEUREX,
	COLUMNSX
};

void treerdv(GtkWidget *liste)
{


GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

char adherant[50];char staff[50];char jour[50];char mois[50];char annee[50];char heure[50];
store=NULL;

FILE *f;

    char username[20];
    FILE *ff=fopen("current.txt","r");
    if(ff)
    fscanf(ff,"%s",username);
    fclose(ff);

store = gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Staff",renderer,"text",ADHERANT,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Adhérant",renderer,"text",STAFF,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Jour",renderer,"text",JOURX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Mois",renderer,"text",MOISX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Année",renderer,"text",ANNEEX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Heure",renderer,"text",HEUREX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);




	}

	store = gtk_list_store_new(COLUMNSX,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("rdv.txt","r");
	if(f==NULL)
	{

		return;
	}
	else
	{
 		f = fopen("rdv.txt", "a+");

              while(fscanf(f,"%s %s %s %s %s %s\n",adherant,staff,jour,mois,annee,heure)!=EOF)
		{
			if(strcmp(staff,username)){
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,ADHERANT,adherant,STAFF,staff,JOURX,jour,MOISX,mois,ANNEEX,annee,HEUREX,heure,-1);
		}
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    		g_object_unref (store);
	}

}

enum
{
	ADHERANTX,
	TAILLE,
	POIDS,
	MATIN,
	MIDI,
	SOIRE,
	COLUMNSY
};

void treefich(GtkWidget *liste)
{


GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

char adherant[50];char taille[50];char poids[50];char matin[50];char midi[50];char soire[50];
store=NULL;

FILE *f;



store = gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" adherant",renderer,"text",ADHERANTX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" taille",renderer,"text",TAILLE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" poids",renderer,"text",POIDS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" matin",renderer,"text",MATIN,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" midi",renderer,"text",MIDI,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" soire",renderer,"text",SOIRE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);




	}

	store = gtk_list_store_new(COLUMNSY,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("fiche.txt","r");
	if(f==NULL)
	{

		return;
	}
	else
	{
 		f = fopen("fiche.txt", "a+");

              while(fscanf(f,"%s %s %s %s %s %s\n",adherant,taille,poids,matin,midi,soire)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,ADHERANTX,adherant,TAILLE,taille,POIDS,poids,MATIN,matin,MIDI,midi,SOIRE,soire,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    		g_object_unref (store);
	}

}
