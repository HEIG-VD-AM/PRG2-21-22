/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.c

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 30.05.22

 Description    : Gestion des affichages pour les véhicules, le parking et les
						statistiques.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "affichage.h"
#include "taxes.h"
#include "parking.h"
#include "stats.h"

// Taille max du buffer pour afficher les types de véhicule
#define TAILLE_MAX_TYPE_VEHICULE 64

void affichageTypeDeVehicule(const Vehicule* v) {

	assert(v);

	char reponse[TAILLE_MAX_TYPE_VEHICULE] = "";
	strcpy(reponse, vehiculeCorrespondance[v->tagVehicule]);

	switch (v->tagVehicule) {
		case VOITURE:
			strcat(reponse, " ");
			strcat(reponse, voitureCorrespondance[v->typeVehicule.voiture.tagVoiture]);
			break;
		case CAMIONNETTE:
			break;
	}

	printf("-------%s-------\n", reponse);
}

void affichageVehicule(const Vehicule* v) {

	assert(v);

	printf("%-*s: %s\n", TAILLE_CHAMP, TYPE_VEHICULE,
			 vehiculeCorrespondance[v->tagVehicule]);
	printf("%-*s: %s\n", TAILLE_CHAMP, MARQUE, v->marque);
	printf("%-*s: %s\n", TAILLE_CHAMP, PLAQUE, v->plaque);

	// Premier switch afin de différencier le type de véhicule.
	// Un switch a été choisi au lieu d'une structure if-else afin de rester le
	// plus évolutif possible si l'on souhaite rajouter des types de véhicules ou
	// des types de voitures.
	switch (v->tagVehicule) {
		case VOITURE:
			printf("%-*s: %s\n", TAILLE_CHAMP, TYPE_VOITURE,
					 voitureCorrespondance[v->typeVehicule.voiture.tagVoiture]);
			printf("%-*s: %"PRIu16" %s\n", TAILLE_CHAMP, POIDS,
					 v->typeVehicule.voiture.poids, UNITE_POIDS);

			// Deuxième switch pour différencier le type de voiture.
			switch (v->typeVehicule.voiture.tagVoiture) {
				case STANDARD:
					printf("%-*s: %"PRIu16" %s\n", TAILLE_CHAMP, CYLINDREE,
							 v->typeVehicule.voiture.typeVoiture.voitureStandard.cylindree,
							 UNITE_CYLINDREE);
					printf("%-*s: %"PRIu16" %s\n", TAILLE_CHAMP, REJET_CO2,
							 v->typeVehicule.voiture.typeVoiture.voitureStandard.rejetCO2,
							 UNITE_REJETCO2);
					break;
				case HAUT_DE_GAMME:
					printf("%-*s: %"PRIu16" %s\n", TAILLE_CHAMP, PUISSANCE,
							 v->typeVehicule.voiture.typeVoiture.voitureHautDeGamme
							 .puissance, UNITE_PUISSANCE);
					break;
			}
			break;
		case CAMIONNETTE:
			printf("%-*s: %.2f %s\n", TAILLE_CHAMP, VOLUME_TRANSPORT,
					 v->typeVehicule.camionnette.volumeDeTransport,
					 UNITE_VOLUME);
			break;
	}
}

void afficherParking(const Vehicule* p, size_t nbreDeVehiculesDansLeParking) {

	assert(nbreDeVehiculesDansLeParking && p);

	printf("%s\n\n", ENTETE_PARKING);

	for (size_t i = 0; i < nbreDeVehiculesDansLeParking; ++i) {
		printf("-------%s #%lld-------\n", ENTETE_PAR_VEHICULE, i + 1);
		affichageVehicule(p + i);
		printf("%-*s: %.2f %s\n", TAILLE_CHAMP, TAXE_ANNUELLE,
				 calculTaxeAnnuelle(p + i), DEVISE);
		printf("\n");
	}
}

void afficherParkingStatistiquesParType(const Vehicule* p,
													 size_t nbreDeVehiculesDansLeParking) {

	assert(nbreDeVehiculesDansLeParking && p);

	double* tableauTaxes = recupererTaxesParking(p, nbreDeVehiculesDansLeParking);

	size_t indexBase = 0;

	printf("%s\n\n", ENTETE_STATISTIQUES);

	for (size_t i = 1; i < nbreDeVehiculesDansLeParking + 1; ++i) {

		if ((i == nbreDeVehiculesDansLeParking) || (recupererIDdeType(p + i) !=
		    recupererIDdeType(p + i - 1))) {

			double* tableauCalcul = tableauTaxes + indexBase;
			size_t taille = i - indexBase;


			affichageTypeDeVehicule(p + indexBase);
			printf("%-*s= %.2f %s\n", TAILLE_CHAMP, SOMME,
					 somme(tableauCalcul, taille), DEVISE);
			printf("%-*s= %.2f %s\n", TAILLE_CHAMP, MOYENNE,
					 moyenne(tableauCalcul, taille), DEVISE);
			printf("%-*s= %.2f %s\n", TAILLE_CHAMP, MEDIANE,
					 mediane(tableauCalcul, taille), DEVISE);
			printf("%-*s= %.2f %s\n", TAILLE_CHAMP, ECART_TYPE,
					 ecartType(tableauCalcul, taille), DEVISE);
			printf("\n");
			indexBase += taille;
		}
	}

	free(tableauTaxes);
	tableauTaxes = NULL;
}
