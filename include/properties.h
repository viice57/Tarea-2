#ifndef ITEM_H
#define ITEM_H
#include "hashmap.h"
#include "list.h"

typedef struct property property;

property * createProperty(char readLine[]);

void importProperties(List * listProperties, HashMap * IDs, HashMap * mapCities, HashMap * mapTypes);

void addProperty(List * listProperties, HashMap * IDs, HashMap * mapCities, HashMap * mapTypes);

void showByAll(HashMap * mapIDs);

void showByCity(HashMap * mapCities);

void showByType(HashMap * mapTypes);

void showByCapacity(HashMap * mapIDs);

void addFavourite(List * listProperties, HashMap * mapIDs);

void showMyFavourites(List * listProperties);

void exportProperties(HashMap * mapIDs);

#endif