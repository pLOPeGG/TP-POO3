


#include <iostream>
#include <cstring>
#include <string>

#include "Trajet.h"
#include "TrajetSimple.h"
//#include "ListeT.h"
#include "TrajetCompose.h"
#include "Catalogue.h"


using namespace std;

void Interface(Catalogue * catalogueUtile, bool * arreter);
//Mode d'emploi : prend en paramètre un pointeur sur le catalogue sur lequel on souhaite effectuer des opérations et un pointeur sur un booléen initialement à false


void AffichageBienvenue();
//Mode d'emploi : Affiche le manuel de l'interface

int main() {
    bool endOfInterface = false;
    Catalogue cataloguePrincipal;

   	AffichageBienvenue();
    while(!endOfInterface)//on boucle tant qu'on le souhaite
    {
        Interface(&cataloguePrincipal,&endOfInterface);
    }
    return 0;
}

void AffichageBienvenue()
// Algorithme :
//
{
	cout<<	"***********************************************************************************************************************\n"
	"Bienvenue dans l'interface d'utilisation du catalogue\n"
	"\tCommandes possibles : \n"
	"Affichage : PRINT\n"
    "AjoutSimple : AS <villeDepart> <villeArrive> <moyenTransport> \n"
    "AjoutComplexe : AC <villeDepart> <villeArrive> <moyenTransport> - [] - <villeDepart> <villeArrive> <moyenTransport> /\n"
    "RechercheSimple : RS <villeDepart> <villeArrive> \n"
    "RechercheComplexe : RC <villeDepart> <villeArrive> \n"
	"Liste des commandes : HELP\n"
    "Sauvegarde dans un fichier : SAVE <nomFichier> \n"
    "                             SAVET <nomFichier> <trajetSimple?simple:compose> \n"
    "                             SAVEV <nomFichier> <villeDepart ou '-' pour toutes> <villeArrive ou '-' pour toutes> \n"
    "                             SAVEI <nomFichier> <débutIntervalle> <finIntervalle> \n"
    "Chargement d'un fichier : LOAD <nomFichier> \n"
    "                          LOADT <nomFichier> <trajetSimple?simple:compose> \n"
    "                          LOADV <nomFichier> <villeDepart ou '-' pour toutes> <villeArrive ou '-' pour toutes> \n"
    "                          LOADI <nomFichier> <débutIntervalle> <finIntervalle> \n"
    "Sortie de l'interface : EXIT\n"
    "***********************************************************************************************************************"<<endl;
}

