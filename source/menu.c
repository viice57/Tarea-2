#include <stdio.h>
#include "../include/properties.h"
#include "../include/menu.h"

void showMenu() {
  printf("\n%sMenú de opciones%s\n\n", "\x1B[1m", "\x1B[0m");

  printf("(1) Importar propiedades desde archivo .CSV\n");
  printf("(2) Agregar propiedad\n");
  printf("(3) Mostrar todas las propiedades\n");
  printf("(4) Mostrar propiedades según ciudad\n");
  printf("(5) Mostrar propiedades según tipo\n");
  printf("(6) Mostrar propiedades según capacidad mínima\n");
  printf("(7) Agregar a favoritos\n");
  printf("(8) Mostrar mis favoritos\n");
  printf("(9) Exportar propiedades hacia archivo .CSV\n");
  printf("(0) Terminar el programa\n");

  printf("\nIndique la accion deseada (solo números): ");
}

void showChoice(List * listProperties, HashMap * mapIDs, HashMap * mapCities, HashMap * mapTypes, short choice) {
  switch(choice) {
    case 0:
      printf("*********************\n");
  		printf("* Fin del programa. *\n");
  		printf("*********************\n");
      break;
		case 1:
      importProperties(listProperties, mapIDs, mapCities, mapTypes);
  		break;
  	case 2:
      addProperty(listProperties, mapIDs, mapCities, mapTypes);
  		break;
  	case 3:
  		showByAll(mapIDs);
  		break;
  	case 4:
  		showByCity(mapCities);
  		break;
  	case 5:
  		showByType(mapTypes);
      break;
  	case 6:
  		showByCapacity(mapIDs);
  		break;
  	case 7:
      addFavourite(listProperties, mapIDs);
  		break;
  	case 8:
  		showMyFavourites(listProperties);
  		break;
  	case 9:
  		exportProperties(mapIDs);
  		break;
  	default:
  		printf("**************************************\n");
  		printf("* ¡No existe tal opcion, elija otra! *\n");
  		printf("**************************************\n");
  		break;
	}
  printf("\n");
}