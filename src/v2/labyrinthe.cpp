#include "labyrinthe.hpp"
#include "personnage.hpp"
#include "sortie.hpp" 
#include <cstdlib> // pour avoir acc�s � la biblioth�que random
#include <string> // pour avoir acc�s aux cha�nes de caract�re (type string)


// Constructeur par d�faut
Labyrinthe :: Labyrinthe(){ 

    m_nbc = 3;
    m_nbl = 3;
	m_plateau = new Plateau();
    m_personnage = new Personnage(1,0);
    m_sortie = new Sortie(2,0);
    m_ennemi = new Ennemi(1,2);

}

// Constructeur param�tr� pour un plateau de taille (11,11)
Labyrinthe :: Labyrinthe(int l , int c){

    m_nbl = l;
    m_nbc = c;
    m_plateau = new Plateau(m_nbl,m_nbc);
    m_personnage = new Personnage(1,6);
    m_sortie = new Sortie(m_nbl-1,7);
    m_ennemi = new Ennemi(5,8);
}

// Constructeur de Labyrinthe � partir d'un fichier
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


// Permet de v�rifier si un d�placement du personnage � droite est possible
void Labyrinthe :: deplacerPersoDroite(){

    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j +1)->getType(); // On obtient le type de la case � droite du personnage pour v�rifier s'il peut se d�placer

    if ((m_personnage->m_i == m_ennemi->m_i) && (m_personnage->m_j +1 == m_ennemi->m_j)){ // On consid�re que le personnage ne peut pas se d�placer de lui-m�me vers l'ennemi
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}
	
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present."); // Renvoie un message d'erreur si un mur est pr�sent � droite du personnage
	}
	
	// On v�rifie que la case � droite du personnage est bien un couloir ou la sortie
    if((type == 2 || type == 3) && ((m_personnage->m_i != m_ennemi->m_i) || (m_personnage->m_j +1 != m_ennemi->m_j))) {
        m_personnage->deplacerDroite();

	}

}

// Permet de v�rifier si un d�placement du personnage � gauche est possible
void Labyrinthe :: deplacerPersoGauche(){

    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j-1)->getType(); // On obtient le type de la case � gauche du personnage pour v�rifier s'il peut se d�placer

    if ((m_personnage->m_i == m_ennemi->m_i) && (m_personnage->m_j -1 == m_ennemi->m_j)){ // On consid�re que le personnage ne peut pas se d�placer de lui-m�me vers l'ennemi
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}
	// On v�rifie que la case � gauche du personnage est bien un couloir ou la sortie
    if((type == 2 || type == 3) && ((m_personnage->m_i != m_ennemi->m_i) ||(m_personnage->m_j -1 != m_ennemi->m_j))) {
        m_personnage->deplacerGauche();
	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present."); // Renvoie un message d'erreur si un mur est pr�sent � gauche du personnage
	}

}


// Permet de v�rifier si un d�placement du personnage en haut est possible
void Labyrinthe :: deplacerPersoHaut(){

    int type = m_plateau->getCase(m_personnage->m_i-1,m_personnage->m_j)->getType(); // On obtient le type de la case en haut du personnage pour v�rifier s'il peut se d�placer

    if ((m_personnage->m_i -1 == m_ennemi->m_i) && (m_personnage->m_j == m_ennemi->m_j)){ // On consid�re que le personnage ne peut pas se d�placer de lui-m�me vers l'ennemi
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}
	// On v�rifie que la case en haut du personnage est bien un couloir ou la sortie	
    if((type == 2 || type == 3) && ((m_personnage->m_i -1 != m_ennemi->m_i) || (m_personnage->m_j != m_ennemi->m_j))) {
        m_personnage->deplacerHaut();
	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present."); // Renvoie un message d'erreur si un mur est pr�sent en haut du personnage
	}
}

