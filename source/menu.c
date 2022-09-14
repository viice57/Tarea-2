#include <stdio.h>
#include <string.h>

#include "../include/properties.h"
#include "../include/menu.h"

void showMenu() {
  printf("\n%sMenu de opciones%s\n\n", "\x1B[1m", "\x1B[0m");

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

void showChoice(int choice) {
  switch(choice) {
    case 0:
      printf("Fin del programa.");
      break;
		case 1:
      importProperties();
      
      printf("***********************\n");
  		printf("* ¡Archivo importado! *\n");
  		printf("***********************\n");
  		break;
  	case 2:
      //addProperty();
      
  		printf("***********************\n");
  		printf("* ¡Propiedad agregada! *\n");
  		printf("***********************\n");
  		break;
  	case 3:
  		//showAllProperties();
  		break;
  	case 4:
  		//showByCity();
  		break;
  	case 5:
      //showByType();
      break;
  	case 6:
  		//showByCapacity();
  		break;
  	case 7:
      //addFavorite();
  		break;
  	case 8:
  		//showMyFavorites();
  		break;
  	case 9:
  		//exportProperties();
  		break;
  	default:
  		printf("**************************************\n");
  		printf("* ¡No existe tal opcion, elija otra! *\n");
  		printf("**************************************\n");
  		break;
		}
  printf("\n");
}