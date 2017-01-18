#ifndef _ILE_H
#define _ILE_H

#include <vector>
#include <iostream>

class Ile{
private:
    int _val; // valeur de l'ile (nombre de ponts qui vont devoir être placés)
    int _abscisse; // Coordonnées en abscisse de l'ile
    int _ordonnee; // Coordonnées en ordonnée de l'ile
    int _ponts_places; // Nombre de ponts déjà placé
    std::vector<Ile> _voisins_possibles; // Vector des iles qui représente tous les voisins possibles
    std::vector<Ile> _voisins_reels; // Vector des iles qui représentent les voisins placés (ne peut pas excéder _val)
    bool _est_relie; // Booléen : true si tous les ponts ont été placés, faux sinon

public:
    //CONSTRUCTEURS
    Ile(int val, int x, int y);
    Ile(int val, int x, int y, int ponts_places, std::vector<Ile> voisins_possibles, std::vector<Ile> voisins_reels, bool est_relie);
    Ile(std::istream& is);

    //ACCESSEURS LECTURE
    int getVal();
    int getX();
    int getY();
    int getPontsPlaces();
    std::vector<Ile> getVoisinsPossibles();
    std::vector<Ile> getVoisinsReels();
    bool estIlLie();

    //ACCESSEURS ECRITURE
    void setVal( int val);
    void setX( int x);
    void setY( int y);
    void setPontsPlaces( int n);
    void setVoisinsPossibles(std::vector<Ile> v);
    void setVoisinsReels( std::vector<Ile> v);

};

#endif // _ILE_H
