#include "personnage.hpp"
#include "objetgraphiquemobile.hpp"

// Personnage est un objet graphique mobile que nous avons choisi arbitrairement de type 4
Personnage::Personnage(int i,int j):ObjetGraphiqueMobile(i,j,4){}


void Personnage::afficher() const{
    cout << "P";
}


