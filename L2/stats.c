/*
 -----------------------------------------------------------------------------------
 Nom du fichier : stats.c

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 24.05.22

 Description    : Fonctions de calcul mathématique recevant des tableaux de double
 					   en paramètres

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "stats.h"

int cmpDouble(const void* a, const void* b) {

	assert(a && b);
	double val1 = *(double*) a;
	double val2 = *(double*) b;

	if (val1 > val2) {
		return 1;
	}
	else if (val1 < val2) {
		return -1;
	}
	else return 0;
}

double mediane(const double* tab, size_t taille) {

	assert(tab && taille);
	double resultat;

	// Créer et trier le tableau temporaire
	double* temp = (double*) calloc(taille, sizeof(double));
	assert(temp);

	memcpy(temp, tab, taille * sizeof(double));
	qsort(temp, taille, sizeof(double), cmpDouble);

	// La ligne suivante determine la médiane tous les cas (taille paire ou impaire)
	resultat = ((temp[(taille - 1) / 2] + temp[taille / 2])) / 2;

	free(temp);
	temp = NULL;

	return resultat;
}

double moyenne(const double* tab, size_t taille) {

	assert(tab && taille);

	return somme(tab, taille) / (double) taille;
}

double somme(const double* tab, size_t taille) {

	assert(tab && taille);

	double resultat = 0.0;

	for (size_t i = 0; i < taille; i++)
		resultat += tab[i];

	return resultat;
}

double ecartType(const double* tab, size_t taille) {

	assert(tab && taille);

	double moyenneTableau = moyenne(tab, taille);
	double resultat = 0.0;

	for (size_t i = 0; i < taille; i++)
		resultat += pow(tab[i] - moyenneTableau, 2);

	return sqrt(resultat / (double) taille);
}


