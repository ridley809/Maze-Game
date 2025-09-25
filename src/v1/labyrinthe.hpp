#ifndef _LABYRINTHE_HPP_
#define _LABYRINTHE_HPP_

#include "plateau.hpp"
#include "personnage.hpp"

#include "sortie.hpp" //peut etre a enlever

using namespace std;

class Labyrinthe{

    protected :

        int m_nbl, m_nbc;
        Plateau* m_plateau;
        Personnage* m_personnage;
        Sortie* m_sortie;

        // methodes :

    public :

        // constructeur :
        Labyrinthe();
        Labyrinthe(int l,int c);
        Labyrinthe(const Labyrinthe&l);
 		Labyrinthe (char* chaine, int l, int c);// constructeur fichiers
        ~Labyrinthe(); //Destructeur

        // methodes :
        void afficher() const;
        void deplacerPersoDroite();
        void deplacerPersoGauche();
        void deplacerPersoHaut();
        void deplacerPersoBas();
        bool fini() const;
        bool EstDansPlateau(int i, int j) const;
};

class ExceptionMouvement{
 public:
 string message;
 ExceptionMouvement(string m =""){message=m;}
};


#endif

