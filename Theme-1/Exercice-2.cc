/*
EJERCICIO 2:
*/
/**
 * Ejercicio sobre matrices, programa que solicite al usuario una matriz de n x m y obtenga en un vector la 
 * diagonal principal de dicha matriz introducida por el usuario.
*/

#include <iostream>


int main() {
  int i_filas, j_columnas;
  std::cout << "Introduzca el número de filas de la matriz: ";
  std::cin >> i_filas;
  std::cout << std::endl;
  std::cout << "Introduzca el número de columnas de la matriz: ";
  std::cin >> j_columnas;
  std::cout << std::endl;

  // Generamos la matriz que quiere el usuario introducir para obtener su diagonal
  int Matrix[i_filas][j_columnas];
  for (int i = 0; i < i_filas; i++) {
    for (int j = 0; j < j_columnas; j++) {
      std::cout << "Introduzca valor para la Posición M( " << i << ", " << j << "): ";
      std::cin >> Matrix[i][j];
      std::cout << std::endl; 
    }
  }

  int diagonal_vector[i_filas];
  // Ya tenemos la matriz introducida por parte del usuario, comprobamos si es una matriz cuadrada para obtener su diagonal
  if (i_filas == j_columnas) {
    std::cout << "Se trata de una matriz cuadrada, procedemos a obtener su diagonal." << std::endl;
    int auxiliary = 0;
    for (int i = 0; i < i_filas; i++) {
      for (int j = 0; j < j_columnas; j++) {
        if (i == j) {
          if (auxiliary != i_filas) {
            diagonal_vector[auxiliary] = Matrix[i][j];
            auxiliary++;
          }
        }

      }
    }

    std::cout << "La diagonal principal de la matriz introducida por tanto es: " << std::endl;
    for (int i = 0; i < i_filas; i++) {
      std::cout << diagonal_vector[i] << "\t";
    }
  } else 
    std::cout << "No se trata de una matriz cuadrada, intentelo de nuevo" << std::endl;
  return 0;
};