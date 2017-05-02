#include <iostream>
#include <fstream>
#include <string>
#include "plan.h"
#include <stdlib.h>
#include <time.h>
/*!
 * \file Gl.cpp
 * \brief le fichier qui contient le code source des classes
 * et des methodes utilise dans ce projet
 * \author equipeDZ
 */

using namespace std;

plan::plan()
{  
	carte=new int*[20];
	for(int i=0;i<20;i++){
    	carte[i]=new int[21];
	}
	configuration();
}

void plan:: configuration(){
	ifstream file;
	file.exceptions ( ifstream::failbit | ifstream::badbit );
	int tmp;
	int i=0;
	try {
		file.open("carte/client.txt",ios::in);
		while((!file.eof()) && (i<20))
        	{	
				for(int j=0;j<21;j++){
				file >> tmp;
				carte[i][j]=tmp;
			}
			i++;
        }
    }
  catch (const ifstream::failure& e) {
    cout << "Exception ouverture/lecture fichier";
  }    
	file.close();	
}


		// -------------------------------       TEST           ----------------------------- //
bool plan:: Test_Plan(){
int zone_inacc=0;
int tmp;

	     for(int i=0;i<20;i++){
		  for(int j=0;j<21;j++){
			tmp=carte[i][j];
				if(tmp>0){zone_inacc++;}
					}   
				 }
	if(zone_inacc>6){  return true;}
	else{ return false;}
	}

		//################################ CLASS PERSONNAGE ############################# //


personnage *personnage::creerPersonnage(string nomPersonnage){
	if(nomPersonnage=="barbare")
	return new barbare();
	else if(nomPersonnage=="amazone")
	return new amazone(); 
	else return new sorciere();
}

amazone::amazone(){
	pos_col=1;
	pos_lig=0;
	string path="personnage/amazone.txt";
	string tmp;
     ifstream file(path.c_str(),ios::in);
      if(file){
		while(!file.eof()){
			getline(file,tmp);
			file >> nom >> mana >> vie >> 
			Competence[0] >> BesoinMana_Et_Degat[0][0] >> BesoinMana_Et_Degat[0][1] >>
 			Competence[1] >> BesoinMana_Et_Degat[1][0] >> BesoinMana_Et_Degat[1][1] >>
			Competence[2] >> BesoinMana_Et_Degat[2][0] >> BesoinMana_Et_Degat[2][1] ;		
			Mana=mana; Vie=vie;
					}

			file.close();
			}
	else{ cerr<<"ce personnage n'existe pas "<<endl;}
}

barbare::barbare(){
	pos_col=1;
	pos_lig=0;
	string path="personnage/barbare.txt";
	string tmp;
     ifstream file(path.c_str(),ios::in);
      if(file){
		while(!file.eof()){
			getline(file,tmp);
			file >> nom >> mana >> vie >> 
			Competence[0] >> BesoinMana_Et_Degat[0][0] >> BesoinMana_Et_Degat[0][1] >>
 			Competence[1] >> BesoinMana_Et_Degat[1][0] >> BesoinMana_Et_Degat[1][1] >>
			Competence[2] >> BesoinMana_Et_Degat[2][0] >> BesoinMana_Et_Degat[2][1] ;		
			Mana=mana; Vie=vie;
					}

			file.close();
			}
	else{ cerr<<"ce personnage n'existe pas "<<endl;}
}

sorciere::sorciere(){
	pos_col=1;
	pos_lig=0;
	string path="personnage/sorciere.txt";
	string tmp;
     ifstream file(path.c_str(),ios::in);
      if(file){
		while(!file.eof()){
			getline(file,tmp);
			file >> nom >> mana >> vie >> 
			Competence[0] >> BesoinMana_Et_Degat[0][0] >> BesoinMana_Et_Degat[0][1] >>
 			Competence[1] >> BesoinMana_Et_Degat[1][0] >> BesoinMana_Et_Degat[1][1] >>
			Competence[2] >> BesoinMana_Et_Degat[2][0] >> BesoinMana_Et_Degat[2][1] ;		
						Mana=mana; Vie=vie;
					}

			file.close();
			}
	else{ cerr<<"ce personnage n'existe pas "<<endl;}
}
//****************************************//
	
