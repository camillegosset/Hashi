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
/* (pont.il1).voisinsreels.push_back(pont.ile2)
(pont.ile2).voisinsreels.push_back(pont.il1)
(pont.nbre++)
Si(pont.nbre >= 2) alors
    Pour i alland de 0 & (pont.ile.voisins_possibles).size() -1
        Si( pont.ile1.voisins_possibles[i]= pont.ile2) // comparer abscisse & ordonnée
         //efface la case
//pareil pour ile2

Si (pont.est_vertical == true ) alors
    pour i allant de ile1.ordonnee à ille.2 ordonnee
        //faire varier l'abscisse pour casser les iles et enlever les voisins_possibles

else //pareil avec l'abscisse*/
void Pont::majVoisinsReels(){
    this->_ile1->setUnVoisinReel(this->_ile2);
    this->_ile2->setUnVoisinReel(this->_ile1);
    if( this->_nombre >= 2){
        for(size_t i=0 ; i< _ile1->getVoisinsPossibles().size() ; i++){
            if( _ile1->getVoisinsPossibles()[i].getX() == _ile2->getX() && _ile1->getVoisinsPossibles()[i].getY() == _ile2->getY()){
                //effacer la case
                _ile1->supprimerUneCaseVoisinsPossibles(i);
            }
        }
        for(size_t i=0 ; i< _ile2->getVoisinsPossibles().size() ; i++){
            if( _ile2->getVoisinsPossibles()[i].getX() == _ile1->getX() && _ile2->getVoisinsPossibles()[i].getY() == _ile1->getY()){
                //effacer la case
                _ile2->supprimerUneCaseVoisinsPossibles(i);
            }
        }
    }
}
