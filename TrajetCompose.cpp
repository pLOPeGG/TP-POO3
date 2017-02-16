/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//#define MAP
#include <iostream>
#include <cstring>
using namespace std;
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Trajet * TrajetCompose::Copie()const
// Algorithme : méthode récursive : copie de tous les éléments de l'attribut compositionTrajet
//
{
	TrajetCompose * retour = new TrajetCompose();

	Trajet ** tableauTrajet = compositionTrajet.GetTrajets();
	unsigned int nombreElt = compositionTrajet.GetCardAct();
	//on récupère les attributs de compositionTrajet	
	
	for(unsigned int i=0;i<nombreElt;i++)//pour chaque élément
	{
		retour->AjouterTrajet(tableauTrajet[i]->Copie());//copie en profondeur de l'élément
		
	}	
	return retour;
	
}

int TrajetCompose::ToLog(string &sauvegarde,int count) const
{
	Trajet ** tableauTrajet = compositionTrajet.GetTrajets();
	unsigned int nombreElt = compositionTrajet.GetCardAct();

	for(unsigned int i=0;i<nombreElt;i++)
	{
		count=tableauTrajet[i]->ToLog(sauvegarde,count);
	}

	return count;
}


void TrajetCompose::Afficher()const
// Algorithme :
//
{
	Trajet ** tableauTrajet = compositionTrajet.GetTrajets();
	unsigned int nombreElt = compositionTrajet.GetCardAct();


	cout<<"[";//les crochets indiquent un trajet composé	
	for(unsigned int i=0;i<nombreElt;i++)
	{
		tableauTrajet[i]->Afficher();
		if(i!=nombreElt-1)
		{
			cout<<" - ";
		}
	}
	cout<<"]";//fin du trajet composé		
}

char * TrajetCompose::GetVilleDepart()const
// Algorithme :
//
{
	return compositionTrajet.GetTrajets()[0]->GetVilleDepart();//la ville de départ du premier élément
}

char * TrajetCompose::GetVilleArrive()const
// Algorithme :
//
{
	
	return compositionTrajet.GetTrajets()[compositionTrajet.GetCardAct()-1]->GetVilleArrive();//la ville d'arrivée du dernier élément
}


bool TrajetCompose::AjouterTrajet(Trajet * unTrajet)
// Algorithme :
//
{
	if(compositionTrajet.GetCardAct()==0 || strcmp(compositionTrajet.GetTrajets()[compositionTrajet.GetCardAct()-1]->GetVilleArrive(),unTrajet->GetVilleDepart())==0)
	//vérification de la continuité dans le cas où l'objet courant est non trivial
	{
		compositionTrajet.Ajouter(unTrajet);
		return true;
	}
	else
	//on refuse d'ajouter
	{
		cerr<<"Trajet invalide"<<endl;
		return false;
	}
}



//------------------------------------------------- Surcharge d'opérateurs
/*
TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
	:Trajet(), compositionTrajet (unTrajetCompose.compositionTrajet)
// Algorithme :
//
{
	#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
	#endif
	

} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose ( )
	:compositionTrajet ()
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose (const ListeT & uneListeT)
	: compositionTrajet (uneListeT)
{
#ifdef MAP
    cout << "Appel au constructeur par ListeT de <TrajetCompose>" << endl;
#endif
}
			


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
}


//----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

