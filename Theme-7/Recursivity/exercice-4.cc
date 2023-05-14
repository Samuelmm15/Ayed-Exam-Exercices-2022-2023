/**
 * @file exercice-4.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Implementar una funcion recursiva que permita calcular la codificacion binaria de un numero
 * entero positivo.
 * @version 0.1
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cmath>

/**
 * @brief Para comenzar realizamos la implementacion de la funcion recursiva que nos permita
 * devolver la representacion binaria de un numero introducido como parametro de dicha funcion.
 * 
 */
int binary_representation(int introduced_number) {
  if (introduced_number <= 1)
    return introduced_number;
  else if (introduced_number > 1) {
    introduced_number = (binary_representation(floor(introduced_number / 2)) * 10) + (introduced_number % 2);
  }
  return introduced_number;
};

/**
 * @brief Realizamos la implementacion de la funcion principal del programa para poder comprobar
 * el correcto funcionamiento de esto.
 * 
 */
int main() {
  std::cout << "<<BIENVENIDO AL PROGRAMA DE CONVERSION DE NUMEROS A REPRESENTACION BINARIA>>" << std::endl;
  std::cout << "1 --> " << binary_representation(1) << std::endl;
  std::cout << "10 --> " << binary_representation(10) << std::endl;
  std::cout << "19 --> " << binary_representation(19) << std::endl;
  std::cout << "20 --> " << binary_representation(20) << std::endl;
  std::cout << "0 --> " << binary_representation(0) << std::endl;
  std::cout << "40 --> " << binary_representation(40) << std::endl;
  std::cout << "27 --> " << binary_representation(27) << std::endl;
  return 0;
};