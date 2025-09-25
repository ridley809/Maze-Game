#include "objetgraphiquemobile.hpp"
#include "objetgraphique.hpp"

ObjetGraphiqueMobile::ObjetGraphiqueMobile(int i,int j,int t):ObjetGraphique(i,j,t){};

// D�placement � droite de l'objet graphique mobile
void ObjetGraphiqueMobile::deplacerDroite(){
    m_j++;
}

// D�placement � gauche de l'objet graphique mobile
void ObjetGraphiqueMobile::deplacerGauche(){
    m_j--;
}

// D�placement en haut de l'objet graphique mobile
void ObjetGraphiqueMobile::deplacerHaut(){
    m_i--;
}

// D�placement en bas de l'objet graphique mobile
void ObjetGraphiqueMobile::deplacerBas(){
    m_i++;
}


