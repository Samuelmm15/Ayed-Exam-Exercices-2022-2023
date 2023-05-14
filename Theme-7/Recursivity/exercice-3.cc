/**
 * @file exercice-3.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Implementacion de una funcion recursiva que permita sumar los numeros de un numero entero
 * positivo.
 * @version 0.1
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cmath>

/**
 * @brief Suponemos que los numeros enteros positivos son de tipo `int` para la implementacion de estos
 * 
 */
int number_add(int introduced_number) {
  if (introduced_number == 0)
    return 0;
  else if (introduced_number > 0) {
    introduced_number = (introduced_number % 10) + number_add(floor(introduced_number / 10));
  }
  return introduced_number;
};

/**
 * @brief Para la comprobacion del funcionamiento de la funcion creada anteriormente, hacemos uso de
 * la funcion principal del programa que nos permite comprobar esto.
 * 
 * @return int 
 */
int main() {
  std::cout << "<<BIENVENIDO AL PROGRAMA QUE SUMA LOS NUMEROS DE UN ENTERO POSITIVO>>" << std::endl;
  std::cout << "0:" << number_add(0) << std::endl;
  std::cout << "15:" << number_add(15) << std::endl;
  std::cout << "243:" << number_add(243) << std::endl;
  std::cout << "1:" << number_add(1) << std::endl;
  std::cout << "20345:" << number_add(20345) << std::endl;
  std::cout << "567:" << number_add(567) << std::endl;

  return 0;
};