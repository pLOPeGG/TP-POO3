/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
//------------------------------------------------------ Include personnel

#include "Catalogue.h"

//------------------------------------------------------------- Constantes
const int TAILLE_MAX_VILLE =100;
const int TAILLE_MAX_LIGNE_LOG=200;
const char CODE[]="TP3V1";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


bool Catalogue::SaveAll(const char* fichier)const
{
	//vérif code
	ifstream inputFichier;
	inputFichier.open(fichier);
	if(inputFichier)
	{
		//lecture code
		char code[5+1];
		inputFichier.read(code, 5);
		code[5]='\0';
		if(strcmp(code,CODE)!=0)
		{
			cerr<<"Arrêt de l'écriture car fichier non conforme"<<endl;
			cerr<<"Opération annulée"<<endl;
			inputFichier.close();
			return false;
		}
	}
	else
	{
		//détermination existence du fichier ?
		if(fopen(fichier,"a+")!=NULL)
		{
			remove(fichier);

		}
		else
		{
			cerr<<"Fichier \" "<<fichier<<" \" avec droits d'accès insuffisants en lecture"<<endl;
			inputFichier.close();
			cerr<<"Opération annulée"<<endl;
			return false;
		}


	}
	inputFichier.close();

	ofstream outputFichier;
	outputFichier.open(fichier,ios::app|ios::out);

	if (outputFichier) {
		string answer;
		if(outputFichier.tellp()!=0)
		{
			cout<<"Le fichier désigné possède déjà un contenu.\r\n";
			cout<<"Voulez-vous écraser le fichier ? (y/n)\r\n";
			cin>>answer;
			if(answer=="y")
			{
				outputFichier.close();
				outputFichier.open(fichier);
				if(!outputFichier)
				{
					cerr << "Erreur à l'ouverture du fichier \" " << fichier << " \""<< endl;//affiche Erreur à l'ouverturee du fichier " <nom du fichier> "
					cerr<<"Opération annulée"<<endl;
					return false;
				}
				outputFichier<<CODE<<"\r\n";
			}
			else
			{
				cout<<"Voulez-vous écrire à la suite du fichier (y) ou simplement ne rien écrire (n) ?\r\n";
				cin>>answer;
				if(answer=="y")
				{

				}
				else
				{
					cout<<"Vous n'avez rien modifié.\r\n";
					outputFichier.close();
					return true;
				}
			}
		}
		else
		{
			outputFichier<<CODE<<"\r\n";
		}


		Trajet **pointeurTrajets = trajetsProposes.GetTrajets();
		unsigned int nombreElt = trajetsProposes.GetCardAct();
		string logTrajet;
		int count = 0;
		string villeDepart;
		for (unsigned int i = 0; i < nombreElt; i++)
		{
			villeDepart=pointeurTrajets[i]->GetVilleDepart();
			count = pointeurTrajets[i]->ToLog(logTrajet, count);

			stringstream out ;

			out << count;
			out << " ";
			out << villeDepart.length();
			out << " ";
			out << villeDepart;
			out << "|";
			out << logTrajet;

			string output = out.str();

			outputFichier << output << "\r\n";

			count = 0;
			logTrajet = "";
		}

		outputFichier.close();
		cout<<"Nombre d'éléments ajoutés au fichier de sauvegarde : "<<nombreElt<<endl;
		return true;

	} else {
		cerr << "Erreur à l'ouverture du fichier \" " << fichier << " \" car droits en écriture insuffisants"
			 << endl;
		cerr<<"Opération annulée"<<endl;
		return false;
	}
}
bool Catalogue::SaveType(const char* fichier, bool simple)const
{
	//vérif code
	ifstream inputFichier;
	inputFichier.open(fichier);
	if(inputFichier)
	{
		//lecture code
		char code[5+1];
		inputFichier.read(code, 5);
		code[5]='\0';
		if(strcmp(code,CODE)!=0)
		{
			cerr<<"Arrêt de l'écriture car fichier non conforme"<<endl;
			cerr<<"Opération annulée"<<endl;
			inputFichier.close();
			return false;
		}
	}
	else
	{
		//détermination existence du fichier ?
		if(fopen(fichier,"a+")!=NULL)
		{
			remove(fichier);

		}
		else
		{
			cerr<<"Fichier \" "<<fichier<<" \" avec droits d'accès insuffisants en lecture"<<endl;
			inputFichier.close();
			cerr<<"Opération annulée"<<endl;
			return false;
		}


	}
	inputFichier.close();


	ofstream outputFichier;
	outputFichier.open(fichier,ios::app|ios::out);


	if (outputFichier) {
		string answer;
		if(outputFichier.tellp()!=0)
		{
			cout<<"Le fichier désigné possède déjà un contenu.\r\n";
			cout<<"Voulez-vous écraser le fichier ? (y/n)\r\n";
			cin>>answer;
			if(answer=="y")
			{
				outputFichier.close();
				outputFichier.open(fichier);
				if(!outputFichier)
				{
					cerr << "Erreur à l'ouverture du fichier \" " << fichier << " \""<< endl;//affiche Erreur à l'ouverturee du fichier " <nom du fichier> "
					cerr<<"opération annulée"<<endl;
					return false;
				}
				outputFichier<<CODE<<"\r\n";
			}
			else
			{
				cout<<"Voulez-vous écrire à la suite du fichier (y) ou simplement ne rien écrire (n) ?\r\n";
				cin>>answer;
				if(answer=="y")
				{

				}
				else
				{
					cout<<"Vous n'avez rien modifié.\r\n";
					outputFichier.close();
					return true;
				}
			}
		}
		else
		{
			outputFichier<<CODE<<"\r\n";
		}

		int nbAjouts=0;
		if(simple)
		{
			Trajet **pointeurTrajets = trajetsProposes.GetTrajets();
			unsigned int nombreElt = trajetsProposes.GetCardAct();
			string logTrajet;
			int count;
			string villeDepart;
			for (unsigned int i = 0; i < nombreElt; i++)
			{
				count=0;
				logTrajet="";
				villeDepart=pointeurTrajets[i]->GetVilleDepart();
				count = pointeurTrajets[i]->ToLog(logTrajet, count);
				if(count==1)
				{
					stringstream out ;

					out << count;
					out << " ";
					out << villeDepart.length();
					out << " ";
					out << villeDepart;
					out << "|";
					out << logTrajet;

					string output = out.str();

					outputFichier << output << "\r\n";

					nbAjouts++;
					logTrajet = "";
				}
			}
		}
		else
		{
			Trajet **pointeurTrajets = trajetsProposes.GetTrajets();
			unsigned int nombreElt = trajetsProposes.GetCardAct();
			string logTrajet;
			int count;
			string villeDepart;
			for (unsigned int i = 0; i < nombreElt; i++)
			{
				count=0;
				logTrajet="";
				villeDepart=pointeurTrajets[i]->GetVilleDepart();
				count = pointeurTrajets[i]->ToLog(logTrajet, count);
				if(count>1)
				{
					stringstream out ;

					out << count;
					out << " ";
					out << villeDepart.length();
					out << " ";
					out << villeDepart;
					out << "|";
					out << logTrajet;

					string output = out.str();

					outputFichier << output << "\r\n";

					nbAjouts++;
					logTrajet = "";
				}
			}
		}

		cout<<"nombre d'éléments ajoutés au fichier de sauvegarde : "<<nbAjouts<<endl;
		outputFichier.close();
		return true;

	} else {
		cerr << "Erreur à l'ouverture du fichier \" " << fichier << " \" car droits en écriture insuffisants"
			 << endl;
		cerr<<"Opération annulée"<<endl;
		return false;
	}
}


