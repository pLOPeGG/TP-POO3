#include <iostream>

using namespace std;

const int TAILLE_MAX_VILLE=100;
/*
int main() {
    //ofstream outputFichier("bite");
    //outputFichier<<"1 3 jfcde\n";
    //outputFichier.close();

    ifstream inputFichier;
    string a ="bfif";
    int un =10;

    stringstream ss ;
    ss<<un;
    ss<<a;
    a=ss.str();
    cout<<a;


    inputFichier.open("/home/doudou/ClionProjects/TP3/test");
    if(inputFichier)
    {
        /*
         * VERSION 1 : espaces séparateurs et on indique le nombre de caractères dans le nom de la ville PB si ville avec espace et mauvais calcul de la longueur
         */
/*
        int tailleTrajet;
        inputFichier >> tailleTrajet;

        int tailleVille;
        char * ville;
        string moyenTransport;

        vector<string> donneesTrajet;

        for (int i = 0; i < tailleTrajet; i++) {
            inputFichier >> tailleVille;
            inputFichier.ignore();
            ville = new char[tailleVille + 1];
            inputFichier.read(ville, tailleVille);
            inputFichier.ignore(7,'|');
            inputFichier>>moyenTransport;

            donneesTrajet.push_back(ville);
            donneesTrajet.push_back(moyenTransport);

        }
        inputFichier>>tailleVille;
        inputFichier.ignore();
        ville = new char[tailleVille + 1];
        inputFichier.read(ville, tailleVille);
        donneesTrajet.push_back(ville);
        inputFichier.close();

        for(vector<string>::iterator it=donneesTrajet.begin();it!=donneesTrajet.end();it++)
        {
            cout<<*it<<" | ";
        }


        /*
         * VERSION 2 toutes les infos sont séparées par un caractère unique inutilisable par l'utilisateur ex '§'
         */
/*

    }
    else
    {
        cerr<<"erreur"<<endl;
    }

    return 0;
*/
    //TODO : méthode log pour les trajets + méthode de décompte de feuille
//}