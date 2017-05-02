#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "plan.h"


using namespace std;

//class plan
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
	//if(file){
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

//class personnage
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
	string path="personnage/amazne.txt";
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
	else{ cerr<<"le fichier de ce personnage n'existe pas "<<endl;

		exit(-1);}
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

//class monstre
monstre::monstre(plan p){
	 Monstre=NombreDeMonstre(p);// pour savoir le nombre de Montre restant a tuer
	 Monstre_tuer=0;

			}

int monstre:: NombreDeMonstre(plan p){
	int NMC; // caluculer le Nombre De Monstre Dans La carte;
	
	for(int i=0;i<20;i++){
		  for(int j=0;j<21;j++){
			if(p.carte[i][j]==-1 || p.carte[i][j]==-2 ){NMC++;}
					 } //end for 2
					      }//end For 1

				return NMC;
					}

void monstre:: effet_attaque(int num_attaque,personnage *per){
		if(mana>=BesoinMana_Et_Degat[num_attaque][0]){
	          //cout<<"  \n le monstre "<<nom<<" a attaqué par "<<Competence[num_attaque]<<endl;
				 per->vie=per->vie+BesoinMana_Et_Degat[num_attaque][1];}
		
				}	

//class combat

				void combat:: personnage_attaque(int num_attaque,personnage *p,monstre &m){

			effet_attaque(num_attaque,p,m);
						}
void combat:: effet_attaque(int num_attaque,personnage *p,monstre &m){
		if(p->mana>=p->BesoinMana_Et_Degat[num_attaque][0]){
				 m.vie=m.vie+p->BesoinMana_Et_Degat[num_attaque][1];}
		
		else{cout<<" votre mana ne vous permetez pas attaquer avec cet competence  "<<endl;}
				
				}					