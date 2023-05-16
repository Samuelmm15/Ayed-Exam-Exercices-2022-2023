/**
 * @file exercice-8.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de una función recursiva que permita el cáculo del mínimo común múltiplo de
 * dos números enteros que son pasados como parámetros de dicha función.
 * @version 0.1
 * @date 2023-05-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

int mcm(int a, int b, int divisor) {
  if ((a < divisor) || (b < divisor))
    return 1;
  else if ((a % divisor == 0) && (b % divisor == 0))
    return divisor * mcm(a/divisor, b/divisor, divisor);
  else if ((a % divisor != 0) && (b % divisor == 0))
    return divisor * mcm(a, b/divisor, divisor);
  else
    return mcm(a, b, divisor + 1);
};

int main() {
  int divisor = 2;
  std::cout << "<<BIENVENIDO AL PROGRAMA DE CÁLCULO DEL MÍNIMO COMÚN MÚLTIPLO DE DOS NÚMEROS INTRODUCIDOS >>" << std::endl;
  std::cout << "mcm: 1, 2 --> " << mcm(1, 2, divisor) << std::endl;
  std::cout << "mcm: 8, 30 --> " << mcm(8, 30, divisor) << std::endl;
  std::cout << "mcm: 30, 8 --> " << mcm(30, 8, divisor) << std::endl;
  std::cout << "mcm: 5, 6 --> " << mcm(5, 6, divisor) << std::endl;
  std::cout << "mcm: 20, 30 --> " << mcm(20, 30, divisor) << std::endl;
  std::cout << "mcm: 45, 135 --> " << mcm(45, 135, divisor) << std::endl;
  return 0;
};