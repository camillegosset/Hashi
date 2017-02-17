#include "../inc/Pont.hpp"

// Constructeur
Pont::Pont(Ile i1, Ile i2) {
    *_ile1= i1;
    *_ile2= i2;
    _nombre= 0;
    _est_vertical= false;
}

//Constructeur lorsque l'on va créer un pont entre 2 iles
// ! Utiliser un Accesseur pour le Boolean => Preferable !
Pont::Pont(Ile ile1, Ile ile2, int nombre){
    *_ile1= ile1;
    *_ile2= ile2;
    if( nombre >= 0 && nombre <= 2)
        _nombre = nombre;
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
    if( n >= 0 && n <= 2)
        _nombre= n;
    else _nombre =0;
}

void Pont::setEstVertical(bool v) {
    _est_vertical= v;
}

void Pont::estVertical(){
    if ( _ile1->getY() == _ile2->getY() ){
        _est_vertical = true;
    }
    else{
        _est_vertical = false;
    }
}
