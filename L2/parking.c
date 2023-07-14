/*
 -----------------------------------------------------------------------------------
 Nom du fichier : parking.c

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 24.05.22

 Description    : Fonctions d'affichage et de tri du parking qui prennent des
						tableaux de véhicules en paramètres

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdlib.h>
#include "parking.h"
#include "taxes.h"

double* recupererTaxesParking(const Vehicule* p,
										size_t nbreDeVehiculesDansLeParking) {

	assert(nbreDeVehiculesDansLeParking && p);

	double* tableauTaxes = (double*) calloc(nbreDeVehiculesDansLeParking, sizeof
								  (double));

	assert(tableauTaxes != NULL);

	for (size_t i = 0; i < nbreDeVehiculesDansLeParking; ++i) {
		tableauTaxes[i] = calculTaxeAnnuelle(p + i);
	}

	return tableauTaxes;
}

void trierParkingParType(Vehicule* p, size_t nbreDeVehiculesDansLeParking) {

	assert(nbreDeVehiculesDansLeParking && p);
	qsort((void*) p, nbreDeVehiculesDansLeParking, sizeof(Vehicule), cmpType);
}

void trierParkingParTaxe(Vehicule* p, size_t nbreDeVehiculesDansLeParking) {

	assert(nbreDeVehiculesDansLeParking && p);
	qsort((void*) p, nbreDeVehiculesDansLeParking, sizeof(Vehicule), cmpTaxe);
}
