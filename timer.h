 #ifndef TIMER_H
 #define TIMER_H

 #include <stdio.h>
 #include <iostream>
 #include <unistd.h>

 #include "donnees_borne.h"
 #include "memoire_borne.h"

 using namespace std;


 class timer
 { entrees *io;
 int shmid;
 int depart_timer;

 public :
 timer();
 void raz();
 int valeur();



 };

 #endif