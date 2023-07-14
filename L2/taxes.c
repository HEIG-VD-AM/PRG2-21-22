/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.c

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 24.05.22

 Description    : Calcul des taxes pour un véhicule du module vehicule.h.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include "taxes.h"
#include "stats.h"

double calculTaxeAnnuelle(const Vehicule* v) {

	assert(v);
	double taxeAnnuelleTotale = 0;

	switch (v->tagVehicule) {
		case VOITURE:

			taxeAnnuelleTotale += TAXE_BASE_VOITURE;

			switch (v->typeVehicule.voiture.tagVoiture) {
				case STANDARD:
					if (v->typeVehicule.voiture.typeVoiture.voitureStandard.cylindree <
						 LIMITE_CYLINDREE && v->typeVehicule.voiture.typeVoiture
						.voitureStandard.rejetCO2 >= LIMITE_REJET_CO2) {
						taxeAnnuelleTotale += TAXE_CYLINDREE_LIMITE_INF;
					}
					else if (v->typeVehicule.voiture.typeVoiture.voitureStandard
								.cylindree >= LIMITE_CYLINDREE) {
						taxeAnnuelleTotale += TAXE_CYLINDREE_LIMITE_SUP *
						v->typeVehicule.voiture.typeVoiture.voitureStandard.cylindree;
					}
					break;

				case HAUT_DE_GAMME:
					if (v->typeVehicule.voiture.typeVoiture.voitureHautDeGamme.puissance
						 <= LIMITE_PUISSANCE) {
						taxeAnnuelleTotale += TAXE_PUISSANCE_MOTEUR_LIMITE_INF;
					}
					else {
						taxeAnnuelleTotale += TAXE_PUISSANCE_MOTEUR_LIMITE_SUP +
												    TAXE_PAR_KG * v->typeVehicule.voiture.poids;
					}
					break;
			}
			break;

		case CAMIONNETTE:
			taxeAnnuelleTotale += TAXE_BASE_CAMIONNETTE;
			taxeAnnuelleTotale += TAXE_VOLUME_TRANSPORT *
				                   v->typeVehicule.camionnette.volumeDeTransport;
			break;
	}

	return taxeAnnuelleTotale;
}

int cmpTaxe(const void* a, const void* b) {

	assert(a && b);

	double taxe1 = calculTaxeAnnuelle((const Vehicule*) b);
	double taxe2 = calculTaxeAnnuelle((const Vehicule*) a);

	return cmpDouble((const void*) &taxe1, (const void*) &taxe2);
}
