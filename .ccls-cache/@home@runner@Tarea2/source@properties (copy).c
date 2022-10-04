#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/properties.h"
#include "../include/hashmap.h"

/* Estructura para asignar propiedades a listas y mapas */
struct property {
  char id[3];
  char city[20];
  char address[30];
  char type[15];
  char capacity[3];
  unsigned long price;
};

/* Estructura para asignar favoritos a una lista */
struct favourite {
  char id[3];
};

/* Función para separar una propiedad a partir del archivo .csv */
property * createProperty(char readLine[]) {
  property * newProperty = (property *) malloc(sizeof(property));
  char * split;

  /* Escaneamos los siguientes items de la propiedad: id, nombre, direccion, tipo, capacidad y su precio. */
  split = strtok(readLine, ",");
  strcpy(newProperty->id, split);

  split = strtok(NULL, ",");
  strcpy(newProperty->city, split);
  
  split = strtok(NULL, ",");
  strcpy(newProperty->address, split);

  split = strtok(NULL, ",");
  strcpy(newProperty->type, split);

  split = strtok(NULL, ",");
  strcpy(newProperty->capacity, split);

  split = strtok(NULL, "\n");
  newProperty->price = (unsigned long) atoi(split);

  return newProperty;
}

/* Función para importar el archivo .csv, asignar a una lista y a los mapas respectivos. */
void importProperties(List * listProperties, HashMap * mapIDs, HashMap * mapCities, HashMap * mapTypes) {
  char filename[30];
  char readLine[99];
  fflush(stdin);

  /* Menú para indicar el nombre, le añadimos la extensión .csv al final*/
  printf("Indique nombre del archivo: ");
  scanf("%30s", filename);
  getchar();
  strcat(filename, ".csv");

  /* Abrimos el archivo en modo lectura */
  FILE * file = fopen(filename, "r");

  /* Si el archivo no existe, simplemente se termina el programa */
  if(!file) {
    fclose(file);
    printf("Archivo no encontrado. ");
    exit(EXIT_FAILURE);
  }

  /* Ciclo while para leer las líneas y asignar cada propiedad a una lista de propiedades*/
  while(fgets(readLine, 99, file)) {
    property * newProperty = createProperty(readLine);
    pushBack(listProperties, newProperty);
  }

  /* Eliminamos primera línea y cerramos el archivo */
  popFront(listProperties);
  fclose(file);

  /* Recorremos la lista de propiedades */
  for(property * element = firstList(listProperties); element != NULL; element = nextList(listProperties)) {
    /* Asignacion del dato de la lista al mapa respectivo */   
    insertMap(mapIDs, element->id, element);
    insertMap(mapCities, element->city, element);
    insertMap(mapTypes, element->type, element);
  }
}

/* Función para añadir una nueva propiedad a los mapas */
void addProperty(HashMap * mapIDs, HashMap * mapCities, HashMap * mapTypes)  {
  /* Nueva asignación de propiedad */
  property * newProperty = (property *) malloc(sizeof(property));
  fflush(stdin);

  /* Menú para el ingreso de datos de una propiedad. En el caso del ID, si es repetido, se pide nuevamente */
  do {
    printf("Ingrese ID de la propiedad: ");
    scanf("%3s", newProperty->id);
    getchar();
  } while(searchMap(mapIDs, newProperty->id) != NULL);

  printf("Ingrese ciudad de la propiedad: ");
  fgets(newProperty->city, 20, stdin);
  newProperty->city[strcspn(newProperty->city, "\n")] = 0;

  printf("Ingrese dirección de la propiedad: ");
  fgets(newProperty->address, 30, stdin);
  newProperty->address[strcspn(newProperty->address, "\n")] = 0;

  printf("Ingrese tipo de propiedad: ");
  scanf("%15s", newProperty->type);
  getchar();

  printf("Ingrese capacidad de la propiedad: ");
  scanf("%3s", newProperty->capacity);
  getchar();

  printf("Ingrese precio de la propiedad: ");
  scanf("%lu", &newProperty->price);
  getchar();

  /* Asignación a los mapas */
  insertMap(mapIDs, newProperty->id, newProperty);
  insertMap(mapCities, newProperty->city, newProperty);
  insertMap(mapTypes, newProperty->type, newProperty);
}

/* Función que muestra todas las propiedades existentes, incluyendo las agregadas */
void showByAll(HashMap * mapIDs) {
  for(Pair * newProperty = firstMap(mapIDs); newProperty != NULL; newProperty = nextMap(mapIDs)) {
    printf("Propiedad %s\n", (char *) newProperty->key);
    printf("Ciudad: %s\n", ((property *) newProperty->value)->city);
    printf("Dirección: %s\n", ((property *) newProperty->value)->address);
    printf("Tipo: %s\n", ((property *) newProperty->value)->type);
    printf("Capacidad: %s\n", ((property *) newProperty->value)->capacity);
    printf("Precio: $ %lu\n", ((property *) newProperty->value)->price);
    
    printf("\n");
  }
}

