#include <fstream>
#include "../inc/Grille.hpp"


int main(int argc, char const *argv[]) {
    Grille grille;

    std::ifstream fichier(argv[1], std::ios::in);

    grille.lecture(fichier);

    fichier.close();
    grille.affichage(std::cout);
    grille.RecupVoisinsPossibles();
    return 0;
}
