#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "treeview.h"


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *login=gtk_widget_get_toplevel(objet_graphique);
  GtkWidget *nutritonniste;
  GtkWidget *coach;
  GtkWidget *adherant;
  GtkWidget *kine;
  GtkWidget *diet;
  GtkWidget *admin;
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *entry1;
  GtkWidget *entry2;
char username[30];
char password[30];

input1=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

if(verifier(username,password)==1)
	{
	admin=create_admin();
	gtk_widget_show(admin);
	gtk_widget_destroy(login);

	}

else if(verifier(username,password)==2)
	{
	coach=create_coach();
	gtk_widget_show(coach);
	gtk_widget_destroy(login);

	}

else if(verifier(username,password)==3)
	{
	adherant=create_adherant();
	gtk_widget_show(adherant);
	gtk_widget_destroy(login);

	}
else if(verifier(username,password)==4)
	{
	diet=create_diet();
	gtk_widget_show(diet);
	gtk_widget_destroy(login);
	}
else if(verifier(username,password)==5)
	{
	kine=create_kine();
	gtk_widget_show(kine);
	gtk_widget_destroy(login);
	}
else if(verifier(username,password)==6)
	{
	nutritonniste=create_nutritonniste();
	gtk_widget_show(nutritonniste);
	gtk_widget_destroy(login);
	}
	FILE *f=fopen("current.txt","w+");
	fprintf(f,"%s",username);
	fclose(f);
}



void
on_button32_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	FILE *fp=fopen("current.txt","r");
	char username[20];
	fscanf(fp,"%s",username);
	fclose(fp);
	char mail[20];
	char tel[20];
	char ville[20];
	GtkWidget *entry1=lookup_widget(button,"entry45");
	GtkWidget *entry2=lookup_widget(button,"entry46");
	GtkWidget *entry3=lookup_widget(button,"entry47");
	strcpy(ville,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(mail,gtk_entry_get_text(GTK_ENTRY(entry2)));
	FILE *f=fopen("information.txt","r");
	info *tab;
	int i=0;
	tab=(info *)malloc(sizeof(info));
	while(fscanf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,&(tab[i].jour),tab[i].mois,&(tab[i].jour),tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail)!=EOF){
		if(strcmp(tab[i].username,username)==0){
			strcpy(tab[i].ville,ville);
			strcpy(tab[i].tel,tel);
			strcpy(tab[i].mail,mail);
		}
		i++;
		tab=(info *)realloc(tab,(i+1)*sizeof(info));
	}
	fclose(f);
	f=fopen("information.txt","w+");
	int j=i;
	i=0;
	for(i=0;i<j;i++){
		fprintf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,tab[i].jour,tab[i].mois,tab[i].jour,tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail);
	}
	fclose(f);
}


void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button23_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button28_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button30_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_coach_saveprof_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	FILE *fp=fopen("current.txt","r");
	char username[20];
	fscanf(fp,"%s",username);
	fclose(fp);
	char mail[20];
	char tel[20];
	char ville[20];
	GtkWidget *entry1=lookup_widget(button,"coach_entry11");
	GtkWidget *entry2=lookup_widget(button,"coach_entry13");
	GtkWidget *entry3=lookup_widget(button,"coach_entry14");
	strcpy(ville,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(mail,gtk_entry_get_text(GTK_ENTRY(entry2)));
	FILE *f=fopen("information.txt","r");
	info *tab;
	int i=0;
	tab=(info *)malloc(sizeof(info));
	while(fscanf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,&(tab[i].jour),tab[i].mois,&(tab[i].jour),tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail)!=EOF){
		if(strcmp(tab[i].username,username)==0){
			strcpy(tab[i].ville,ville);
			strcpy(tab[i].tel,tel);
			strcpy(tab[i].mail,mail);
		}
		i++;
		tab=(info *)realloc(tab,(i+1)*sizeof(info));
	}
	fclose(f);
	f=fopen("information.txt","w+");
	int j=i;
	i=0;
	for(i=0;i<j;i++){
		fprintf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,tab[i].jour,tab[i].mois,tab[i].jour,tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail);
	}
	fclose(f);
}


void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button51_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *date;
  GtkWidget *mois;
  GtkWidget *annee;
  GtkWidget *heure;
  GtkWidget *username;
  int day;
  char month[10];
  int year;
  char user[20];
  char coach[20];
  int time;
  FILE *f1,*f2;
  date=lookup_widget(button,"spinbutton43");
  mois=lookup_widget(button,"combobox14");
  annee=lookup_widget(button,"spinbutton44");
  heure=lookup_widget(button,"spinbutton45");
  username=lookup_widget(button,"entry70");
  strcpy(month,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
  day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(date));
  year=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
  time=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure));
  strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
  f1=fopen("current.txt","r");
  f2=fopen("rdv.txt","a+");
  fscanf(f1,"%s",coach);
  fclose(f1);
  fprintf(f2,"%s %s %d %s %d %d",coach,user,day,month,year,time);
  fclose(f2);
}


