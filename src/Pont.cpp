#include "../inc/Pont.hpp"

// Constructeur
Pont::Pont(Ile i1, Ile i2) {
    *_ile1= i1;
    *_ile2= i2;
    _nombre= 0;
    _est_vertical= false;
}

// Accesseurs en lecture
Ile* Pont::getIle1() {
    return _ile1;
}

Ile* Pont::getIle2() {
    return _ile2;
}

int Pont::getNombre() {
    return _nombre;
}

bool Pont::getEstVertical() {
    return _est_vertical;
}

// Accesseurs en écriture
void Pont::setIle1(Ile* i) {
    _ile1= i;
}

void Pont::setIle2(Ile* i) {
    _ile2= i;
}

void Pont::setNombre(int n) {
    _nombre= n;
}

void Pont::setEstVertical(bool v) {
    _est_vertical= v;
}

//Méthode de màj quand on crée un pont
//void majVoisinsReels()
/* i<- abscisse
tantque (i<n && objets_presents[i][ordonnée].getIle() == NULL)
i++
fintq
Si( objets_presents[i][ordonéne].getPont() == NULL ){
voisins_possibles.push_back(objets_presents[i][ordonnée])
(objets_presents.voisins_possibles).push_back(objets_presents[abscisse][ordonnée])
}
i<- abscisse (faire gauche droite haut et bas)
}*/
