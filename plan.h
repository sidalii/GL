#ifndef PLAN_H
#define PLAN_H

/*!
 * \file plan.h
 * \brief le seul header de ce projet
 * \author equipeDZ
 */

/*! 
  * \def clrsrc()
  * faire un clear screen du terminal
  */
#define clrscr() printf("\033[H\033[2J")
using namespace std;
/*! \class plan
   * \brief classe representant le plan du jeux
   *
   *  La classe gere la configuration de la carte du jeux
   *  a partir d'un fichier text "client.txt"
   */        
class plan
{
	public:
    int ** carte; /*!< une matrice representant la carte*/
     /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe plan
     */
    plan();
    /*!
     *  \brief chargement du fichier client.txt 
     *
     *  Methode qui permet de construire la carte du jeux 
     *  selon les specification presente dans client.txt 
     */
    void configuration();
    /*!
     *  \brief teste de la carte 
     *
     *  Methode permet de tester que la carte fournie par le client n'est pas vide
     *  est qu'elle contient tout les elements pour que le personnage puisse jouer
     * \return true si tout est bien, false sinon
     */
    bool Test_Plan();
	
};
/*! \class personnage
   * \brief classe abstraite representant un personnage parmi les 3
   *  disponibles dans ce jeux
   *
   *  La classe gere le deplacement, l'attaque ... du personnage 
   */
class personnage{
	public:
	int mana,Mana;/*!< un entier representant le mana */
	int vie,Vie;/*!< un entier representant la vie*/
	int pos_lig;/*!< la ligne ou le personnage se situe*/
	int pos_col;/*!< la colonne ou le personnage se situe*/
	int NMC;/*!<l'identifiant de monstre a combattre dans la carte pour telecharger ces comptences*/ 
	int POSM;/*!<la postion du monstre dans la carte*/
	int BesoinMana_Et_Degat[3][2];/*!<une matrice representant le Besion de mana d'une attaque et son degat*/
	std::string nom;/*!< une chaine de caractere contient le nom du personnage*/
	string Competence[2];/*!< un tableau contient les competences du personnage*/
	/*!
     *  \brief creation d'un objet de type barbare ou amazone ou sorciere
     *  Methode static qui permet de creer plusieurs types d'objets
     *  suivant un paramètre fourni
     *
     *  \param nomPersonnage : chaine de caractere representant le nom du personnage
     *  qu'on veut creer, il doit etre parmi les 3 disponibles (barbare,amazone,sorciere)
     */
	static personnage *creerPersonnage(string nomPersonnage);
    /*!
     *  \brief deplacer le personnage
     *  Methode qui permet de deplacer le personnage dans la carte 
     *  afin de se battre contre un monstre 
     *
     *  \param &p : une reference de la carte du jeux ou le personnage jouera
     *  \param pos: represente la prochaine position 
     *   dans la carte, par exemple : si on tape 'd' le personnage deplacera
     *   vers la droite.
     */
	bool deplacer(plan &p,string pos);
};

/*! \class amazone
   * \brief classe representant le personnage amazone
   *
   *  La classe gere le deplacement, l'attaque ... de ce personnage 
   */

class amazone: public personnage{
public:
	/*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe amazone
     *
     */
    amazone();
};
/*! \class barbare
   * \brief classe representant le personnage barbare
   *
   *  La classe gere le deplacement, l'attaque ... de ce personnage 
   */
class barbare: public personnage{
public:
	/*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe barbare
     *
     */
    barbare();
};
/*! \class sorciere
   * \brief classe representant le personnage sorciere
   *
   *  La classe gere le deplacement, l'attaque ... de ce personnage 
   */
class sorciere: public personnage{
public:
	/*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe sorciere
     *
     */
    sorciere();
};
/*! \class monstre
   * \brief classe representant un monstre parmi les monstres
   *  disponibles dans ce jeux
   *
   *  La classe gere le chargement des informations de chaque monstre
   *  pour que il puisse combattre contre le personnage 
   */

