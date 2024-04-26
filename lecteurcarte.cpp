 #include "lecteurcarte.h"

 lecteurcarte::lecteurcarte (){};
 void lecteurcarte::initialiser()
 {
 initialisations_ports();
 num1=0;
 num2=0;
 service_en_cours=0;
 }

 void lecteurcarte::lire_carte()
 {
 cout<<"Veuillez inserer votre carte"<<endl;
 attente_insertion_carte();
 if(1) //test de la détection d’insertion de la carte
 {
 num1 = lecture_numero_carte(); //lecture du numéro de la carte
 cout<<"Votre numero de carte est : "<<num1<<endl;

 if(bc.authentifier(num1) && voy.dispo()) //authentification réussie et borne disponible
 {
 cout<<"Authentification reussi"<<endl;

 service_en_cours=1;
 tim.raz();
 voy.blink_charge();

 do
 {
 if(bout.charge())
 {
 voy.set_dispo(OFF);
 cout<<"Veuillez retirer votre carte"<<endl;
 attente_retrait_carte();
 sav.charger();
 cout<<"Veuillez inserer votre carte"<<endl;
 do
 {
 attente_insertion_carte();
 num2 = lecture_numero_carte();
 if(num1!=num2)
 {
 cout<<"Le numero saisi est incorrect"<<endl;
 }
 sleep(1);
 }
 while(num1!=num2);
 sav.deconnecter();
 cout <<"Veuillez retirer votre carte \n"<<endl;
 attente_retrait_carte();
 if(bout.stop())
 {
 cout<<"Charge arrete"<<endl;
 }
 service_en_cours=0;
 cout<<"Service termine"<<endl;

 }

 }while(tim.valeur()<10&&service_en_cours==1);

 if(service_en_cours==0)
 {
 cout <<"Execution reussi"<<endl;
 }
 else
 {
 cout <<"Temps ecoule"<<endl;
 cout <<"Veuillez retirer votre carte "<<endl;
 attente_retrait_carte();
 }

 //Réinitialisation
 voy.set_dispo(VERT);
 tim.raz();
 bout.boutons_initialiser();
 service_en_cours=0;

 } //end client auth

 else //client non identifité
 {
 cout <<"Authentification refusee "<<endl;
 voy.blink_defaut();
 }


 } //end if carte inseree

 } //end main
