/*
 -----------------------------------------------------------------------------------
 Nom du fichier : vehicule.c

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 24.05.22

 Description    : Dans ce module, il est possible de créer des véhicules et de les
 						gérer. Chaque type de véhicule possède une fonction de création.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include "vehicule.h"

const char* vehiculeCorrespondance[] = {
	"Voiture",
	"Camionnette"
};

const char* voitureCorrespondance[] = {
	"Standard",
	"Haut de gamme"
};

Vehicule camionnette(const char* marque, const char* plaque, double
                     volumeDeTransport) {

	// On était obligé de marquer la différente de 0.0 pour éviter une conversion
	// implicite
	assert(marque && plaque && volumeDeTransport != 0.0);

	Vehicule camionnette = {
		.tagVehicule = CAMIONNETTE,
		.marque = marque,
		.plaque = plaque,
		.typeVehicule.camionnette.volumeDeTransport = volumeDeTransport
	};

	return camionnette;
}

Vehicule voitureHautDeGamme(const char* marque, const char* plaque, uint16_t poids,
									 uint16_t puissance) {

	assert(marque && plaque && poids && puissance);

	Vehicule voitureHautDeGamme = {
		.tagVehicule = VOITURE,
		.typeVehicule.voiture.tagVoiture = HAUT_DE_GAMME,
		.marque = marque,
		.plaque = plaque,
		.typeVehicule.voiture.poids = poids,
		.typeVehicule.voiture.typeVoiture.voitureHautDeGamme.puissance = puissance
	};

	return voitureHautDeGamme;
}

Vehicule voitureStandard(const char* marque, const char* plaque, uint16_t poids,
								 uint16_t cylindree, uint16_t rejetCO2) {

	// On teste que tous les champs soient différents de NULL/0, sauf le rejet de
	// C02 dans le cas des véhicules électriques et autres types de véhicules sans
	// rejet.
	assert(marque && plaque && poids && cylindree);

	Vehicule voitureStandard = {
		.tagVehicule = VOITURE,
		.typeVehicule.voiture.tagVoiture = STANDARD,
		.marque = marque,
		.plaque = plaque,
		.typeVehicule.voiture.poids = poids,
		.typeVehicule.voiture.typeVoiture.voitureStandard.rejetCO2 = rejetCO2,
		.typeVehicule.voiture.typeVoiture.voitureStandard.cylindree = cylindree
	};

	return voitureStandard;
}

// ID = 0bxxxyyy00
//        ^^^||||| -> bits de type de véhicule
//           ^^^|| -> bits de type spécifique (si besoin)
//              ^^ -> bits reservé pour une utilisation future
uint8_t recupererIDdeType(const Vehicule* v) {

	assert(v);

	const uint8_t CHAMP_VEHICULE = 3;
	const uint8_t CHAMP_SPECIFICITE = 3;
	uint8_t id = (uint8_t) ((uint8_t) v->tagVehicule <<
		          (sizeof(id) * 8 - CHAMP_VEHICULE));

	switch (v->tagVehicule) {
		case VOITURE:
			id += (uint8_t) ((uint8_t) v->typeVehicule.voiture.tagVoiture <<
				   (sizeof(id) * 8 - CHAMP_VEHICULE - CHAMP_SPECIFICITE));
			break;
		case CAMIONNETTE:
			break;
	}

	return id;
}

int cmpType(const void* a, const void* b) {

	assert(a && b);

	uint8_t class1 = recupererIDdeType((const Vehicule*) a);
	uint8_t class2 = recupererIDdeType((const Vehicule*) b);

	return (int) class1 - (int) class2;
}



