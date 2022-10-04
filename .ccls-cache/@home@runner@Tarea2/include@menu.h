#ifndef MENU_H
#define MENU_H
#include "hashmap.h"
#include "list.h"

void showMenu();

void showChoice(List * listProperties, HashMap * mapIDs, HashMap * mapCities, HashMap * mapTypes, short choice);

#endif