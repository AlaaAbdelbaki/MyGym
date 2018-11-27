#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "admin.h"


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *window1=gtk_widget_get_toplevel(objet_graphique);
  GtkWidget *window2;
  GtkWidget *window3;
  GtkWidget *window4;
  GtkWidget *window5;
  GtkWidget *window6;
  GtkWidget *window7;
  GtkWidget *window8;
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
	window7=create_window7();
	gtk_widget_show(window7);
	gtk_widget_destroy(window1);

	}

else if(verifier(username,password)==2)
	{
	window3=create_window3();
	gtk_widget_show(window3);
	gtk_widget_destroy(window1);

	}

else if(verifier(username,password)==3)
	{
	window4=create_window4();
	gtk_widget_show(window4);
	gtk_widget_destroy(window1);

	}
else if(verifier(username,password)==4)
	{
	window5=create_window5();
	gtk_widget_show(window5);
	gtk_widget_destroy(window1);
	}
else if(verifier(username,password)==5)
	{
	window6=create_window6();
	gtk_widget_show(window6);
	gtk_widget_destroy(window1);
	}
else if(verifier(username,password)==6)
	{
	window6=create_window2();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
	}
}


void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{


gtk_main_quit();
}




void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button4_clicked                     (GtkWidget       *button,

                                      gpointer         user_data)
{
 GtkWidget *window7=gtk_widget_get_toplevel(button);
  GtkWidget *window8;


	window8=create_window8();
	gtk_widget_show(window8);
	gtk_widget_hide(window7);
}


void
on_button6_clicked                     (GtkWidget *object_graphique,
                                        gpointer         user_data)
{
GtkWidget *window10;
window10=create_window10();
	gtk_widget_show(window10);
GtkWidget *window8=gtk_widget_get_toplevel(object_graphique);
	gtk_widget_hide(window8);
}


void
on_button5_clicked                     (GtkWidget *object_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window9;
	window9=create_window9();
	gtk_widget_show(window9);
	GtkWidget *window8=gtk_widget_get_toplevel(object_graphique);
	gtk_widget_hide(window8);
}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window7;

	gtk_widget_destroy(window7);
}

