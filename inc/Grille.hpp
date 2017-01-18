#ifndef _GRILLE_H
#define _GRILLE_H

#include <vector>
#include <iostream>
#include "Ile.hpp"

class Grid{
private:
    int _n;
    int _m; // Car on a une grille de type nxm
    std::vector<Ile> _iles_presentes; // Vector des iles dans la grille
public:
    //CONSTRUCTEURS
    Grid(); //Par défaut
    Grid(int n, int m, std::vector<Ile> iles_presentes); //Classique
    Grid(std::istream& is); // à partir du fichier

    //ACCESSEURS LECTURE

    int getN() const;
    int getM() const;
    std::vector<Ile> getIlesPresentes() const;

    //ACCESSEURS ECRITURE

    void setN( int n);
    void setM( int m);
    void setIlesPresentes(std::vector<Ile> iles_presentes);
};

#endif // _GRILLE_H
