/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE


//-------------------------------------------------------- Include système

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
//#define MAP
//------------------------------------------------------ Include personnel

#include "TrajetSimple.h"


//------------------------------------------------------------- Constantes

const char * moyenTransportDispo[]={"voiture","avion","train","bateau","velo","pied","kayak","bus"};
const MoyenTransport moyenTransportDispoEnum[]={VOITURE,AVION,TRAIN,BATEAU,VELO,PIED,KAYAK,BUS};

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
int TrajetSimple::ToLog(string & sauvegarde, int count)const
{
    sauvegarde+=enumToString();
    sauvegarde+=" ";

    int taille = strlen(villeArrive);

    stringstream ss ;
    ss<<taille;
    string tailleString=ss.str();

    sauvegarde+=tailleString;
    sauvegarde+=" ";
    sauvegarde+=villeArrive;
    sauvegarde+="|";
    count++;
    return count;

}

Trajet * TrajetSimple::Copie()const
// Algorithme :
//
{

	Trajet * retour = new TrajetSimple(*this);//copie de l'élément actuel par le constructeur de copie
	return retour;
		
}

void TrajetSimple::Afficher()const
// Algorithme :
//
{
	cout<<"De "<<villeDepart <<" à " <<villeArrive <<" en ";
	afficherEnum();//affichage du moyen de transport utilisé
}

char* TrajetSimple::GetVilleDepart()const
// Algorithme :
//
{
	return villeDepart;

}
    
    
char* TrajetSimple::GetVilleArrive()const
// Algorithme :
//
{
	return villeArrive;

}



//------------------------------------------------- Surcharge d'opérateurs
/*TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
	:Trajet()
// Algorithme :
//
{	
	#ifdef MAP
    	cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
	#endif
	villeDepart=new char[strlen(unTrajetSimple.villeDepart)+1];//+1 pour le caractère \0
	villeArrive=new char[strlen(unTrajetSimple.villeArrive)+1];//idem
	//allocation des chaines de caractères au plus juste	

	strcpy(villeDepart,unTrajetSimple.villeDepart);
	strcpy(villeArrive,unTrajetSimple.villeArrive);
	//copie en profondeur
	
	moyenT=unTrajetSimple.moyenT;

} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple (const char * villeD, const char * villeA,const char * moyen)
// Algorithme :
//
{
	#ifdef MAP
    	cout << "Appel au constructeur de <TrajetSimple>" << endl;
	#endif
	villeDepart=new char[strlen(villeD)+1];
	villeArrive=new char[strlen(villeA)+1];
	
	strcpy(villeDepart,villeD);
	strcpy(villeArrive,villeA);
	
	moyenT=this->stringToMoyenTransport(moyen);//conversion char*->MoyenTransport

} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple(const string villeD, const string villeA, const string moyenTransport)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    villeDepart=new char[villeD.length()+1];
    villeArrive=new char[villeA.length()+1];
    strcpy(villeDepart,villeD.c_str());
    strcpy(villeArrive,villeA.c_str());
    moyenT=this->stringToMoyenTransport(moyenTransport.c_str());


}



TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{	
	#ifdef MAP
    	cout << "Appel au destructeur de <TrajetSimple>" << endl;
	#endif
	delete[] villeDepart;
	delete[] villeArrive;

} //----- Fin de ~TrajetSimple



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void TrajetSimple::afficherEnum()const
// Algorithme :
//
{
	//VOITURE, AVION, TRAIN, BATEAU, VELO, PIED, KAYAK, BUS

	cout<<moyenTransportDispo[moyenT];

}

string TrajetSimple::enumToString()const
// Algorithme :
//
{
	//VOITURE, AVION, TRAIN, BATEAU, VELO, PIED, KAYAK, BUS

	string retour (moyenTransportDispo[moyenT]);
	return retour;

}

MoyenTransport TrajetSimple::stringToMoyenTransport(const char* moyen)const
// Algorithme :
//
{


	for(int i=0;i<8;i++)
    {
        if(strcmp(moyen,moyenTransportDispo[i])==0)
        {
            return moyenTransportDispoEnum[i];
        }
    }

	return moyenTransportDispoEnum[0];

}


	
	


