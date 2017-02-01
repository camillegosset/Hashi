#include <fstream>
#include "../inc/Grille.hpp"


int main(int argc, char const *argv[]) {
    Grille grille;

    std::ifstream fichier(argv[1], std::ios::in);

    grille.lecture(fichier);
    grille.affichage(std::cout);
    return 0;
}
