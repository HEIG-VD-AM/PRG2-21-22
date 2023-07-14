/*
 -----------------------------------------------------------------------------------
 Nom du fichier : stats.h

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 24.05.22

 Description    : Ce fichier contient les déclarations de plusieurs fonctions
                  mathématiques pour calculer certaines statistiques d'un ensemble.

 Remarque(s)    : Les fonctions déclarées dans ce fichier sont faites pour être
                  utilisées sur des données au format double. Dans d'autres cas le
                  fonctionnement n'est pas garantie.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_LABO02_STATS_H
#define PRG2_LABO02_STATS_H

#include <stdlib.h>

/// Fonction qui retourne la valeur médiane d'un tableau de double.
/// \param tab pointeur sur le premier élément du tableau.
/// \param taille nombre d'éléments contenus dans le tableau.
/// \return valeur médiane.
double mediane(const double* tab, size_t taille);

/// Fonction qui retourne la valeur moyenne d'un tableau de double.
/// \param tab pointeur sur le premier élément du tableau.
/// \param taille nombre d'éléments contenus dans le tableau.
/// \return valeur moyenne.
double moyenne(const double* tab, size_t taille);

/// Fonction qui retourne la somme des valeurs d'un tableau de double.
/// \param tab pointeur sur le premier élément du tableau.
/// \param taille nombre d'éléments contenus dans le tableau.
/// \return valeur de la somme.
double somme(const double* tab, size_t taille);

/// Fonction qui retourne la valeur de l'écart-type d'un tableau de double.
/// \param tab pointeur sur le premier élément du tableau.
/// \param taille nombre d'éléments contenus dans le tableau.
/// \return valeur de l'écart-type.
double ecartType(const double* tab, size_t taille);

/// Fonction pour qsort() afin de trié des doubles de manière croissante.
/// \param a pointeur sur le premier élément à comparer.
/// \param b pointeur sur le deuxième élément à comparer.
/// \return -1 si le type de a est plus petit que celui de b
///          0 si le type de a est égal à le type de b
///          1 si le type de a est plus grand que celui de b
int cmpDouble(const void* a,const void* b);

#endif //PRG2_LABO02_STATS_H