bool Catalogue::SaveVille(const char* fichier,const string villeD,const string villeA)const
{
	//vérif code
	ifstream inputFichier;
	inputFichier.open(fichier);
	if(inputFichier)
	{
		//lecture code
		char code[5+1];
		inputFichier.read(code, 5);
		code[5]='\0';
		if(strcmp(code,CODE)!=0)
		{
			cerr<<"Arrêt de l'écriture car fichier non conforme"<<endl;
			cerr<<"Opération annulée"<<endl;
			inputFichier.close();
			return false;
		}
	}
	else
	{
		//détermination existence du fichier ?
		if(fopen(fichier,"a+")!=NULL)
		{
			remove(fichier);

		}
		else
		{
			cerr<<"Fichier \" "<<fichier<<" \" avec droits d'accès insuffisants en lecture"<<endl;
			inputFichier.close();
			cerr<<"Opération annulée"<<endl;
			return false;
		}


	}
	inputFichier.close();

	ofstream outputFichier;
	outputFichier.open(fichier,ios::app|ios::out);


	if (outputFichier) {
		string answer;
		bool existeVD=villeD!="-";
		bool existeVA=villeA!="-";
		if(outputFichier.tellp()!=0)
		{
			cout<<"Le fichier désigné possède déjà un contenu.\r\n";
			cout<<"Voulez-vous écraser le fichier ? (y/n)\r\n";
			cin>>answer;
			if(answer=="y")
			{
				outputFichier.close();
				outputFichier.open(fichier);
				if(!outputFichier)
				{
					cerr << "Erreur à l'ouverture du fichier \" " << fichier << " \""<< endl;//affiche Erreur à l'ouverturee du fichier " <nom du fichier> "
					cerr<<"opération annulée"<<endl;
					return false;
				}
				outputFichier<<CODE<<"\r\n";
			}
			else
			{
				cout<<"Voulez-vous écrire à la suite du fichier (y) ou simplement ne rien écrire (n) ?\r\n";
				cin>>answer;
				if(answer=="y")
				{

				}
				else
				{
					cout<<"Vous n'avez rien modifié.\r\n";
					outputFichier.close();
					return true;
				}
			}
		}
		else
		{
			outputFichier<<CODE<<"\r\n";
		}

		Trajet **pointeurTrajets = trajetsProposes.GetTrajets();
		unsigned int nombreElt = trajetsProposes.GetCardAct();
		string logTrajet;
		int count = 0;
		int nbAjouts = 0;
		string villeDepart;
		string villeArrive;
		for (unsigned int i = 0; i < nombreElt; i++)
		{
			villeDepart=pointeurTrajets[i]->GetVilleDepart();
			villeArrive=pointeurTrajets[i]->GetVilleArrive();
			count = pointeurTrajets[i]->ToLog(logTrajet, count);

			stringstream out ;

			out << count;
			out << " ";
			out << villeDepart.length();
			out << " ";
			out << villeDepart;
			out << "|";
			out << logTrajet;

			string output = out.str();

			if( (villeD==villeDepart || !(existeVD)) && (villeA==villeArrive || !(existeVA)) )
			{
				outputFichier << output << "\r\n";
				nbAjouts++;
			}
			count = 0;
			logTrajet = "";
		}

		cout<<"nombre d'éléments ajoutés au fichier de sauvegarde : "<<nbAjouts<<endl;
		outputFichier.close();
		return true;

	}
	else {
		cerr << "Erreur à l'ouverture du fichier \" " << fichier << " \" car droits en écriture insuffisants"
			 << endl;
		cerr<<"Opération annulée"<<endl;
		return false;
	}
}





