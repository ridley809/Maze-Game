#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#include "objetgraphiquefixe.hpp"
#include "objetgraphiquemobile.hpp"


#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>

using namespace std;


class Plateau {

    protected :
    	
        int m_nbl;
        int m_nbc;
        ObjetGraphiqueFixe ***m_plateau;

    public :
    	
    	// Constructeurs/Destructeurs : 
    	
        Plateau();                            // Constructeur par défaut
        Plateau(const Plateau& p);            // Constructeur de copie
        Plateau(int l , int c);               // Constructeur paramétré
        Plateau(string chaine, int &l, int &c,int&p_i, int &p_j, int& e_i, int& e_j, int& s_i, int& s_j);  // Constructeur pour lire les fichiers
        ~Plateau();  						  // Destructeur
        
        
		// Méthodes :
		
        void setCase(int i, int j, ObjetGraphiqueFixe* o);
        ObjetGraphiqueFixe* getCase(int i, int j) const;
        void afficher() const;
        void afficher(ObjetGraphiqueMobile& p,ObjetGraphiqueMobile& e) const; 
        void taillePlateauFichier(string chaine, int &nbl, int &nbc) const; 
		void VerificationPlateauFichier(string chaine, int l, int c) const;
};

// Classe d'exceptions pour gérer les déplacements interdits
class ExceptionFormat{
	
 	public:
 		
 		string message;
 		ExceptionFormat(string m =""){message=m;}
};

class ExceptionOuvertureFichier{
	
	public:
		
		string message;
		ExceptionOuvertureFichier(string m =""){message=m;}
};


#endif
