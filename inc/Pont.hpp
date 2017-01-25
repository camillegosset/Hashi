#ifndef _PONT_H
#define _PONT_H

#include "Ile.hpp"

class Pont {
private:
    Ile _ile1;
    Ile _ile2;
    int _nombre; //Nombre de Ponts reliant les iles
    bool _est_vertical; //True si le pont est vertical, false s'il est horizontal
public:
    //CONSTRUCTEURS
    Pont( Ile ile1, Ile ile2);

    //ACCESSEURS LECTURE
    Ile getIle1();
    Ile getIle2();
    int getNombre();

    //ACCESSEURS ECRITURE
    void setIle1(Ile ile1);
    void setIle2(Ile ile2);
    void setNombre(int nombre);

};

#endif
