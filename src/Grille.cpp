#include "../inc/Grille.hpp"

std::string Grille::enleverEspace(std::string str){
    std::size_t gauche = str.find_first_not_of("\t ");
    std::size_t droite = str.find_last_not_of("\t ");

    if (gauche != std::string::npos && droite != std::string::npos)
    {
        return str.substr(gauche, droite - gauche + 1);
    }

    return str;
}


std::string Grille::champDeLecture(std::istream& in){
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

void Grille::ignoreChars(std::istream& in, std::string chars){
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
    int x,y,val;
    Ile* ile;
    bool estCree = false;

    do {
        champ = champDeLecture(in);
        ignoreChars(in, " \t");

        if (champ == "Hauteur"){
            in >> _n;
	    in.get();
        }

        if (champ == "Longueur"){
            in >> _m;
	    in.get();
        }

        if(_n && _m && !estCree){

            _objets_presents = new IleOuPont*[_n];
            for (size_t i = 0; i < _n; i++) {
                _objets_presents[i] = new IleOuPont[_m];
            }
            estCree = true;

            // Vidage des iles
            for(size_t i=0; i<_n; i++){
                for(size_t j=0; j<_m; j++){
                    (this->_objets_presents[i][j]).setIle(NULL);
                    (this->_objets_presents[i][j]).setPont(NULL);
                }
            }
        }

        if (champ == "Grille"){
	    in.seekg(1,std::ios_base::cur);

	    while(champ.size()) {

	        in >> y;
	        in >> x;
	        in >> val;

	        if (x <_n && y<_m && y >= 0 && x >= 0 && val >= 1 && val <= 8) {
		    ile = new Ile(val,x,y);
		    _objets_presents[x][y].setIle(ile);
		}
		else {
		    std::cerr<<"Erreur: mauvais choix de coordonnées \n";
            std::exit(EXIT_FAILURE); // FAIIIIIL
		}
	        in.get();
		      champ= champDeLecture(in);
	    }
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
  return _objets_presents;
}
IleOuPont Grille::getUneIleOuUnPont(int x, int y) const{
    return this->_objets_presents[x][y];
}

bool Grille::getEstResolu(){
    return this->_est_resolu;
}

//ACCESSEURS ECRITURE
void Grille::setN( int n){
    this->_n = n;
}

void Grille::setM( int m){
    this->_m = m;
}

void Grille::setIlesOuPonts(IleOuPont** objets_presents){

    for(size_t i =0; i< _n ; i++){
        for(size_t j=0; j< _m; j++ ){
            this->_objets_presents[i][j] = objets_presents[i][j];
        }
    }
}

void Grille::setUneIleOuUnPont(IleOuPont une_ile_ou_un_pont, int x, int y){
    this->_objets_presents[x][y]= une_ile_ou_un_pont;
}

void Grille::setEstResolu(bool resolu){
    this->_est_resolu = resolu;
}

void Grille::affichage (std::ostream& sortie) const{
    sortie << "+";
  for (size_t i = 1; i <= 2*_m; i++) {
      sortie << "-";
  }
  sortie<< "+"<< '\n';
  for (size_t i = 0; i < _n; i++) {
      sortie << "|";
    for (size_t j = 0; j < _m; j++) {
      auto grille = getUneIleOuUnPont(i,j);
      if( grille.getIle() != NULL){
        sortie << grille.getIle()->getVal() << " ";
      }
      else
      sortie << ". ";
    }
    sortie <<"|" << '\n';
  }

  sortie << "+";
for (size_t i = 1; i <= 2*_m; i++) {
    sortie << "-";
}
sortie<< "+"<< '\n';
}
