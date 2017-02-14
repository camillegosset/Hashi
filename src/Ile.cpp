#include "../inc/Ile.hpp"

// Constructeurs

Ile::Ile(): _val(0), _abscisse(0), _ordonnee(0), _ponts_places(0), _est_relie(false) // Constructeurs par défaut
{}

Ile::Ile(int val, int x, int y):
  _val(val), _abscisse(x), _ordonnee(y), _ponts_places(0), _est_relie(false)
{}

Ile::Ile(int val, int x, int y, int p_p, std::vector<Ile> v_p, std::vector<Ile> v_r, bool est_r):
_val(val), _abscisse(x), _ordonnee(y), _ponts_places(p_p), _voisins_possibles(v_p), _voisins_reels(v_r), _est_relie(est_r)
{}

//Ile::Ile(Ile& ile): _val(ile._val), _abscisse(ile._abscisse), _ordonnee(ile._ordonnee), _ponts_places(ile._ponts_places), _voisins_possibles(ile._voisins_possibles), _voisins_reels(ile._voisins_reels), _est_relie(ile._est_relie)
//{}

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

void Ile::setUnVoisinPossible(Ile ile){
    _voisins_possibles.push_back(ile);
}

void Ile::setUnVoisinPossible(Ile* ile){
    _voisins_possibles.push_back(*ile);
}

void Ile::setVoisinsReels(std::vector<Ile> v) {
    _voisins_reels= v;
}

void Ile::setEstRelie(bool r) {
    _est_relie= r;
}

void Ile::setUnVoisinReel(Ile ile){
    _voisins_reels.push_back(ile);
}

void Ile::setUnVoisinReel(Ile* ile){
    _voisins_reels.push_back(*ile);
}

//SURCHARGE AFFECTATION par méthode
void Ile::affectation(Ile& ile){
    this->_val= ile.getVal();
    this->_abscisse= ile.getX();
    this->_ordonnee= ile.getY();
    this->_ponts_places= ile.getPontsPlaces();
    this->_voisins_possibles= ile.getVoisinsPossibles();
    this->_voisins_reels= ile.getVoisinsReels();
    this->_est_relie= ile._est_relie;
}
