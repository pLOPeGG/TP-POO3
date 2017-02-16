/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H


//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "ListeT.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Catalogue permet de stocker des trajets
// et d'effectuer des recherches sur les éléments stockés.
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	bool LoadAll(const char* fichier);

    bool LoadType(const char* fichier, bool estSimple);

    bool LoadVille(const char * fichier,const string depart, const string arrive);

    bool LoadIntervalle(const char* fichier, int n, int m);

	bool SaveAll(const char* fichier)const;

    bool SaveType(const char* fichier, bool simple)const;

    bool SaveVille(const char* fichier,const string villeD,const string villeA)const;

    bool SaveIntervalle(const char* fichier,int n,int m)const;
	Catalogue RechercheSimple (const char * villeD, const char * villeA)const;
	//Mode d'emploi : 	paramètres : 	villeD : ville de départ de la recherche
	//									villeA : ville d'arrivée de la recherche
	//				  	retour : 		renvoie un catalogue qui contient une copie des trajets uniques correspondant à la recherche
	//Affiche le catalogue retourné sur la sortie standard
	//l'ordre dans le catalogue de retour est aléatoire.
	//Contrat : Prend en compte la casse sur les ville : "Lyon" et "lyon" sont deux villes diffrentes.


	Catalogue RechercheCompose(const char * villeD, const char * villeA)const;
	//Mode d'emploi : 	paramètres : 	villeD : ville de départ de la recherche
	//									villeA : ville d'arrivée de la recherche
	//				  	retour : 		renvoie un catalogue qui contient une copie des trajets composées ou uniques correspondant à la recherche
	//Affiche le catalogue retourné sur la sortie standard
	//Les trajets du catalogue de retour ne contiennent pas de boucle et ne repassent jamais deux fois par la même ville (sauf si villeD==villeA alors cette ville est exemptée 
	//	et peut être traversée deux fois). NB : pour un trajet composé, les villes intermédiaires ne comptent pas.
	//l'ordre dans le catalogue de retour est aléatoire.
	//Contrat : Prend en compte la casse sur les villes : "Lyon" et "lyon" sont deux villes diffrentes.


    virtual void Afficher()const;
	// Mode d'emploi :	Affiche l'ensemble des trajets contenus dans le catalogue ligne par ligne.
	//
	// Contrat :
	//
    
    void AjouterTrajet(Trajet * unTrajet);
	// Mode d'emploi : paramètre :		unTrajet : pointeur sur le trajet que l'on souhaite ajouter au catalogue
	//
	// Contrat : pointeur initialisé
	//
//------------------------------------------------- Surcharge d'opérateurs
	Catalogue & operator = ( const Catalogue & unCatalogue );
	// Sans définition
	//
	//
	//

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue ( );
    // Mode d'emploi : (constructeur vide)
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :	(destructeur)
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	bool ArriveeNonInclue (const ListeT & tableauPassage, const char * ville) const;
	// Mode d'emploi : 	paramètres :	tableauPassage : référence d'une listeT qui contient (ou non) des trajets
	//									ville : une chaine de caractères représentant un ville
	// 					retour : 		booléen true si ville n'est pas présent dans tableauPassage en tant que ville d'arrivée
	//											false sinon
	// Contrat :
	//
	void rechercheRecursiveBoucle (const char * depart, const char * arrive, ListeT & tabPassage, Catalogue & leCatalogue)const;
	// Mode d'emploi : fonction récursive.
	// 					paramètres : 	depart, arrive : villes de départ et d'arrivée
	//									tabPassage : conteneur des trajets de leCatalogue qui ont pour villeDepart le parametre depart
	//									leCatalogue : catalogue qui contient les trajets qui satisfont la ville d'arrivée.
	// Contrat :	initialement depart==arrive : le trajet recherché est une boucle
	//
	void rechercheRecursive (const char * origine, const char * depart, const char * arrive, ListeT & tabPassage, Catalogue & leCatalogue)const;
	// Mode d'emploi : fonction récursive.
	// 					paramètres : 	origine : ville d'origine de la recherche (différent de depart après une itération)
	// 							depart, arrive : villes de départ et d'arrivée
	//							tabPassage : conteneur des trajets de leCatalogue qui ont pour villeDepart le parametre depart
	//							leCatalogue : catalogue qui contient les trajets qui satisfont la ville d'arrivée.
	// Contrat :	initialement depart!=arrive : le trajet recherché n'est pas une boucle
	//
//----------------------------------------------------- Attributs protégés
	ListeT trajetsProposes; 	//conteneur des Trajets.
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H

