#include "objetgraphique.hpp"


// Constructeur paramétré
ObjetGraphique::ObjetGraphique(int i, int j, int t){
	
    m_i = i;
    m_j = j;
    m_type = t;
}

// Constructeur de recopie 
ObjetGraphique::ObjetGraphique(const ObjetGraphique& o){
	
    m_i = o.m_i;
    m_j = o.m_j;
    m_type = o.m_type;
}

// Obtenir le type d'un objet graphique 
int ObjetGraphique::getType() const {
    return m_type;
}

// Obtenir l'abscisse de la posiiton d'un objet graphique
int ObjetGraphique::getI() const {
    return m_i;
}

// Obtenir l'ordonnée de la posiiton d'un objet graphique
int ObjetGraphique::getJ() const {
    return m_j;
}
