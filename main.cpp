#include <iostream>
#include "plan.h"
#include <string>
/*!
 * \file main.cpp
 * \brief le fichier principal du projet
 * \author equipeDZ
 * \version 0.1
 */
/*!
 * \mainpage Dscription
 * Ce projet a ete realise pour pouvoir jouer un jeux de combat
 * de 2D en mode console en utilisant le langage C++ et le langage C.
 * 
 * \section librairies Les bibliotheques utilise dans ce projet
 * La librairie standard du C++ et du C.
*/
using namespace std;
/*!  \fn  la fonction principale.
   * \brief le main de ce projet
   * @code
   * main();
   * @endcode
   */
int main()
{
string chaine;
while(chaine!="sorciere" && chaine!="barbare" && chaine!="amazone"){
	cout<<"choisissez entre amazone,barbare ou sorciere" <<endl;
	cout<<" Tapez le nom de votre personnage : "<<endl;
	cin>> chaine;}


personnage *per=personnage::creerPersonnage(chaine);
jeux j;
plan p;
combat c;
monstre m (p);
j.jouer(p,per,m,c);
}


