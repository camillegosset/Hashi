#include <cstdlib>
#include "../inc/Grille.hpp"

//CONSTRUCTEUR
Grille::Grille(): _n(0), _m(0), _objets_presents(0) {}

//DESTRUCTEUR
Grille::~Grille(){
    for (size_t i = 0; i < _n; i++) {
        delete [] _objets_presents[i];
    }

    delete [] _objets_presents;
}


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

int Grille::getNbreComposantesConnexes(){
    return _nbre_composantes_connexes;
}

//ACCESSEURS ECRITURE
void Grille::setN( int n){
    this->_n = n;
}

void Grille::setM( int m){
    this->_m = m;
}

void Grille::setUneIleOuUnPont(IleOuPont une_ile_ou_un_pont, int x, int y){
    this->_objets_presents[x][y]= une_ile_ou_un_pont;
}

void Grille::setEstResolu(){
    if ( _nbre_composantes_connexes == 1)
        _est_resolu = true;
    else _est_resolu = false;
}

void Grille::setNbreComposanteConnexes(){
    if( _nbre_composantes_connexes > 1)
        _nbre_composantes_connexes = _nbre_composantes_connexes - 1;

    if( _nbre_composantes_connexes == 1)
        _est_resolu = true;
}

// Méthodes récupération fichier et affichage
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

	        if ((unsigned int) x <_n && (unsigned int) y<_m && y >= 0 && x >= 0 && val >= 1 && val <= 8) {
		    ile = new Ile(val,x,y);
		    _objets_presents[x][y].setIle(ile);
		    _nbre_composantes_connexes++;
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


void Grille::affichage (std::ostream& sortie) const{
    sortie << "+";
  for (size_t i = 1; i <= 2*_m; i++) {
      sortie << "-";
  }
  sortie<< "+"<< '\n';
  for (size_t i = 0; i < _n; i++) {
    sortie << "|";
    for (size_t j = 0; j < _m; j++) {
      IleOuPont grille = getUneIleOuUnPont(i,j);
      if( grille.getIle() != NULL) {
        sortie << grille.getIle()->getVal() << " ";
      }
      else {
	if ( grille.getPont() != NULL ) {
	  if ( grille.getPont()->getNombre() == 1 ) {
	    if ( grille.getPont()->getEstVertical() ) {
	      sortie << "| ";
	    }
	    else {
	      sortie << "--";
	    }
	  }
	  else {
	    if ( grille.getPont()->getEstVertical() ) {
	      sortie << "|| ";
	    }
	    else {
	      sortie << "==";
	    }
	  }
	}
	else {
	  sortie << ". ";
	}
      }
    }
    sortie <<"|" << '\n';
  }
  
  sortie << "+";
  for (size_t i = 1; i <= 2*_m; i++) {
    sortie << "-";
  }
  sortie<< "+"<< '\n';
}

//Methode pour récupérer les voisins possibles de chaque ile
void Grille::RecupVoisinsPossibles(){
    for(size_t i=0; i< _n ; i++){
        Ile* ile= new Ile(-1, -1, -1);
        for(size_t j=0; j< _m; j++){
            if(_objets_presents[i][j].getIle() != NULL){
                if( ile->getVal()== -1 && ile->getX() == -1 && ile->getY() == -1){
                    ile = _objets_presents[i][j].getIle();
                }
                else{
                    ile->setUnVoisinPossible(_objets_presents[i][j].getIle());
                    _objets_presents[i][j].getIle()->setUnVoisinPossible(*ile);
                    ile = _objets_presents[i][j].getIle();

                }
            }
        }
    }
}


//Méthode de màj quand on crée un pont
void Grille::majVoisinsReels(Pont* pont){
    pont->getIle1()->setUnVoisinReel( pont->getIle2());
    pont->getIle2()->setUnVoisinReel( pont->getIle1());
    if( pont->getNombre() >= 2){
        for(size_t i=0 ; i< pont->getIle1()->getVoisinsPossibles().size() ; i++){
            if( pont->getIle1()->getVoisinsPossibles()[i].getX() == pont->getIle2()->getX() && pont->getIle1()->getVoisinsPossibles()[i].getY() == pont->getIle2()->getY()){
                //effacer la case
                pont->getIle1()->supprimerUneCaseVoisinsPossibles(i);
            }
        }
        for(size_t i=0 ; i< pont->getIle2()->getVoisinsPossibles().size() ; i++){
            if( pont->getIle2()->getVoisinsPossibles()[i].getX() == pont->getIle1()->getX() && pont->getIle2()->getVoisinsPossibles()[i].getY() == pont->getIle1()->getY()){
                //effacer la case
                pont->getIle2()->supprimerUneCaseVoisinsPossibles(i);
            }
        }
    }
    if( pont->getEstVertical() ){
        for(int i= std::min(pont->getIle1()->getY(), pont->getIle2()->getY()) ; i <= std::max(pont->getIle1()->getY(), pont->getIle2()->getY()) ; i++){
            //Chercher 2 iles de chaque côtés du pont sur l'ordonné
            int j = i;
            while( j< getM() && (getUneIleOuUnPont( pont->getIle1()->getX(), j).getIle() == NULL ) ){
                j++;
            }
            if ( getUneIleOuUnPont( pont->getIle1()->getX(), j).getIle() != NULL){
                int k = 0;
                while( k< getM() && (getUneIleOuUnPont( pont->getIle1()->getX(), k).getIle() == NULL )){
                    k--;
                }
                if( getUneIleOuUnPont( pont->getIle1()->getX(), k).getIle() != NULL){
                    for(size_t l=0 ; l< getUneIleOuUnPont( pont->getIle1()->getX(), k).getIle()->getVoisinsPossibles().size() ; l++){
                        if( getUneIleOuUnPont( pont->getIle1()->getX(), k).getIle()->getVoisinsPossibles()[l].getX() == getUneIleOuUnPont( pont->getIle1()->getX(), j).getIle()->getX()
                        && getUneIleOuUnPont(pont->getIle1()->getX(), k).getIle()->getVoisinsPossibles()[l].getY() == getUneIleOuUnPont( pont->getIle1()->getX(), j).getIle()->getY() ){
                            //effacer la case
                            getUneIleOuUnPont( pont->getIle1()->getX(), k).getIle()->supprimerUneCaseVoisinsPossibles(l);
                        }
                    }

                    for(size_t l=0 ; l< getUneIleOuUnPont( pont->getIle1()->getX(), k).getIle()->getVoisinsPossibles().size() ; l++){
                        if( getUneIleOuUnPont( pont->getIle1()->getX(), j).getIle()->getVoisinsPossibles()[l].getX() == getUneIleOuUnPont( pont->getIle1()->getX(), k).getIle()->getX()
                        && getUneIleOuUnPont( pont->getIle1()->getX(), j).getIle()->getVoisinsPossibles()[l].getY() == getUneIleOuUnPont( pont->getIle1()->getX(), k).getIle()->getY() ){
                            //effacer la case
                            getUneIleOuUnPont( pont->getIle1()->getX(), j).getIle()->supprimerUneCaseVoisinsPossibles(l);
                        }
                    }
                }
            }
        }
    }
    else{
        for(int i= std::min(pont->getIle1()->getX(), pont->getIle2()->getX()) ; i <= std::max(pont->getIle1()->getX(), pont->getIle2()->getX()) ; i++){
            //Chercher 2 iles de chaque côtés du pont sur l'absisse
            int j = i;
            while( j< getN() && (getUneIleOuUnPont( pont->getIle1()->getY(), j).getIle() == NULL ) ){
                j++;
            }
            if ( getUneIleOuUnPont( pont->getIle1()->getY(), j).getIle() != NULL){
                int k = 0;
                while( k< getN() && (getUneIleOuUnPont( pont->getIle1()->getY(), k).getIle() == NULL )){
                    k--;
                }
                if( getUneIleOuUnPont( pont->getIle1()->getY(), k).getIle() != NULL){
                    for(size_t l=0 ; l< getUneIleOuUnPont( pont->getIle1()->getY(), k).getIle()->getVoisinsPossibles().size() ; l++){
                        if( getUneIleOuUnPont( pont->getIle1()->getY(), k).getIle()->getVoisinsPossibles()[l].getY() == getUneIleOuUnPont( pont->getIle1()->getY(), j).getIle()->getY()
                        && getUneIleOuUnPont(pont->getIle1()->getY(), k).getIle()->getVoisinsPossibles()[l].getX() == getUneIleOuUnPont( pont->getIle1()->getY(), j).getIle()->getX() ){
                            //effacer la case
                            getUneIleOuUnPont( pont->getIle1()->getY(), k).getIle()->supprimerUneCaseVoisinsPossibles(l);
                        }
                    }

                    for(size_t l=0 ; l< getUneIleOuUnPont( pont->getIle1()->getY(), k).getIle()->getVoisinsPossibles().size() ; l++){
                        if( getUneIleOuUnPont( pont->getIle1()->getY(), j).getIle()->getVoisinsPossibles()[l].getY() == getUneIleOuUnPont( pont->getIle1()->getY(), k).getIle()->getY()
                        && getUneIleOuUnPont( pont->getIle1()->getY(), j).getIle()->getVoisinsPossibles()[l].getX() == getUneIleOuUnPont( pont->getIle1()->getY(), k).getIle()->getX() ){
                            //effacer la case
                            getUneIleOuUnPont( pont->getIle1()->getY(), j).getIle()->supprimerUneCaseVoisinsPossibles(l);
                        }
                    }
                }
            }
        }
    }
}

void Grille::placerPonts(Ile* ile){

    if( ile->getPontsPlaces() == 0 && (unsigned int)ile->getVal() == 2*(ile->getVoisinsPossibles().size())){
        for(size_t i = 0 ; i < ile->getVoisinsPossibles().size() ; i++){
            creerPont(ile, ile->getVoisinsPossibles().at(i), 2); //Pb : On a un vector d'ile et non un vector de pointeurs d'ile
        }
    }

}

void Grille::creerPont(Ile* ile1, Ile ile2, int nbr_ponts){
    Pont* pont= new Pont(ile1, _objets_presents[ile2.getX()][ile2.getY()].getIle(), nbr_ponts);
    if( ile1->getX() == ile2.getX()){ //Possibilité de savoir dès maintenant si vertical ou non donc on peut faire le CONSTRUCTEUR adéquate
        for(int i = ile1->getY() ; i < ile2.getY(); i++){
            //On crée un pont à chaque case
            _objets_presents[ile1->getX()][i].setPont(pont);
        }
    }
}
