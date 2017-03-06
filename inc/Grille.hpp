#ifndef _GRILLE_H
#define _GRILLE_H

#include <string>
#include "IleOuPont.hpp"
#include "Pont.hpp"

class Grille{
private:
    unsigned int _n; //Hauteur
    unsigned int _m; //Longueur
    // Car on a une grille de type nxm
    IleOuPont** _objets_presents; // Vector à 2 dimensions des iles ou des ponts dans la grille
    bool _est_resolu;
    int _nbre_composantes_connexes;

public:
    //CONSTRUCTEURS
    Grille(); // Par défaut

    //DESTRUCTEUR
    ~Grille();

    //ACCESSEURS LECTURE
    int getN() const;
    int getM() const;
    IleOuPont** getIlesOuPonts() const;
    IleOuPont getUneIleOuUnPont(int x, int y) const;
    bool getEstResolu();
    int getNbreComposantesConnexes();

    //ACCESSEURS ECRITURE
    void setN(int n);
    void setM(int m);
    void setUneIleOuUnPont(IleOuPont une_ile_ou_un_pont, int x, int y);
    void setEstResolu();

    //Choisir entre les deux suivants:
    void setNbreComposanteConnexes( int nbre); // Soit dans la fonction on mettra setNbreComposanteConnexes( _nbre_composantes_connexes -1)
    void setNbreComposanteConnexes(); // Le fera directement : Au choix



    //METHODES
    // Construire la Grille
    std::string enleverEspace(std::string str);
    std::string champDeLecture(std::istream& in);
    void ignoreChars(std::istream& in, std::string chars);
    void lecture(std::istream& is); // à partir du fichier reconstruit la grille
    // Affichage
    void affichage(std::ostream&) const;// affichage sur un flux de sortie

    // Voisins Iles
    void RecupVoisinsPossibles(); // Récupère les voisins possibles de chaque ile
    void majVoisinsReels(Pont* pont); //Méthode de màj quand on crée un pont
    void tracerPonts();
    void placerPonts(Ile* ile); // Enumération des cas possibles
    void creerPont(Ile* ile1, Ile* ile2, int nbr_ponts);
};

#endif // _GRILLE_H
