/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 24.05.22

 Description    : Programme principal dans lequel on va tester la création d'un
 			  			parking de véhicules (représenté par un tableau), ceux-ci sont
 			  			présents dès la compilation (créés en dur). Une fois
 			  			celui-ci créé, on exécute d'abord un premier tri par taxe
 			  			décroissant et on affiche les caractéristiques de chaque
 			  			véhicule, ainsi que leur taxe. Le programme possède un second
 			  			affichage qui affiche chaque catégorie de véhicule présente dans
 			  			le tableau, ainsi que leurs diverses statistiques (somme,
 			  			moyenne, médiane et écart-type). Avant de calculer ces
 			  			statistiques, on procède à un tri par type de véhicule afin de
 			  			faciliter la sélection des différents types présents.

 Remarque(s)    : - Le programme contient 2 affichages : L'affichage des véhicules
						  et de toutes ses caractéristiques et l'affichage des
						  statistiques sur les taxes de chaque type de véhicule.
						- Le programme a été découpé en plusieurs modules, afin de
						  respecter la modularité. Il est donc nécessaire d'utiliser la
						  compilation séparée.
						- Aucune saisie utilisateur n'est requise dans ce programme.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "vehicule.h"
#include "affichage.h"
#include "parking.h"

int main(void) {

	// Tableau non constant, car celui-ci est trié donc modifié plusieurs fois.
	Vehicule parking[] = {
		voitureStandard("Peugeot", "VD123456", 1400, 200, 120),
		voitureHautDeGamme("Ferrari", "BE80085", 900, 800),
		camionnette("Suzuki", "VS24816", 2.5),
		voitureHautDeGamme("Rolls-Royce", "VS634432", 1400, 220),
		voitureStandard("Volvo", "FR753684", 450, 100, 250),
		voitureStandard("Citroen", "JR156489", 1200, 1400, 100)
	};

	const size_t NB_VEHICULES = sizeof(parking) / sizeof(Vehicule);

	trierParkingParTaxe(parking, NB_VEHICULES);
	afficherParking(parking, NB_VEHICULES);

	trierParkingParType(parking, NB_VEHICULES);
	afficherParkingStatistiquesParType(parking, NB_VEHICULES);

	return EXIT_SUCCESS;
}
