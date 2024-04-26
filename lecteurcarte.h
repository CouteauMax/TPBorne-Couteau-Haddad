#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>

#include "lcarte.h"
#include "base_clients.h"
#include "generateur_save.h"
 #include "timer.h"
 #include "voyants.h"
 #include "boutons.h"




 class lecteurcarte
 {
 public :
 lecteurcarte();
 void initialiser();
 void lire_carte();
 voyants voy;
 boutons bout;
 prise pri;
 timer tim;
 base_clients bc;
 generateur_save sav;
 int num1;
 int num2;
 char service_en_cours;
 };

 #endif // LECTEURCARTE_H