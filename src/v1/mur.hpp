#ifndef _MUR_HPP_
#define _MUR_HPP_

#include "objetgraphiquefixe.hpp"

#include <iostream>
#include <stdexcept>


class Mur : public ObjetGraphiqueFixe {

    // type = 1
    public :
    Mur(int i=0, int j=0);
    void afficher() const;
};

using std::cout;

#endif

