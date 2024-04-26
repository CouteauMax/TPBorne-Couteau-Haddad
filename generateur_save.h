 #ifndef GENERATEUR_SAVE_H
 #define GENERATEUR_SAVE_H

 #include "voyants.h"
 #include "boutons.h"
 #include "prise.h"

 using namespace std;

 class generateur_save
 {
 public :
 generateur_save ();
 //void generateur_save_initialiser();
 void generer_PWM(pwm mode);
 float tension();
 void ouvrir_AC();
 void fermer_AC();
 void mef();
 void charger();
 void deconnecter();

 entrees *io;
 int shmid;
 char etat;
 char fin;
 boutons b;
 voyants v;
 prise p;

 };

 #endif