bool Catalogue::SaveIntervalle(const char* fichier,int n,int m)const
{
	//vérif code
	ifstream inputFichier;
	inputFichier.open(fichier);
	if(inputFichier)
	{
		//lecture code
		char code[5+1];
		inputFichier.read(code, 5);
		code[5]='\0';
		if(strcmp(code,CODE)!=0)
		{
			cerr<<"Arrêt de l'écriture car fichier non conforme"<<endl;
			cerr<<"Opération annulée"<<endl;
			inputFichier.close();
			return false;
		}
	}
	else
	{
		//détermination existence du fichier ?
		if(fopen(fichier,"a+")!=NULL)
		{
			remove(fichier);

		}
		else
		{
			cerr<<"Fichier \" "<<fichier<<" \" avec droits d'accès insuffisants en lecture"<<endl;
			inputFichier.close();
			cerr<<"Opération annulée"<<endl;
			return false;
		}


	}
	inputFichier.close();

	Trajet **pointeurTrajets = trajetsProposes.GetTrajets();
	unsigned int nombreElt = trajetsProposes.GetCardAct();
	if(n>m)
	{
		cerr<<"borne inf supérieure à la borne sup"<<endl;
		cerr<<"opération annulée"<<endl;
		return false;
	}
	else
	{
		if((n-1)<0)
		{
			cerr<<"borne inf inférieure à 1"<<endl;
			cerr<<"opération annulée"<<endl;
			return false;
		}
		else
		{
			if(static_cast<unsigned int>(m)>nombreElt)
			{
				cerr<<"borne sup supérieure au nombre d'éléments du catalogue"<<endl;
				cerr<<"nombre actuel d'éléments du catalogue: "<<nombreElt<<endl;
				cerr<<"opération annulée"<<endl;
				return false;
			}
			else
			{
				ofstream outputFichier;
				outputFichier.open(fichier,ios::app|ios::out);


				if (outputFichier) {
					string answer;
					if(outputFichier.tellp()!=0)
					{
						cout<<"Le fichier désigné possède déjà un contenu.\r\n";
						cout<<"Voulez-vous écraser le fichier ? (y/n)\r\n";
						cin>>answer;
						if(answer=="y")
						{
							outputFichier.close();
							outputFichier.open(fichier);
							if(!outputFichier)
							{
								cerr << "Erreur à l'ouverture du fichier \" " << fichier << " \""<< endl;//affiche Erreur à l'ouverturee du fichier " <nom du fichier> "
								cerr<<"opération annulée"<<endl;
								return false;

							}
							outputFichier<<CODE<<"\r\n";
						}
						else
						{
							cout<<"Voulez-vous écrire à la suite du fichier (y) ou simplement ne rien écrire (n) ?\r\n";
							cin>>answer;
							if(answer=="y")
							{

							}
							else
							{
								cout<<"Vous n'avez rien modifié.\r\n";
								outputFichier.close();
								return true;
							}
						}
					}
					else
					{
						outputFichier<<CODE<<"\r\n";
					}

					string logTrajet;
					int count = 0;
					string villeDepart;
					for (int i = (n-1); i < m; i++)
					{
						villeDepart=pointeurTrajets[i]->GetVilleDepart();
						count = pointeurTrajets[i]->ToLog(logTrajet, count);

						stringstream out ;

						out << count;
						out << " ";
						out << villeDepart.length();
						out << " ";
						out << villeDepart;
						out << "|";
						out << logTrajet;

						string output = out.str();

						outputFichier << output << "\r\n";

						count = 0;
						logTrajet = "";
					}

					cout<<"nombre d'éléments ajoutés au fichier de sauvegarde : "<<(m-n+1)<<endl;
					outputFichier.close();
					return true;
				}
				else
				{
					cerr << "Erreur à l'ouverture du fichier \" " << fichier <<  "\" car droits en écriture insuffisants" << endl;
					cerr << "Opération annulée"<<endl;
					return false;
				}
			}
		}

	}

}



