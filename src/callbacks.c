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
  GtkWidget *name;
  GtkWidget *surname;
  GtkWidget *bday;
  GtkWidget *cin;
  FILE *f2;
  name=lookup_widget(objet_graphique,"label306");
  surname=lookup_widget(objet_graphique,"label307");
  bday=lookup_widget(objet_graphique,"label308");
  cin=lookup_widget(objet_graphique,"label309");
  char user[20];
  char nom[20];
  char prenom[20];
  char date[2];
  char mois[10];
  char annee[4];
  char town[10];
  char carte[20];
  char num[10];
  char email[20];
  f2=fopen("information.txt","r");
  while(!EOF)
  {
  fscanf(f2,"%s %s %s %s %s %s %s %s %s %s %s",user,nom,prenom,date,mois,annee,town,carte,num,email);
  if(strcmp(user,username)==0)
  {
    gtk_label_set_text(GTK_LABEL(name),nom);
    gtk_label_set_text(GTK_LABEL(surname),prenom);
    gtk_label_set_text(GTK_LABEL(bday),date);
    gtk_label_set_text(GTK_LABEL(cin),carte);
  }
  }
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
char ville[100],email[100];
char numtel[20];
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
input1=lookup_widget(button,"entry45");
input2=lookup_widget(button,"entry46");
input3=lookup_widget(button,"entry47");
strcpy(ville,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(email,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(numtel,gtk_entry_get_text(GTK_ENTRY(input3)));
Modifierprofil(ville, email, numtel);
}


void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char date[10],mois[12],annee[7],heure[6],user[100];
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
input1=lookup_widget(button,"spinbutton27");
input2=lookup_widget(button,"combobox5");
input3=lookup_widget(button,"spinbutton28");
input4=lookup_widget(button,"spinbutton29");
input5=lookup_widget(button,"entry41");
//dt_resr.input1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
//dt_resr.input2=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));
strcpy(date,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(annee,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(heure,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(user,gtk_entry_get_text(GTK_ENTRY(input5)));
AjouterRdv(date,mois,annee,heure,user);
}


void
on_button23_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char user[100];
GtkWidget *input1;
input1=lookup_widget(button,"entry41");
//dt_resr.input1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
//dt_resr.input2=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));
strcpy(user,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimerRdv(user);
}


void
on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char nom[100];
GtkWidget *treeview5;
GtkWidget *input;
input=lookup_widget(button,"entry41");
treeview5=lookup_widget(button,"treeview5");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
AfficherRdv(nom,treeview5);
}


void
on_button28_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char nom[100];
GtkWidget *treeview7;
GtkWidget *input;
input=lookup_widget(button,"entry75");
treeview7=lookup_widget(button,"treeview7");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
afficherFM(nom,treeview7);
}


void
on_button30_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char nom[100];
GtkWidget *treeview8;
GtkWidget *input;
input=lookup_widget(button,"entry71");
treeview8=lookup_widget(button,"treeview8");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
AfficherRapport(nom,treeview8);
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
  fprintf(f2,"%s %s %d %s %d %d \n",coach,user,day,month,year,time);
  fclose(f2);
}


void
on_button52_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *user;
  char username[50];
  user=lookup_widget(button,"entry70");
  strcpy(username,gtk_entry_get_text(GTK_ENTRY(user)));
  supprdv(username);
}


void
on_button53_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *tree;
  tree=lookup_widget(button,"treeview11");
  treerdv(tree);

}


void
on_button15_enter                      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *treeviewcoach;
  treeviewcoach=lookup_widget(button,"treeviewcoach");
  treecoach(treeviewcoach);
}


