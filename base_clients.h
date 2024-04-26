#ifndef BASE_CLIENTS_H
#define BASE_CLIENTS_H

 #include <stdio.h>
 #include <iostream>
 #include <unistd.h>

 #include <vector>

 using namespace std;

 typedef vector<unsigned short int> vecteur;

 class base_clients
 {
 std::vector <int> liste={1,2,3,4,5,6,7,8,9};
 int compteur;
 public :
 base_clients();
 int authentifier(unsigned short int numero_carte);

 void ajout_client();
 void supprimer_client();
 void afficher_client();

 };

 #endif 

