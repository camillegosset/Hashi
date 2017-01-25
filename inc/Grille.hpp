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
    std::vector<std::vector<Ile>> _iles_presentes; // Vector à 2 dimensiond des iles dans la grille 
    //TODO : faire une structure pour remplacer les iles par soit des iles soit des ponts ou soit NULL 
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

    //METHODES
    std::string enleverEspace(std::string str);
    std::string champDeLecture(std::istream& in);
    void ignoreChars(std::istream& in, std::string chars);
    void lecture(std::istream& is); // à partir du fichier reconstruit la grille
};

#endif // _GRILLE_H
