#include "../inc/Grille.hpp"

/*void Grille::lecture(std::istream& is){
} */

//CONSTRUCTEURS

Grille::Grille(): _n(0), _m(0), _iles_presentes({}) {}
Grille::Grille(int n, int m, std::vector<Ile> iles_presentes) : _n(n) , _m(m), _iles_presentes(iles_presentes) {}

//ACCESSEURS EN LECTURE
int Grille::getN() const{
    return this->_n;
}

int Grille::getM() const{
    return this->_m;
}

std::vector<Ile> Grille::getIlesPresentes() const{
    return this->_iles_presentes;
}

//ACCESSEURS ECRITURE
void Grille::setN( int n){
    this->_n = n;
}

void Grille::setM( int m){
    this->_m = m;
}

void Grille::setIlesPresentes(std::vector<Ile> iles_presentes){
    _iles_presentes.clear();
    for(size_t i = 0 ; i< iles_presentes.size(); i++){
        this->_iles_presentes.push_back(iles_presentes.at(i));
    }
}

void Grille::setUneIle(Ile UneIle){
    _iles_presentes.push_back(UneIle);
}
