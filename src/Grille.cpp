#include "../inc/Grille.hpp"
#include "../inc/IleOuPont.hpp"

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
    for(int i=0; i<_n; i++){
        for(int j=0; j<_m; j++){
            (this->_objets_presents[i][j]).setIle(NULL);
            (this->_objets_presents[i][j]).setPont(NULL);
        }
    }

    do {
        champ = champDeLecture(in);
        ignoreChars(in, " \t");

        if (champ == "longueur"){
            in >> _n;
        }
        if (champ == "largeur"){
            in >> _m;
        }
        if(_n && _m){
            _objets_presents = new IleOuPont*[_n];
            for (size_t i = 0; i < _n; i++) {
                _objets_presents[i] = new IleOuPont[_m];
            }
        }
        if (champ == "Grille"){

            in.seekg(1,std::ios_base::cur);
            int x,y,val;
            in >> x;
            in >> y;
            in >> val;

            Ile *ile = new Ile(val,x,y);
            _objets_presents[x][y].setIle(ile);
        }
    } while(champ.size());
}

//CONSTRUCTEURS

Grille::Grille(): _n(0), _m(0), _objets_presents(0) {}

//ACCESSEURS EN LECTURE
int Grille::getN() const{
    return this->_n;
}

int Grille::getM() const{
    return this->_m;
}

IleOuPont** Grille::getIlesOuPonts() const{
    return this->_objets_presents;
}
IleOuPont Grille::getUneIleOuUnPont(int x, int y) const{
    return this->_objets_presents[x][y];
}

//ACCESSEURS ECRITURE
void Grille::setN( int n){
    this->_n = n;
}

void Grille::setM( int m){
    this->_m = m;
}

void Grille::setIlesOuPonts(IleOuPont** objets_presents){

    for(int i =0; i< _n ; i++){
        for(int j=0; j< _m; j++ ){
            this->_objets_presents[i][j] = objets_presents[i][j];
        }
    }
}

void Grille::setUneIleOuUnPont(IleOuPont une_ile_ou_un_pont, int x, int y){
    this->_objets_presents[x][y]= une_ile_ou_un_pont;
}
