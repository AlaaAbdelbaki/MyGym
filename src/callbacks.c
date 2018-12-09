#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

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
}



void
on_button32_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

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
	

 char nom[30];char prenom[30];char ville[30];char id[30];int jour;int mois;int annee;char tel[30];char mail[30];
 char username[30];char password[30];int role;
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

    strcpy(username,gtk_entry_get_text(GTK_ENTRY(entry48)));
    strcpy(password,gtk_entry_get_text(GTK_ENTRY(entry49)));
    strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry51)));
    strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(entry52)));
    strcpy(ville,gtk_entry_get_text(GTK_ENTRY(entry53)));
    strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry54)));
    strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entry55)));
	strcpy(mail,gtk_entry_get_text(GTK_ENTRY(entry50)));

    jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
    mois=gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox11));
    annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));


    if(strcmp("Coach",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
    {    role=2;
    }
    else if(strcmp("Adherent",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
    {    role=3;
    }
    else if(strcmp("Kine",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
    {    role=5;
    }
	else if(strcmp("Dieteticien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox9)))==0)
    {    role=4;
    }

    else{
    role=6;
}

ajouter(username,password,role);
information(nom,prenom,ville,id,jour,mois,annee,tel,mail);

}


void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button49_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button50_clicked                    (GtkWidget       *object_graphique,
                                        gpointer         user_data)
{
	GtkWidget *admin;
	GtkWidget *treeview10;
	admin = lookup_widget(object_graphique,"admin");
	treeview10=lookup_widget(admin,"treeview10");
	tree(treeview10);
}