class monstre {
	public:
	int vie;/*!< un entier representant la vie*/
	int mana;/*!< un entier representant le mana */
	int BesoinMana_Et_Degat[3][2];/*!<une matrice representant le Besion de mana d'une attaque et son degat*/
	int Monstre;/*!< un entier representant le nombre total des monstres dans la partie */
	int Monstre_tuer;/*!< un entier representant le nombre total des monstres tues dans la partie */
	string Competence[3];/*!< un tableau contient les competences du monstre*/
	string nom;	/*!< une chaine de caractere contient le nom du personnage*/
	/*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe monstre
     *
     */
  monstre(plan p);
  /*!
     *  \brief telecharger les informations du monstre
     *  Methode qui permet le chargement des informations du monste
     *  apartir du fichier edite par le client, le choix du monstre se fait selon
     *  le personnage qui joue
     *
     *  \param *p : un pointeur sur le personnage qui est en train de jouer
     */ 
	void Telecharger_info_monstre(personnage *p);
  /*!
     *  \brief savoir le nombre des monstres restants
     *
     *  Methode permet de savoir le nombre des monstres restant et l'affiche sur ecran
     *
     *  \return le nombre des monstres
     */
	int NombreDeMonstre(plan p);
  /*!
     *  \brief attaquer le personnage
     *
     *  Methode permet d'attaquer le personnage qui est en train de jouer
     *
     *  \param *per : un pointeur sur le personnage
     */
	void attaquer(personnage *per);
  /*!
     *  \brief gere l'effet de l'attaque
     *
     *  Methode permet calculer l'effet de l'attaque du monstre envers le personnage
     *
     *  \param num_attaque : un entier aleatoire entre 0 et 3 representant l'attaque produite
     *  \param *per : un pointeur sur le personnage
     */
  void effet_attaque(int num_attaque,personnage *per);
};
/*! \class combat
   * \brief classe representant un combat entre un personnage 
   *  et un monstre rencontre
   *
   *  La classe gere l'attaque, le degat recu pour les deux
   */
class combat {
	public:
   /*!
     *  \brief lancement d'un combat
     *
     *  Methode permet lancer le combat entre le personnage et le monstre
     *  au moment du rencontre
     *
     *  \param &p : une reference sur le plan du jeux
     *  \param *per : un pointeur sur le personnage
     *  \param &m : une reference sur le monstre
     */  
	void Lancer_Combat(plan &p,personnage *per,monstre &m);
   /*!
     *  \brief attaquer le montre
     *
     *  Methode permet d'attaquer le monstre trouve
     *
     *  \param num_attaque : 
     *  \param *p : un pointeur sur le personnage
     *  \param &m : une reference du monstre trouve
     */
	void personnage_attaque(int num_attaque,personnage *p,monstre &m);
  /*!
     *  \brief gere l'effet de l'attaque
     *
     *  Methode permet calculer l'effet de l'attaque entre le monstre et le personnage
     *
     *  \param num_attaque : un entier aleatoire entre 0 et 3 representant l'attaque produite
     *  \param *per : un pointeur sur le personnage
     *  \param &m : une reference du monstre
     */
	void effet_attaque(int num_attaque,personnage *p,monstre &m);
};
/*! \class jeux
   * \brief classe representant une partie de ce jeux
   *
   *  La classe permet de jouer une parie a l'aide d'un affichage sur console
   */
class jeux{
	public:
		/*!
     *  \brief jouer une partie
     *  Methode qui permet de jouer une parie avec un personnage
     *  selectionne
     *
     *  \param &p : une reference de la carte du jeux ou la partie se deroule
     *  \param *per : un pointeur sur le personnage qui est en train de jouer
     *  \param &m : une reference du monstre trouve 
     *  \param &c : une reference du combat entre le personnage et le monstre rencontre  
     */	
	void jouer(plan &p,personnage *per,monstre &m,combat &c);
	 /*!
     *  \brief affichage de la carte 
     *
     *  Methode qui affiche la carte du jeux avec
     *  la position de chaque element du jeux
     *  \param &p : une reference de la carte du jeux ou la partie se deroule
     *  \param *per : un pointeur sur le personnage qui est en train de jouer
     *  \param m: pour afficher le nombre des monstres restants a tuer
     */
    void affichage( plan &p,personnage *per,monstre m);
};

#endif
