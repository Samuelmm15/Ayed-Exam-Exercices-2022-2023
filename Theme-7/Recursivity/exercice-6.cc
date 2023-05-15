/**
 * @file exercice-6.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementacion de una funcion que se encargue de comprobar si un numero entero positivo introducido como
 * parametro es primo o no.
 * @version 0.1
 * @date 2023-05-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

bool is_prime(int introduced_value, int divider) {
  if (introduced_value == divider)
    return true;
  else if (introduced_value % divider == 0)
    return false;
  else
    is_prime(introduced_value, divider + 1);
};

int main() {
  int divider = 2;
  std::cout << "<<BIENVENIDO AL PROGRAMA QUE COMPRUEBA SI UN NUMERO ES PRIMO O NO>>" << std::endl;
  std::cout << "2 --> " << is_prime(2, divider) << std::endl;
  std::cout << "3 --> " << is_prime(3, divider) << std::endl;
  std::cout << "4 --> " << is_prime(4, divider) << std::endl;
  std::cout << "5 --> " << is_prime(5, divider) << std::endl;
  std::cout << "7 --> " << is_prime(7, divider) << std::endl;
  std::cout << "11 --> " << is_prime(11, divider) << std::endl;
  std::cout << "15 --> " << is_prime(15, divider) << std::endl;
  return 0;
};