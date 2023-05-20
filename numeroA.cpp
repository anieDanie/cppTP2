/*
    TP2 - numero A

    Auteure: Annie Rhéaume
    Date: 19-05-2023

    Version : initiale (spécifications 1, 2, 3, 4)

*/


#include <iostream>
#include <iomanip>
#include<string>
#include<stdlib.h>

using namespace std;


/*
    Fonction qui donne un nouveau format à un numéro de téléphone. Prend en 
    paramètre une chaîne de caractère comprenant 10 chiffres et retourne
    une chaîne de caractère comprenant le numéro reformaté.
*/

string getTel(string tel){

    if (tel.length() == 10)
        return "(" + tel.substr(0,3) + ") " + tel.substr(3,3) + "-" + tel.substr(6,4);

    return "Erreur : le numero de telephone n'est pas compose de 10 chiffres";
}

/*
    Fonction qui calcule les fréquences d'apparition d'un caractère dans une chaîne
    de caractères. Prend en paramètre une chaîne et retourne la fréquence recherchée.
*/

int compter(string tel, char c){

    int n = 0;
    for (int i = 0; i < tel.length(); i++)
        if (tel[i] == c) n++;
    return n;
}

/*
    Fonction qui compare 2 chaînes de caractères et qui détermine si tous
    les caractères de la chaîne modèle se trouve dans la chaine évaluée.
    Prend en paramètre la chaine à évaluer et la chaîne modèle, retourne
    un booléen comme résultat.
*/

bool comparerChaines(string chaineEval, string modele){

    bool estPresent = 1;
    for (int i = 0; i < chaineEval.length(); i++ ){
        if (modele.find(chaineEval[i]) == -1) {
            estPresent = 0;
        }
    }
    return estPresent;
}

/*
    Fonction qui compare 2 chaînes de caractères et qui repère
    les caractères de la chaîne modèle qui ne se trouve pas dans la chaine évaluée.
    Prend en paramètre la chaine à évaluer et la chaîne modèle, retourne
    un string qui comprend tous les caractères absents.
*/

string trouverAbsents(string chaineEval, string modele){

    string absents = "";

    for (int i = 0; i < chaineEval.length() ; i++ ){
        if (modele.find(chaineEval[i]) == -1) {
            if(i > 0){
                absents += " ";
            }
            absents += chaineEval.at(i);
        }
    }
    return absents;
}

int main(){

    string telUdem = "5143436111", telJean = "4501237654", telTest= "5143369898";

    // Afficher les numéros de téléphone en format (XXX) XXX-XXXX

    cout << "Le telephone de l'Universite de Montreal : " + getTel(telUdem) << endl;
    cout << "Le telephone de Jean : " + getTel(telJean) << endl;
    cout << "Le telephone de Jean : " + getTel(telTest) << endl;

    // Compter le nombre de fois qu'apparaît un chiffre dans un numéro de téléphone

    cout << "Il y a " << compter(telUdem, '3') << " fois le chiffre 3 dans le numero de telephone de UdeM" << endl;
    cout << "Il y a " << compter(telUdem, '1') << " fois le chiffre 1 dans le numero de telephone de UdeM" << endl;
    cout << "Il y a " << compter(telJean, '4') << " fois le chiffre 4 dans le numero de telephone de UdeM" << endl;
    
    // Comparer telUdeM et telJean pour déterminer si tous les chiffres de l'Udem se trouve dans telJean
    
    cout << "Tous les chiffres du numero de telephone de l'UdeM se retrouve dans celui de Jean ? " << endl;
    cout << "Reponse: " << (comparerChaines(telUdem, telJean) ? " Oui !" : " Non !" ) << endl;

    cout << "Tous les chiffres du numero de telephone telTest se retrouve dans celui de Jean ? " << endl;
    cout << "Reponse: " << (comparerChaines(telTest, telJean) ? " Oui !" : " Non !" ) << endl;

    // Comparer telUdeM et telJean pour déterminer quels sont les chiffres du numéro de téléphone de Jean qui ne se trouve pas dans celui de l'UdeM

    cout << "Les chiffres du numeros de telephone de Jean qui ne figurent pas dans celui de l'UdeM :" << endl;
    cout << "Reponse :" << trouverAbsents(telJean, telUdem) << endl;

    // CONTINUER avec 5

}
