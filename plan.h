#ifndef PLAN_H
#define PLAN_H

class plan
{
	public:
     int ** carte;
     int personnage;
        plan();
	void configuration();
        void affichage();
	
};

class personnage{
	public:
	int mana;
	int vie;
	int pos_lig;
	int pos_col;
	void Selectioner_joeur(plan p,char j);
	void deplacer(plan p,char pos);
	void Competence_joeur(char j);

               };

//9=B  8=A

class combat {


              };


class jeux{
public:
void jouer(plan p,personnage per);
	  };

#endif

