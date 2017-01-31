#include <iostream>
#include <fstream>
#include "../inc/Grille.hpp"


int main(int argc, char const *argv[]) {
    Grille grille;

    std::ifstream fichier(argv[1], std::ios::in);

    grille.lecture(fichier);

    std::cout<<grille.getN()<<" "<<grille.getM()<<" "<<grille.getUneIleOuUnPont(1,1).getIle()->getVal()<<" "<<grille.getUneIleOuUnPont(5,5).getIle()->getVal();

    return 0;
}
