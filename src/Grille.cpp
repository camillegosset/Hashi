#include "../inc/Grille.hpp"

std::string enleverEspace(std::string str){
    std::size_t gauche = str.find_first_not_of("\t ");
    std::size_t droite = str.find_last_not_of("\t ");

    if (gauche != std::string::npos && droite != std::string::npos)
    {
        return str.substr(gauche, droite - gauche + 1);
    }

    return str;
}

std::string champDeLecture(std::istream& in){
    std::string champ;
    int lecture = in.get();
    // Lecture de la ligne jusqu’au prochain : ou bien la fin de la ligne
    while (lecture != ':' && lecture != '\n' && in)
    {
        champ += lecture;
        lecture = in.get();
    }

    return enleverEspace(champ);
}

void ignoreChars(std::istream& in, std::string chars){
    // Lecture jusqu’au prochain caractère intéressant
    int lecture = in.get();

    while (chars.find(lecture) != std::string::npos && in)
    {
        lecture = in.get();
    }

    // Comme on a lu un caractère de trop, on revient d’un en arrière
    if (in)
    {
        in.unget();
    }
}

void Grille::lecture(std::istream& in){
    std::string champ;
    //vidage des iles
    _iles_presentes.clear();

    do {
        champ = champDeLecture(in);
        ignoreChars(in, " \t");

        if (champ == "longueur"){
            in >> _n;
        }
        if (champ == "largeur"){
            in >> _m;
        }
        if (champ == "Grid"){
            // remplir le vector d'iles => appeler le constructeurs d'iles depuis un istream
        }
    } while(champ.size());
}

//CONSTRUCTEURS

Grille::Grille(): _n(0), _m(0), _iles_presentes(0) {}
//Grille::Grille(int n, int m, std::vector<std::vector<Ile>> iles_presentes) : _n(n) , _m(m), _iles_presentes(iles_presentes) {}

//ACCESSEURS EN LECTURE
int Grille::getN() const{
    return this->_n;
}

int Grille::getM() const{
    return this->_m;
}

std::vector<std::vector<Ile>> Grille::getIlesPresentes() const{
    return this->_iles_presentes;
}

//ACCESSEURS ECRITURE
void Grille::setN( int n){
    this->_n = n;
}

void Grille::setM( int m){
    this->_m = m;
}

/*void Grille::setIlesPresentes(std::vector<std::vector<Ile>> iles_presentes){
    _iles_presentes.clear();
    for(int i = 0 ; i< _n; i++){
        for(int j=0; j< _m ; j++ ){
            this->_iles_presentes.push_back((iles_presentes.at(i)).at(j));
        }
    }
}

void Grille::setUneIle(Ile UneIle){
    _iles_presentes.push_back(UneIle);
}*/