bool Catalogue::LoadIntervalle(const char* fichier, int n, int m)
{
	//vérif n,m
	int nInit=n;

	if(n>m)
	{
		cerr<<"La borne inférieure est supérieure à la borne supérieure"<<endl;
		return false;
	}
	else if(n<1)
	{
		cerr<<"La borne inférieure est plus petite que 1"<<endl;
		return false;
	}
	//combien de lignes ?




	ifstream inputFichier;
	inputFichier.open(fichier);
	if(inputFichier)
	{

		int tailleFichier=-1;
		while(inputFichier.ignore(TAILLE_MAX_LIGNE_LOG,'\n'))
		{
			inputFichier.ignore();
			tailleFichier++;
		}
		inputFichier.clear(); //le stream est fail on

		if(m>tailleFichier)
		{
			cerr<<"La borne supérieure est plus grande que le nombre de lignes à lire : "<<tailleFichier<<endl;
			inputFichier.close();
			return false;
		}
		//on est positionné après le code s'il existe.


		inputFichier.seekg(0,ios_base::beg);//on se replace au début
		char code[5+1];
		inputFichier.read(code, 5);
		code[5]='\0';
		if(strcmp(code,CODE)!=0)
		{
			cerr<<"Arrêt de la lecture car fichier non conforme"<<endl;
			inputFichier.close();
			return false;
		}

		for(int i=0;i<n;i++)
		{
			inputFichier.ignore(TAILLE_MAX_LIGNE_LOG,'\n');
		}

		int tailleTrajet;
		while(n<=m)
		{
			inputFichier>>tailleTrajet;
			int tailleVille;
			char * ville;
			string villeString;
			string moyenTransport;

			vector<string> donneesTrajet;

			for (int i = 0; i < tailleTrajet; i++) {
				inputFichier >> tailleVille;
				inputFichier.ignore();
				ville = new char[tailleVille + 1];

				inputFichier.read(ville, tailleVille);
				ville[tailleVille]='\0';
				inputFichier.ignore(TAILLE_MAX_VILLE,'|');//TODO const à defininir

				inputFichier >> moyenTransport;

				villeString=ville;

				donneesTrajet.push_back(villeString);
				donneesTrajet.push_back(moyenTransport);

				delete[] ville;

			}
			inputFichier>>tailleVille;
			inputFichier.ignore();
			ville = new char[tailleVille + 1];
			inputFichier.read(ville, tailleVille);
			ville[tailleVille]='\0';
			inputFichier.ignore(TAILLE_MAX_VILLE,'|');
			villeString=ville;

			donneesTrajet.push_back(villeString);


			//inputFichier.ignore(TAILLE_MAX_VILLE,'\n'); //TODO retest avec ecriture
			delete[] ville;



			if(tailleTrajet==1)
			{
				Trajet * trajetSimple=new TrajetSimple(donneesTrajet[0],donneesTrajet[2],donneesTrajet[1]);
				this->AjouterTrajet(trajetSimple);
			}
			else
			{
				ListeT composition;
				for (int i = 0; i < tailleTrajet*2; i=i+2)
				{
					Trajet * trajetSimple=new TrajetSimple(donneesTrajet[i],donneesTrajet[i+2],donneesTrajet[i+1]);
					composition.Ajouter(trajetSimple);
				}
				Trajet * trajetCompose =new TrajetCompose(composition);
				this->AjouterTrajet(trajetCompose);
			}
			n++;

		}
		cout<<m-nInit+1<<" éléments chargés dans le catalogue"<<endl;
		inputFichier.close();
		return true;
	}
	else
	{
		if(fopen(fichier,"a+")!=NULL)
		{
			remove(fichier);
			cerr<<"Le fichier \" "<<fichier<<" \" n'existe pas"<<endl;
		}
		else//fichier inexistant => failbit
		{
			cerr<<"Fichier \" "<<fichier<<" \" avec droits d'accès insuffisants en lecture"<<endl;

		}
		inputFichier.close();
		return false;
	}
}

