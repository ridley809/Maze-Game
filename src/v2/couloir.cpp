#include "couloir.hpp"

// Couloir est un objet graphique fixe que nous avons choisi arbitrairement de type 2
Couloir::Couloir(int i, int j):ObjetGraphiqueFixe(i,j,2){}

void Couloir::afficher() const{
    cout << " ";
}

