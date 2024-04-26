 #include "timer.h"

 timer::timer() {io=acces_memoire(&shmid);
 if (io==NULL)
 {
 cout<<"Erreur!!";
 }};

 void timer::raz()
 {
 depart_timer = io->timer_sec;
 }

 int timer::valeur()
 {
 return io->timer_sec - depart_timer;
 }
