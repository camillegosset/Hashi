#include <fstream>
#include "../inc/Grille.hpp"


int main(int argc, char const *argv[]) {
    Grille grille;

    std::ifstream fichier(argv[1], std::ios::in);

    grille.lecture(fichier);

    //std::cout<<"Longueur: "<<grille.getN()<<", Hauteur: "<<grille.getM()<<", valeur des iles: "<<grille.getUneIleOuUnPont(1,1).getIle()->getVal()<<", "<<grille.getUneIleOuUnPont(10,9).getIle()->getVal()<<", "<<grille.getUneIleOuUnPont(4,7).getIle()->getVal()<<", "<<grille.getUneIleOuUnPont(2,8).getIle()->getVal()<<'\n';
    //std::cout << grille.getUneIleOuUnPont().getIle()->getVal() << '\n';
    grille.affichage(std::cout);
    return 0;
}
