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
enum
{
  NOM,
  PRENOM,
  NUM,
  EMAIL,
  POIDS,
  TAILLE,
  COLUMNS,
};
void afficher_coach(GtkWidget* list)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  char nom[30];
  char prenom[30];
  char num[30];
  char email[30];
  char poids[30];
  char taille[30];
  store=NULL;
  FILE *f;
  store=gtk_tree_view_get_model(list);
  if (store==NULL)
  {
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" num",renderer,"text",NUM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" email",renderer,"text",EMAIL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" poids",renderer,"text",POIDS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" taille",renderer,"text",TAILLE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f=fopen("profilutulisateur.txt","r");
    if(f==NULL)
      {
        return;
      }
      else
      {
        f=fopen("profilutulisateur.txt","a+");
        while(fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,num,email,poids,taille)!=EOF)
        {
          gtk_list_store_append(store,&iter);
          gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,NUM,num,EMAIL,email,POIDS,poids,TAILLE,taille,-1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
        g_object_unref(store);
      }
  }
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