void
on_button52_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button53_enter                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button15_enter                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button54_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	FILE *fp=fopen("current.txt","r");
	char username[20];
	fscanf(fp,"%s",username);
	fclose(fp);
	char mail[20];
	char tel[20];
	char ville[20];
	GtkWidget *entry1=lookup_widget(button,"entry32");
	GtkWidget *entry2=lookup_widget(button,"entry33");
	GtkWidget *entry3=lookup_widget(button,"entry34");
	strcpy(ville,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(mail,gtk_entry_get_text(GTK_ENTRY(entry2)));
	FILE *f=fopen("information.txt","r");
	info *tab;
	int i=0;
	tab=(info *)malloc(sizeof(info));
	while(fscanf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,&(tab[i].jour),tab[i].mois,&(tab[i].jour),tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail)!=EOF){
		if(strcmp(tab[i].username,username)==0){
			strcpy(tab[i].ville,ville);
			strcpy(tab[i].tel,tel);
			strcpy(tab[i].mail,mail);
		}
		i++;
		tab=(info *)realloc(tab,(i+1)*sizeof(info));
	}
	fclose(f);
	f=fopen("information.txt","w+");
	int j=i;
	i=0;
	for(i=0;i<j;i++){
		fprintf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,tab[i].jour,tab[i].mois,tab[i].jour,tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail);
	}
	fclose(f);
}


void
on_button48_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button25_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button26_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button27_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	FILE *fp=fopen("current.txt","r");
	char username[20];
	fscanf(fp,"%s",username);
	fclose(fp);
	char mail[20];
	char tel[20];
	char ville[20];
	GtkWidget *entry1=lookup_widget(button,"entry56");
	GtkWidget *entry2=lookup_widget(button,"entry57");
	GtkWidget *entry3=lookup_widget(button,"entry58");
	strcpy(ville,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(mail,gtk_entry_get_text(GTK_ENTRY(entry2)));
	FILE *f=fopen("information.txt","r");
	info *tab;
	int i=0;
	tab=(info *)malloc(sizeof(info));
	while(fscanf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,&(tab[i].jour),tab[i].mois,&(tab[i].jour),tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail)!=EOF){
		if(strcmp(tab[i].username,username)==0){
			strcpy(tab[i].ville,ville);
			strcpy(tab[i].tel,tel);
			strcpy(tab[i].mail,mail);
		}
		i++;
		tab=(info *)realloc(tab,(i+1)*sizeof(info));
	}
	fclose(f);
	f=fopen("information.txt","w+");
	int j=i;
	i=0;
	for(i=0;i<j;i++){
		fprintf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,tab[i].jour,tab[i].mois,tab[i].jour,tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail);
	}
	fclose(f);
}


void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button36_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button37_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button55_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button31_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	FILE *fp=fopen("current.txt","r");
	char username[20];
	fscanf(fp,"%s",username);
	fclose(fp);
	char mail[20];
	char tel[20];
	char ville[20];
	GtkWidget *entry1=lookup_widget(button,"entry42");
	GtkWidget *entry2=lookup_widget(button,"entry43");
	GtkWidget *entry3=lookup_widget(button,"entry44");
	strcpy(ville,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(mail,gtk_entry_get_text(GTK_ENTRY(entry2)));
	FILE *f=fopen("information.txt","r");
	info *tab;
	int i=0;
	tab=(info *)malloc(sizeof(info));
	while(fscanf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,&(tab[i].jour),tab[i].mois,&(tab[i].jour),tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail)!=EOF){
		if(strcmp(tab[i].username,username)==0){
			strcpy(tab[i].ville,ville);
			strcpy(tab[i].tel,tel);
			strcpy(tab[i].mail,mail);
		}
		i++;
		tab=(info *)realloc(tab,(i+1)*sizeof(info));
	}
	fclose(f);
	f=fopen("information.txt","w+");
	int j=i;
	i=0;
	for(i=0;i<j;i++){
		fprintf(f,"%s %s %s %d %s %d %s %s %s %s\n",tab[i].username,tab[i].nom,tab[i].prenom,tab[i].jour,tab[i].mois,tab[i].jour,tab[i].ville,tab[i].id,tab[i].tel,tab[i].mail);
	}
	fclose(f);

}