void
on_button9_clicked                     (GtkWidget       *object_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window8=gtk_widget_get_toplevel(object_graphique);
	gtk_widget_hide(window8);

 char login[30];char password[30];int role;
    char nom[30];char prenom[30];
    int jour;int mois;int annee;
    char ville[30];char mail[30];char tel[50];char id[30];

    GtkWidget *input3=lookup_widget(object_graphique,"entry3");
    GtkWidget *input4=lookup_widget(object_graphique,"entry4");
    GtkWidget *input5=lookup_widget(object_graphique,"entry5");
    GtkWidget *input6=lookup_widget(object_graphique,"entry6");
    GtkWidget *input7=lookup_widget(object_graphique,"entry7");
    GtkWidget *input8=lookup_widget(object_graphique,"entry8");
    GtkWidget *input9=lookup_widget(object_graphique,"entry9");
	GtkWidget *input10=lookup_widget(object_graphique,"entry10");
    GtkWidget *combobox1=lookup_widget(object_graphique,"combobox1");
	GtkWidget *combobox2=lookup_widget(object_graphique,"combobox2");
    GtkWidget *j=lookup_widget(object_graphique, "spinbutton1");
    GtkWidget *m=lookup_widget(object_graphique, "spinbutton2");
    GtkWidget *a=lookup_widget(object_graphique, "spinbutton3");

    strcpy(login,gtk_entry_get_text(GTK_ENTRY(input3)));
    strcpy(password,gtk_entry_get_text(GTK_ENTRY(input4)));
    strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input6)));
    strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input7)));
    strcpy(ville,gtk_entry_get_text(GTK_ENTRY(input8)));
    strcpy(id,gtk_entry_get_text(GTK_ENTRY(input9)));
    strcpy(mail,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(input10)));

    jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
    mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (m));
    annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));


    if(strcmp("coach",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
    {    role=2;
    }
    else if(strcmp("adherent",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
    {    role=3;
    }
    else if(strcmp("kine",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
    {    role=4;
    }
	else if(strcmp("dietecien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
    {    role=5;
    }

    else{
    role=6;
}
	if(strcmp("coach",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
    {    role=2;
    }
    else if(strcmp("adherent",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
    {    role=3;
    }
    else if(strcmp("kine",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
    {    role=4;
    }
	else if(strcmp("dietecien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
    {    role=5;
    }

    else{
    role=6;
}
info(nom,prenom,jour,mois,annee,tel,ville,mail,role);
ajouter(login,password,role);
}


void
on_button10_clicked                    (GtkWidget       *object_graphique,
                                        gpointer         user_data)
{


FILE *fichierliste;
    char buffer[30],texte_entry[30];
    GtkTextBuffer *pBuffer;
    GtkTextIter fin;


    GtkWidget *tviewliste = lookup_widget(object_graphique,"textview1");
    GtkWidget *entry = lookup_widget(object_graphique,"entry1");


     pBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tviewliste));


     if(fichierliste=fopen("info.txt","r")){
              while(fgets(buffer,30,fichierliste)){

		gtk_text_buffer_get_end_iter(pBuffer, &fin);

                  gtk_text_buffer_insert(pBuffer, &fin, buffer, strlen(buffer));
              }
     }

    fclose(fichierliste);

}



void
on_button11_clicked                    (GtkButton       *object_graphique,
                                        gpointer         user_data)
{
GtkWidget *window9;
GtkWidget *window8;
window9=lookup_widget(object_graphique,"window9");
window8=create_window8();
gtk_widget_show(window8);
gtk_widget_hide(window9);
}

void
on_coach_saveprof_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *name;
  GtkWidget *surname;
  GtkWidget *day;
  GtkWidget *month;
  GtkWidget *year;
  GtkWidget *email;
  GtkWidget *number;
  char nom[30];
  char prenom [30];
  int jour;
  char mois[10];
  int annee;
  char mail[50];
  char num[13];
  FILE *f;
  name=lookup_widget(button,"coach_entry11");
  surname=lookup_widget(button,"coach_entry12");
  day=lookup_widget(button,"coach_spinbutton5");
  month=lookup_widget(button,"coach_combobox3");
  year=lookup_widget(button,"coach_spinbutton6");
  email=lookup_widget(button,"coach_entry13");
  number=lookup_widget(button,"coach_entry14");
  strcpy(nom,gtk_entry_get_text(GTK_ENTRY(name)));
  strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(surname)));
  jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
  strcpy(mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(month)));
  annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
  strcpy(mail,gtk_entry_get_text(GTK_ENTRY(email)));
  strcpy(num,gtk_entry_get_text(GTK_ENTRY(number)));
  f=fopen("profilecoach.txt","w");
  fprintf(f,"%s %s %d %s %d %s %s",nom,prenom,jour,mois,annee,mail,num);
  fclose(f);
}


void
on_coach_save_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *username;
  GtkWidget *seance;
  GtkWidget *poids_old;
  GtkWidget *poids_new;
  char user;
  int sessions,old,new;
  FILE *f;
  username=lookup_widget(button,"coach_userrap");
  seance=lookup_widget(button,"coach_spinbutton4");
  poids_old=lookup_widget(button,"spinbutton5");
  poids_new=lookup_widget(button,"spinbutton6");
  strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
  sessions=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(seance));
  old=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(poids_old));
  new=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(poids_new));
  f=fopen("rap_coach","w");
  fprintf(f,"%s %d %d %d",user,sessions,old,new);
  fclose(f);

}


void
on_coach_saveemp_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *seancel;
  GtkWidget *seancem;
  GtkWidget *seanceme;
  GtkWidget *seancej;
  GtkWidget *seancev;
  GtkWidget *seances;
  GtkWidget *entrainementl;
  GtkWidget *entrainementm;
  GtkWidget *entrainementme;
  GtkWidget *entrainementj;
  GtkWidget *entrainementv;
  GtkWidget *entrainements;
  char lundis[50];
  char lundie[50];
  char mardis[50];
  char mardie[50];
  char mercredis[50];
  char mercredie[50];
  char jeudis[50];
  char jeudie[50];
  char vendredis[50];
  char vendredie[50];
  char samedis[50];
  char samedie[50];
  FILE *f;
  seancel=lookup_widget(button,"coach_seancel");
  seancem=lookup_widget(button,"coach_séancem");
  seanceme=lookup_widget(button,"coach_séanceme");
  seancej=lookup_widget(button,"coach_séancej");
  seancev=lookup_widget(button,"coach_séancev");
  seances=lookup_widget(button,"coach_séances");
  entrainementl=lookup_widget(button,"coach_entrainementl");
  entrainementm=lookup_widget(button,"coach_entrainementm");
  entrainementme=lookup_widget(button,"coach_entrainementme");
  entrainementj=lookup_widget(button,"coach_entrainementj");
  entrainementv=lookup_widget(button,"coach_entrainementv");
  entrainements=lookup_widget(button,"coach_entrainements");
  strcpy(lundis,gtk_combo_box_get_active_text(GTK_COMBO_BOX(seancel)));
  strcpy(mardis,gtk_combo_box_get_active_text(GTK_COMBO_BOX(seancem)));
  strcpy(mercredis,gtk_combo_box_get_active_text(GTK_COMBO_BOX(seanceme)));
  strcpy(jeudis,gtk_combo_box_get_active_text(GTK_COMBO_BOX(seancej)));
  strcpy(vendredis,gtk_combo_box_get_active_text(GTK_COMBO_BOX(seancev)));
  strcpy(samedis,gtk_combo_box_get_active_text(GTK_COMBO_BOX(seances)));
  strcpy(lundie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrainementl)));
  strcpy(mardie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrainementm)));
  strcpy(mercredie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrainementme)));
  strcpy(jeudie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrainementj)));
  strcpy(vendredie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrainementv)));
  strcpy(samedie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrainements)));
  f=fopen("empcoach.txt","w");
  fprintf(f,"Lundi: %s %s\nMardi: %s %s\nMercredi: %s %s\nJeudi: %s %s\nVendredi: %s %s\nSamedi: %s %s\n",lundis,lundie,mardis,mardie,mercredis,mercredie,jeudis,jeudie,vendredis,vendredie,vendredis,samedie);
  fclose(f);
}

