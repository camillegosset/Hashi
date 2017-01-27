#include <iostream>

IleOuPont::IleOuPont(Ile* ile,Pont* pont): _ile(ile), _pont(pont) {}

Ile* IleOuPont::getIle() const{
    return this->_ile;
}

Pont* IleOuPont::getPont() const{
    return this->_pont;
}

void IleOuPont::setIle(Ile* ile) {
    this->_ile = ile;
}

void IleOuPont::setPont(Pont* pont){
    this->_pont = pont;
}
