 #ifndef VOYANTS_H
 #define VOYANTS_H

 #include <stdio.h>
 #include <iostream>
 #include <unistd.h>

 #include "donnees_borne.h"
 #include "memoire_borne.h"

 using namespace std;

 class voyants
 {
 entrees *io;
 int shmid;

 public :
 voyants();
 void set_dispo(led val);
 void set_charge(led val);
 void blink_charge();
 void blink_defaut();
 int dispo();

 };

 #endif