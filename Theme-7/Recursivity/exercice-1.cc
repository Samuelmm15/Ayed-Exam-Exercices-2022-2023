/**
 * @file exercice-1.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Implementacion de una funcion recursiva que permita el calculo del factorial de un numero
 * que se le pasa como parametro a la funcion.
 * @version 0.1
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <utility>

double factorial(double n_value) {
  if (n_value == 0)
    return 1;
  else if (n_value > 0) {
    n_value = n_value * factorial(n_value - 1);
  }
  return n_value;
};

/**
 * @brief Realizamos la implementacion de la funcion principal del programa para poder comprobar
 * el funcionamiento de este.
 * 
 * @return int 
 */
int main() {
  std::cout << "<< BIENVENIDO AL PROGRAMA DEL CALCULO DEL FACTORIAL DE UN NUMERO DE MANERA RECURSIVA" << std::endl;
  std::cout << "0! >> " << factorial(0) << std::endl;
  std::cout << "5! >> " << factorial(5) << std::endl;
  std::cout << "10! >> " << factorial(10) << std::endl;
  std::cout << "12! >> " << factorial(12) << std::endl;
  return 0;
}