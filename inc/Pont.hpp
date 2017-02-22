#ifndef _PONT_H
#define _PONT_H

#include "Ile.hpp"

class Pont {
private:
    Ile* _ile1;
    Ile* _ile2;
    int _nombre; // Nombre de Ponts reliant les iles
    bool _est_vertical; // True si le pont est vertical, false s'il est horizontal

public:
    // CONSTRUCTEURS
    Pont(Ile, Ile, int);

    // ACCESSEURS LECTURE
    Ile* getIle1();
    Ile* getIle2();
    int getNombre();
    bool getEstVertical();

    // ACCESSEURS ECRITURE
    void setIle1(Ile*);
    void setIle2(Ile*);
    void setNombre(int);
    void estVertical();

    // Méthode pour faire l'union de composantes connexes
    void majComposantesConnexes();


};

#endif
