/**
 * @file exercice-7.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementacion de una funcion recursiva que se encargue del calculo del máximo común divisor
 * de dos números enteros positivos.
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

/**
 * @brief Cabe destacar que para la implementación del divisor del maximo comun divisor, cabe destacar
 * que para poder implantar este divisor de manera predeterminada, suponemos que dicho divisor siempre es
 * 2.
 * 
 */

int MCD(int a, int b, int divisor) {
  int total_result;
  if ((a < divisor) || (b < divisor))
    return 1;
  else if ((a % divisor == 0) && (b % divisor == 0))
    return divisor * MCD(a/divisor, b/divisor, divisor);
  else
    return MCD(a, b, divisor + 1);
};

int main() {
  int divisor = 2;
  std::cout << "<<BIENVENIDO AL PROGRAMA QUE SE ENCARGA DE CALCULAR EL MAXIMO COMUN DIVISOR DE DOS NUMEROS INTRODUCIDOS >>" << std::endl;
  std::cout << "MCD: 1, 2 --> " << MCD(1, 2, divisor) << std::endl;
  std::cout << "MCD: 3, 4 --> " << MCD(3, 4, divisor) << std::endl;
  std::cout << "MCD: 5, 6 --> " << MCD(5, 6, divisor) << std::endl;
  std::cout << "MCD: 15, 2 --> " << MCD(15, 2, divisor) << std::endl;
  std::cout << "MCD: 11, 3 --> " << MCD(11, 3, divisor) << std::endl;
  std::cout << "MCD: 14, 6 --> " << MCD(14, 6, divisor) << std::endl;
  std::cout << "MCD: 8, 30 --> " << MCD(8, 30, divisor) << std::endl;
  return 0;
};
