#include<iostream>
#include"plan.h"
#include<fstream>
using namespace std;


 

plan::plan()
{  
carte=new int*[20];
        
for(int i=0;i<20;i++){
    carte[i]=new int[21];
            
                    }
/*
 for(int i=0;i<20;i++){
		for(int j=0;j<21;j++){
			 carte[i][j]=0;
				}
				}	
*/

configuration();
}

void plan:: affichage(){
	
		cout<<" \t \t  -------------------------------------------------------------"<<endl;
	 for(int i=0;i<20;i++){
			 cout<<"\t \t";
		for(int j=0;j<21;j++){
			if(carte[i][j]==0){cout<<"   ";}
			else if(carte[i][j]==1)	{cout<<"  -";}	
			else if(carte[i][j]==2)	{cout << "\033[0;"<<44<<"m"<<"   "<<"\033[0m";;}					
			else if(carte[i][j]==3)	{cout << "\033[0;"<<42<<"m"<<"  *"<<"\033[0m";;}		
			else if(carte[i][j]==4)	{cout<<"  ¦";}	
                        else if(carte[i][j]==5)	{cout << "\033[0;"<<41<<"m"<<"   "<<"\033[0m";;} 
                        else if(carte[i][j]==8)	{cout << "\033[0;"<<43<<"m"<<"  A"<<"\033[0m";;} 
                        else if(carte[i][j]==9)	{cout << "\033[0;"<<47<<"m"<<"   "<<"\033[0m";;} 
//cout << "\033[0;"<<42<<"m"<<"  #"<<"\033[0m";;}
														
			 else {cout<<"  "<<carte[i][j];}
				}
			//cout<<"  "<<carte[i][j];
						cout<<"\n";
				}

					
		cout<<" \t \t  -------------------------------------------------------------"<<endl;
		    
	}

void plan:: configuration(){
ifstream file("client.txt",ios::in);
//string lig;
int tmp;
int i=0;
if(file){

	while((!file.eof()) && (i<20))//getline(file, lig))  // tant que l'on peut mettre la ligne dans "contenu"
        {	

		for(int j=0;j<21;j++){
			file >> tmp;
			carte[i][j]=tmp;

			}
				i++;
        }
	
	file.close();
}

else {
cerr<<"file wasn't found"<<endl;
		}	
	
		}
		//################################ CLASS PERSONNAGE ############################# //


void personnage:: Selectioner_joeur(plan p,char j){
pos_lig=0;
pos_col=0;
if(j=='A'){p.carte[0][0]=8;}
else if(j=='B'){p.carte[0][0]=9;}
}


//****************************************//
	
void personnage:: deplacer(plan p,char pos){
//2 4 3 5
int t;

if(pos=='z'){
	if( p.carte[pos_lig-1][pos_col]!=2 && p.carte[pos_lig-1][pos_col]!=3 && p.carte[pos_lig-1][pos_col]!=4 && p.carte[pos_lig-1][pos_col]!=5){
                  p.carte[pos_lig-1][pos_col]=p.carte[pos_lig][pos_col]; p.carte[pos_lig][pos_col]=0; pos_lig=pos_lig-1;
                                                                                             }
			}

else if(pos=='s'){
	if( p.carte[pos_lig+1][pos_col]!=2 && p.carte[pos_lig+1][pos_col]!=3 && p.carte[pos_lig+1][pos_col]!=4 && p.carte[pos_lig+1][pos_col]!=5){
                  p.carte[pos_lig+1][pos_col]=p.carte[pos_lig][pos_col]; p.carte[pos_lig][pos_col]=0; pos_lig=pos_lig+1;
                                                                                             }
			}
else if(pos=='q'){
	if( p.carte[pos_lig][pos_col-1]!=2 && p.carte[pos_lig][pos_col-1]!=3 && p.carte[pos_lig][pos_col-1]!=4 && p.carte[pos_lig][pos_col-1]!=5){
                  p.carte[pos_lig][pos_col-1]=p.carte[pos_lig][pos_col]; p.carte[pos_lig][pos_col]=0; pos_col=pos_col-1;
                                                                                             }
			}


else if(pos=='d'){
	if( p.carte[pos_lig][pos_col+1]!=2 && p.carte[pos_lig][pos_col+1]!=3 && p.carte[pos_lig][pos_col+1]!=4 && p.carte[pos_lig][pos_col+1]!=5){
                  p.carte[pos_lig][pos_col+1]=p.carte[pos_lig][pos_col+1]; p.carte[pos_lig][pos_col]=0; pos_col=pos_col+1;
                                                                                             }
			}


    else{ cout<<"zone inaccessible :)"<<endl;}
}


//############################### Class Jeux ###################################" //

void jeux::  jouer(plan p,personnage per){

char tmp,u;
while(tmp!='A' && tmp!='B'){
	cout<<" Selectionner Votre personnager :"<<endl;
	cout <<"     A         ou       B      " <<endl;
	cin>>tmp;
			}

per.Selectioner_joeur(p,tmp);
p.affichage();


while(per.pos_lig!=20 && per.pos_col!=21)
	{cout<<"deplacer:"<<endl;	
	cin>>u; 
	per.deplacer(p,u);
	p.affichage();	
	}



}

	
