#ifndef _GRILLE_H
#define _GRILLE_H

#include <string>
#include "IleOuPont.hpp"

class Grille{
private:
    unsigned int _n;
    unsigned int _m; // Car on a une grille de type nxm
    IleOuPont** _objets_presents; // Vector à 2 dimensions des iles ou des ponts dans la grille
    bool _est_resolu;

public:
    //CONSTRUCTEURS
    Grille(); // Par défaut

    //ACCESSEURS LECTURE
    int getN() const;
    int getM() const;
    IleOuPont** getIlesOuPonts() const;
    IleOuPont getUneIleOuUnPont(int x, int y) const;
    bool getEstResolu();

    //ACCESSEURS ECRITURE
    void setN(int n);
    void setM(int m);
    void setIlesOuPonts(IleOuPont** objets_presents);
    void setUneIleOuUnPont(IleOuPont une_ile_ou_un_pont, int x, int y);
    void setEstResolu(bool resolu);


    //METHODES
    std::string enleverEspace(std::string str);
    std::string champDeLecture(std::istream& in);
    void ignoreChars(std::istream& in, std::string chars);
    void lecture(std::istream& is); // à partir du fichier reconstruit la grille
    void affichage(std::ostream&) const;// affichage sur un flux de sortie
};

#endif // _GRILLE_H
