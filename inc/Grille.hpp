#ifndef _GRILLE_H
#define _GRILLE_H

#include <vector>
#include <iostream>
#include <string>
#include "Ile.hpp"

class Grille{
private:
    int _n;
    int _m; // Car on a une grille de type nxm
    std::vector<Ile> _iles_presentes; // Vector des iles dans la grille
public:
    //CONSTRUCTEURS
    Grille(); //Par défaut
    Grille(int n, int m, std::vector<Ile> iles_presentes); //Classique

    //ACCESSEURS LECTURE

    int getN() const;
    int getM() const;
    std::vector<Ile> getIlesPresentes() const;

    //ACCESSEURS ECRITURE

    void setN( int n);
    void setM( int m);
    void setIlesPresentes(std::vector<Ile> iles_presentes);
    void setUneIle(Ile UneIle);
    void lecture(std::istream& is); // à partir du fichier reconstruit la grille
};

#endif // _GRILLE_H
