#include "mur.hpp"

// Mur est un objet graphique fixe que nous avons choisi arbitrairement de type 2
Mur::Mur(int i, int j):ObjetGraphiqueFixe(i,j,1){}

void Mur::afficher() const{
    cout << "#"; 
}

