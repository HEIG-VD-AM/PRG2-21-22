/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.h

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 24.05.22

 Description    : Module qui permet de calculer la taxe due pour un véhicule donné.
 						Il permet aussi de comparer les taxes de deux véhicules.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_LABO02_TAXES_H
#define PRG2_LABO02_TAXES_H

#include "vehicule.h"

// Taxes de bases pour tous les véhicules selon leur type
static const double TAXE_BASE_VOITURE = 400;
static const double TAXE_BASE_CAMIONNETTE = 700;

// Taxes spécifiques aux camionnettes
static const double TAXE_VOLUME_TRANSPORT = 10;

// Taxes spécifiques aux voitures standards
static const uint16_t LIMITE_CYLINDREE = 1400;
static const uint16_t LIMITE_REJET_CO2 = 130;
static const double TAXE_CYLINDREE_LIMITE_INF = 50;
static const double TAXE_CYLINDREE_LIMITE_SUP = 0.05;

// Taxes spécifiques aux voitures haut de gammes
static const uint16_t LIMITE_PUISSANCE = 250;
static const double TAXE_PUISSANCE_MOTEUR_LIMITE_SUP = 300;
static const double TAXE_PUISSANCE_MOTEUR_LIMITE_INF = 200;
static const double TAXE_PAR_KG = 0.02;

/// Calcul de la taxe annuelle pour un véhicule donné en fonction de ses
/// caractéristiques.
/// \param v Véhicule dont on calcul les taxes
/// \return Taxe annuelle
double calculTaxeAnnuelle(const Vehicule* v);

/// Fonction à donner au qsort pour trier les véhicules par taxe
/// \param a Premier objet à comparer
/// \param b Second objet à comparer
/// \return -1 si la taxe de b est plus petite que celle de a
///          0 si la taxe de b est égal à la taxe de a
///          1 si la taxe de b est plus grande que celle de a
int cmpTaxe(const void* a, const void* b);

#endif //PRG2_LABO02_TAXES_H
