/* 
    TP2 - numero C

    Auteure: Annie Rhéaume
    Date: 27-05-2023

    source: fichier Tab_Pers.cpp

    Version 1: 
      -dans cette version, j'ai essentiellement
      crée des getters et des setters pour accéder et modifier
      les valeurs de champs des objets de Personne.
      -beaucoup de redondance de code (en raison de l'impossibilité
      d'accéder aux données de la classe...)
      -toutes les fonctions "statistiques" ne sont pas considérées
      comme des fonctions membres de la classe Personne (seulement
      des fonctions du programme)
      -NUMERO C: essentiellement une synthese TP1 et TP2 numeroB 
      (rien sur les Strings), pour manipuler des objets dans un
      tableau (plutôt que des types primitifs)

*/


#include <iostream>
#include <iomanip>   
#include <string>
#include <fstream>   

using namespace std; // librairie standard

/*
  Structure de données (classe) du fichier Tab_Pers.cpp
  Fournie pour le TP2
*/

class Personne
{
   private :
      char sexe ;
      float taille, poids ;
      int numero;
   public :

    // Déclaration constructeur avec paramèetres      
    Personne(char sexe, int numero, float taille, float poids);
    
    // Constructeur par défaut explicite 
    Personne()  {}  

    // Déclaration des 'getters' pour les champs de la classe Personne
    float getTaille();
    float getPoids();
    int getNumero(); 
    char getSexe();

    // Déclaration des 'setters' pour les champs de la classe Personne
    void setNumero(int val);

    // Déclaration fonction membre afficher
    void afficher(); 

};

/*
  Définition du contructeur avec paramètres (tous les champs)
*/
Personne::Personne(char sexe, int numero, float taille, float poids)
      {
        this->sexe = sexe;
        this->numero = numero;
        this->taille = taille;
        this->poids = poids;            
      } 

/*
  Définition du 'getter' pour le champ taille
  Accesseur retourne la taille d'une personne.
*/
float Personne::getTaille()
{
    return taille;
}

/*
  Définition du 'getter' pour le champ poids
  Accesseur retourne le poids d'une personne.
*/
float Personne::getPoids()
{
    return poids;
}

/*
  Définition du 'getter' pour le champ sexe
  Accesseur retourne le sexe d'une personne.
*/
char Personne::getSexe()
{
    return sexe;
}

/*
  Définition du 'getter' pour le champ numero
  Accesseur retourne le numéro d'identifiant d'une personne.
*/
int Personne::getNumero()
{
    return numero;
}

/*
  Définition du 'setter' pour le champ numero
  Mutateur qui modifie le champ numero d'un objet de type Personne.
*/
void Personne::setNumero(int numero)
{
  this->numero = numero;
}

/*
  Définition de la fonction afficher():
  Affiche tous les champs d'un objet de la classe Personne
*/
void Personne::afficher()
{
  cout << "sexe             : " << (sexe == 'F'? "feminin" : "masculin") << endl ;
  cout << "numero           : " << numero << endl ;
  cout << "taille           : " << taille << endl ;
  cout << "poids            : " << poids << " $\n\n";
}  


/*
  Fonction qui lit une fichier .txt et qui crée un tableau d'objets
  de type Personne. Fonction du fichier Tab_Pers.cpp
  Fournie pour le TP2
*/
void lireRemplir(string nomALire, Personne pers[], int & n)
{   
  const float PIED_EN_METRE = 0.3048,
              LIVRE_EN_KG = 0.454;
  int numero, nbPieds, nbPouces, nbLivres;
  float taille, poids;
  char sexe;
    
  ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture

  n = 0;

  while (aLire >> sexe >> numero >> nbPieds >> nbPouces >> nbLivres)			       
  {
              taille = (nbPieds + nbPouces /12.0) * PIED_EN_METRE;
              poids  = nbLivres * LIVRE_EN_KG ;                                
              pers[n++] = Personne(sexe, numero, taille, poids);               
  }
  aLire.close();   
}

/*
  Fonction qui permet d'afficher tous les éléments du tableau
  composé d'objets de la classe Personne
*/
void afficherListePersonnes(string mes, Personne tab[], int nbPers){
  cout << mes << ":\n" << endl;
  for (int i = 0; i  < nbPers ; i++){
      cout << "Element - " << i << endl;
      tab[i].afficher();
  }
} 

/*
  Fonction qui détermine l'enregistrement contenant la taille 
  la plus grande parmi un échantillon de personne. Retourne 
  l'indice de l'enregistrement qui la contient.
*/
int rechercherTailleMax(Personne tab[], int nbElem){
    int indice = -1;
    float valMax = tab[0].getTaille();
    
    for (int i = 1; i < nbElem ; i++)
    {
        if(tab[i].getTaille() > valMax) {
          valMax = tab[i].getTaille();
          indice = i;
        }
    } 
    return indice;
}

