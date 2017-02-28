#ifndef _ILE_HPP
#define _ILE_HPP

#include <vector>
#include <iostream>


class Ile {
private:
    int _val; // Valeur de l'ile (nombre de ponts qui vont devoir être placés)
    int _abscisse; // Coordonnées en abscisse de l'ile
    int _ordonnee; // Coordonnées en ordonnée de l'ile
    int _ponts_places; // Nombre de ponts déjà placé
    std::vector<Ile> _voisins_possibles; // Vector des iles qui représente tous les voisins possibles
    std::vector<Ile> _voisins_reels; // Vector des iles qui représentent les voisins placés (ne peut pas excéder _val)
    bool _est_relie; // Booléen : true si tous les ponts ont été placés, faux sinon
//Problème: #include "Arbre.hpp" et dans Arbre on include "Ile.hpp" donc pas la possibilité de structure (ou trouver une solution)
    //Copie de la structure d'Arbre
    int _hauteur;
    Ile* _pere;
    Ile* _chef;

public:
    // CONSTRUCTEURS
    Ile();
    Ile(int val, int x, int y);
    Ile(int val, int x, int y, int ponts_places, std::vector<Ile> voisins_possibles, std::vector<Ile> voisins_reels, bool est_relie);

    // ACCESSEURS LECTURE
    int getVal();
    int getX();
    int getY();
    int getPontsPlaces();
    std::vector<Ile> getVoisinsPossibles();
    std::vector<Ile> getVoisinsReels();
    bool estIlLie();
    int getHauteur();
    Ile* getPere();
    Ile* getChef();

    // ACCESSEURS ECRITURE
    void setVal();
    void setX(int);
    void setY(int);
    void setPontsPlaces(int);
    void setUnVoisinPossible(Ile ile);
    void setUnVoisinPossible(Ile* ile);
    void setEstRelie(bool);
    void setUnVoisinReel(Ile ile);
    void setUnVoisinReel(Ile* ile);
    void setHauteur(int h);
    void setPere(Ile* ile);
    void setChef(Ile* ile);

    //SURCHARGE
    void affectation(Ile& ile);

    //Methodes
    void supprimerUneCaseVoisinsPossibles(size_t i);
    void toString();

};

#endif // _ILE_HPP
