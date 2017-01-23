#include <iostream>
#include "../inc/Ile.hpp"

Ile::Ile(int val, int x, int y): _val(val), _abscisse(x), _ordonnee(y), _ponts_places(0), _voisins_possibles ({}), _voisins_reels({}), _est_relie(false) {}

Ile::Ile(int val, int x, int y, int ponts_places, std::vector<Ile> voisins_possibles, std::vector<Ile> voisins_reels, bool est_relie) :
_val(val), _abscisse(x), _ordonnee(y), _ponts_places(ponts_places), _voisins_possibles(voisins_possibles), _voisins_reels(voisins_reels), _est_relie(est_relie) {}

int Ile::getVal() {
    return this->_val;
}