/* Función que muestra todas las propiedades existentes, filtrando por ciudad */
void showByCity(HashMap * mapCities) {
  char city[30];
  char temp;
  fflush(stdin);

  /* Pedimos la ciudad */
  printf("Ingrese ciudad para la propiedad: ");
  scanf("%c", &temp);
  fgets(city, 20, stdin);
  city[strcspn(city, "\n")] = 0;

  /* Preguntamos si es que existe la ciudad */
  if(searchMap(mapCities, city) == NULL) printf("\nNo existen propiedades para tal ciudad.\n\n");
  
  for(Pair * newProperty = firstMap(mapCities); newProperty != NULL; newProperty = nextMap(mapCities)) {
    if(is_equal(city, ((property *) newProperty->value)->city)) {
      printf("Propiedad %s\n", ((property *) newProperty->value)->id);
      printf("Ciudad: %s\n", (char *) newProperty->key);
      printf("Dirección: %s\n", ((property *) newProperty->value)->address);
      printf("Tipo: %s\n", ((property *) newProperty->value)->type);
      printf("Capacidad: %s\n", ((property *) newProperty->value)->capacity);
      printf("Precio: $ %lu\n", ((property *) newProperty->value)->price);
    
      printf("\n");
    }
  }
}

void showByType(HashMap * mapTypes) {
  char type[15];
  fflush(stdin);

  /* Pedimos la ciudad */
  printf("Ingrese tipo de propiedad: ");
  scanf("%15s", type);
  getchar();

  /* Preguntamos si es que existe la ciudad */
  if(searchMap(mapTypes, type) == NULL) printf("\nLa propiedad no existe o está mal escrita.\n\n");
  
  for(Pair * newProperty = firstMap(mapTypes); newProperty != NULL; newProperty = nextMap(mapTypes)) {
    if(is_equal(type, ((property *) newProperty->value)->type)) {
      printf("Propiedad %s\n", ((property *) newProperty->value)->id);
      printf("Ciudad: %s\n", (char *) newProperty->key);
      printf("Dirección: %s\n", ((property *) newProperty->value)->address);
      printf("Tipo: %s\n", ((property *) newProperty->value)->type);
      printf("Capacidad: %s\n", ((property *) newProperty->value)->capacity);
      printf("Precio: $ %lu\n", ((property *) newProperty->value)->price);
    
      printf("\n");
    }
  }
}

void showByCapacity(HashMap * mapIDs) {
  for(Pair * newProperty = firstMap(mapIDs); newProperty != NULL; newProperty = nextMap(mapIDs)) {
    /* Preguntamos por las propiedades con capacidad "1" */
    if(is_equal("1", ((property *) newProperty->value)->capacity)) {
      printf("Propiedad %s\n", ((property *) newProperty->value)->id);
      printf("Ciudad: %s\n", (char *) newProperty->key);
      printf("Dirección: %s\n", ((property *) newProperty->value)->address);
      printf("Tipo: %s\n", ((property *) newProperty->value)->type);
      printf("Capacidad: %s\n", ((property *) newProperty->value)->capacity);
      printf("Precio: $ %lu\n", ((property *) newProperty->value)->price);
    
      printf("\n");
    }
  }
}

void addFavourite(List * listProperties, HashMap * mapIDs) {
  char favourite[3];
  fflush(stdin);

  do {
    printf("Ingrese ID de la nueva propiedad favorita: ");
    scanf("%3s", favourite);
    getchar();
  } while(searchMap(mapIDs, favourite) == NULL);

  for(property * favProperties = firstList(listProperties); favProperties != NULL; favProperties = nextList(listProperties)) {
    if(favProperties->id ==  favourite) {
      favProperties->
    }
  }

  //pushBack(listFavourites, newFavourite);
  /*  favourite * newFavourite = (favourite *) malloc(sizeof(favourite));
  fflush(stdin);

  do {
    printf("Ingrese ID de la nueva propiedad favorita: ");
    scanf("%3s", newFavourite->id);
    getchar();
  } while(searchMap(mapIDs, newFavourite->id) == NULL);

  pushBack(listFavourites, newFavourite);*/
}

void showMyFavourites(List * listFavourites) {
  for(favourite * Favourite = firstList(listFavourites); Favourite != NULL; Favourite = nextList(listFavourites)) {
    printf("Propiedad %s\n", Favourite->id);
  }
}

/* Función para exportar items hacia archivo */
void exportProperties(HashMap * mapIDs) {
  char filename[30];
  fflush(stdin);
  
  /* Menú para indicar el nombre, le añadimos la extensión .csv al final */
  printf("Indique nombre del archivo: ");
  scanf("%30s", filename);
  getchar();
  strcat(filename, ".csv");
  
  /* Eliminamos el contenido actual del archivo */
  remove(filename);

  /* Abrimos el archivo en modo escritura */
  FILE *file = fopen(filename, "w");
  
  /* Si el archivo no existe, simplemente se termina el programa */
  if(!file) {
    fclose(file);
    printf("Archivo no encontrado. ");
    exit(EXIT_FAILURE);
  }

  /* Escribimos la primera línea */
  fprintf(file, "%s", "Id,Ciudad,Direccion,Tipo,Capacidad,Valor\n");
  
  /* Recorriendo el mapa e imprimiendo sus datos */
  for(Pair * newProperty = firstMap(mapIDs); newProperty != NULL; newProperty = nextMap(mapIDs)) {
    fprintf(file, "%s,", (char *) newProperty->key);
    fprintf(file, "%s,", ((property *) newProperty->value)->city);
    fprintf(file, "%s,", ((property *) newProperty->value)->address);
    fprintf(file, "%s,", ((property *) newProperty->value)->type);
    fprintf(file, "%s,", ((property *) newProperty->value)->capacity);
    fprintf(file, "%lu\n", ((property *) newProperty->value)->price);
  }
  
  /* Cerramos el archivo */
  fclose(file);
}