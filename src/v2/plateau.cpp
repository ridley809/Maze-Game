#include "plateau.hpp"
#include "labyrinthe.hpp"
#include "mur.hpp"
#include "couloir.hpp"
#include "sortie.hpp"
#include "ennemi.hpp"

#include <fstream>
#include <string>


// Constructeur par défaut
Plateau :: Plateau(){
	
	m_nbl = 4;
    m_nbc = 4;
    m_plateau = new ObjetGraphiqueFixe**[m_nbl];
    // Crée un plateau de dimension (4,4) avec que des murs (arbitraire)
    
    for (int i =0; i<m_nbl; i++){
        m_plateau[i] = new ObjetGraphiqueFixe*[m_nbc];
    }
    
    for(int i = 0; i<m_nbl; i++){
        for(int j=0; j<m_nbc; j++){
        	setCase(i,j,new Mur(i,j));
    	}
	}
}


// Constructeur paramétré
Plateau :: Plateau(int l, int c){
	
    m_nbl = l;
    m_nbc = c;
    m_plateau = new ObjetGraphiqueFixe**[m_nbl];

    for (int i = 0; i<m_nbl; i++){
        m_plateau[i] = new ObjetGraphiqueFixe*[m_nbc];
    }

    for(int i = 0; i<m_nbl; i++){
        for(int j=0; j<m_nbc; j++){
                if(i==0 || i==m_nbl-1 || j==0 || j==m_nbc-1){
                    setCase(i,j,new Mur(i,j));
                }
                else if(i==2 && j!=2 && j!= 6 &&j!=8){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(i==4 && j!=1 && j!= 7 && j!= 10){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(i==6 && j!=7&& j!= 3 && j!= 5&& j!= 9){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(i==8 && j!=2 && j!= 9){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(i==8 && j!=2 && j!= 9){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(j==8 && (i==5|| i ==6 || i== 7 || i ==8 || i==9)){
                	  setCase(i,j, new Mur(i,j));
				}
                else{
                    setCase(i,j, new Couloir(i,j));
                }
        }
    }

    setCase(m_nbl-1,7, new Sortie(m_nbl-1,7));
}

// Constructeur pour les fichiers
Plateau :: Plateau(string chaine, int& l, int &c, int &p_i, int& p_j, int &e_i, int &e_j, int& s_i, int& s_j){
	
    int Perso_i, Perso_j, Sortie_i, Sortie_j, Ennemi_i, Ennemi_j;
    m_nbl = l;
    m_nbc = c;
    string m_chaine = chaine;
    m_plateau = new ObjetGraphiqueFixe**[m_nbl];

    for (int i = 0; i<m_nbl; i++){
        m_plateau[i] = new ObjetGraphiqueFixe*[m_nbc];
    }

    ifstream ifs(m_chaine.c_str());
    if(!ifs){
    	cout << "Probleme d'ouverture fichier" << endl;
        throw ExceptionOuvertureFichier (""); // Message d'erreur s'il y a un problème d'ouverture
    }

    else{	
		VerificationPlateauFichier(m_chaine, m_nbl, m_nbc);		
		string ligne;
        int i = 0;
    	while(getline(ifs, ligne)){ // Utilisation de getline pour obtenir chaque ligne de notre fichier
			for(int j=0;j<m_nbc; j++){ // Parcours de chaque ligne pour accéder à tous les caractères du fichier
				if(ligne[j] == '#'){
					setCase(i,j, new Mur(i,j)); // Mur
				}
				else if(ligne[j] == '2'){
					setCase(i,j, new Couloir(i,j)); // Couloir
				}
				else if(ligne[j] =='P') {
					setCase(i,j, new Couloir(i,j)); // Le personnage est placé sur un couloir
					// On précise les coordonnées du personnage
					p_i = i; 
					p_j = j;
				}
				else if(ligne[j] =='S') {
					setCase(i,j, new Sortie(i,j));
					s_i = i;
					s_j = j;
				}
				else if(ligne[j] =='E') {
					setCase(i,j, new Couloir(i,j)); // L'ennemi est placé sur un couloir
					// On précise les coordonnées de l'ennemi
					e_i = i;
					e_j = j;
				}
			}
			i++;
		}
		
	}
    ifs.close(); // Fermeture du fichier
}



// Constructeur de recopie
Plateau :: Plateau(const Plateau& p){
	
	m_nbl = p.m_nbl;
	m_nbc = p.m_nbc;
    m_plateau = new ObjetGraphiqueFixe**[m_nbl];
    
    for (int i = 0; i<m_nbl; i++){
        m_plateau[i] = new ObjetGraphiqueFixe*[m_nbc];
    }
    for(int i = 0; i<m_nbl; i++){
        for(int j=0; j<m_nbc; j++){
        	m_plateau[i][j] = p.m_plateau[i][j];
    	}
	}
}


// Destructeur
Plateau :: ~Plateau(){
	
	for(int i = 0; i<m_nbl; i++){
		delete[] m_plateau[i]; // On désaloue la mémoire de toutes les lignes du plateau
	}
	delete[] m_plateau; // On désaloue le plateau

}

// Vérifie le bon format du plateau (avec des murs tout autour à part la sortie)
void Plateau :: VerificationPlateauFichier(string chaine, int l, int c) const{
	
	ifstream ifs(chaine.c_str());
	int compteur_mur = 0;
	string ligne;
        int i = 0;
    	while(getline(ifs, ligne)){ // Utilisation de getline pour obtenir chaque ligne de notre fichier
			for(int j=0;j<m_nbc; j++){ // Parcours de chaque ligne pour accéder à tous les caractères du fichier
				if((i == 0 || i == l - 1 || j == 0 || j == c - 1) && (ligne[j] == '#')){
					compteur_mur++; // On incrémente le compteur pour chaque mur sur les bords du labyrinthe
				}
			}
			i++;
		}
	int nb_bords = 2*l + 2*c - 4 - 1;
	if (compteur_mur != nb_bords){
		cout << "Votre labyrinthe ne respecte pas le format conventionnel. Rajoutez des murs sur les bords." << endl;
    	throw ExceptionFormat("");
	}
    
}

// Permet d'obtenir la dimension (nombre de lignes et colonnes) du plateau
void Plateau :: taillePlateauFichier(string chaine, int &nbl, int &nbc) const{
	
	ifstream ifs(chaine.c_str());
	nbl = 0;

	string ligne;
	while(getline(ifs, ligne)){
		nbl = nbl + 1; // Pour savoir combien de fois on change de lignes (nombre de lignes)
		if(nbl == 1){ // On sélectionne une ligne au hasard car toutes les lignes ont le même nombre de caractères
			nbc = ligne.length(); // Nombre de caractères dans une ligne, donc nombre de colonnes
		}
	}
	ifs.close();
}


// Modifie une case du plateau (par exemple rempacler un mur par 
void Plateau :: setCase(int i, int j, ObjetGraphiqueFixe* o){
    m_plateau[i][j] = o;
}

// Pour obtenir un pointeur vers un objet graphique fixe (Couloir, Mur, Sortie)
ObjetGraphiqueFixe* Plateau :: getCase(int i, int j) const{
    if ((i >= 0) && (i < m_nbl) && (j >= 0) && (j < m_nbc)) {
        return m_plateau[i][j];
    } else {
        return NULL;
    }
}


// Affiche le plateau avec le personnage et l'ennemi
void Plateau :: afficher(ObjetGraphiqueMobile&p,ObjetGraphiqueMobile&e ) const{

    int l = p.getI();
    int c = p.getJ();
	int l1 = e.getI();
    int c1 = e.getJ();
        for(int i = 0; i<m_nbl; i++){
            for(int j=0; j<m_nbc; j++){
            	
            	if(i == l1 && c1==j && e.getType() == 5){
                    e.afficher();
                    }
                else if(i == l && c==j && p.getType() == 4){
                    p.afficher();
                    }
                else{
                    getCase(i,j)->afficher();
                }

            }
            cout << endl;
        }
}

// Affiche le plateau avec uniquement les objets graphiques fixes 
void Plateau :: afficher() const{
	
    for(int i = 0; i<m_nbl; i++){
        for(int j=0; j<m_nbc; j++){
            getCase(i,j)->afficher();
        }
        cout << endl;
    }

}
