/*
 -----------------------------------------------------------------------------------
 Nom du fichier : parking.h

 Auteur(s)      : Ylli Fazlija
                  Alexis Martins
                  Loïc Brasey

 Date creation  : 24.05.22

 Description    : Permet l'affichage d'un tableau de véhicules (parking) selon
 					   l'ordre décroissant des taxes de chaque véhicule et l'affichage
 					   des statistiques de chaque type. On peut aussi utiliser ce
 					   module pour trier le parking par taxe et par type.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_LABO02_PARKING_H
#define PRG2_LABO02_PARKING_H

#include <stdlib.h>
#include "vehicule.h"

/// Création d'un tableau avec toutes les taxes des véhicules dans le parking.
/// \param p Parking dont on souhaite récupérer les taxes
/// \param nbreDeVehiculesDansLeParking Taille du parking
/// \return Tableau contenant les taxes
double* recupererTaxesParking(const Vehicule* p, size_t
                              nbreDeVehiculesDansLeParking);

/// Trie le tableau p par type de véhicule. L'ordre des types est déterminé par
/// l'énumération des types dans vehicule.h
/// \param p Tableau contenant des structures véhicules
/// \param nbreDeVehiculesDansLeParking Taille du parking
void trierParkingParType(Vehicule* p, size_t nbreDeVehiculesDansLeParking);

/// Trie le tableau p par taxe annuelle de manière décroissante.
/// \param p Tableau contenant des structures véhicules
/// \param nbreDeVehiculesDansLeParking Taille du parking
void trierParkingParTaxe(Vehicule* p, size_t nbreDeVehiculesDansLeParking);

#endif //PRG2_LABO02_PARKING_H
