/* 
    TP2 - numero B

    Auteure: Annie Rhéaume
    Date: 21-05-2023

    Version 1: ajout des algorithmes de quicksort et recherche
    dichotomique.
*/

#include <iostream>  // pour entree-sortie  cin, cout
#include <iomanip>   // pour le formatage
#include <fstream>   // pour les fichiers
#include <string>
#include <float.h>

using namespace std; // librairie standard

/*
   Structure de données (de type structure) du fichier structure.cpp
   Fournie pour le TP2
*/

   struct Employe {
         char sexe ;
         int  numero;
         float salHebdo ;  
         
         void afficher(string mess)
         {
            cout << mess << " :\n";
            cout << "sexe             : " << (sexe == 'F'? "feminin" : "masculin") << endl ;
            cout << "numero           : " << numero << endl ;
            cout << "sal. hebdo.      : " << salHebdo << " $\n\n";
         }            
   };

   /* 
      Fonction qui lit une fichier .txt et qui crée un tableau de structures.
      de type Employe. Fonction du fichier structure.cpp
      Fournie pour le TP2
   */    
      
    void lireRemplir(const char nomALire[], Employe emp[], int & n)                     
     {   
        float nbHr, tauxHr;
        ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture
		   	   
	    n = 0; // initialiser le compteur
				
		while (aLire >> emp[n].sexe >> emp[n].numero >> nbHr >> tauxHr)
            emp[n++].salHebdo = nbHr * tauxHr;
		
		aLire.close();   
     }
	
   // NOUVELLES MÉTHODES (TP2)

   //Quicksort

   /*
      Fonction qui prend en paramètre un tableau de structures et les indices
      de 2 valeurs à permuter dans le tableau. Ne retourne rien.
      Spécifique au type Employe, pour accéder à son membre données 'numero'
   */
   void permuter(Employe tab[], int indiceA, int indiceB){
      int temp = tab[indiceA].numero;
      tab[indiceA].numero = tab[indiceB].numero;
      tab[indiceB].numero = temp;
   }

   /*
      Fonction qui trie les structs d'un tableau selon l'ordre croissant du
      numéro d'employé. Ne retourne rien.
      Spécifique au type Employe, pour accéder à son membre données 'numero'
      Implémentation d'un algorithme du tri rapide (quicksort)
   */

      void trier(Employe tab[], int indiceMin, int indiceMax){

      // Condition de sortie de la boucle récursive
      if(indiceMin >= indiceMax)
         return;

      // Sélectionner un pivot
      int pivot = tab[indiceMax].numero;

      // Créer traceurs gauche et droite
      int g = indiceMin;
      int d = indiceMax;

      // Aussi longtemps que les traceurs gauche et droite ne se rencontrent pas
      while(g < d){

         // On cherche une valeur plus petite que le pivot
         while(tab[g].numero <= pivot && g < d){
            g++;
         }

         // On cherche une valeur plus grande que le pivot
         while(tab[d].numero >= pivot && g < d){
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
      Fonction qui recherche une valeur (clé) dans un tableau de structs trié selon
      le membre données 'numero'. Retourne l'indice de la valeur recherchee, ou -1,
      si absente.
      Spécifique au type Employe, pour accéder à son membre données 'numero'
      Implémentation d'un algorithme de recherche dichotomique (binary search)
   */

   int rechercher(Employe tab[], int nbElem, int cle) {  
      
      // Traceurs gauche et droit
      int indiceMin = 0;
      int indiceMax = nbElem-1;

      //Jusqu'à ce que les traceurs se rencontrent...
      while (indiceMin <= indiceMax)
      {
         int milieu = (indiceMin + indiceMax) / 2;
         int valeurMilieu = tab[milieu].numero;

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
      Fonction qui permet d'afficher tous les éléments du tableau de structs
   */

   void afficherListeEmployes(Employe tab[], int nbEmp){

      for (int i = 0; i  < nbEmp ; i++){
         cout << "Element - " << i << endl;
         tab[i].afficher("");
      }

   } 

   /*
      Fonction qui permet d'afficher le résultat (en mots) de la recherche d'une valeur dans le tableau
   */

   void afficherResultatRecherche(Employe tab[], int nbEmp, int valeurRecherchee, int indice){
      if (indice == -1){
      cout << valeurRecherchee << " => introuvable";
   } else {
      tab[indice].afficher("");
   }
   }         

   // Programme principal
   int main() {
      
      const int MAX_EMP = 100;
      Employe emp[MAX_EMP];
      int nbEmp ;

      // Créer un tableau de structures 'Employe' à partir d'un fichier .txt
      lireRemplir("employe.txt", emp, nbEmp);

      // Trier le tableau de structures selon le numéro d'employé
      trier(emp, 0, nbEmp-1);

      afficherListeEmployes(emp, nbEmp);

      // Rechercher dans le tableau des employés les numéros: 272, 607, 993
      afficherResultatRecherche(emp, nbEmp, 272,rechercher(emp, nbEmp, 272));
      afficherResultatRecherche(emp, nbEmp, 607,rechercher(emp, nbEmp, 607));
      afficherResultatRecherche(emp, nbEmp, 993,rechercher(emp, nbEmp, 993));

      return 0;

   }


   /*
      AFFICHAGE:

         C:\Users\Annie\Desktop\cppTP2>numeroB.exe
         :
         sexe             : masculin
         numero           : 272
         sal. hebdo.      : 389.5 $

         :
         sexe             : masculin
         numero           : 607
         sal. hebdo.      : 379.25 $

         993 => introuvable      
   */
    