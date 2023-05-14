/**
 * @file exercice-2.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Implementacion de una funcion recursiva que permita calcular el numero de digitos de un
 * numero entero positivo.
 * @version 0.1
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

/**
 * @brief Suponemos que los numeros que queremos comprobar el numero de digitos que posee dicho numero
 * introducido como parametro de la funcion, es de tipo `double`.
 * 
 */

double digit_calculator(double introduced_number) {
  if (introduced_number == 0)
    return 0;
  else if (introduced_number > 0) {
    /**
     * @brief Cabe destacar que para poder hacer uso de la division entre 10, se especifica que se debe
     * de redondear los valores para que funcione de manera correcta, por tanto, se hace uso de 
     * una operacion de la librearia cmath que se denomina floor que sirve para poder redondear las
     * operaciones que se realicen dentro de esta.
     * 
     * NOTA: Hay que tener en cuenta que existen distintas operaciones para esto, floor() redondea tirando
     * para lo bajo, mientras que la operacion round() redondea tirando para lo alto.
     * 
     */
    introduced_number = 1 + digit_calculator(floor(introduced_number / 10));
  }
  return introduced_number;
};

/// Hacemos uso de la funcion principal del programa para poder comprobar el funcionamiento de la funcion recursiva
int main() {
  std::cout << "<<BIENVENIDO AL PROGRAMA QUE PERMITE OBTENER EL NUMERO DE DIGITOS DE UN VALOR INTRODUCIDO>>" << std::endl;
  std::cout << "0:" << digit_calculator(0) << std::endl;
  std::cout << "9:" << digit_calculator(9) << std::endl;
  std::cout << "20:" << digit_calculator(20) << std::endl;
  std::cout << "341:" << digit_calculator(341) << std::endl;
  std::cout << "1354:" << digit_calculator(1354) << std::endl;
  std::cout << "20000:" << digit_calculator(20000) << std::endl;
  return 0;
};