#include "../inc/Pont.hpp"

//Constructeur lorsque l'on va créer un pont entre 2 iles
// ! Utiliser un Accesseur pour le Boolean => Preferable !
Pont::Pont(Ile ile1, Ile ile2, int nombre){
    *_ile1= ile1;
    *_ile2= ile2;
    if( nombre >= 0 && nombre <= 2)
        _nombre = nombre;
}

Pont::Pont(Ile* ile1, Ile* ile2, int nombre){

    this->_ile1 = ile1;
    this->_ile2 = ile2;
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

void Pont::setEstVertical(){
    if ( _ile1->getX() == _ile2->getX() ){
        _est_vertical = true;
    }
    else{
        _est_vertical = false;
    }
}

// METHODE majComposantesConnexes
// Correction pb: On va comparer uniquement les hauteurs des chefs comme ça pas de parcours
void Pont::majComposantesConnexes(){
     if( _ile1->getChef()->getHauteur() >= _ile2->getChef()->getHauteur() ){
         int HauteurMaximale = _ile1->getChef()->getHauteur();
         if (HauteurMaximale < _ile2->getChef()->getHauteur() + 1 )
            HauteurMaximale = _ile2->getChef()->getHauteur() + 1;
         _ile2->getChef()->setPere(_ile1->getChef());
         _ile1->getChef()->setHauteur(HauteurMaximale);

     }
     else{
         int HauteurMaximale = _ile2->getChef()->getHauteur();
         _ile1->getChef()->setPere(_ile2->getChef());
         _ile1->getChef()->setHauteur( HauteurMaximale);

     }
}
