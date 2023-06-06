/*
    TP2 - numero A

    Auteure: Annie Rhéaume
    Date: 20-05-2023

    Version 1 (complète): spécifications 1 à 7

    NOTA: comprend encore la variable telTest (à enlever pour version finale)

*/


#include <iostream>
#include <iomanip>
#include<string>
#include<stdlib.h>

using namespace std;


/*
    Fonction qui donne un nouveau format à un numéro de téléphone. Prend en 
    paramètre une chaîne de caractère comprenant 10 chiffres et retourne
    une chaîne de caractères comprenant le numéro reformaté.
*/

string obtenirTel(string tel){

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
        if (tel.at(i) == c) n++;
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
        if (modele.find(chaineEval.at(i)) == string::npos) {
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
        if (modele.find(chaineEval.at(i)) == string::npos) {
            if(i > 0){
                absents += " "; // pour format en sortie : espace après un caractère
            }
            absents += chaineEval.at(i);
        }
    }
    return absents;
}

/*
    Fonction qui repère les chiffres impairs dans une chaîne de caractères. Prend une
    chaîne de caractères en paramètre et retourne un string qui comprend les chiffres impairs trouvés.
*/

string trouverImpairs(string chaineEval){

    string impairs = "";

    for (char c = '1'; c <= '9'; c += 2){
        if (chaineEval.find(c) != string::npos){
            if (c > 1){
                impairs += " ";
            }
            impairs += c;
        }
    }
    return impairs;
}

/*
    Fonction qui repère les chiffres pairs dans une chaîne de caractères. Prend une
    chaîne de caractères en paramètre et retourne un string qui comprend les chiffres pairs trouvés.
*/

string trouverPairs(string chaineEval){

    string pairs = "";

    for (char c = '0'; c <= '8'; c += 2){
        if (chaineEval.find(c) != string::npos){
            if (c > 1){
                pairs += " ";
            }
            pairs += c;
        }
    }
    return pairs;
}

/*
    Fonction qui retourne l'indice de la valeur minimale dans une chaine
    de caractère (selon code ASCII). Prend en paramètre une chaine de caractères
    et retourne la valeur de l'indice (int).
*/

int trouverIndMin (string chaine){
    int tailleChaine = chaine.length();
    int indMin = 0;

    for (int i = 0; i  < tailleChaine; i++){
        if (chaine.at(i) < chaine.at(indMin)){
            indMin = i;
        }
    }
    return indMin;
}


int main(){

    string telUdem = "5143436111", telJean = "4501237654", telTest= "5143369898";

    // Obtenir les numéros de téléphone en format (XXX) XXX-XXXX

    cout << "Le telephone de l'Universite de Montreal : " + obtenirTel(telUdem) << endl;
    cout << "Le telephone de Jean : " + obtenirTel(telJean) << endl;
    cout << "Le telephone 'test' : " + obtenirTel(telTest) << endl;

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
    cout << "Reponse: " << trouverAbsents(telJean, telUdem) << endl;

    // Trouver les chiffres impairs dans le numéro de téléphone de Jean

    cout << "Les chiffres impairs dans le numero de telephone de Jean : " << endl;
    cout << "Reponse: " << trouverImpairs(telJean) << endl;

    // Trouver les chiffres pairs dans le numéro de téléphone de l'UdeM

    cout << "Les chiffres pairs dans le numero de telephone de l'UdeM : " << endl;
    cout << "Reponse: " << trouverPairs(telUdem) << endl;

    // Trouver l'indice du plus petit chiffre dans un numero de teléphone (sous forme de chaine de caractères)

    cout << "Le plus petit chiffre du numero de telephone de l'UdeM: " << telUdem.at(trouverIndMin(telUdem)) << endl;
    cout << "Le plus petit chiffre du numero de telephone de Jean: " << telJean.at(trouverIndMin(telJean)) << endl;
}

/*

    AFFICHAGE

        C:\Users\Annie\Desktop\cppTP2>numeroA.exe

        Le telephone de l'Universite de Montreal : (514) 343-6111
        Le telephone de Jean : (450) 123-7654
        Le telephone 'test' : (514) 336-9898

        Il y a 2 fois le chiffre 3 dans le numero de telephone de UdeM
        Il y a 4 fois le chiffre 1 dans le numero de telephone de UdeM
        Il y a 2 fois le chiffre 4 dans le numero de telephone de UdeM

        Tous les chiffres du numero de telephone de l'UdeM se retrouve dans celui de Jean ?
        Reponse:  Oui !
        Tous les chiffres du numero de telephone telTest se retrouve dans celui de Jean ?
        Reponse:  Non !

        Les chiffres du numeros de telephone de Jean qui ne figurent pas dans celui de l'UdeM :
        Reponse:  0 2 7

        Les chiffres impairs dans le numero de telephone de Jean :
        Reponse:  1 3 5 7

        Les chiffres pairs dans le numero de telephone de l'UdeM :
        Reponse:  4 6
        
        Le plus petit chiffre du numero de telephone de l'UdeM: 1
        Le plus petit chiffre du numero de telephone de Jean: 0    

*/
