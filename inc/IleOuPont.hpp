#ifndef _IleOuPont_HPP
#define _IleOuPont_HPP
#include "Ile.hpp"
#include "Pont.hpp"

class IleOuPont {
    private :
        Ile* _ile;
        Pont* _pont;
  
    public :
        // Constructeurs
        IleOuPont();
        IleOuPont(Ile*);
        IleOuPont(Pont*);
  
        // Accesseurs en écriture
        void setIle(Ile* ile);
        void setPont(Pont* pont);
  
        // Accesseurs en lecture
        Ile* getIle() const;
        Pont* getPont() const;
};

#endif // _IleOuPont_HPP
