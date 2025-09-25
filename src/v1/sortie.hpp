#ifndef _SORTIE_HPP_
#define _SORTIE_HPP_

#include "objetgraphiquefixe.hpp"

#include <iostream>
#include <stdexcept>


class Sortie : public ObjetGraphiqueFixe {

    // type = 3
    public :
    Sortie(int i=0, int j=0);
    void afficher() const;
};

using std::cout;

#endif

