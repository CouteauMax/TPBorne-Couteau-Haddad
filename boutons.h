 #ifndef BOUTONS_H
 #define BOUTONS_H

 #include <stdio.h>
 #include <iostream>
 #include <unistd.h>

 #include "donnees_borne.h"
 #include "memoire_borne.h"

 class boutons
 {
 public :

 entrees *io;
 int shmid;

 boutons();
 void boutons_initialiser();
 int charge();
 int stop();



 };

 #endif