bool personnage:: deplacer(plan &p,string pos){
if(pos=="z"){  // up
	if(pos_lig>0) {

if( p.carte[pos_lig-1][pos_col]!=2 && p.carte[pos_lig-1][pos_col]!=3 && p.carte[pos_lig-1][pos_col]!=4 && p.carte[pos_lig-1][pos_col]!=5)
   {if( p.carte[pos_lig-1][pos_col]==-1 || p.carte[pos_lig-1][pos_col]==-2 ){ POSM= (pos_lig-1)*100+pos_col;
					NMC=p.carte[pos_lig-1][pos_col]; return false;}
      else if( p.carte[pos_lig-1][pos_col]==7){ cout<<"soignement  réussi"<<endl;mana=Mana; vie=Vie;}
	else{p.carte[pos_lig-1][pos_col]=p.carte[pos_lig][pos_col]; p.carte[pos_lig][pos_col]=0; pos_lig=pos_lig-1; }
			 
			}}}
else  if(pos=="s"){ //down
   if(pos_lig<19) {
if( p.carte[pos_lig+1][pos_col]!=2 && p.carte[pos_lig+1][pos_col]!=3 && p.carte[pos_lig+1][pos_col]!=4 && p.carte[pos_lig+1][pos_col]!=5)
	{	  if( p.carte[pos_lig+1][pos_col]==-1 || p.carte[pos_lig+1][pos_col]==-2){ POSM= (pos_lig+1)*100+pos_col;
							NMC=p.carte[pos_lig+1][pos_col]; return false;}
      		else if( p.carte[pos_lig+1][pos_col]==7){ cout<<"soignement  réussi"<<endl;mana=Mana; vie=Vie;}
                  else{p.carte[pos_lig+1][pos_col]=p.carte[pos_lig][pos_col]; p.carte[pos_lig][pos_col]=0; pos_lig=pos_lig+1;}
                                                                                             }
			} 
		}
 else if(pos=="q"){ //left
     if(pos_col>0) {

if( p.carte[pos_lig][pos_col-1]!=2 && p.carte[pos_lig][pos_col-1]!=3 && p.carte[pos_lig][pos_col-1]!=4 && p.carte[pos_lig][pos_col-1]!=5)
		{  if( p.carte[pos_lig][pos_col-1]==-1 || p.carte[pos_lig][pos_col-1]==-2){ POSM= pos_lig*100+pos_col-1;
							NMC=p.carte[pos_lig][pos_col-1]; return false;}
      		else if( p.carte[pos_lig][pos_col-1]==7){ cout<<"soignement  réussi"<<endl;mana=Mana; vie=Vie;}
                   else{p.carte[pos_lig][pos_col-1]=p.carte[pos_lig][pos_col]; p.carte[pos_lig][pos_col]=0; pos_col=pos_col-1;}
                                                                                             }
			} }
 else if(pos=="d"){// right
	if(pos_col<21) {
if( p.carte[pos_lig][pos_col+1]!=2 && p.carte[pos_lig][pos_col+1]!=3 && p.carte[pos_lig][pos_col+1]!=4 && p.carte[pos_lig][pos_col+1]!=5)
		{if(p.carte[pos_lig][pos_col+1]==-1 || p.carte[pos_lig][pos_col+1]==-2){  POSM= pos_lig*100+pos_col+1;
							NMC=p.carte[pos_lig][pos_col+1]; return false;}
      		  else if( p.carte[pos_lig][pos_col+1]==7){ cout<<"soignement  réussi"<<endl;mana=Mana; vie=Vie;}
                  else{p.carte[pos_lig][pos_col+1]=p.carte[pos_lig][pos_col]; p.carte[pos_lig][pos_col]=0; pos_col=pos_col+1;}
                                                                                             }
			} }

return true;
}

			//###############################" CLASS MONSTRE ################################//


