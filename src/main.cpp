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

    grille.creerPont(i1,grille.getUneIleOuUnPont(2,0).getIle(),1);
    
    for (size_t i = 0; i < grille.getN(); i++) {
        for (size_t j = 0; j < grille.getM(); j++) {
            std::cout << grille.getUneIleOuUnPont(i,j) << '\n';
        }
    }
    */
    
    grille.RecupVoisinsPossibles();
    //grille.tracerPonts(); Erreur segmentation (demander l'explication parce que franchement c'est chiant à expliquer à l'écrit)

    grille.affichage(std::cout);

    return 0;
}
