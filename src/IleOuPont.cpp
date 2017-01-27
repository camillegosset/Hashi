#include <iostream>
#include "../inc/IleOuPont.hpp"

IleOuPont::IleOuPont(): _ile(NULL), _pont(NULL) {}
IleOuPont::IleOuPont(Ile* ile): _ile(ile), _pont(NULL) {}

IleOuPont::IleOuPont(Pont* pont): _ile(NULL), _pont(pont) {}

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