monstre::monstre(plan p){
	 Monstre=NombreDeMonstre(p);// pour savoir le nombre de Montre restant a tuer
	 Monstre_tuer=0;

			}

			//------------------------------------------------//
void monstre:: Telecharger_info_monstre(personnage *p) {

 string tmp;
	if(p->NMC==-1){ tmp="tapator";} 	
	else if(p->NMC==-2){ tmp="xana";} 	
	string path="monstre/"+tmp+".txt";
	string t;
     	ifstream file(path.c_str(),ios::in);
      	if(file){
		while(!file.eof()){
			getline(file,t);
			file >> nom >> mana >> vie >> 
			Competence[0] >> BesoinMana_Et_Degat[0][0] >> BesoinMana_Et_Degat[0][1] >>
 			Competence[1] >> BesoinMana_Et_Degat[1][0] >> BesoinMana_Et_Degat[1][1] >>
			Competence[2] >> BesoinMana_Et_Degat[2][0] >> BesoinMana_Et_Degat[2][1] ;		
					}

			file.close();
			}
	else{ cerr<<"ce Monstre n'existe pas "<<endl;}

		}

                //--------------------------------------------------------------//
	int monstre:: NombreDeMonstre(plan p){
	int NMC; // caluculer le Nombre De Monstre Dans La carte;
	
	for(int i=0;i<20;i++){
		  for(int j=0;j<21;j++){
			if(p.carte[i][j]==-1 || p.carte[i][j]==-2 ){NMC++;}
					 } //end for 2
					      }//end For 1

				return NMC;
					}

    //--------------------------------------------------------------//
	void monstre:: attaquer(personnage *per){
	int RandIndex= rand() % 3;
			effet_attaque(RandIndex,per);
						}

    //--------------------------------------------------------------//
	void monstre:: effet_attaque(int num_attaque,personnage *per){
		if(mana>=BesoinMana_Et_Degat[num_attaque][0]){
	          cout<<"  \n le monstre "<<nom<<" a attaqué par "<<Competence[num_attaque]<<endl;
				 per->vie=per->vie+BesoinMana_Et_Degat[num_attaque][1];}
		
				}	
    //-------------------------------------------------------------//
			//############################### Class Jeux ###################################" //

