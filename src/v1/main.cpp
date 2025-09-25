#include "labyrinthe.hpp"
#include "plateau.hpp"
#include "personnage.hpp"
#include "objetgraphique.hpp"
#include "objetgraphiquefixe.hpp"
#include "objetgraphiquemobile.hpp"
#include "mur.hpp"
#include "couloir.hpp"
#include "sortie.hpp"

#include <iostream>

int main(){


    Labyrinthe l(11,11);
    l.afficher();

    char reponse;
	
    while (l.fini() == 0){

        cout << "Quelle action voulez-vous faire ? (d : droite, g : gauche, h : haut, b : bas)" << endl;
        cin >> reponse;

        switch (reponse) {

            case 'd' :
            try{
                l.deplacerPersoDroite();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
                l.afficher();
                break;

            case 'g' :
            try{
                l.deplacerPersoGauche();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
                l.afficher();
                break;

            case 'h' :
            try{
                l.deplacerPersoHaut();
            }catch (ExceptionMouvement& ex){
				cerr << ex.message << endl;
			}
                l.afficher();
                break;

            case 'b' :
                try{
                l.deplacerPersoBas();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
                l.afficher();
                break;

            default :
                cout << "Choix Invalide. Reessayez. \n";
        }
    }

    cout << "La partie est finie. Vous avez atteint la sortie." << endl;
}

