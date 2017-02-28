#include <fstream>
#include "../inc/Grille.hpp"


int main(int argc, char const *argv[]) {
    Grille grille;

    std::ifstream fichier(argv[1], std::ios::in);

    grille.lecture(fichier);

    fichier.close();

    /* Test de l'affichage des ponts
    grille.creerPont(grille.getUneIleOuUnPont(0,0).getIle(),grille.getUneIleOuUnPont(2,0).getIle(),1);
    grille.creerPont(grille.getUneIleOuUnPont(0,2).getIle(),grille.getUneIleOuUnPont(2,2).getIle(),2);
    */
    
    grille.affichage(std::cout);

    grille.RecupVoisinsPossibles();

    return 0;
}
