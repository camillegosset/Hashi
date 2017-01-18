#ifndef _ILE_H
#define _ILE_H

#include <vector>

class Ile{
private:
    int _val; // valeur de l'ile (nombre de ponts qui vont devoir être placés)
    int _abscisse; // Coordonnées en abscisse de l'ile
    int _ordonnee; // Coordonnées en ordonnée de l'ile
    int _ponts_places; // Nombre de ponts déjà placé
    std::vector<Ile> _voisins_possibles; // Vector des iles qui représente tous les voisins possibles
    std::vector<Ile> _voisins_reels; // Vector des iles qui représentent les voisins placés (ne peut pas excéder _val)
    bool _est_relie; // Booléen : true si tous les ponts ont été placés, faux sinon
};

#endif // _ILE_H
