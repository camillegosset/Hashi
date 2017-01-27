#include "../inc/Ile.hpp"

// Constructeurs
Ile::Ile(int val, int x, int y):
  _val(val), _abscisse(x), _ordonnee(y), _ponts_places(0), _voisins_possibles(), _voisins_reels(), _est_relie(false)
{}

Ile::Ile(int val, int x, int y, int p_p, std::vector<Ile> v_p, std::vector<Ile> v_r, bool est_r):
_val(val), _abscisse(x), _ordonnee(y), _ponts_places(p_p), _voisins_possibles(v_p), _voisins_reels(v_r), _est_relie(est_r)
{}

// Accesseurs en lecture
int Ile::getVal() {
    return _val;
}

int Ile::getX() {
    return _abscisse;
}

int Ile::getY() {
    return _ordonnee;
}

int Ile::getPontsPlaces() {
    return _ponts_places;
}

std::vector<Ile> Ile::getVoisinsPossibles() {
    return _voisins_possibles;
}

std::vector<Ile> Ile::getVoisinsReels() {
    return _voisins_reels;
}

bool Ile::estIlLie() {
    return _est_relie;
}

// Accesseurs en écriture
void Ile::setVal(int val) {
    _val= val;
}

void Ile::setX(int x) {
    _abscisse= x;
}

void Ile::setY(int y) {
    _ordonnee= y;
}

void Ile::setPontsPlaces(int n) {
    _ponts_places= n;
}

void Ile::setVoisinsPossibles(std::vector<Ile> v) {
   _voisins_possibles= v;
}

void Ile::setVoisinsReels(std::vector<Ile> v) {
    _voisins_reels= v;
}

void Ile::setEstRelie(bool r) {
    _est_relie= r;
}
