#include "labyrinthe.hpp"
#include "personnage.hpp"
#include "sortie.hpp" 
#include <cstdlib> // pour avoir accès à la bibliothèque random
#include <string> // pour avoir accès aux chaînes de caractère (type string)


// Constructeur par défaut
Labyrinthe :: Labyrinthe(){ 

    m_nbc = 3;
    m_nbl = 3;
	m_plateau = new Plateau();
    m_personnage = new Personnage(1,0);
    m_sortie = new Sortie(2,0);
    m_ennemi = new Ennemi(1,2);

}

// Constructeur paramétré pour un plateau de taille (11,11)
Labyrinthe :: Labyrinthe(int l , int c){

    m_nbl = l;
    m_nbc = c;
    m_plateau = new Plateau(m_nbl,m_nbc);
    m_personnage = new Personnage(1,6);
    m_sortie = new Sortie(m_nbl-1,7);
    m_ennemi = new Ennemi(5,8);
}

// Constructeur de Labyrinthe à partir d'un fichier
Labyrinthe :: Labyrinthe (string chaine){
	
	int l;
	int c;
	int perso_i =0, perso_j = 0, ennemi_i =0, ennemi_j = 0, sortie_i =0, sortie_j = 0;
	m_plateau->taillePlateauFichier(chaine, l, c);
    m_nbl = l;
    m_nbc = c;
    m_plateau = new Plateau(chaine, m_nbl, m_nbc,perso_i, perso_j, ennemi_i, ennemi_j, sortie_i, sortie_j );
    m_personnage = new Personnage(perso_i,perso_j);
    m_sortie = new Sortie(sortie_i,sortie_j);
    m_ennemi = new Ennemi(ennemi_i,ennemi_j);
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
    
	int Ennemi_i = l.m_ennemi->getI();
    int Ennemi_j = l.m_ennemi->getJ();
    
    m_personnage = new Personnage(Per_i, Per_j);
    m_sortie = new Sortie(Sortie_i, Sortie_j);
    m_ennemi = new Ennemi(Ennemi_i, Ennemi_j);
    
}

// Destructeur 
Labyrinthe :: ~Labyrinthe(){

    delete m_plateau;
    delete m_personnage;
    delete m_ennemi;
    delete m_sortie;
}


// Permet de vérifier si un déplacement du personnage à droite est possible
void Labyrinthe :: deplacerPersoDroite(){

    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j +1)->getType(); // On obtient le type de la case à droite du personnage pour vérifier s'il peut se déplacer

    if ((m_personnage->m_i == m_ennemi->m_i) && (m_personnage->m_j +1 == m_ennemi->m_j)){ // On considère que le personnage ne peut pas se déplacer de lui-même vers l'ennemi
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}
	
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present."); // Renvoie un message d'erreur si un mur est présent à droite du personnage
	}
	
	// On vérifie que la case à droite du personnage est bien un couloir ou la sortie
    if((type == 2 || type == 3) && ((m_personnage->m_i != m_ennemi->m_i) || (m_personnage->m_j +1 != m_ennemi->m_j))) {
        m_personnage->deplacerDroite();

	}

}

// Permet de vérifier si un déplacement du personnage à gauche est possible
void Labyrinthe :: deplacerPersoGauche(){

    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j-1)->getType(); // On obtient le type de la case à gauche du personnage pour vérifier s'il peut se déplacer

    if ((m_personnage->m_i == m_ennemi->m_i) && (m_personnage->m_j -1 == m_ennemi->m_j)){ // On considère que le personnage ne peut pas se déplacer de lui-même vers l'ennemi
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}
	// On vérifie que la case à gauche du personnage est bien un couloir ou la sortie
    if((type == 2 || type == 3) && ((m_personnage->m_i != m_ennemi->m_i) ||(m_personnage->m_j -1 != m_ennemi->m_j))) {
        m_personnage->deplacerGauche();
	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present."); // Renvoie un message d'erreur si un mur est présent à gauche du personnage
	}

}


// Permet de vérifier si un déplacement du personnage en haut est possible
void Labyrinthe :: deplacerPersoHaut(){

    int type = m_plateau->getCase(m_personnage->m_i-1,m_personnage->m_j)->getType(); // On obtient le type de la case en haut du personnage pour vérifier s'il peut se déplacer

    if ((m_personnage->m_i -1 == m_ennemi->m_i) && (m_personnage->m_j == m_ennemi->m_j)){ // On considère que le personnage ne peut pas se déplacer de lui-même vers l'ennemi
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}
	// On vérifie que la case en haut du personnage est bien un couloir ou la sortie	
    if((type == 2 || type == 3) && ((m_personnage->m_i -1 != m_ennemi->m_i) || (m_personnage->m_j != m_ennemi->m_j))) {
        m_personnage->deplacerHaut();
	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present."); // Renvoie un message d'erreur si un mur est présent en haut du personnage
	}
}

