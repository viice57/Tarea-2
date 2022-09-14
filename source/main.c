#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/hashmap.h"
#include "../include/menu.h"

int main(void) {
  int choice = -1; 

  do {
		showMenu();

    fflush(stdin);
		scanf("%i", &choice);
		printf("\n");
    
		/*if(choice > 1 && !firstMap(listItems)) {
      printf("No se ha abierto archivo alguno. Cerrando");
      break;
    }*/
    
		showChoice(choice);
	} while(choice != 0);
  
  return 0;
}