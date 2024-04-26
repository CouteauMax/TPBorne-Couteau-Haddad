 #include "base_clients.h"

 base_clients::base_clients(){compteur=0;}


 int base_clients::authentifier(unsigned short int numero_carte)
 {

 unsigned int i;
 for(i=0;i<liste.size();i++)
 {

 if (numero_carte==liste.at(i))
 {
 return 1;
 }
 }

 return 0;
 }

 void base_clients::ajout_client()
 {
 int numero;
 char verif;
 unsigned int i;

 i=0;

 do
 {
 verif=1;
 cout<<"Saisir le numéro de la nouvelle carte "<<endl;
 cin>>numero;

 //Vérfie si le numéro est déjà saisi
 for(i=0;i<liste.size();i++)
 {

 if (numero==liste.at(i))
 {
 verif=0;
 }
 }

 //Ajouter un client
 if (verif==1)
 {
 liste.push_back(numero);
 compteur++;
 }
 else //verif==0
 {
 cout<<"Client deja enregistre"<<endl;
 }
 }while(verif==0);
 cout<<"Ajout reussi"<<endl;
 }

 void base_clients::supprimer_client()
 {
 int numero;
 int position;
 char verif=0;
 unsigned int i;

 cout<<"Entrer votre numero: "<<endl;
 cin>>numero;

 for(i=0;i<liste.size();i++)
 {
 if (numero==liste.at(i)) //Vérfie si le numéro est déjà saisi
 {
 verif=1;
 position=i;
 }
 }

 if(verif==1)
 {
 liste.erase(liste.begin()+position);
 cout<<"Suppression reussi"<<endl;
 }
 else
 {
 cout<<"Numero inconnu "<<endl;
 }
 }

 void base_clients::afficher_client()
 {
 unsigned int i;

 for(i=0;i<liste.size();i++)
 {
 cout<<liste.at(i)<<" ";
 }
 }
