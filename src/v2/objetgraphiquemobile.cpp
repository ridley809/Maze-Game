#include "objetgraphiquemobile.hpp"
#include "objetgraphique.hpp"

ObjetGraphiqueMobile::ObjetGraphiqueMobile(int i,int j,int t):ObjetGraphique(i,j,t){};

// Déplacement à droite de l'objet graphique mobile
void ObjetGraphiqueMobile::deplacerDroite(){
    m_j++;
}

// Déplacement à gauche de l'objet graphique mobile
void ObjetGraphiqueMobile::deplacerGauche(){
    m_j--;
}

// Déplacement en haut de l'objet graphique mobile
void ObjetGraphiqueMobile::deplacerHaut(){
    m_i--;
}

// Déplacement en bas de l'objet graphique mobile
void ObjetGraphiqueMobile::deplacerBas(){
    m_i++;
}


