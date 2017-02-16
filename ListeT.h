/*************************************************************************
                           ListeT  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeT> (fichier ListeT.h) ----------------
#if ! defined ( LISTET_H )
#define LISTET_H
#include "Trajet.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
	const unsigned int CARD_MAX = 5;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeT>
//Structure de données : tableaux dynamique de Trajet *
//Offre des méthode pour ajouter des éléments au tableau et lire les données stockées.
//------------------------------------------------------------------------

class ListeT
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    unsigned int Ajouter( Trajet * aAjouter);
	// Mode d'emploi : Ajoute le pointeur sur trajet fourni en paramètre au tableau trajets de l'objet courant
	//					param :l'élément à ajouter
	//					retour : le nombre d'éléments stockés après ajout.
	// Contrat : pointeur initialisé et non déjà présent dans un conteneur.
	//

	unsigned int GetCardAct()const;
	//Mode d'emploi : Renvoie l'attribut cardAct soit le nombre d'éléments stockés actuellement
	//


	Trajet ** GetTrajets()const;
	//Mode d'emploi : Renvoie l'attribut trajets soit le tableau contenant les pointeurs vers les trajets stockés
	//

//------------------------------------------------- Surcharge d'opérateurs
    ListeT & operator = ( const ListeT & unListeT );
    // Sans définition
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ListeT ( const ListeT & unListeT );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ListeT ( );
    // Mode d'emploi : (constructeur par défault) Liste vide initiallement
    //
    // Contrat :
    //

    virtual ~ListeT ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
	


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	unsigned int ajuster();
	// Mode d'emploi : double la taille allouée du tableau trajets sans perte d'éléments
	//					retour : la taille allouée après augmentation de la taille
	// Contrat :
	//
	
//----------------------------------------------------- Attributs protégés
	unsigned int cardAct;//nombre de pointeurs actuellement stockés
	unsigned int cardMax;//taille actuellement allouée
	Trajet ** trajets;//tableau de pointeurs sur trajets
};

//-------------------------------- Autres définitions dépendantes de <ListeT>

#endif // LISTET_H