bool Catalogue::LoadVille(const char * fichier,const string depart, const string arrive) {
	ifstream inputFichier;
	inputFichier.open(fichier);
	if (inputFichier) {
		char code[5 + 1];
		inputFichier.read(code, 5);
		code[5] = '\0';
		if(strcmp(code,CODE)!=0)
		{
			cerr<<"Arrêt de la lecture car fichier non conforme"<<endl;
			inputFichier.close();
			return false;
		}

		bool existeDepart=(depart!="-");
		bool existeArrive=(arrive!="-");


		int tailleTrajet;
		int nbTrajetsLus=0;
		while(inputFichier>>tailleTrajet)
		{


			int tailleVille;
			char *ville;
			string villeString;
			string moyenTransport;

			vector<string> donneesTrajet;

			for (int i = 0; i < tailleTrajet; i++) {
				inputFichier >> tailleVille;
				inputFichier.ignore();
				ville = new char[tailleVille + 1];

				inputFichier.read(ville, tailleVille);
				ville[tailleVille] = '\0';
				inputFichier.ignore(TAILLE_MAX_VILLE, '|');

				inputFichier >> moyenTransport;

				villeString = ville;

				donneesTrajet.push_back(villeString);
				donneesTrajet.push_back(moyenTransport);

				delete[] ville;

			}
			inputFichier >> tailleVille;
			inputFichier.ignore();
			ville = new char[tailleVille + 1];
			inputFichier.read(ville, tailleVille);
			ville[tailleVille] = '\0';
			inputFichier.ignore(TAILLE_MAX_VILLE, '|');
			villeString = ville;

			donneesTrajet.push_back(villeString);

			delete[] ville;

			if((donneesTrajet[0]==depart || !existeDepart) && (donneesTrajet[tailleTrajet*2]==arrive || !existeArrive)) //condition sur les villes
			{
				if (tailleTrajet == 1) {
					Trajet *trajetSimple = new TrajetSimple(donneesTrajet[0], donneesTrajet[2], donneesTrajet[1]);
					this->AjouterTrajet(trajetSimple);
					nbTrajetsLus++;
				} else {
					ListeT composition;
					for (int i = 0; i < tailleTrajet * 2; i = i + 2) {
						Trajet *trajetSimple = new TrajetSimple(donneesTrajet[i], donneesTrajet[i + 2],
																donneesTrajet[i + 1]);
						composition.Ajouter(trajetSimple);
					}
					Trajet *trajetCompose = new TrajetCompose(composition);
					this->AjouterTrajet(trajetCompose);
					nbTrajetsLus++;
				}
			}
			else
			{
				//inputFichier.ignore(TAILLE_MAX_LIGNE_LOG,'\n');//on saute pas la ligne puisqu'on l'a lue.
			}



		}


		if(nbTrajetsLus==0)
		{
			cout<<"Aucun trajet ajouté au catalogue"<<endl;
		}
		else
		{
			cout<<nbTrajetsLus<<" éléments chargés dans le catalogue"<<endl;
		}
		inputFichier.close();
		return true;

	}
	else
	{
		if(fopen(fichier,"a+")!=NULL)
		{
			remove(fichier);
			cerr<<"Le fichier \" "<<fichier<<" \" n'existe pas"<<endl;
		}
		else//fichier inexistant => failbit
		{
			cerr<<"Fichier \" "<<fichier<<" \" avec droits d'accès insuffisants en leccture ou dossier inexistant"<<endl;

		}
		inputFichier.close();
		return false;
	}
}

