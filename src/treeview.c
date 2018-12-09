#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "treeview.h"



enum
{
	USERNAME,
	NOM,
	PRENOM,
	VILLE,
	ID,
	JOUR,
	MOIS,
	ANNEE,
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

char username[50];char nom[50];char prenom[50];char ville[50];char id[50];char mail[50];char jour[50];char mois[50];char annee[50];char tel[50];char role[50];
store=NULL;

FILE *f;



store = gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" ville",renderer,"text",VILLE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
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
		column = gtk_tree_view_column_new_with_attributes(" tel",renderer,"text",TEL,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" mail",renderer,"text",MAIL,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


		
	}

	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	f=fopen("information.txt","r");

	if(f==NULL)
	{

		return;
	}
	else
	{
 		f = fopen("information.txt", "a+");

              while(fscanf(f,"%s%s%s%s%s%s%s%s%s\n",nom,prenom,ville,id,jour,mois,annee,tel,mail)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,NOM,nom,PRENOM,prenom,VILLE,ville,ID,id,JOUR,jour,MOIS,mois,ANNEE,annee,TEL,tel,MAIL,mail,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    		g_object_unref (store);
	}

}
