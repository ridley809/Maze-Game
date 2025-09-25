#ifndef _COULOIR_HPP_
#define _COULOIR_HPP_

#include "objetgraphiquefixe.hpp"

#include <iostream>
#include <stdexcept>

class Couloir : public ObjetGraphiqueFixe {

    // type = 2
    public :
    Couloir(int i=0, int j=0);
    void afficher() const;
};

using std::cout;

#endif