/*
  Fonction qui détermine l'enregistrement contenant la taille 
  la plus petite parmi un échantillon de personne. Retourne 
  l'indice de l'enregistrement qui la contient.
*/
int rechercherTailleMin(Personne tab[], int nbElem){
    int indice = -1;
    float valMin = tab[0].getTaille();
    
    for (int i = 1; i < nbElem ; i++)
    {
        if(tab[i].getTaille() < valMin) {
          valMin = tab[i].getTaille();
          indice = i;
        }
    } 
    return indice;
}

/*
  Fonction qui détermine l'enregistrement contenant la poids 
  le plus petit parmi un échantillon de personne. Retourne 
  l'indice de l'enregistrement qui le contient.
*/
int rechercherPoidsMin(Personne tab[], int nbElem){
    int indice = -1;
    float valMin = tab[0].getPoids();
    
    for (int i = 1; i < nbElem ; i++)
    {
        if(tab[i].getPoids() < valMin) {
            valMin = tab[i].getPoids();
            indice = i;
        }
    } 
    return indice;
}

/*
Fonction qui calcule la moyenne des tailles des enregistrements de type Personne.
Ne retourne rien (modifie la variable dont la référence est passée en param)
*/
void calculerTailleMoyenneHommes(Personne tab[], int nbElem, float& refMoyenne){
    float somme = 0.0f;
    int nbHommes = 0;

    for (int i = 0; i < nbElem ; i++)
    {
      if(tab[i].getSexe() == 'M'){
        somme += tab[i].getTaille();
        nbHommes++;
      }
    } 
    refMoyenne = somme / nbHommes;  
}

/*
Fonction qui calcule la moyenne des tailles des enregistrements de type Personne.
Ne retourne rien (modifie la variable dont la référence est passée en param)
*/
void calculerPoidsMoyenFemmes(Personne tab[], int nbElem, float& refMoyenne){

    float somme = 0.0f;
    int nbFemmes = 0;

    for (int i = 0; i < nbElem ; i++)
    {
      if(tab[i].getSexe() == 'F'){
        somme += tab[i].getPoids();
        nbFemmes++;
      }
    } 
    refMoyenne = somme / nbFemmes;  
}

//Quicksort

/*
  Fonction qui prend en paramètre un tableau de Personne et les indices
  de 2 valeurs à permuter dans le tableau. Ne retourne rien.
  Spécifique au type Personne, pour accéder à son membre données 'numero'
*/
void permuter(Personne tab[], int indiceA, int indiceB){
  int temp = tab[indiceA].getNumero();
  tab[indiceA].setNumero(tab[indiceB].getNumero());
  tab[indiceB].setNumero(temp);
}

/*
  Fonction qui trie les objets de type Personne d'un tableau selon 
  l'ordre croissant du numéro d'identifiant. Ne retourne rien.
  Spécifique au type Personne, pour accéder à son membre données 'numero'
  Implémentation d'un algorithme du tri rapide (quicksort)
*/
  void trier(Personne tab[], int indiceMin, int indiceMax){

  // Condition de sortie de la boucle récursive
  if(indiceMin >= indiceMax)
      return;

  // Sélectionner un pivot
  int pivot = tab[indiceMax].getNumero();

  // Créer traceurs gauche et droite
  int g = indiceMin;
  int d = indiceMax;

  // Aussi longtemps que les traceurs gauche et droite ne se rencontrent pas
  while(g < d){

      // On cherche une valeur plus petite que le pivot
      while(tab[g].getNumero() <= pivot && g < d){
        g++;
      }

      // On cherche une valeur plus grande que le pivot
      while(tab[d].getNumero() >= pivot && g < d){
        d--;
      }

      // Permuter les valeurs pointées par les traceurs g et d
      permuter(tab, g, d);
  }

  // Lorsque les traceurs d et g se rejoignent,
  // Permuter la valeur pointée par traceur d et celle à indiceMax
  permuter(tab, g, indiceMax);

  // Trier les sous-tableaux (à gauche et à droite du pivot) récursivement
  trier(tab, indiceMin, g-1);
  trier(tab, g+1, indiceMax);
}    

//Recherche dichotomique

