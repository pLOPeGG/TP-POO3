/*************************************************************************
                           ListeT  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeT> (fichier ListeT.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
//#define MAP
//------------------------------------------------------ Include personnel

#include "ListeT.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ListeT::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
unsigned int ListeT::Ajouter(Trajet * aAjouter)
// Algorithme :
//
{
	if(cardAct==cardMax)
	//le tableau est plein
	{
		this->ajuster();//la taille allouée est doublée
	}
	this->trajets[cardAct]=aAjouter;//copie de pointeurs !	
	cardAct++;
	return cardAct;
}

//------------------------------------------------- Surcharge d'opérateurs
/*ListeT & ListeT::operator = ( const ListeT & unListeT )
	
// Algorithme :
//
{
	
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
ListeT::ListeT ( const ListeT & unListeT )
	: cardAct (0), cardMax (unListeT.cardMax)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur de copie de <ListeT>" << endl;
	#endif
	trajets=new Trajet*[cardMax];
	for(unsigned int i=0;i<unListeT.cardAct;i++)
	{
		Ajouter(unListeT.trajets[i]->Copie());//copie en profondeur de chaque élément
	}


} //----- Fin de ListeT (constructeur de copie)


ListeT::ListeT ( )
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au constructeur de <ListeT>" << endl;
	#endif
	trajets = new Trajet*[CARD_MAX];
	cardAct=0;//liste vide
	cardMax = CARD_MAX;
} //----- Fin de ListeT


ListeT::~ListeT ( )
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au destructeur de <ListeT>" << endl;
	#endif
	unsigned int i;
	for(i=0;i<cardAct;i++)
	{
		delete trajets[i];//chaque élément est détruit
	}
	delete[] trajets;//le tableau est détruit
} //----- Fin de ~ListeT



unsigned int ListeT::GetCardAct()const
{
	return cardAct;
}

Trajet ** ListeT::GetTrajets()const
{
	return trajets;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


unsigned int ListeT::ajuster()
// Appelée quand cardAct=cardMax
{
	Trajet ** nouvtab= new Trajet *[cardMax*2];//double la taille
	Trajet ** deleteTab = trajets;//sauvegarde du poiteur de l'ancien tableau

	for(unsigned int i=0;i<cardMax;i++) 
	{
		nouvtab[i]=trajets[i];//copie des pointeurs
	}

	trajets=nouvtab;//l'objet courant est mis à jour
	delete[] deleteTab;//on détruit l'ancien tableau sans toucher à ses éléments
	cardMax=cardMax*2;//on double l'attribut pour correspondre au nouveu tableau alloué
	return cardMax;
}
