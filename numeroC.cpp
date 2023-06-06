/* 
    TP2 - numero C

    Auteure: Annie Rhéaume
    Date: 05-06-2023

    source: fichier Tab_Pers.cpp

    Version 1: 
      -dans cette version, j'ai modifié les méthodes statiques et les appels
      dans le main en lien avec le tri rapide et la recherche dichotomique
        --> Patron de fonction, pour le QUICKSORT
          ----> surcharge des opérateurs de comparaison pour comparer les objets
        --> Patron de fonction pour le BINARYSEARCH + version RÉCURSIVE
          ----> surchage des opérateurs + constructeur (ajout de 4: numero seulement)
          pour comparaison des objets
      -NUMERO C: à présent, comprend les nouveautés en lien avec la manipulation
      d'objets dans des tableaux.

      - Il me reste à réviser cette version pour la remise.

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

    // Constructeur 1: tous les paramètres      
    Personne(char sexe, int numero, float taille, float poids);
    
    // Constructeur 2: par défaut explicite (sans paramètre) 
    Personne()  {} 

    // Constructeur 3: de recopie explicite
    Personne (const Personne&); 

    // Constructeur 4: un paramètre (numero)
    Personne (int numero);

    // Déclaration des 'getters' pour les champs de la classe Personne
    float getTaille();
    float getPoids();
    int getNumero(); 
    char getSexe();

    // Déclaration des 'setters' pour les champs de la classe Personne
    void setNumero(int val);

    // Déclaration fonction membre afficher
    void afficher();

    //Déclaration des opérateurs surdéfinis
    bool operator<= (const Personne&);
    bool operator>= (const Personne&); 
    bool operator== (const Personne&);
    bool operator< (const Personne&);    

};

// MÉTHODES DE LA CLASSE PERSONNE

/*
  Définition du contructeur 1: avec paramètres (tous les champs)
*/
Personne::Personne(char sexe, int numero, float taille, float poids)
      {
        this->sexe = sexe;
        this->numero = numero;
        this->taille = taille;
        this->poids = poids;            
      } 


/*
    Définition du constructeur 3: de recopie explicite
*/
    
    Personne::Personne(const Personne& autre ){
        this->sexe = autre.sexe;
        this->numero = autre.numero;
        this->taille = autre.taille;
        this->poids = autre.poids; 
    }

/*
    Définition du constructeur 4: 1 paramètre (numero)
*/    
    Personne::Personne(int numero ){
        this->numero = numero; 
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
  cout << "taille           : " << setprecision(2) << taille << " metre" << endl ;
  cout << "poids            : " << setprecision(1) << poids << " kg\n\n";
}
/*
    Comparateur selon l'attribut numero
    Surcharge operateur <= 
*/
bool Personne::operator<= (const Personne& autre){
    if (this->numero <= autre.numero)
        return true;
    return false;
}

/*
    Comparateur selon l'attribut numero
    Surcharge operateur  >= 
*/
bool Personne::operator>= (const Personne& autre){
    if (this->numero >= autre.numero)
        return true;
    return false;
}

/*
    Surcharge opérateur ==
*/
bool Personne::operator==(const Personne& autre){
  if (this->numero == autre.numero)
      return true;
  return false;
}

/*
    Surcharge opérateur <
*/
bool Personne::operator<(const Personne& autre){
  if (this->numero < autre.numero)
      return true;
  return false;
}

// MÉTHODES STATIQUES

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

// QUICKSORT

/*
    Echange les objets dans un tableau selon les indices fournis en paramètre
    Patron de fonction (copie possible objets de même type via constructeur de recopie)
*/
template<class T>
void permuter(T tab[], int indiceA, int indiceB){
    Personne temp = tab[indiceA];
    tab[indiceA] = tab[indiceB];
    tab[indiceB] = temp;
}

