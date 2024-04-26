#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "donnees_borne.h"
#include "memoire_borne.h"

 #ifndef PRISE_H
 #define PRISE_H

 #include <stdio.h>
 #include <iostream>
 #include <unistd.h>

 #include "donnees_borne.h"
 #include "memoire_borne.h"

 class prise
 {
 entrees *io;
 int shmid;
 public :
 prise();
 void verouiller_trappe();
 void deverouiller_trappe();
 void set_prise(led val);

 };

 #endif // PRISE_H