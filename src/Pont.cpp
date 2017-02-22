#include "../inc/Pont.hpp"

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

void Pont::estVertical(){
    if ( _ile1->getY() == _ile2->getY() ){
        _est_vertical = true;
    }
    else{
        _est_vertical = false;
    }
}

// METHODE majComposantesConnexes
//Problème : On peut accéder au père des éléments mais pas aux fils donc on peut pas parcourir les Composantes à condition de connaitre les feuilles
void Pont::majComposantesConnexes(){
     if( _ile1->getHauteur() >= _ile2->getHauteur() ){
         int HauteurMaximale = _ile1->getHauteur();
         if (HauteurMaximale < _ile2->getHauteur() + 1 )
            HauteurMaximale = _ile2->getHauteur() + 1;
         _ile2->getChef()->setPere(_ile1->getChef());
         // Parcourir l'arbre de la compo connexe de l'ile _ile2

     }
     else{
         int HauteurMaximale = _ile2->getHauteur();
         _ile1->getChef()->setPere(_ile2->getChef());
          // Parcourir l'arbre de la compo connexe de l'ile _ile1
          _ile1->getChef()->setHauteur( HauteurMaximale);

     }
}