// Permet de vérifier si un déplacement du personnage en bas est possible
void Labyrinthe :: deplacerPersoBas(){

    int type = m_plateau->getCase(m_personnage->m_i+1,m_personnage->m_j)->getType(); // On obtient le type de la case en bas du personnage pour vérifier s'il peut se déplacer

    if ((m_personnage->m_i +1 == m_ennemi->m_i) && (m_personnage->m_j == m_ennemi->m_j)){ // On considère que le personnage ne peut pas se déplacer de lui-même vers l'ennemi
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present."); 
	}
    // On vérifie que la case en bas du personnage est bien un couloir ou la sortie
    if((type == 2 || type == 3) && ((m_personnage->m_i +1 != m_ennemi->m_i) || (m_personnage->m_j != m_ennemi->m_j))) {
        m_personnage->deplacerBas();
	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present."); // Renvoie un message d'erreur si un mur est présent en bas du personnage
	}
}

// Méthode qui permet de déplacer l'ennemi de manière aléatoire à un emplacement valide (un couloir)
void Labyrinthe :: deplacerEnnemi(){

	int random; // Entier qui sert à déterminer une direction aléatoire
	int booleen = 0;

	while (booleen == 0) { // Tant que booleen = 0, la direction déterminée aléatoirement n'est pas valide pour déplacer l'ennemi. On réitère jusqu'à ce que booleen soit différent de 0.

        random = rand() %4; // On applique un modulo 4 pour choisir une des quatre directions au hasard

        if(random == 0){ // Mouvement à droite
            int type = m_plateau->getCase(m_ennemi->m_i,m_ennemi->m_j +1)->getType(); // On obtient le type de la case à droite de l'ennemi

            if(type == 2) { // Si la case à droite de l'ennemi est un couloir, on le déplace
                m_ennemi->deplacerDroite();
                booleen = 1; // Le booleen est différent de 0 donc le déplacement est valide, on appelle la méthode deplacerDroite() de la classe ObjetGraphiqueMobile
            }
        }

        else if(random == 1){ // Mouvement à gauche
            int type = m_plateau->getCase(m_ennemi->m_i,m_ennemi->m_j -1)->getType(); // On obtient le type de la case à gauche de l'ennemi

            if(type == 2) { // Si la case à gauche de l'ennemi est un couloir, on le déplace
                m_ennemi->deplacerGauche();
                booleen = 1; // Le booleen est différent de 0 donc le déplacement est valide, on appelle la méthode deplacerGauche() de la classe ObjetGraphiqueMobile
            }
        }

        else if(random == 2){ // Mouvement en haut
            int type = m_plateau->getCase(m_ennemi->m_i-1,m_ennemi->m_j)->getType(); // On obtient le type de la case en haut de l'ennemi

            if(type == 2) { // Si la case en haut de l'ennemi est un couloir, on le déplace
                m_ennemi->deplacerHaut();
                booleen = 1; // Le booleen est différent de 0 donc le déplacement est valide, on appelle la méthode deplacerHaut() de la classe ObjetGraphiqueMobile
            }

        }

        else if(random == 3){ // Mouvement en bas
            int type = m_plateau->getCase(m_ennemi->m_i+1,m_ennemi->m_j)->getType(); // On obtient le type de la case en bas de l'ennemi

            if(type == 2) { // Si la case en bas de l'ennemi est un couloir, on le déplace
                m_ennemi->deplacerBas(); // Le booleen est différent de 0 donc le déplacement est valide, on appelle la méthode deplacerBas() de la classe ObjetGraphiqueMobile
                booleen = 1;
            }

        }
	}


}

//  Renvoie l'état de la partie
int Labyrinthe :: fini() const{

	int fini = 0; // Renvoie 0 tant que la partie continue 
    if(m_personnage->m_i == m_sortie->m_i && m_personnage->m_j == m_sortie->m_j){
        fini = 1; // Renvoie 1 si le personnage arrive à la sortie
        return fini;
    }
    else if (m_personnage->m_i == m_ennemi->m_i && m_personnage->m_j == m_ennemi->m_j){
        fini = 2; // Renvoie 2 si l'ennemi attrape le personnage
        return fini;
    }
    return fini;

}

// Permet d'afficher le labyrinthe (avec le personnage et l'ennemi)
void Labyrinthe :: afficher() const {

    m_plateau->afficher(*m_personnage, *m_ennemi);
}


// Surcharge de l'opérateur "="
Labyrinthe& Labyrinthe::operator=(const Labyrinthe& other) {
    if (this != &other) { // Évite l'auto-affectation
        // Libérer les attributs existants
        delete m_plateau;
        delete m_personnage;
        delete m_sortie;
        delete m_ennemi;

        // Copier les attributs sans pointeurs
        m_nbl = other.m_nbl;
        m_nbc = other.m_nbc;

        // Copier les attributs avec pointeurs
        m_plateau = new Plateau(*other.m_plateau);
        m_personnage = new Personnage(*other.m_personnage);
        m_sortie = new Sortie(*other.m_sortie);
        m_ennemi = new Ennemi(*other.m_ennemi);
    }
    return *this;
}