// Permet de v�rifier si un d�placement du personnage en bas est possible
void Labyrinthe :: deplacerPersoBas(){

    int type = m_plateau->getCase(m_personnage->m_i+1,m_personnage->m_j)->getType(); // On obtient le type de la case en bas du personnage pour v�rifier s'il peut se d�placer

    if ((m_personnage->m_i +1 == m_ennemi->m_i) && (m_personnage->m_j == m_ennemi->m_j)){ // On consid�re que le personnage ne peut pas se d�placer de lui-m�me vers l'ennemi
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present."); 
	}
    // On v�rifie que la case en bas du personnage est bien un couloir ou la sortie
    if((type == 2 || type == 3) && ((m_personnage->m_i +1 != m_ennemi->m_i) || (m_personnage->m_j != m_ennemi->m_j))) {
        m_personnage->deplacerBas();
	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present."); // Renvoie un message d'erreur si un mur est pr�sent en bas du personnage
	}
}

// M�thode qui permet de d�placer l'ennemi de mani�re al�atoire � un emplacement valide (un couloir)
void Labyrinthe :: deplacerEnnemi(){

	int random; // Entier qui sert � d�terminer une direction al�atoire
	int booleen = 0;

	while (booleen == 0) { // Tant que booleen = 0, la direction d�termin�e al�atoirement n'est pas valide pour d�placer l'ennemi. On r�it�re jusqu'� ce que booleen soit diff�rent de 0.

        random = rand() %4; // On applique un modulo 4 pour choisir une des quatre directions au hasard

        if(random == 0){ // Mouvement � droite
            int type = m_plateau->getCase(m_ennemi->m_i,m_ennemi->m_j +1)->getType(); // On obtient le type de la case � droite de l'ennemi

            if(type == 2) { // Si la case � droite de l'ennemi est un couloir, on le d�place
                m_ennemi->deplacerDroite();
                booleen = 1; // Le booleen est diff�rent de 0 donc le d�placement est valide, on appelle la m�thode deplacerDroite() de la classe ObjetGraphiqueMobile
            }
        }

        else if(random == 1){ // Mouvement � gauche
            int type = m_plateau->getCase(m_ennemi->m_i,m_ennemi->m_j -1)->getType(); // On obtient le type de la case � gauche de l'ennemi

            if(type == 2) { // Si la case � gauche de l'ennemi est un couloir, on le d�place
                m_ennemi->deplacerGauche();
                booleen = 1; // Le booleen est diff�rent de 0 donc le d�placement est valide, on appelle la m�thode deplacerGauche() de la classe ObjetGraphiqueMobile
            }
        }

        else if(random == 2){ // Mouvement en haut
            int type = m_plateau->getCase(m_ennemi->m_i-1,m_ennemi->m_j)->getType(); // On obtient le type de la case en haut de l'ennemi

            if(type == 2) { // Si la case en haut de l'ennemi est un couloir, on le d�place
                m_ennemi->deplacerHaut();
                booleen = 1; // Le booleen est diff�rent de 0 donc le d�placement est valide, on appelle la m�thode deplacerHaut() de la classe ObjetGraphiqueMobile
            }

        }

        else if(random == 3){ // Mouvement en bas
            int type = m_plateau->getCase(m_ennemi->m_i+1,m_ennemi->m_j)->getType(); // On obtient le type de la case en bas de l'ennemi

            if(type == 2) { // Si la case en bas de l'ennemi est un couloir, on le d�place
                m_ennemi->deplacerBas(); // Le booleen est diff�rent de 0 donc le d�placement est valide, on appelle la m�thode deplacerBas() de la classe ObjetGraphiqueMobile
                booleen = 1;
            }

        }
	}


}

//  Renvoie l'�tat de la partie
int Labyrinthe :: fini() const{

	int fini = 0; // Renvoie 0 tant que la partie continue 
    if(m_personnage->m_i == m_sortie->m_i && m_personnage->m_j == m_sortie->m_j){
        fini = 1; // Renvoie 1 si le personnage arrive � la sortie
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


// Surcharge de l'op�rateur "="
Labyrinthe& Labyrinthe::operator=(const Labyrinthe& other) {
    if (this != &other) { // �vite l'auto-affectation
        // Lib�rer les attributs existants
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


