#ifndef _GRILLE_H
#define _GRILLE_H

#include <vector>
#include "Ile.hpp"

class Grid{
    int _n;
    int _m; // Car on a une grille de type nxm
    std::vector<Ile> _iles_presentes; // Vector des iles dans la grille
};

#endif // _GRILLE_H
