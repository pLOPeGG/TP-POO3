/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//Classe mère permettant le polymorphisme. Déclare des méthodes utilisées dans l'une de ses classes filles
//
//------------------------------------------------------------------------


class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual int ToLog(string & sauvegarde, int count)const=0;
	
	virtual Trajet * Copie()const=0;
	// Mode d'emploi : Renvoie un pointeur sur un Trajet ayant les meme caractéristiques que l'appelant (Copie)
	//					retour : pointeur sur la copie du trajet
	// Contrat :
	//
	virtual void Afficher()const =0;
	// Mode d'emploi : Affiche le Trajet courant
	//


	virtual char* GetVilleDepart()const =0;
	// Mode d'emploi : renvoie la ville de départ du trajet soit l'attribut villeDepart du premier trajet simple
	//
	// Contrat :
	//

	virtual char* GetVilleArrive()const =0;
	// Mode d'emploi : renvoie la ville d'arrivée du trajet soir l'attibut villeArrvie du dernier trajet simple
	//
	// Contrat :
	//
//------------------------------------------------- Surcharge d'opérateurs
	Trajet & operator =( const Trajet & unTrajet);
	//sans définition
//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
	


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

