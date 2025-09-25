// On inclut tous les fichiers .hpp
#include "labyrinthe.hpp"
#include "plateau.hpp"
#include "personnage.hpp"
#include "objetgraphique.hpp"
#include "objetgraphiquefixe.hpp"
#include "objetgraphiquemobile.hpp"
#include "mur.hpp"
#include "couloir.hpp"
#include "sortie.hpp"

// Bibliothèques utiles dans ce programme
#include <iostream> // Pour cout, cin, endl
#include <fstream> 	// Pour manipuler des fichiers 
#include <string> 	// Pour utiliser le type string (chaîne de caractères)

	

int main(){ 

    // Si vous voulez tester les constructeurs par défaut, paramétrés et de recopie pour notre labyrinthe, enlevez les commentaires juste en dessous :
    
    /*
    Labyrinthe l(11,11);
    cout<<"Labyrinthe 1 : \n";
    l.afficher();
    
    // Constructeur par défaut
	Labyrinthe l2;
    cout<<"Labyrinthe 2 : \n";
    l2.afficher();
    
    Labyrinthe l3;
    cout<<"Labyrinthe 3 apres copie du labyrinthe 1 : \n";
    l3 = l;
    l3.afficher();
    */
    
    Labyrinthe l;
    int preference;
    int booleen = 0;
    
    cout << "Preferez-vous  :\n1 : Utiliser le labyrinthe de dimension (11,11) parametre dans labyrinthe.cpp \n2 : Selectionner un fichier pour importer le labyrinthe" << endl;
    cin >> preference;
    
    while (booleen == 0){
    	
    	if (preference == 1){
    		l = Labyrinthe(11,11);
    		cout << "Voici le labyrinthe : \n";
    		l.afficher();
    		booleen = 1;
		}
		else if (preference == 2){
			string chaine;
			cout << "Entrez le nom du fichier :" << endl;
			cin >> chaine;
			l = Labyrinthe(chaine);
			cout << "Voici le labyrinthe : \n";
			l.afficher();
			booleen = 1;
		}
		else{
			cout << "Erreur de saisie. Recommencez en saisissant 1 ou 2 : " << endl;
			cin >> preference;
		}
	}
	
	
    char reponse; // Réponse de l'utilisateur concernant le déplacement choisi pour le personnage
    while (l.fini() == 0){ // Tant que la partie n'est pas terminée

        cout << "Quelle action voulez-vous faire ? (d : droite, g : gauche, h : haut, b : bas)" << endl;
        cin >> reponse;

        switch (reponse) { // En fonction de la réponse, on adapte le déplacement

            case 'd' :
            try{
                l.deplacerPersoDroite();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
            // Déplacement ennemi :
            try{
                l.deplacerEnnemi();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
				cout<<"Apres deplacement Ennemi : \n";
				l.afficher();
                break;

            case 'g' :
            try{
                l.deplacerPersoGauche();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
            // Déplacement ennemi :
            try{
                l.deplacerEnnemi();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
				cout<<"Apres deplacement Ennemi : \n";
                l.afficher();
                break;

            case 'h' :
            try{
                l.deplacerPersoHaut();
            }catch (ExceptionMouvement& ex){
				cerr << ex.message << endl;
			}
            // Déplacement ennemi :
            try{
                l.deplacerEnnemi();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
				cout<<"Apres deplacement Ennemi : \n";
                l.afficher();
                break;

            case 'b' :
                try{
                l.deplacerPersoBas();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
            // Déplacement ennemi :
            try{
                l.deplacerEnnemi();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
				cout<<"Apres deplacement Ennemi : \n";
                l.afficher();
                break;

            default :
                cout << "Choix Invalide. Reessayez. \n"; // Si l'utilisateur ne saisit pas un caractère valide, un message d'erreur lui est envoyé pour qu'il entre une lettre de nouveau
        }
    }
	
	// Deux moyens pour que la partie soit terminée : le personnage atteint la sortie ou l'ennemi attrape le personnage
	if(l.fini() == 1){
		cout << "La partie est finie. Vous avez atteint la sortie." << endl;

	}
	else if(l.fini() == 2){
		cout << "Vous avez Perdu. L'ennemi vous a trouve " << endl;

	}
} 



	

