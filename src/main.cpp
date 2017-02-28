#include <fstream>
#include "../inc/Grille.hpp"


int main(int argc, char const *argv[]) {
    Grille grille;

    std::ifstream fichier(argv[1], std::ios::in);

    grille.lecture(fichier);

    fichier.close();

    /* Test de l'affichage des ponts
    Ile* i1 = grille.getUneIleOuUnPont(0,0).getIle();
    Ile* i2 = grille.getUneIleOuUnPont(2,0).getIle();
    Ile* i3 = grille.getUneIleOuUnPont(0,2).getIle();
    Ile* i4 = grille.getUneIleOuUnPont(2,2).getIle();
    
    grille.creerPont(i1,i2,1);
    grille.creerPont(i3,i4,2);
    */
    
    grille.affichage(std::cout);

    grille.RecupVoisinsPossibles();

    return 0;
}