void
on_Nutritionniste_button13_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Nutritionniste_button14_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Nutritionniste_button16_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Nutritionniste_button15_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Nutritionniste_button18_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Nutritionniste_button12_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Nutritionniste_button17_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Nutritionniste_button19_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}




void
on_coach_valider_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}



void
on_adherant_comboboxentry1_changed     (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_adherant_button13_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adherant_button14_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adherant_entry11_delete_text        (GtkEditable     *editable,
                                        gint             start_pos,
                                        gint             end_pos,
                                        gpointer         user_data)
{

}


void
on_adherant_entry11_insert_text        (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{

}


void
on_adherant_entry12_insert_text        (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{

}


void
on_adherant_entry12_delete_text        (GtkEditable     *editable,
                                        gint             start_pos,
                                        gint             end_pos,
                                        gpointer         user_data)
{

}


void
on_adherant_spinbutton4_changed        (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_adherant_spinbutton5_changed        (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_adherant_button15_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adherant_spinbutton6_change_value   (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_spinbutton7_change_value            (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_spinbutton8_change_value            (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_comboboxentry2_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_adherant_button17_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_badherant_utton18_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adherant_spinbutton9_change_value   (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_adherant_spinbutton10_change_value  (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_adherant_spinbutton11_change_value  (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_comboboxentry3_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_adherant_button20_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button21_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adherant_button22_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_spinbutton12_change_value           (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_spinbutton13_change_value           (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_adherant_spinbutton14_change_value  (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_comboboxentry4_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_adherant_button23_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adherant_button24_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adherant_button25_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_spinbutton15_change_value           (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_adherant_spinbutton16_change_value  (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_adherant_spinbutton17_change_value  (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data)
{

}


void
on_button26_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adherant_button27_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button28_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adherant_button29_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_kine_gererfiche_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_kine_rapport_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_kine_quit1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_kine_button16_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_kine_button17_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_kine_button18_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_kine_button19_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_dietsaveprof_clicked                (GtkButton       *button,
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
on_kine_button20_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_buttondietdel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}