/*
    Trie un tableau d'objets de même type selon les opérateurs de comparaison surdéfinis 
    dans la classe. Ne retourne rien (modification 'sur place').
    Algorithme tri rapide récursif
    Patron de fonction (copue possible objets de même type via constructeur de recopie)
*/
template <class T>
void trier(T tab[], int indiceMin, int indiceMax){
    
    // Condition de sortie de la boucle récursive
    if(indiceMin >= indiceMax)
        return;

    // Sélectionner un pivot
    Personne pivot = tab[indiceMax];                    // CONSTRUCTEUR RECOPIE PAR DEFAUT

    // Créer traceurs gauche et droite
    int g = indiceMin;
    int d = indiceMax;

    // Aussi longtemps que les traceurs gauche et droite ne se rencontrent pas
    while(g < d){

        // On cherche une valeur plus petite que le pivot
        while(tab[g] <= pivot && g < d){                // SURCHARGE OPERATEUR <= DANS PERSONNE
            g++;
        }

        // On cherche une valeur plus grande que le pivot
        while(tab[d] >= pivot && g < d){                // SURCHARGE OPERATEUR >= DANS PERSONNE
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

// RECHERCHE DICHOTOMIQUE

/*
   Recherche une valeur (clé) dans un tableau d'objets de même type selon les opérateurs de
   comparaison surdéfinis dans la classe. Retourne l'indice de la clé (type int).
   Algorithme de recherche dichotomique récursif
   Patron de fonction (copie possible objets de même type via constructeur de recopie)
*/
   template <class T>
   int rechercher(T tab[], int indiceMin, int indiceMax, T cle) {  

      // condition de sortie de la boucle récursive : lorsque les indices se rencontrent
      if (indiceMin > indiceMax)
         return -1; // recherche infructueuse

      int milieu = (indiceMin + indiceMax) / 2;
      Personne valeurMilieu = tab[milieu];                     // CONSTRUCTEUR DE RECOPIE PAR DÉFAUT

      // La valeur recherchée est celle de la position du milieu
      if (cle == valeurMilieu)                                 // ON COMPARE 2 OBJETS PERSONNE: SURCHARGE ==
         return milieu;
      
      // Sinon , on continue la recherche à gauche
      if (cle < valeurMilieu)                                  // ON COMPARE 2 OBJETS PERSONNE: SURCHARGE <
         rechercher(tab, indiceMin, milieu - 1, cle);
      else  //si n'est pas à gauche, on avance à droite
         rechercher(tab, milieu + 1, indiceMax, cle);  
   } 

/*
  Fonction qui permet d'afficher le résultat d'une recherche dans le tableau d'objets Personne.
  Ne retoune rien.
*/
template <class T>
void afficherResultatRecherche(T tab[], int nbPers, int valeurRecherchee, int indice){
  if (indice == -1){
  cout << valeurRecherchee << " => introuvable";
  } else {
  tab[indice].afficher();
  }
}  

//  PROGRAMME PRINCIPAL
int main() {

  // Nécessaire pour le format d'affichage des réels (nombre de décimales après la virgule)
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);  
 
 const int MAX_PERS = 30 ;
 Personne pers[MAX_PERS];
 int nbPers;
 
 lireRemplir("imp_e23.txt", pers, nbPers);
 
 cout << "\nOn a lu les infos de " << nbPers << " personnes\n";
 cout << endl;

 // Afficher la liste des personnes (tableau des objets de type Personne)
//afficherListePersonnes("Liste non triee", pers, nbPers);

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
//afficherListePersonnes("Liste triee", pers, nbPers);

// Rechercher et afficher les informations des enregistrements dont le numéro d'identifiant est: 4433,2879,9876
cout << "Resultats des recherches dans la liste de personnes:  " << endl;
Personne cle1 = Personne(4433);
Personne cle2 = Personne(2879);
Personne cle3 = Personne(9873);
afficherResultatRecherche(pers, nbPers, 4433, rechercher(pers, 0, nbPers -1, cle1));
afficherResultatRecherche(pers, nbPers, 2879, rechercher(pers, 0, nbPers -1, cle2));
afficherResultatRecherche(pers, nbPers, 9876, rechercher(pers, 0, nbPers -1, cle3));
 
 return 0; 
}


/*
    AFFICHAGE (fichier modifié) - sans listes complètes

    C:\Users\Annie\Desktop\cppTP2>numeroC.exe

    On a lu les infos de 20 personnes

    Informations sur la personne dont la taille est la plus grande: 
    sexe             : feminin
    numero           : 5678
    taille           : 2.01 metre
    poids            : 86.3 kg


    Informations sur la personne dont la taille est la plus petite: 
    sexe             : feminin
    numero           : 4433
    taille           : 1.47 metre
    poids            : 57.7 kg


    Informations sur la personne dont le poids est le plus petit:
    sexe             : feminin
    numero           : 4100
    taille           : 1.65 metre
    poids            : 54.0 kg


    Taille moyenne des hommes: 1.8
    Poids moyen des femmes: 69.5

    Resultats des recherches dans la liste de personnes:
    sexe             : feminin
    numero           : 4433
    taille           : 1.47 metre
    poids            : 57.7 kg

    sexe             : masculin
    numero           : 2879
    taille           : 1.88 metre
    poids            : 86.7 kg

    9876 => introuvable


    AFFICHAGE (fichier modifié) - sans listes complètes
*/