void
on_button54_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *username;
  GtkWidget *tree;
  char user[20];
  username=lookup_widget(button,"entry72");
  tree=lookup_widget(button,"treeview12");
  strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
  treerapp(tree,user);
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
      GtkWidget *combobox1=lookup_widget(button,"comboboxdietrv");
      GtkWidget *j=lookup_widget(button, "spinbuttondietrv1");
      GtkWidget *a=lookup_widget(button, "spinbuttondietrv2");
      GtkWidget *h=lookup_widget(button, "spinbutton21");
      GtkWidget *entry1=lookup_widget(button,"dietenteruserrv");
      int jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
      int annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));
      int hour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (h));
      char mois[15];
      char user[20];
      char username[20];
      strcpy(mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
      strcpy(user,gtk_entry_get_text(GTK_ENTRY(entry1)));
      FILE *f=fopen("current.txt","r");
      fscanf(f,"%s",username);
      fclose(f);
      int x=rechrdv(user,username,jour,mois,annee,hour);
      if(!x){
      f=fopen("Rendez.txt","a+");
      fprintf(f,"%s %s %d %s %d %d\n",user,username,jour,mois,annee,hour);
      fclose(f);
      }
}


void
on_buttondietrv20_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *combobox1=lookup_widget(button,"comboboxdietrv");
      GtkWidget *j=lookup_widget(button, "spinbuttondietrv1");
      GtkWidget *a=lookup_widget(button, "spinbuttondietrv2");
      GtkWidget *h=lookup_widget(button, "spinbutton21");
      int jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
      int annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));
      int hour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (h));
      char mois[15];
      strcpy(mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

  	char userx[20];
  	char usernamex[20];
  	int jourx;
  	char moisx[20];
  	int anneex;
  	int hourx;
  	FILE *f=fopen("Rendez.txt","r");
  	FILE *ft=fopen("r.txt","w+");
  	while(fscanf(f,"%s %s %d %s %d %d\n",userx,usernamex,&jourx,moisx,&anneex,&hourx)!=EOF){
  		if((((jour!=jourx)&&(strcmp(mois,moisx)))&&(anneex!=annee))&&(hourx!=hour)){
  			fprintf(ft,"%s %s %d %s %d %d\n",userx,usernamex,jourx,moisx,anneex,hourx);
  		}
  	}
  	fclose(f);
  	fclose(ft);

  	remove("Rendez.txt");
  	rename("r.txt","Rendez.txt");
}


void
on_buttondietrv30_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *diet;
  	GtkWidget *treeview10;
  	diet = lookup_widget(button,"diet");
  	treeview10=lookup_widget(diet,"treeviewdiet22");
  	treerdv(treeview10);
}


void
on_buttondietaff_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *diet;
  	GtkWidget *treeview10;
  	diet = lookup_widget(button,"diet");
  	treeview10=lookup_widget(diet,"treeviewdiet1");
  	treefich(treeview10);
}


void
on_buttondietadd_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *m=lookup_widget(button, "spinbuttondietrama");
  	int matin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (m));
  	GtkWidget *mi=lookup_widget(button, "spinbuttonrami");
  	int midi=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mi));
  	GtkWidget *s=lookup_widget(button, "spinbuttonraso");
  	int soir=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (s));
  	GtkWidget *entry1=lookup_widget(button,"dietenteruser");
  	char user[20];
  	strcpy(user,gtk_entry_get_text(GTK_ENTRY(entry1)));
  	int x=rechfiche(user);
  	if(!x){
  	FILE *f=fopen("fiche.txt","a+");
  	fprintf(f,"%s 0 0 %d %d %d\n",user,matin,midi,soir);
  	fclose(f);
  	}
  	else{
  	char userx[20];
  	int ch1;
  	int ch2;
  	int ch3;
  	int ch4;
  	int ch5;
  	strcpy(user,gtk_entry_get_text(GTK_ENTRY(entry1)));
  	FILE *f=fopen("fiche.txt","r");
  	FILE *ft=fopen("r.txt","w+");
  	while(fscanf(f,"%s %d %d %d %d %d\n",userx,&ch1,&ch2,&ch3,&ch4,&ch5)!=EOF){
  		if(strcmp(user,userx)){
  			fprintf(ft,"%s %d %d %d %d %d\n",userx,ch1,ch2,ch3,ch4,ch5);
  		}
  		else{
  			fprintf(ft,"%s %d %d %d %d %d\n",userx,ch1,ch2,matin,midi,soir);
  		}
  	}
  	fclose(f);
  	fclose(ft);

  	remove("fiche.txt");
  	rename("r.txt","fiche.txt");
  	}
}


