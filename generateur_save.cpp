 #include "generateur_save.h"

 //MAE
 //Etats
 #define etat0 0
 #define etat1 1
 #define etat2 2
 #define etat3 3
 #define etat4 4
 #define etat5 5
 #define etat6 6
 //Transitions
 #define T0_1 tension()==9
 #define T1_2 tension()==6
 #define T1_4 b.stop()
 #define T2_3 tension()==6
 #define T2_4 b.stop()||(tension()==9)
 #define T3_4 b.stop()||(tension()==9)
 #define T5_6 tension()==12

 generateur_save::generateur_save() {io=acces_memoire(&shmid);}
 void generateur_save::generer_PWM(pwm mode)
 {
 io->gene_pwm=mode;
 sleep(1);
 }

 float generateur_save::tension()
 {
 return(io->gene_u);
 }



 void generateur_save::ouvrir_AC()
 {
 io->contacteur_AC=0;
 }
 void generateur_save::fermer_AC()
 {
 io->contacteur_AC=1;
 }



 void generateur_save::mef()
 {

 switch (etat)
 {
 case etat0: //attente du branchement de la prise
 if(T0_1)
 {
 etat=etat1;
 }
 break;
 case etat1: // prise branchée !
 if(T1_2)
 {
 etat=etat2;
 }
 else
 {
 if(T1_4)
 {
 etat=etat4;
 }
 }
 break;
 case etat2: // attente de la vehicule
 if(T2_3)
 {
 etat=etat3;
 }
 else
 {
 if(T2_4)
 {
 etat=etat4;
 }
 }
 break;
 case etat3: // voiture en charge
 if(T3_4)
 {

 etat=etat4;
 }
 break;
 case etat4: //la batterie est bien chargée
 break;
 case etat5: //attente pour que la prise soit debranchée
 if(T5_6)
 {
 etat=etat6;
 }
 break;
 case etat6: // véhicule prete à la reprise
 break;

 default : etat = etat0;
 }


 switch (etat)
 {
 case etat0: // attente de la prise pour charger la voiture
 v.set_charge(ROUGE);
 p.deverouiller_trappe();
 generer_PWM(DC);
 break;
 case etat1: // la prise est bien chargée
 p.set_prise(VERT);
 p.verouiller_trappe();
 generer_PWM(AC_1K);
 break;
 case etat2: // attente de la voiture
 fermer_AC();
 generer_PWM(AC_CL);
 break;
 case etat4: //batterie pleine
 ouvrir_AC();
 v.set_charge(VERT);
 generer_PWM(DC);
 fin=1;
 break;

 case etat5: // en attendant jusqu’au que la voiture soit prete à la reprise
 v.set_charge(OFF);
 p.deverouiller_trappe();
 break;
 case etat6: // la voiture sest prete à la reprise
 p.verouiller_trappe();
 v.set_dispo(VERT);
 p.set_prise(OFF);
 fin=1;
 break;


 }
 }

 void generateur_save::charger()
 {
 etat=0;
 fin=0;
 while(!fin)
 {
 mef();
 }
 }

 void generateur_save::deconnecter()
 {
 etat=5;
 fin=0;
 while(!fin)
 {
 mef();
 }
 }
