#ifndef _IleOuPont_HPP
#define _IleOuPont_HPP
#include "Ile.hpp"
#include "Pont.hpp"

class IleOuPont {
    private :
        Ile* _ile;
        Pont* _pont;
    public :
        IleOuPont();
        IleOuPont(Ile*);
        IleOuPont(Pont*);
        void setIle(Ile* ile);
        void setPont(Pont* pont);
        Ile* getIle() const;
        Pont* getPont() const;
};

#endif // _IleOuPont_HPP
