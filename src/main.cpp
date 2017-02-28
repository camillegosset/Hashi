#include <fstream>
#include "../inc/Grille.hpp"


int main(int argc, char const *argv[]) {
    Grille grille;

    std::ifstream fichier(argv[1], std::ios::in);

    grille.lecture(fichier);

    fichier.close();

    // Test de l'affichage des ponts
    Pont* p1 = new Pont(grille.getUneIleOuUnPont(0,0).getIle(),grille.getUneIleOuUnPont(0,9).getIle(),1);
    p1->estVertical();
    Pont* p2 = new Pont(grille.getUneIleOuUnPont(2,8).getIle(),grille.getUneIleOuUnPont(4,8).getIle(),2);
    p2->estVertical();

    for (int i = 1; i < 9; i++)
      grille.getUneIleOuUnPont(0,i).setPont(p1);
    for (int j = 3; j < 4; j++)
      grille.getUneIleOuUnPont(j,8).setPont(p2);
    //
    
    grille.affichage(std::cout);
    
    return 0;
}