/*
  Fonction qui recherche une valeur (clé) dans un tableau d'objets de type
  Personne, trié selon le 'numero'. Retourne l'indice de la valeur recherchee, 
  ou -1, si absente.
  Spécifique au type Personne, pour accéder à son membre données 'numero'
  Implémentation d'un algorithme de recherche dichotomique (binary search)
*/
int rechercher(Personne tab[], int nbElem, int cle) {  
  
  // Traceurs gauche et droit
  int indiceMin = 0;
  int indiceMax = nbElem-1;

  //Jusqu'à ce que les traceurs se rencontrent...
  while (indiceMin <= indiceMax)
  {
      int milieu = (indiceMin + indiceMax) / 2;
      int valeurMilieu = tab[milieu].getNumero();

      // La valeur recherchée est celle de la position milieu
      if (cle == valeurMilieu){
        return milieu;
      }
      // Dans ce cas, on continue la recherche à gauche... 
      if (cle < valeurMilieu){
        indiceMax = milieu - 1 ;
      } else { // si n'est pas à gauche, on cherche à droite...
        indiceMin = milieu + 1;
      }                             
  } 
  // Recherche infructueuse          
  return -1;               
} 

/*
  Fonction qui permet d'afficher le résultat (en mots) de la recherche d'une valeur dans le tableau
*/
void afficherResultatRecherche(Personne tab[], int nbPers, int valeurRecherchee, int indice){
  if (indice == -1){
  cout << valeurRecherchee << " => introuvable";
  } else {
  tab[indice].afficher();
  }
}  


int main() {
 
 const int MAX_PERS = 30 ;
 Personne pers[MAX_PERS];
 int nbPers;
 
 lireRemplir("imp_e23.txt", pers, nbPers);
 
 cout << "\nOn a lu les infos de " << nbPers << " personnes\n";
 cout << endl;

 // Afficher la liste des personnes (tableau des objets de type Personne)
afficherListePersonnes("Liste non triee", pers, nbPers);

// Déterminer et afficher les informations de la personne dont la taille est la plus grande
cout << "Informations sur la personne dont la taille est la plus grande: " << endl;
pers[rechercherTailleMax(pers,nbPers)].afficher();
cout << endl; 

// Déterminer et afficher les informations des personnes dont la taille et le poids sont les plus petits
cout << "Informations sur la personne dont la taille est la plus petite: " << endl;
pers[rechercherTailleMin(pers,nbPers)].afficher();
cout << endl;
cout << "Informations sur la personne dont le poids est le plus petit: " << endl;
pers[rechercherPoidsMin(pers,nbPers)].afficher();
cout << endl;

// Afficher la taille moyenne et le poids moyen à partir des enregistrements de type Personne
float tailleMoyenne, poidsMoyen;

calculerTailleMoyenneHommes(pers, nbPers, tailleMoyenne);
calculerPoidsMoyenFemmes(pers, nbPers, poidsMoyen);

cout << "Taille moyenne des hommes: " << tailleMoyenne << endl;
cout << "Poids moyen des femmes: " << poidsMoyen << endl;
cout<< endl;

// Trier le tableau d'objets de type Personne selon le numéro d'identifiant.
trier(pers, 0, nbPers - 1);
afficherListePersonnes("Liste triee", pers, nbPers);

// Rechercher et afficher les informations des enregistrements dont le numéro d'identifiant est: 4433,2879,9876
cout << "Resultats des recherches dans la liste de personnes:  " << endl;
afficherResultatRecherche(pers, nbPers, 4433, rechercher(pers, nbPers, 4433));
afficherResultatRecherche(pers, nbPers, 2879, rechercher(pers, nbPers, 2879));
afficherResultatRecherche(pers, nbPers, 9876, rechercher(pers, nbPers, 9876));
 
 return 0; 
}


/*
  AFFICHAGE (fichier initial)

  C:\Users\Annie\Desktop\cppTP2>numeroC.exe
  On a lu les infos de 20 personnes

*/

/*

AFFICHAGE (fichier modifié) - sans listes complètes

C:\Users\Annie\Desktop\cppTP2>numeroC.exe

On a lu les infos de 20 personnes

Informations sur la personne dont la taille est la plus grande:
sexe             : feminin
numero           : 5678
taille           : 2.0066
poids            : 86.26 $


Informations sur la personne dont la taille est la plus petite:
sexe             : feminin
numero           : 4433
taille           : 1.4732
poids            : 57.658 $


Informations sur la personne dont le poids est le plus petit:
sexe             : feminin
numero           : 4100
taille           : 1.651
poids            : 54.026 $


Taille moyenne des hommes: 1.778
Poids moyen des femmes: 69.4998

Resultats des recherches dans la liste de personnes:
sexe             : masculin
numero           : 4433
taille           : 1.8796
poids            : 85.806 $

sexe             : feminin
numero           : 2879
taille           : 1.8796
poids            : 84.898 $

9876 => introuvableS

*/
