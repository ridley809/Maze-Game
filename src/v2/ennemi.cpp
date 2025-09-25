#include "ennemi.hpp"
#include "objetgraphiquemobile.hpp"

// Ennemi est un objet graphique mobile que nous avons choisi arbitrairement de type 5
Ennemi::Ennemi(int i,int j):ObjetGraphiqueMobile(i,j,5){}


void Ennemi::afficher() const{
    cout << "E";
}




