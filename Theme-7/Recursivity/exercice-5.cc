/**
 * @file exercice-5.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Implementacion de una funcion recursiva que se ecargue de realizar e implementar la conjetura de collatz
 * @version 0.1
 * @date 2023-05-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

int collatz_function(int introduced_value) {
  if (introduced_value == 1)
    return 1;
  else if ((introduced_value > 1) && (introduced_value % 2 == 0))
    introduced_value = 1 + collatz_function(introduced_value / 2);
  else if ((introduced_value > 1) && (introduced_value % 2 != 0))
    introduced_value = 1 + collatz_function((3 * introduced_value) + 1);

  return introduced_value;
};

int main() {
  std::cout << "<<BIENVENIEDO AL PROGRAMA DE COLLATZ>>" << std::endl;
  std::cout << "1 --> " << collatz_function(1) << std::endl;
  std::cout << "10 --> " << collatz_function(10) << std::endl;
  std::cout << "20 --> " << collatz_function(20) << std::endl;
  std::cout << "73 --> " << collatz_function(73) << std::endl;
  std::cout << "19 --> " << collatz_function(19) << std::endl;
  std::cout << "47 --> " << collatz_function(47) << std::endl;
  std::cout << "222 --> " << collatz_function(222) << std::endl;
  std::cout << "13 --> " << collatz_function(13) << std::endl;
  return 0;
};