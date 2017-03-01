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
  sortie<< "+ \n";
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
	      sortie << "-- ";
	    }
	    else {
	      sortie << "| ";
	    }
	  }
	  else {
	    if ( grille.getPont()->getEstVertical() ) {
	      sortie << "==";
	    }
	    else {
	      sortie << "||";
	    }
	  }
	}
	else {
	  sortie << ". ";
	}
      }
    }
    sortie <<"| \n";
  }

  sortie << "+";
  for (size_t i = 1; i <= 2*_m; i++) {
    sortie << "-";
  }
  sortie<< "+ \n";
}

//Methode pour récupérer les voisins possibles de chaque ile
void Grille::RecupVoisinsPossibles(){
    for(size_t i=0; i< _n ; i++){
        Ile* ile = NULL;
        for(size_t j=0; j< _m; j++){
            IleOuPont caseActuelle =  _objets_presents[i][j];
            if(caseActuelle.getIle() != NULL){
                if( ile == NULL ) {
                    ile = caseActuelle.getIle();
                }
                else{
                    if ((size_t)ile->getX() != i || (size_t)ile->getY() != j) {
                        ile->setUnVoisinPossible(caseActuelle.getIle());
                        caseActuelle.getIle()->setUnVoisinPossible(*ile);

                        ile = caseActuelle.getIle();
                    }

                }
            }
        }
    }

    for(size_t j=0; j < _m; j++){
        Ile* ile = NULL;
        for(size_t i=0; i< _n; i++){
            IleOuPont caseActuelle =  _objets_presents[i][j];
            if(caseActuelle.getIle() != NULL){
                if( ile == NULL ) {
                    ile = caseActuelle.getIle();
                }
                else{
                    if ((size_t)ile->getX() != i || (size_t)ile->getY() != j) {
                        ile->setUnVoisinPossible(caseActuelle.getIle());
                        caseActuelle.getIle()->setUnVoisinPossible(*ile);

                        ile = caseActuelle.getIle();
                    }

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

    if( ile->getPontsPlaces() == 0 && (unsigned int)ile->getVal() == 2*(ile->getVoisinsPossibles().size()) ){
        Ile ile2;
        for(size_t i = 0 ; i < ile->getVoisinsPossibles().size() ; i++){
            ile2 = ile->getVoisinsPossibles().at(i);
            creerPont(ile, getUneIleOuUnPont(ile2.getX(), ile2.getY()).getIle() , 2);
            ile->setVal(2);
            ile->getVoisinsPossibles().at(i).setVal(2);
        }
        ile->setEstRelie(true);
    }
    if( (unsigned int)(1 + (ile->getVal() - ile->getPontsPlaces()) / 2) == ile->getVoisinsPossibles().size() && !(ile->getRelie())){
        Ile ile2;
        for(size_t i = 0; i< ile->getVoisinsPossibles().size() ; i++){
            ile2 = ile->getVoisinsPossibles().at(i);
            creerPont(ile, getUneIleOuUnPont(ile2.getX(), ile2.getY()).getIle() , 1);
            ile->setVal(1);
            ile->getVoisinsPossibles().at(i).setVal(1);
        }
    }

}

void Grille::creerPont(Ile* ile1, Ile* ile2, int nbr_ponts){
    Pont* pont= new Pont(ile1, ile2, nbr_ponts);

    pont->setEstVertical();

    if( pont->getEstVertical() == false ) { // Possibilité de savoir dès maintenant si vertical ou non donc on peut faire le CONSTRUCTEUR adéquate

        for(int i = std::min(ile1->getX(), ile2->getX())+1 ; i < std::max(ile2->getX(), ile1->getX()); i++) {
            // On crée un pont à chaque case
            _objets_presents[i][ile1->getY()].setPont(pont);
            majVoisinsReels(_objets_presents[i][ile1->getY()].getPont());
        }
    }
    else {
        for(int i = std::min(ile1->getY(), ile2->getY())+1 ; i < std::max(ile2->getY(), ile1->getY()); i++) {
            // On crée un pont à chaque case
            _objets_presents[ile1->getX()][i].setPont(pont);
            majVoisinsReels(_objets_presents[ile1->getX()][i].getPont());
        }
    }
}