void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttondietrv10_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttondietrv20_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttondietrv30_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttondietaff_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttondietadd_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttondietmod_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttondietdel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button56_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button33_clicked                    (GtkWidget       *object_graphique,
                                        gpointer         user_data)
{

    info p;
    int role;
    GtkWidget *entry48=lookup_widget(object_graphique,"entry48");
    GtkWidget *entry49=lookup_widget(object_graphique,"entry49");
    GtkWidget *entry51=lookup_widget(object_graphique,"entry51");
    GtkWidget *entry52=lookup_widget(object_graphique,"entry52");
    GtkWidget *entry53=lookup_widget(object_graphique,"entry53");
    GtkWidget *entry54=lookup_widget(object_graphique,"entry54");
    GtkWidget *entry55=lookup_widget(object_graphique,"entry55");
    GtkWidget *entry50=lookup_widget(object_graphique,"entry50");
    GtkWidget *combobox11=lookup_widget(object_graphique,"combobox11");
    GtkWidget *combobox9=lookup_widget(object_graphique,"combobox9");
    GtkWidget *j=lookup_widget(object_graphique, "spinbutton35");
    GtkWidget *a=lookup_widget(object_graphique, "spinbutton37");

    strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(entry48)));
    strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(entry49)));
    strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(entry51)));
    strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(entry52)));
    strcpy(p.ville,gtk_entry_get_text(GTK_ENTRY(entry53)));
    strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(entry54)));
    strcpy(p.tel,gtk_entry_get_text(GTK_ENTRY(entry55)));
    strcpy(p.mail,gtk_entry_get_text(GTK_ENTRY(entry50)));

    p.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
    p.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));

    strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)));
    strcpy(p.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox11)));

    if(strcmp("Coach",p.role)==0)
    {    role=2;
    }
    else if(strcmp("Adherent",p.role)==0)
    {    role=3;
    }
    else if(strcmp("Kine",p.role)==0)
    {    role=5;
    }
	else if(strcmp("Dieteticien",p.role)==0)
    {    role=4;
    }

    else{
    role=6;
}

ajouter(p.username,p.password,role);
information(p);

}

void
on_button42_clicked                    (GtkWidget       *object_graphique,
                                        gpointer         user_data)
{
	GtkWidget *admin;
	GtkWidget *login;
	login=create_login();
	gtk_widget_show(login);
	admin=gtk_widget_get_toplevel(object_graphique);
	gtk_widget_hide(admin);
}


void
on_button9_clicked                     (GtkWidget       *object_graphique,
                                        gpointer         user_data)
{
char username[30];int jour;char mois[30];int annee;
char nom[30];char prenom[30];char ville[30];char id[30];char mail[30];char tel[30];

GtkWidget *entry68=lookup_widget(object_graphique,"entry68");
GtkWidget *entry63=lookup_widget(object_graphique,"entry63");
GtkWidget *entry64=lookup_widget(object_graphique,"entry64");
GtkWidget *entry65=lookup_widget(object_graphique,"entry65");
GtkWidget *entry66=lookup_widget(object_graphique,"entry66");
GtkWidget *entry67=lookup_widget(object_graphique,"entry67");
GtkWidget *entry62=lookup_widget(object_graphique,"entry62");
GtkWidget *j=lookup_widget(object_graphique, "spinbutton41");
GtkWidget *a=lookup_widget(object_graphique, "spinbutton42");
GtkWidget *combobox12=lookup_widget(object_graphique,"combobox12");

  strcpy(username,gtk_entry_get_text(GTK_ENTRY(entry68)));
  strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry63)));
  strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(entry64)));
  strcpy(ville,gtk_entry_get_text(GTK_ENTRY(entry65)));
  strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry66)));
  strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entry67)));
  strcpy(mail,gtk_entry_get_text(GTK_ENTRY(entry62)));

  jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (j));
  strcpy(mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox12)));
  annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (a));

modif(username,nom,prenom,jour,mois,annee,ville,id,tel,mail);


}

void
on_button49_clicked (GtkWidget *object_graphique, gpointer user_data)
{



char username[30];
int x;

GtkWidget *entry69=lookup_widget(object_graphique,"entry69");

strcpy(username,gtk_entry_get_text(GTK_ENTRY(entry69)));

x=suppression(username);




}


void
on_button50_clicked                    (GtkWidget       *object_graphique,
                                        gpointer         user_data)
{
	GtkWidget *admin;
	GtkWidget *treeview10;
	admin = lookup_widget(object_graphique,"admin");
	treeview10=lookup_widget(admin,"treeview10");
	treeprofile(treeview10);
}


void
on_button58_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button57_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}
