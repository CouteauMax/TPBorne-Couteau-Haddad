 #include <iostream>

 #include "lecteurcarte.h"
 #include "base_clients.h"

 using namespace std;

 int main()
 {

 //Déclarations
 voyants voya;
 boutons bouto;
 prise pris;
 timer time;
 base_clients bcs;
 generateur_save sav;
 lecteurcarte lc;

 lc.initialiser();
 bouto.boutons_initialiser();

 int mode;
 char mode2_choix;


 while (1)
 {

 cout<<"Authentification : Saisir 1\n"<<endl;
 cout<<"Gestion des clients : Saisir 2 "<<endl;
 cin >> mode;

 if(mode==1)
 {
 lc.lire_carte();
 }
 else
 {
 cout<<"Gestion des clients, veuillez choisir le mode\n"<<endl;
 cout<<"A: Ajouter un client\n"<<endl;
 cout<<"B: Affichage des numero\n"<<endl; 
 cout<<"C: Supprimer un client"<<endl;
 cin>>mode2_choix;

 if(mode2_choix=='A') //ajouter des nouveux clients
 {
 bcs.ajout_client();
 }
 else
 {
 if (mode2_choix=='B') //affichage des clients qui sont déjà saisis
 {
 cout<<"Affichage"<<endl;
 bcs.afficher_client();
 }
 else //supression des clients ajoutés
 {
 bcs.supprimer_client();
 }
 }

 } //end if mode 2
 } //end while(1)

 } //end main
