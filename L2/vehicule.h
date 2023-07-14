/*
 -----------------------------------------------------------------------------------
 Nom du fichier : vehicule.h

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 24.05.22

 Description    : Module fournissant toute la structure d'un véhicule, des
 						fonctions pour les créer en passant leurs caractéristiques,
 						des fonctions pour les comparer et pour leur assigner un ID.

 Remarque(s)    : On peut retrouver ci-dessous la structure de nos véhicules
						Vehicule (struct)
						|---TypeVehicule (union)
						|   |---Voiture (struct)
						|   |   |---TypeVoiture (union)
						|   |   |   |---VoitureStandard (struct)
						|   |   |   |   |---Cylindree (uint16_t)
						|   |   |   |   |---RejetCo2 (uint16_t)
						|   |   |   |---VoitureHautDeGamme (struct)
						|   |   |   |   |---Puissance (uint16_t)
						|   |   |---TagVoiture (enum)
						|   |   |---Poids (uint16_t)
						|   |---Camionnette (struct)
						|       |---VolumeDeTransport (double)
						|---TagVehicule (enum)
						|---Marque (const char*)
						|---Plaque (const char*)

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_LABO02_VEHICULE_H
#define PRG2_LABO02_VEHICULE_H

#include <inttypes.h>

// Tableau de correspondance pour les types de véhicules
// par rapport à l'énumération TagVehicule définie dans vehicule.h
extern const char* vehiculeCorrespondance[];

// Tableau de correspondance pour les types de voitures
// par rapport à l'énumération TagVoiture définie dans vehicule.h
extern const char* voitureCorrespondance[];

typedef enum {
	VOITURE, CAMIONNETTE
} TagVehicule;

typedef enum {
	STANDARD, HAUT_DE_GAMME
} TagVoiture;

typedef struct {
	uint16_t cylindree;			// Unité : cm3
	uint16_t rejetCO2;			// Unité : g/km
} VoitureStandard;

typedef struct {
	uint16_t puissance;			// Unité : CV
} VoitureHautDeGamme;

typedef union {
	VoitureStandard voitureStandard;
	VoitureHautDeGamme voitureHautDeGamme;
} TypeVoiture;

typedef struct {
	TagVoiture tagVoiture;
	TypeVoiture typeVoiture;
	uint16_t poids;				// Unité : kg
} Voiture;

typedef struct {
	double volumeDeTransport;	// Unité : m3
} Camionnette;

typedef union {
	Voiture voiture;
	Camionnette camionnette;
} TypeVehicule;

typedef struct {
	const char* marque;
	const char* plaque;
	TagVehicule tagVehicule;
	TypeVehicule typeVehicule;
} Vehicule;

/// Sert à créer plus facilement une structure véhicule de type camionnette
/// \return Copie de structure véhicule de type camionnette
Vehicule camionnette(const char* marque, const char* plaque, double
                     volumeDeTransport);

/// Sert à créer plus facilement une structure véhicule de type voiture haut de gamme
/// \return Copie de structure véhicule de type voiture haut de gamme
Vehicule voitureHautDeGamme(const char* marque, const char* plaque, uint16_t poids,
									 uint16_t puissance);

/// Sert à créer plus facilement une structure véhicule de type voiture standard
/// \return Copie de structure véhicule de type voiture standard
Vehicule voitureStandard(const char* marque, const char* plaque, uint16_t poids,
								 uint16_t cylindree, uint16_t rejetCO2);

/// Compare les types de véhicules grâce à leur ID qui est créer dans recupererType.
/// Fonction qui sert de fonction de comparaison pour qsort. La comparaison se
/// fait selon l'ordre des types est déterminé par l'énumération des types dans
/// vehicule.h
/// \param a Premier objet à comparer
/// \param b Second objet à comparer
/// \return -1 si le type de a est plus petit que celui de b
///          0 si le type de a est égal à le type de b
///          1 si le type de a est plus grand que celui de b
int cmpType(const void* a, const void* b);

/// Récupère à quelle catégorie appartient le véhicule en assignant un ID à chaque
/// catégorie.
/// \param v Véhicule à dont on souhaite récupérer le type
/// \return ID attribué à ce type de véhicule
uint8_t recupererIDdeType(const Vehicule* v);

#endif //PRG2_LABO02_VEHICULE_H
