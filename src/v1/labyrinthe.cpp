#include "labyrinthe.hpp"
#include "personnage.hpp"

#include "sortie.hpp" 


// constructeur paramétré : 

Labyrinthe :: Labyrinthe(int l, int c){
    m_nbl = l;
    m_nbc = c;
    m_plateau = new Plateau(m_nbl,m_nbc);
    m_personnage = new Personnage(1,6);
    m_sortie = new Sortie(m_nbl-1,7);
}

Labyrinthe :: Labyrinthe(){ // defaut

    int m_nbc = 2;
    int m_nbl = 2;
	m_plateau = new Plateau();
    m_personnage = new Personnage(1,0);
    m_sortie = new Sortie(2,0);

}

// Constructeur de recopie 
Labyrinthe :: Labyrinthe(const Labyrinthe&l){
	m_nbc = l.m_nbc ;
    m_nbl = l.m_nbl;
    m_plateau = l.m_plateau;
    
    int Per_i = l.m_personnage->getI();
    int Per_j = l.m_personnage->getJ();
    
    int Sortie_i = l.m_sortie->getI();
    int Sortie_j = l.m_sortie->getJ();
    
    m_personnage = new Personnage(Per_i, Per_j);
    m_sortie = new Sortie(Sortie_i, Sortie_j);
    
}


//Destructeur
Labyrinthe :: ~Labyrinthe(){

    delete m_plateau;
    delete  m_personnage;
    delete  m_sortie;
}



//Methodes :

void Labyrinthe :: deplacerPersoDroite(){
    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j +1)->getType();

    if( type == 2 || type == 3) {
        m_personnage->deplacerDroite();
	}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement, Mur");
	}
	
}

void Labyrinthe :: deplacerPersoGauche(){
    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j-1)->getType();

    if(type == 2 || type == 3) {
        m_personnage->deplacerGauche();
	}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement, Mur");
	}	
}



void Labyrinthe :: deplacerPersoHaut(){
    int type = m_plateau->getCase(m_personnage->m_i-1,m_personnage->m_j)->getType();

    if(type == 2 || type == 3) {
        m_personnage->deplacerHaut();
	}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement, Mur");
	}
}


void Labyrinthe :: deplacerPersoBas(){
    int type = m_plateau->getCase(m_personnage->m_i+1,m_personnage->m_j)->getType();

    if((type == 2 || type == 3)) {
        m_personnage->deplacerBas();
	}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement, Mur");
	}
	
}


bool Labyrinthe :: fini() const{
	bool finit = false;
    if(m_personnage->m_i == m_sortie->m_i && m_personnage->m_j == m_sortie->m_j ){
        finit = true;
		return finit;
    }
    else{
    	return false;
	}
}


void Labyrinthe :: afficher() const {
    m_plateau->afficher(*m_personnage);
}
