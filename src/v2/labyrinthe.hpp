#ifndef _LABYRINTHE_HPP_
#define _LABYRINTHE_HPP_

#include "plateau.hpp"
#include "personnage.hpp"
#include "ennemi.hpp"
#include "sortie.hpp"

using namespace std;

class Labyrinthe{

    protected :

        int m_nbl, m_nbc; // Dimension du labyrinthe
        Plateau* m_plateau; 
        Personnage* m_personnage;
        Ennemi* m_ennemi;
        Sortie* m_sortie;


    public :

        // Constructeurs/Destructeurs :
        
        Labyrinthe();                   //Constructeur par d�faut
        Labyrinthe(int l, int c);       // Constructeur param�tr�
        Labyrinthe(string chaine);      // Constructeur pour les fichiers
        Labyrinthe(const Labyrinthe&l); // Constructeur de recopie
        ~Labyrinthe();                  // Destructeur
	
        // Methodes :
        
        void deplacerPersoDroite();
        void deplacerPersoGauche();
        void deplacerPersoHaut();
        void deplacerPersoBas();
		void deplacerEnnemi();
        int fini() const;
        void afficher() const;
        
        // Surcharge de l'op�rateur "=" :
        
        Labyrinthe& operator=(const Labyrinthe& other);
};

// Classe d'exceptions pour g�rer les d�placements interdits
class ExceptionMouvement{
	
 	public:
 		
 		string message;
 		ExceptionMouvement(string m =""){message=m;}
};


#endif
