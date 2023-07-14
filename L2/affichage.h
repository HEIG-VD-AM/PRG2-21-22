/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.h

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 30.05.22

 Description    : Module qui permet de gérer les différents affichages du
 						programme. C'est-à-dire l'affichage pour un véhicule, pour le
 						parking entier et pour les statistiques du parking.

 Remarque(s)    : - Nous avons mis à disposition des constantes pour que les
 						  utilisateurs puissent modifier les différents champs et unités
 						  du programme si besoin.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/
#ifndef PRG2_LABO02_AFFICHAGE_H
#define PRG2_LABO02_AFFICHAGE_H

#include "vehicule.h"

// Taille max pour les champs à afficher
static const int TAILLE_CHAMP = 20;

// En-tête pour l'affichage du parking
static const char* const ENTETE_PARKING = "--------Affichage des statistiques de "
														"chaque vehicule--------";

// En-tête pour l'affichage des statistiques par type de véhicule
static const char* const ENTETE_STATISTIQUES = "-------Affichage des statistiques "
														 "du parking par type de vehicule-------";

//En-tête pour l'affichage d'un véhicule
static const char * const ENTETE_PAR_VEHICULE = "Vehicule";

//Unités utilisées pour les différentes caractéristiques des véhicules
static const char* const UNITE_PUISSANCE = "CV";
static const char* const UNITE_VOLUME = "m3";
static const char* const UNITE_CYLINDREE = "cm3";
static const char* const UNITE_REJETCO2 = "g/km";
static const char* const UNITE_POIDS = "kg";

// Champs pour l'affichage des caractéristiques
static const char* const TYPE_VEHICULE = "Type de vehicule";
static const char* const MARQUE = "Marque";
static const char* const PLAQUE = "Plaque";
static const char* const TYPE_VOITURE = "Type de voiture";
static const char* const POIDS = "Poids";
static const char* const CYLINDREE = "Cylindree";
static const char* const REJET_CO2 = "Rejet Co2";
static const char* const PUISSANCE = "Puissance";
static const char* const VOLUME_TRANSPORT = "Volume de transport";
static const char* const TAXE_ANNUELLE = "Taxe annuelle";

// Champs pour l'affichage des taxes
static const char* const SOMME = "Somme";
static const char* const MOYENNE = "Moyenne";
static const char* const MEDIANE = "Mediane";
static const char* const ECART_TYPE = "Ecart type";

// Devise utilisée pour les taxes
static const char* const DEVISE = "CHF";

/// Affiche le type du véhicule parmi ceux disponibles
/// \param v Véhicule dont on souhaite afficher le type
void affichageTypeDeVehicule(const Vehicule* v);

/// Affiche un véhicule et toutes ses caractéristiques
/// \param v Véhicule à afficher
void affichageVehicule(const Vehicule* v);

/// Affiche individuellement chaque véhicule du parking ainsi que toutes les
/// caractéristiques de chacun des véhicules.
/// \param p Tableau contenant des structures véhicules
/// \param nbreDeVehiculesDansLeParking Taille du parking
void afficherParking(const Vehicule* p, size_t nbreDeVehiculesDansLeParking);

/// Affiche un résumé des caractéristiques de chaque catégorie de véhicule.
/// Il faut que le parking soit trié au préalable par type de véhicule.
/// \param p Tableau contenant des structures véhicules
/// \param nbreDeVehiculesDansLeParking Taille du parking
void afficherParkingStatistiquesParType(const Vehicule* p,
													 size_t nbreDeVehiculesDansLeParking);

#endif //PRG2_LABO02_AFFICHAGE_H