bool Catalogue::LoadType(const char* fichier, bool estSimple)
{
	ifstream inputFichier;
	inputFichier.open(fichier);
	if(inputFichier)
	{
		char code[5+1];
		inputFichier.read(code, 5);
		code[5]='\0';

		if(strcmp(code,CODE)!=0)
		{
			cerr<<"Arrêt de la lecture car fichier non conforme"<<endl;
			inputFichier.close();
			return false;
		}


		int tailleTrajet;
		int nbTrajetsLus=0;
		while(inputFichier>>tailleTrajet) {
			if (((tailleTrajet == 1 && estSimple) || (tailleTrajet > 1 && !estSimple))) {
				int tailleVille;
				char *ville;
				string villeString;
				string moyenTransport;

				vector<string> donneesTrajet;

				for (int i = 0; i < tailleTrajet; i++) {
					inputFichier >> tailleVille;
					inputFichier.ignore();
					ville = new char[tailleVille + 1];

					inputFichier.read(ville, tailleVille);
					ville[tailleVille] = '\0';
					inputFichier.ignore(TAILLE_MAX_VILLE, '|');//TODO const à defininir

					inputFichier >> moyenTransport;

					villeString = ville;

					donneesTrajet.push_back(villeString);
					donneesTrajet.push_back(moyenTransport);

					delete[] ville;

				}
				inputFichier >> tailleVille;
				inputFichier.ignore();
				ville = new char[tailleVille + 1];
				inputFichier.read(ville, tailleVille);
				ville[tailleVille] = '\0';
				inputFichier.ignore(TAILLE_MAX_VILLE, '|');
				villeString = ville;

				donneesTrajet.push_back(villeString);


				//inputFichier.ignore(TAILLE_MAX_VILLE,'\n'); //TODO retest avec ecriture
				delete[] ville;


				if (tailleTrajet == 1) {
					Trajet *trajetSimple = new TrajetSimple(donneesTrajet[0], donneesTrajet[2], donneesTrajet[1]);
					this->AjouterTrajet(trajetSimple);
					nbTrajetsLus++;
				} else {
					ListeT composition;
					for (int i = 0; i < tailleTrajet * 2; i = i + 2) {
						Trajet *trajetSimple = new TrajetSimple(donneesTrajet[i], donneesTrajet[i + 2],
																donneesTrajet[i + 1]);
						composition.Ajouter(trajetSimple);
					}
					Trajet *trajetCompose = new TrajetCompose(composition);
					this->AjouterTrajet(trajetCompose);
					nbTrajetsLus++;
				}

			}
			else
			{
				inputFichier.ignore(TAILLE_MAX_LIGNE_LOG,'\n');//on saut la ligne si on ne la lit pas

			}
		}
		if(nbTrajetsLus==0)
		{
			cout<<"Aucun trajet ajouté au catalogue"<<endl;
		}
		else
		{
			cout<<nbTrajetsLus<<" éléments chargés dans le catalogue"<<endl;
		}
		inputFichier.close();
		return true;
	}
	else
	{
		if(fopen(fichier,"a+")!=NULL)
		{
			remove(fichier);
			cerr<<"Le fichier \" "<<fichier<<" \" n'existe pas"<<endl;
		}
		else//fichier inexistant => failbit
		{
			cerr<<"Fichier \" "<<fichier<<" \" avec droits d'accès insuffisants en leccture ou dossier inexistant"<<endl;

		}
		inputFichier.close();
		return false;
	}
}

bool Catalogue::LoadAll(const char* fichier)
{
	ifstream inputFichier;
	inputFichier.open(fichier);
	if(inputFichier)
	{
        char code[5+1];
        inputFichier.read(code, 5);
        code[5]='\0';
		if(strcmp(code,CODE)!=0)
		{
			cerr<<"Arrêt de la lecture car fichier non conforme"<<endl;
			inputFichier.close();
			return false;
		}

        //on est positionné après le code s'il existe.



		int tailleTrajet;
		int nbTrajetsLus=0;
		while(inputFichier>>tailleTrajet)
		{
			int tailleVille;
			char * ville;
			string villeString;
            string moyenTransport;

			vector<string> donneesTrajet;

			for (int i = 0; i < tailleTrajet; i++) {
				inputFichier >> tailleVille;
				inputFichier.ignore();
				ville = new char[tailleVille + 1];

				inputFichier.read(ville, tailleVille);
                ville[tailleVille]='\0';
				inputFichier.ignore(TAILLE_MAX_VILLE,'|');//TODO const à defininir

                inputFichier >> moyenTransport;

                villeString=ville;

				donneesTrajet.push_back(villeString);
				donneesTrajet.push_back(moyenTransport);

                delete[] ville;

			}
			inputFichier>>tailleVille;
			inputFichier.ignore();
			ville = new char[tailleVille + 1];
			inputFichier.read(ville, tailleVille);
            ville[tailleVille]='\0';
            inputFichier.ignore(TAILLE_MAX_VILLE,'|');
            villeString=ville;

			donneesTrajet.push_back(villeString);


            //inputFichier.ignore(TAILLE_MAX_VILLE,'\n'); //TODO retest avec ecriture
            delete[] ville;



			if(tailleTrajet==1)
			{
				Trajet * trajetSimple=new TrajetSimple(donneesTrajet[0],donneesTrajet[2],donneesTrajet[1]);
				this->AjouterTrajet(trajetSimple);
				nbTrajetsLus++;
			}
			else
			{
				ListeT composition;
				for (int i = 0; i < tailleTrajet*2; i=i+2)
				{
					Trajet * trajetSimple=new TrajetSimple(donneesTrajet[i],donneesTrajet[i+2],donneesTrajet[i+1]);
					composition.Ajouter(trajetSimple);
				}
				Trajet * trajetCompose =new TrajetCompose(composition);
				this->AjouterTrajet(trajetCompose);
				nbTrajetsLus++;
			}

		}
		inputFichier.close();
		if(nbTrajetsLus==0)
		{
			cout<<"Aucun trajet ajouté au catalogue"<<endl;
		}
		else
		{
			cout<<nbTrajetsLus<<" éléments chargés dans le catalogue"<<endl;
		}
		return true;
	}
	else
	{
		if(fopen(fichier,"a+")!=NULL)
		{
			remove(fichier);
			cerr<<"Le fichier \" "<<fichier<<" \" n'existe pas"<<endl;
		}
        else//fichier inexistant => failbit
        {
            cerr<<"Fichier \" "<<fichier<<" \" avec droits d'accès insuffisants en lecture"<<endl;

        }
        inputFichier.close();
		return false;
	}


}

