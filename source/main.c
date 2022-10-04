#include <stdio.h>
#include <stdlib.h>
#include "../include/hashmap.h"
#include "../include/list.h"
#include "../include/menu.h"

int main(void) {
  short choice = -1; 
  
  List * listProperties = createList();
  HashMap * mapIDs = createMap(50);
  HashMap * mapCities = createMap(50);
  HashMap * mapTypes = createMap(50);

  do {
    fflush(stdin);
    
		showMenu();
		scanf("%hi", &choice);
		printf("\n");

		if(choice > 1 && !firstList(listProperties)) {
      printf("No se ha abierto archivo alguno. Cerrando");
      break;
    }
    
		showChoice(listProperties, mapIDs, mapCities, mapTypes, choice);
	} while(choice != 0);

  free(listProperties);
  free(mapIDs);
  free(mapCities);
  free(mapTypes);
  
  return 0;
}