#ifndef _ILE_H
#define _ILE_H

#include <vector>

class Ile{
private:
    int _val;
    int _abscisse;
    int _ordonnee;
    int _ponts_places;
    std::vector<Ile> _voisins_possibles;
    std::vector<Ile> _voisins_reels;
    bool _est_relie;
};

#endif // _ILE_H