void Catalogue::AjouterTrajet(Trajet * unTrajet)
{
	trajetsProposes.Ajouter(unTrajet);//ajout du pointeur directement sans copie en profondeur
}

void Catalogue::Afficher()const
{
	cout<<	"***********************************************************************************************************************\n";
	cout<<"Le catalogue contient : \n";
	//affichage

	Trajet ** pointeur=trajetsProposes.GetTrajets();
	unsigned int nombreElt=trajetsProposes.GetCardAct();
	//on récupère les attributs protégés du conteneur

	for(unsigned int i=0;i<nombreElt;i++)
	//parcours de tous les trajets contenus dans le catalogue en O(n)
	{
		cout<<i+1<<" : ";
		pointeur[i]->Afficher();
		//on affiche chaque élément
		cout<<"."<<endl;
	}
	cout<<	"***********************************************************************************************************************"<<endl;

}

Catalogue Catalogue::RechercheSimple(const char * villeD, const char * villeA)const
// Algorithme : parcours en boucle simple du conteneur, un test de comparaison permet de sélectionner les trajets qui répondent à la recherche
// complexité O(n)
{
	Catalogue retour;//Catalogue auquel sont ajoutés les trajets valides

	Trajet ** actuel = trajetsProposes.GetTrajets();
	unsigned int lim = trajetsProposes.GetCardAct();
	//on récupère les attributs du conteneur de l'objet courant

	cout<<"Recherche de "<<villeD<< " à "<< villeA<<endl;
	for(unsigned int i=0; i<lim;i++)
	{
		if(strcmp(villeD,actuel[i]->GetVilleDepart())==0 && strcmp(villeA,actuel[i]->GetVilleArrive())==0)
		//test qui compare villeD entré en paramètre et villeDepart du ième trajet du catalogue courant, idem pour villeA et villeArrive.
		{		
			cout<<endl;
			retour.AjouterTrajet(actuel[i]->Copie());//on ajoute une copie du ième trajet au catalogue retour
			
		}
	}
	retour.Afficher();
	//affichage sur la sortie std

	return retour;
}

Catalogue Catalogue::RechercheCompose(const char * villeD,const char * villeA)const
// Algorithme : détection du cas d'une recherche en boucle où villeD = villeA, execution de la méthode appropriée
//
{
	Catalogue retour;//stocke l'ensemble des trajets hautement composés qui répondent à la recherche
	ListeT tabPassage;//stocke les trajets sélectionnés par la méthode les uns à la suite
   	//objets passés en paramètre des méthodes, se remplissent au cours des RecherchesRecursives
	if(strcmp(villeD,villeA)==0)
	//si on boucle
	{
		rechercheRecursiveBoucle(villeD, villeA, tabPassage, retour);//méthode de recherche pour ville de départ identique à l'arrivée
	}
	else
	{
		rechercheRecursive(villeD, villeD, villeA, tabPassage, retour);//méthode pour toutes les autres recherches
	}
	retour.Afficher();
	return retour;
	



}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
	: trajetsProposes ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool Catalogue::ArriveeNonInclue (const ListeT & tableauPassage, const char * ville) const
// Algorithme : parcours de tous les éléments du catalogue
// complexité : O(n)
{
	for(unsigned int i=0;i<tableauPassage.GetCardAct();i++)
	{
		if(strcmp(tableauPassage.GetTrajets()[i]->GetVilleArrive(),ville) == 0)
		//si un élément a pour attribut villeArrive le paramètre ville		
		{
			return false;
		}
	}
	//si aucun élément ne vérifie la condition
	return true;
}


