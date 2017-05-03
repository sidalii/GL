#include "whattotest.cpp"
#include <gtest/gtest.h>

using namespace std;

 TEST(fichier_client, plan){
    EXPECT_NO_THROW(plan p);
    plan p;
    EXPECT_TRUE(p.Test_Plan());
}

TEST(vieTest, constructeur){
	ASSERT_EQ(35, personnage::creerPersonnage("sorciere")->vie);
	//ASSERT_EQ(33, personnage::creerPersonnage("sorciere")->vie);
}

TEST(competenceTest, constructeur){
	ASSERT_EQ("LANCER_DU_FEU", personnage::creerPersonnage("sorciere")->Competence[0]);
}

TEST(pos_col, constructeur){
	ASSERT_EQ(1, personnage::creerPersonnage("barbare")->pos_col);
}

TEST(pos_lig, constructeur){
	ASSERT_EQ(0, personnage::creerPersonnage("barbare")->pos_lig);
}

TEST(nombreMonstre, plan){
	plan p;
	monstre m(p);
	ASSERT_EQ(5, m.NombreDeMonstre(p));
}

TEST(effetAttaque, viePersonnage){
	plan p;
	monstre m(p);
	personnage *per=personnage::creerPersonnage("barbare");
	m.effet_attaque(2,per);
	ASSERT_EQ(30, per->vie);
	//ASSERT_EQ(20, per->vie);
}

TEST(effetAttaque, vieMonstre){
	plan p;
	monstre m(p);
	personnage *per=personnage::creerPersonnage("sorciere");
	combat c;
	c.personnage_attaque(2,per,m);
	ASSERT_NE(50, m.vie);
}

TEST (fichier_amazone, ErrorMessage) { 
	::testing::FLAGS_gtest_death_test_style = "threadsafe";
    ASSERT_DEATH(personnage::creerPersonnage("amazone"), "le fichier de ce personnage n'existe pas ");
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}