void Interface(Catalogue * cataloguePrincipal,bool * endOfInterface)
// Algorithme : découpe l'instruction passée par l'entrée std et l'exécute sur le paramètre cataloguePrincipal 
//
{

	char commande[10];//pour contenir la commande
    cin>>commande;

    if(strcmp(commande,"AS")==0)
	//Ajout Simple : AS <ville_départ> <ville_arrivée> <moyen_transport>
    {
        char villeD[100];
        char villeA[100];
		char moyen[10];

        cin>>villeD;
        cin>>villeA;
        cin>>moyen;
        
        
		Trajet * trajet =new TrajetSimple(villeD,villeA,moyen);
		cataloguePrincipal->AjouterTrajet(trajet);
		cout<<"* OK *"<<endl;

    }
    else if(strcmp(commande,"AC")==0)
	//Ajout Composé : AC <ville_départ> <ville_arrivée> <moyen_transport> - ... - <ville_départ> <ville_arrivée> <moyen_transport> /
    {
        char villeD[100];
        char villeA[100];
        char moyenChaine[10];
        TrajetCompose * nouvTrajet=new TrajetCompose;
        
        bool continuer=true;//si il y a encore une composante du trajet à ajouter
        bool ajouter=true;//si le dernier trajet a bien été ajouté
        bool testReussite;
        
        
        while(continuer)
        {
            cin>>villeD;
            cin>>villeA;
            cin>>moyenChaine;
            cin>>commande;
            Trajet * maillonTrajet = new TrajetSimple(villeD,villeA,moyenChaine);
            testReussite=nouvTrajet->AjouterTrajet(maillonTrajet);
            if(!testReussite)	
            {	

            	ajouter=false;
            	continuer=false;
            	delete maillonTrajet;
        	}
            if(strcmp(commande,"-")!=0)
            {
				continuer=false;
            }

        }
        if(ajouter)
        {
        	cataloguePrincipal->AjouterTrajet(nouvTrajet);
		    cout<<"* OK *"<<endl;
    	}
    	else
    	{
    		delete nouvTrajet;
    	}
    }
	else if (strcmp(commande,"RS")==0)
	{
		char villeD[100];
        char villeA[100];
 


       	cin>>villeD;
       	cin>>villeA;
        	
		Catalogue recherche = cataloguePrincipal->RechercheSimple(villeD,villeA);
	}
	else if (strcmp(commande,"RC")==0)
	{
		char villeD[100];
        char villeA[100];
       


        cin>>villeD;
        cin>>villeA;
        	
		Catalogue recherche = cataloguePrincipal->RechercheCompose(villeD,villeA);
	}
    else if(strcmp(commande,"PRINT")==0)
    {
    	cataloguePrincipal->Afficher();
    }
    else if(strcmp(commande,"EXIT")==0)
    {
        *endOfInterface=true;
    }
	else if(strcmp(commande,"LOAD")==0)
	{
		char nomFichier[100];
		cin>>nomFichier;
		if(cataloguePrincipal->LoadAll(nomFichier))
            cout<<"* OK *"<<endl;
	
	}
    else if(strcmp(commande,"LOADT")==0)
    {
        char nomFichier[100];
        string simple;
        cin>>nomFichier;
        cin>>simple;
        bool bSimple;
        if(simple=="simple")
        {
            bSimple=true;
            if(cataloguePrincipal->LoadType(nomFichier,bSimple))
                cout<<"* OK *"<<endl;
        }
        else if(simple=="compose")
        {
            bSimple=false;
            if(cataloguePrincipal->LoadType(nomFichier,bSimple))
                cout<<"* OK *"<<endl;
        }
        else
        {
            cerr<<"Le second attribut doit être simple ou compose"<<endl;
            cerr<<"Opération annulée"<<endl;
        }

    }

    else if(strcmp(commande,"LOADV")==0)
    {
        char nomFichier[100];
        string depart;
        string arrive;
        cin>>nomFichier;
        cin>>depart;
        cin>>arrive;
        if(cataloguePrincipal->LoadVille(nomFichier, depart, arrive))
            cout<<"* OK *"<<endl;

    }
    else if(strcmp(commande,"LOADI")==0)
    {
        char nomFichier[100];
        int debut;
        int fin;
        cin>>nomFichier;
        cin>>debut;
        cin>>fin;
        if(cin.fail())
        {
            cin.clear();
            cerr<<"Un des deux derniers attributs n'est pas un entier"<<endl;
            cerr<<"Opération annulée"<<endl;
        }
        else{
            if(cataloguePrincipal->LoadIntervalle(nomFichier, debut, fin))
                cout<<"* OK *"<<endl;
        }
    }
    else if(strcmp(commande,"SAVE")==0) {
        char nomFichier[100];
        cin >> nomFichier;
        if (cataloguePrincipal->SaveAll(nomFichier)) {
            cout << "* OK *" << endl;

        }
    }
    else if(strcmp(commande,"SAVET")==0)
    {
        char nomFichier[100];
        char type[100];
        cin>>nomFichier;
        cin>>type;
        if(strcmp(type,"simple")==0)
        {
            if(cataloguePrincipal->SaveType(nomFichier,true))
            {
                cout<<"* OK *"<<endl;
            }
        }
        else if(strcmp(type,"compose")==0)
        {
            if(cataloguePrincipal->SaveType(nomFichier,false))
            {
                cout<<"* OK *"<<endl;
            }
        }
        else
        {
            cerr<<"Le second attribut doit être simple ou compose"<<endl;
            cerr<<"Opération annulée"<<endl;
        }
    }
    else if(strcmp(commande,"SAVEI")==0)
    {
        char nomFichier[100];
        int n;
        int m;
        cin>>nomFichier;
        cin>>n;
        cin>>m;
        if(cin.fail())
        {
            cin.clear();
            cerr<<"Une des bornes n'est pas un entier"<<endl;
            cerr<<"Opération annulée"<<endl;

        }
        else
        {
            if(cataloguePrincipal->SaveIntervalle(nomFichier,n,m))
            {
                cout<<"* OK *"<<endl;
            }
        }
    }
    else if(strcmp(commande,"SAVEV")==0)
    {
        char nomFichier[100];
        string villeDepart;
        string villeArrive;
        cin>>nomFichier;
        cin>>villeDepart;
        cin>>villeArrive;
        if(cataloguePrincipal->SaveVille(nomFichier,villeDepart,villeArrive))
        {
            cout<<"* OK *"<<endl;
        }
    }
    else if(strcmp(commande,"HELP")==0)
    {
	cout<<	"***********************************************************************************************************************\n"
   		"\tCommandes possibles : \n"
		"Affichage : PRINT\n"
        "AjoutSimple : AS <villeDepart> <villeArrive> <moyenTransport> \n"
        "AjoutComplexe : AC <villeDepart> <villeArrive> <moyenTransport> - [] - <villeDepart> <villeArrive> <moyenTransport> /\n"
        "RechercheSimple : RS <villeDepart> <villeArrive> \n"
        "RechercheComplexe : RC <villeDepart> <villeArrive> \n"
		"Liste des commandes : HELP\n"
        "Sauvegarde dans un fichier : SAVE <nomFichier> \n"
        "                             SAVET <nomFichier> <trajetSimple?simple:compose> \n"
        "                             SAVEV <nomFichier> <villeDepart ou '-' pour toutes> <villeArrive ou '-' pour toutes> \n"
        "                             SAVEI <nomFichier> <débutIntervalle> <finIntervalle> \n"
        "Chargement d'un fichier : LOAD <nomFichier> \n"
        "                          LOADT <nomFichier> <trajetSimple?simple:compose> \n"
        "                          LOADV <nomFichier> <villeDepart ou '-' pour toutes> <villeArrive ou '-' pour toutes> \n"
        "                          LOADI <nomFichier> <débutIntervalle> <finIntervalle> \n"
        "Sortie de l'interface : EXIT"<<endl;
    }

}
