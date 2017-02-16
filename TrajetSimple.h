/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H


//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum MoyenTransport
{
	VOITURE=0, AVION, TRAIN, BATEAU, VELO, PIED, KAYAK, BUS
};//type énuméré qui décrit l'ensemble des moyen de transports permis par l'application


//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Défini le comportement d'un trajet simple, uniquement composé d'une ville de départ, d'arrivée et d'un moyen de transport
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	virtual int ToLog(string & sauvegarde, int count)const;
	
	virtual void Afficher()const;
	// Mode d'emploi : Affiche les attributs de l'objet selon le format <De $villeDepart à $villeArrive en $moyenT>
	//
	// Contrat :
	//

	virtual char* GetVilleDepart()const;
	// Mode d'emploi : retourne l'attribut villeDepart
	//
	// Contrat :
	//
    
	virtual char* GetVilleArrive()const;
	// Mode d'emploi : retourne l'attribut villeArrive
	//	
	// Contrat :
	//


	virtual Trajet * Copie()const; 
	// Mode d'emploi : renvoie un pointeur sur une copie en profondeur de l'objet courant
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi : non définie
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetSimple (const char * villeD, const char * villeA, const char * moyenTransport);
    // Mode d'emploi : recopie les paramètres dans les attributs correspondants. effectue la conversion char*->MoyenTransport
    //
    // Contrat : moyenTransport doit faire référence à un élément de l'énum MoyenTransport (en minuscule e.g. avion) sinon ce sera voiture par défault
    //

	TrajetSimple (const string villeD, const string villeA, const string moyenTransport);


	TrajetSimple();
	//Mode d'emploi : non défini
	//

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
   
    
    
    
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	string enumToString()const;
	void afficherEnum()const;
	// Mode d'emploi : affiche l'attribut moyenT de l'objet courant
	//
	// Contrat :
	//
	MoyenTransport stringToMoyenTransport(const char * moyen)const;
	// Mode d'emploi : renvoie le MoyenTransport qui correspond au paramètre moyen
	//
	// Contrat : moyen doit être en minuscule, si aucun MoyenTransport ne correspont, VOITURE est retourné par défault
	//
//----------------------------------------------------- Attributs protégés
	char * villeDepart;//la ville de départ du trajet
	char * villeArrive;//la ville d'arrivée
	MoyenTransport moyenT;//le moyen de transport utilisé

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H

