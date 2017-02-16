/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeT.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//Défini la succession de plusieurs trajets, simples ou composés.
//donne des méthodes équivalentes à celles de la classe TrajetSimple pour une succession de Trajets
//Tout TrajetCompose se doit d'être continu : l'arrivée d'un trajet est identique au départ du trajet suivant
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
	//Mode d'emploi :
	//
	// Contrat :
	//
	virtual int ToLog(string & sauvegarde, int count)const;

	virtual void Afficher()const;
	//Mode d'emploi : Affiche les Trajets contenus dans l'attribut compositionTrajet selon le format <[ AffichageTrajet1 - AffichageTrajet2 - ... - AffichageTrajetN ]>
	//	où AffichageTrajetI est l'affichage du Ième trajet de compositionTrajet
	// Contrat :
	//

	virtual char* GetVilleDepart()const;
	//Mode d'emploi : renvoie la ville de départ du trajet, c'est à dire l'attribut villeDepart du premier TrajetSimple
	//
	// Contrat :
	//
	
	virtual char* GetVilleArrive()const;
	//Mode d'emploi : renvoie la ville d'arrivée du trajet, c'est à dire l'attribut villeArrive du dernier TrajetSimple
	//
	// Contrat :
	//
	
	bool AjouterTrajet(Trajet * unTrajet);
	//Mode d'emploi : Ajoute le paramètre à l'attribut compositionTrajet de l'objet courant
	//	retour  : true si le paramètre est ajouté, false si la continuité n'était pas vérifiée et que le paramètre est réfusé.
	//
	// Contrat : le trajet doit rester continu même après l'ajout : le paramètre n'est ajouté à compositionTrajet que si la ville d'arrivée de l'objet courant avant ajout
	//	est indentique à la ville de départ du paramètre.
	
	virtual Trajet * Copie()const;
	//Mode d'emploi : renvoie un pointeur sur une copie en profondeur de l'objet courant
	//
	// Contrat :
	//

	
//------------------------------------------------- Surcharge d'opérateurs
    TrajetCompose & operator = ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi : non défini
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

	TrajetCompose (const ListeT & uneListeT);
	//Mode d'emploi : construit un trajet en copiant un objet ListeT fourni en paramètre
	//
	// Contrat : ATTENTION : aucune vérification sur la continuité du trajet !
	//	la continuité du paramètre doit être vérifiée auparavent !
	//

    TrajetCompose ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	ListeT compositionTrajet;//conteneur de pointeur sur des Trajets
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H

