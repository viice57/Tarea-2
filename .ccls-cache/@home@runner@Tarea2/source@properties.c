#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/properties.h"

struct property {
  unsigned short id;
  char city[20];
  char address[30];
  char type[15];
  unsigned short capacity;
  unsigned int price;
};

void importProperties() {
  char filename[30];
  
  printf("Indique nombre del archivo: ");
  scanf("%30s", filename);
  strcat(filename, ".csv");

  FILE * file = fopen(filename, "r");
  
  if(!file) {
    printf("Archivo no encontrado.");
    exit(EXIT_FAILURE);
  }
}