void Catalogue::rechercheRecursiveBoucle (const char * depart, const char * arrive, ListeT & tabPassage, Catalogue & leCatalogue)const
// Algorithme : méthode récursive : à chaque appel, on cherche dans le catalogue tous les trajets qui ont pour attribut villeDepart le parametre depart
//		et dont l'attribut villeArrive ne figure pas déjà dans le parametre tabPassage (voir méthode ArriveeNonInclue()). Alors ce trajet est ajouté à tabPassage et 
//		la méthode est appelée avec pour nouveaux paramètres depart=villeArrive, arrive est inchangé, le tabPassage mis à jour et la même référence sur leCatalogue.
//		
//complexité :  parcours presque complet du graphe : O(nombreDeVilleDuGraphe^(nombreDeConnexionMoyenParVille))
{
	if(strcmp(depart,arrive)==0 && tabPassage.GetCardAct()!=0)
	//test de fin de la récursivité
	//la méthode a été appelée avec la meme ville de départ et d'arrivée ET notre trajet est non vide -> on a trouvé une composition de trajet qui répond à la recherche 
	{
		
		Trajet * trajetSolution = new TrajetCompose(tabPassage);//appel du constructeur de trajet Composé avec pour parametre une ListeT		
		leCatalogue.AjouterTrajet(trajetSolution);//on ajoute ce trajet au catalogue de retour
	
	}
	else
	{
		//récursivité : parcourir tous les trajets du catalogue courant (this), si concordance des départs ET l'arrivée du trajet n'est pas déjà dans tabPAssage -> récursion.
		unsigned int nombreElt=trajetsProposes.GetCardAct();
		Trajet ** currentTrajet=trajetsProposes.GetTrajets();
		//récupération des attributs		
		
		for(unsigned int i=0;i<nombreElt;i++)//pour chaque trajet du catalogue courant
		{
			if(strcmp(depart,currentTrajet[i]->GetVilleDepart())==0 && ArriveeNonInclue(tabPassage,currentTrajet[i]->GetVilleArrive()) )
			//attribut depart identique à villeDepart du trajet pointé ET villeArrive du trajet non inclue dans tabPassage
			{
				ListeT copieTabPassage (tabPassage);//création d'une copie en profondeur de tabPassage
				copieTabPassage.Ajouter(currentTrajet[i]->Copie());//on ajoute une copie en profondeur du trajet pointé

				rechercheRecursiveBoucle(currentTrajet[i]->GetVilleArrive(),arrive,copieTabPassage,leCatalogue);//appel récursif en incrémentant le départ et avec le nouveau tabPassage
			}
		}
	}
}

void Catalogue::rechercheRecursive (const char * origine, const char * depart, const char * arrive, ListeT & tabPassage, Catalogue & leCatalogue)const
// Algorithme : méthode récursive : à chaque appel, on cherche dans le catalogue tous les trajets qui ont pour attribut villeDepart le parametre depart
//		et dont l'attribut villeArrive ne figure pas déjà dans le parametre tabPassage (voir méthode ArriveeNonInclue()). Alors ce trajet est ajouté à tabPassage et 
//		la méthode est appelée avec pour nouveaux paramètres depart=villeArrive, arrive et origine sont inchangés, le tabPassage mis à jour et la même référence sur leCatalogue.
//
//complexité :  parcours presque complet du graphe : O(nombreDeVilleDuGraphe^(nombreDeConnexionMoyenParVille))
{
	if(strcmp(depart,arrive)==0)
	//test de fin de la récursivité
	//la méthode a été appelée avec la meme ville de départ et d'arrivée -> on a trouvé une composition de trajet qui répond à la recherche
	{
		Trajet * trajetSolution = new TrajetCompose(tabPassage);//appel du constructeur de trajet Composé avec pour parametre une ListeT
		leCatalogue.AjouterTrajet(trajetSolution);//on ajoute ce trajet au catalogue de retour
	
	}
	else
	{
		//récursivité : parcourir tous les trajets du catalogue courant (this), si concordance des départs ET l'arrivée du trajet n'est pas déjà dans (tabPAssage union origine) -> récursion.
		unsigned int nombreElt=trajetsProposes.GetCardAct();
		Trajet ** currentTrajet=trajetsProposes.GetTrajets();
		//récupération des attributs		
	
		for(unsigned int i=0;i<nombreElt;i++)
		{
			if(strcmp(depart,currentTrajet[i]->GetVilleDepart())==0 && strcmp(currentTrajet[i]->GetVilleArrive(),origine)!=0 && ArriveeNonInclue(tabPassage,currentTrajet[i]->GetVilleArrive()) )
			//les départs sont identiques, l'arrivée n'est ni origine ni inclue dans tabPassage			
			{
				ListeT copieTabPassage (tabPassage);//création d'une copie en profondeur de tabPassage
				copieTabPassage.Ajouter(currentTrajet[i]->Copie());//on ajoute une copie en profondeur du trajet pointé

				rechercheRecursive(origine,currentTrajet[i]->GetVilleArrive(),arrive,copieTabPassage,leCatalogue);//appel récursif en incrémentant le départ et avec le nouveau tabPassage
			}
		}
	}
}
