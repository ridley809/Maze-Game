#ifndef _COULOIR_HPP_
#define _COULOIR_HPP_

#include "objetgraphiquefixe.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

class Couloir : public ObjetGraphiqueFixe {

    // Type = 2
    public :
    	
   	 	Couloir(int i, int j);
    	void afficher() const;
};


#endif