void jeux::jouer(plan &p,personnage *per,monstre &m ,combat &c){
string u;
int compteur_mana=0;  
if(p.Test_Plan()==true){
		p.carte[0][1]=8;
		affichage(p,per,m);
		while(per->vie>0 && m.Monstre_tuer<m.Monstre)
			{cout<<" Move:\n  \t Up (z) \t Down(s) \t Left(q) \t Right(d) ."<<endl;	
			cin>>u;
		    if(u.length()==1){ // si u.length>1 ou <1 il ne passe pas a les etapes suivant
			
			compteur_mana++;  
			if(compteur_mana>=6){per->mana--; compteur_mana=0;} // si le personnage marche 6 pas alors mana--

			if(per->deplacer(p,u)==false){ 
				cout<<" Combat :"<<endl; 
				m.Telecharger_info_monstre(per);
				c.Lancer_Combat(p,per,m);}
				//affichage(p,per);}	
				
		        else{
			//per.deplacer(p,u);
			affichage(p,per,m);}	
					} // end if2 
			 } //end while
			if(m.Monstre_tuer==m.Monstre){affichage(p,per,m); cout<<"\t \t \t \t BRAVO vous avez gagné"<<endl;}
			} //end if 1
else{ cout<<"\n Impossible de lancer le jeux \n Raison: Carte  incomplet "<<endl;}
}

					//----------------------------------
					//----------------------------------
	void jeux:: affichage(plan &p,personnage *per,monstre m){
clrscr();
	cout<<" \t \t  -------------------------------------------------------------"<<endl;
	for(int i=0;i<20;i++){
		cout<<"\t \t";
	for(int j=0;j<21;j++){
		if(p.carte[i][j]==0){cout<<"   ";}
		else if(p.carte[i][j]==1)	{cout<<"  -";}	
		else if(p.carte[i][j]==2)       {cout << "\033[0;"<<44<<"m"<<"   "<<"\033[0m";;} // afficher colour Bleu pour le lac
		else if(p.carte[i][j]==3)	{cout << "\033[0;"<<42<<"m"<<"  *"<<"\033[0m";;} // vert pour les arbres
		else if(p.carte[i][j]==4)	{cout<<"  ¦";}	
		else if(p.carte[i][j]==5)	{cout << "\033[0;"<<41<<"m"<<"   "<<"\033[0m";;} // rouge pour les rochets
		else if(p.carte[i][j]==8)	{cout << "\033[0;"<<43<<"m"<<"  P"<<"\033[0m";;} // jaune pour le personage
		else if(p.carte[i][j]==-1 ||p.carte[i][j]==-2 )	{cout << "\033[0;"<<47<<"m"<<"  M"<<"\033[0m";;} // jaune pour le personage
			else if(p.carte[i][j]==7)	{cout << "\033[0;"<<45<<"m"<<"  H"<<"\033[0m";;} // jaune pour le personage 										
			else {cout<<"  "<<p.carte[i][j];}
		}
		cout<<"\n";
	}				
	cout<<" \t \t  -------------------------------------------------------------"<<endl;	  
	cout<<" \t \t        Vie: "<<per->vie<<"/"<<per->Vie;  cout<<"\t    Mana: "<<per->mana<<"/"<<per->Mana;     	
				cout<<"\t  Monstre tuer :"<<m.Monstre_tuer<<"/"<<m.Monstre<<endl;             		
	cout<<" \t \t  |___________________________________________________________|"<<endl;	      
	}

     //####################################### Class  COMBAT  #######################################//

void combat:: personnage_attaque(int num_attaque,personnage *p,monstre &m){

			effet_attaque(num_attaque,p,m);
						}

       //--------------------------------------------------------------//
	void combat:: effet_attaque(int num_attaque,personnage *p,monstre &m){
		if(p->mana>=p->BesoinMana_Et_Degat[num_attaque][0]){
				 m.vie=m.vie+p->BesoinMana_Et_Degat[num_attaque][1];}
		
		else{cout<<" votre mana ne vous permetez pas attaquer avec cet competence  "<<endl;}
				
				}	
	//-------------------------------------------------------------//

void combat:: Lancer_Combat(plan &p,personnage *per,monstre &m){

while(per->vie>0 && m.vie>0){
string attaque;
int att;
   cout<<"\n  que doit faire "<<per->nom<<endl;
	cout<<"\t 1 - "<<per->Competence[0]<<endl;
	cout<<"\t 2 - "<<per->Competence[1]<<endl;
		cin>> attaque;
	   if( attaque!="1" && attaque!="2" ){cout<<"mechimah"<<endl;}
		else{
			if(attaque=="1"){att=1;}else{att=2;}	   
		personnage_attaque(att-1,per,m);

		if(per->mana<0){ per->mana=per->Mana;per->vie--;}
		if(m.vie<=0){   cout<<"le monstre eté tué "<<endl; 
				p.carte[per->POSM/100][per->POSM%100]=0;	
					m.Monstre_tuer++; break;}


		m.attaquer(per);
		if(per->vie<=0){ cout<< per->nom<<" est Mort \n Game Over "<<endl; break;}
		cout<<"\n"<<per->nom<<": \n vie = "<<per->vie<<" mana = "<<per->mana<<endl;
	        cout<<"\n"<<m.nom<<" (Monstre): \n vie = "<<m.vie<<" mana = "<<m.mana<<endl; }//end else


								} //end while

}


