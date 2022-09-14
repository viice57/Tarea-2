#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "hashmap.h"

int main(void) {
  HashMap * map = createMap();
  int choice; 

  do {
		showMenu();

    fflush(stdin);
		scanf("%i", &choice);
		printf("\n");
    
		if(choice == 0) {
      printf("Fin del programa.");
      break;
    } else if(choice > 1) {
      if(!firstList(listItems)){
        printf("No se ha abierto archivo alguno. Cerrando");
        break;
      }
    }
		
		switch(choice) {
      //Impotar desde el archivo ".csv" cada item a una lista nueva
		  case 1:
  			listItems = importItems(listItems);
        
  			printf("***********************\n");
  			printf("* ¡Archivo importado! *\n");
  			printf("***********************\n");
  			break;
      //Exportar al archivo ".csv" cada item de la lista creada.
  		case 2:
  			exportItems(listItems);
        
  			printf("***********************\n");
  			printf("* ¡Archivo exportado! *\n");
  			printf("***********************\n");
  			break;
      //Agregar un item, con su tipo, nombre, lvl o qty y personaje que lo posee.
  		case 3:
  			addItem(listItems);
  
  			printf("*******************\n");
  			printf("* ¡Item agregado! *\n");
  			printf("*******************\n");
  			break;
      //Mostrar ítems equipables de un personaje
  		case 4:
  			showEquippableItems(listItems);
  			break;
      // Mostrar ítems consumibles de un personaje
  		case 5:
        showConsumableItems(listItems);
        break;
      //Eliminar ítem de un personaje
  		case 6:
  			//deleteItem(listItems);
  			break;
      //Eliminar ítem de todos los personajes 
  		case 7:
        //deleteItemFromAll(listItems)
  			break;
      //Mostrar nombres de los personajes
  		case 8:
  			showAllNames(listItems);
  			break;
      //Mostrar todos los nombres de ítems
  		case 9:
  			showAllItems(listItems);
  			break;
      //Si la opción no existe...
  		default:
  			printf("**************************************\n");
  			printf("* ¡No existe tal opcion, elija otra! *\n");
  			printf("**************************************\n");
  			break;
		}
		printf("\n");
	} while(choice != 0);

  //Liberamos memoria
	free(listItems);
  
  return 0;
}
/*
//  {---}    {---}       {----}
//   ´´´     ´´´´{----}   ´´´´                    
//  ´´´´   ´´´´  ´´´´´´                       /0\--|
// ´´´´  0  {srry}´´´´                        ^^^  |
//      /|\¬        ~~~~{it´s okey :)}             |
//      /'\       >-->o~~                         /_\
//---------------------------------------------------------
*/