void
on_buttondietmod_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *m=lookup_widget(button, "spinbuttondietrama");
  	int matin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (m));
  	GtkWidget *mi=lookup_widget(button, "spinbuttonrami");
  	int midi=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mi));
  	GtkWidget *s=lookup_widget(button, "spinbuttonraso");
  	int soir=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (s));
  	GtkWidget *entry1=lookup_widget(button,"dietenteruser");
  	char user[20];
  	strcpy(user,gtk_entry_get_text(GTK_ENTRY(entry1)));
  	int x=rechfiche(user);
  	if(!x){
  	FILE *f=fopen("fiche.txt","a+");
  	fprintf(f,"%s 0 0 %d %d %d\n",user,matin,midi,soir);
  	fclose(f);
  	}
  	else{
  	char userx[20];
  	int ch1;
  	int ch2;
  	int ch3;
  	int ch4;
  	int ch5;
  	strcpy(user,gtk_entry_get_text(GTK_ENTRY(entry1)));
  	FILE *f=fopen("fiche.txt","r");
  	FILE *ft=fopen("r.txt","w+");
  	while(fscanf(f,"%s %d %d %d %d %d\n",userx,&ch1,&ch2,&ch3,&ch4,&ch5)!=EOF){
  		if(strcmp(user,userx)){
  			fprintf(ft,"%s %d %d %d %d %d\n",userx,ch1,ch2,ch3,ch4,ch5);
  		}
  		else{
  			fprintf(ft,"%s %d %d %d %d %d\n",userx,ch1,ch2,matin,midi,soir);
  		}
  	}
  	fclose(f);
  	fclose(ft);

  	remove("fiche.txt");
  	rename("r.txt","fiche.txt");
  	}
}


void
on_buttondietdel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *entry1=lookup_widget(button,"dietenteruser");
  	char user[20];
  	char userx[20];
  	int ch1;
  	int ch2;
  	int ch3;
  	int ch4;
  	int ch5;
  	strcpy(user,gtk_entry_get_text(GTK_ENTRY(entry1)));
  	FILE *f=fopen("fiche.txt","r");
  	FILE *ft=fopen("r.txt","w+");
  	while(fscanf(f,"%s %d %d %d %d %d\n",userx,&ch1,&ch2,&ch3,&ch4,&ch5)!=EOF){
  		if(strcmp(user,userx)){
  			fprintf(ft,"%s %d %d %d %d %d\n",userx,ch1,ch2,ch3,ch4,ch5);
  		}
  	}
  	fclose(f);
  	fclose(ft);

  	remove("fiche.txt");
  	rename("r.txt","fiche.txt");
}


void
on_button56_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *diet;
  	GtkWidget *treeview10;
  	GtkWidget *entry1=lookup_widget(button,"entry74");
  	char user[20];
  	strcpy(user,gtk_entry_get_text(GTK_ENTRY(entry1)));
  	diet = lookup_widget(button,"diet");
  	treeview10=lookup_widget(diet,"treeview14");
  	treerapp(treeview10,user);
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
char user[100];
GtkWidget *input1;
input1=lookup_widget(button,"entry75");
//dt_resr.input1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
//dt_resr.input2=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));
strcpy(user,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimerFicheMedicale(user);
}


void
on_button57_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char user[100],poids[7],taille[6];
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
input1=lookup_widget(button,"spinbutton34");
input2=lookup_widget(button,"spinbutton33");
input3=lookup_widget(button,"entry75");
//dt_resr.input1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
//dt_resr.input2=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));
strcpy(taille,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(poids,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(user,gtk_entry_get_text(GTK_ENTRY(input3)));
AjouterFicheMedicale(user,taille,poids);
}

void
on_button29_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char user[100],poids[7],taille[6];
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
input1=lookup_widget(button,"spinbutton34");
input2=lookup_widget(button,"spinbutton33");
input3=lookup_widget(button,"entry75");
//dt_resr.input1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
//dt_resr.input2=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));
strcpy(taille,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(poids,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(user,gtk_entry_get_text(GTK_ENTRY(input3)));
ModifierFicheMedicales(user,taille,poids);
}
