#include <stdio.h>
#include "menu.h"

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