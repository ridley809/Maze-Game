#include "sortie.hpp"

// Sortie est un objet graphique fixe que nous avons choisi arbitrairement de type 3
Sortie::Sortie(int i, int j):ObjetGraphiqueFixe(i,j,3){}


void Sortie::afficher() const{
    cout << "S";
}

