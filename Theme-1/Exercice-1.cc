/*
======================================
EJERCICIO 1:
======================================
*/
/**
 * Dado un vector de tamaño 1 invertir este haciendo uso de punteros para ello.
*/

#include <iostream>

using namespace std;

int main() {
  int vector[] = {1,2,3,4,5,6,7};
  int *vector_start, *vector_finish;
  int auxiliary;
  vector_start = vector; // Apunta a la primera posición del vector
  vector_finish = vector + 6; // Apunta a la última posición del vector

  while (vector_start < vector_finish) {
    auxiliary = *vector_start; // De esta manera es como se obtiene el dato propio de la posición a la que apunta un puntero
    *vector_start = *vector_finish;
    *vector_finish = auxiliary;
    vector_start++;
    vector_finish--;
  }
  return 0;
};

// Hay que tener en cuenta que cuando se hace uso directamente de * en los punteros se accede al contenido al que apunta este.
// en cambio si hacemos uso de & estamos accediendo a la dirección de memoria que apunta dicho puntero.