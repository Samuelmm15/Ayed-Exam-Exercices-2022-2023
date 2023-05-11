/**
 * @file exercice-1.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Intercambiar el orden de los dos primeros elementos en el top de la pila que haya sido introducida
 * por el usuario que ejecuta el programa.
 * @version 0.1
 * @date 2023-05-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Suponemos que el usuario es el que introduce los valores dentro de la pila, y tras esto, se
 * realiza la operación de cambio de los dos primeros elementos del top de la pila.
 * 
 * Cabe destacar que para poder probar el programa y todo, implementamos dicha operación dentro de
 * la función principal del programa.
 * 
 */

#include <iostream>

/**
 * @brief Hay que destacar que ambas clases realizan la implementación de pilas y de sus correspondientes
 * operaciones necesarias, pero, hay que comentar que la primero de ellas hace uso de una estructura
 * dinámica, mientras que la segunda de ellas hace uso de estructuras estáticas.
 * 
*/
#include "../stack-data/stack_l_t.h"
#include "../stack-data/stack_v_t.h"

int main() {
  /**
   * @brief Comenzamos con la introducción por parte del usuario de los elementos dentro de la pila
   * hasta que este especifique lo contrario.
   * 
   * Cabe destacar que como no se especifica el tipo de dato que se debe de encontrar dentro de la pila
   * , suponemos que se trata de una pila que en su interior contiene `dobule`.
   * 
   */
  bool option = false;
  double number = 0;
  stack_l_t<double> user_stack;
  while (option != true) {
    char introduced_option;
    std::cout << "Introduzca el valor que quiere introducir dentro de la pila de elementos: ";
    std::cin >> number;
    user_stack.push(number);
    std::cout << std::endl;
    std::cout << "Desea finalizar con la introducción de elementos dentro de la pila? (y/n): ";
    std::cin >> introduced_option;
    std::cout << std::endl;
    if (introduced_option == 'y' || introduced_option == 'Y')
      option = true;
    else if (introduced_option == 'n' || introduced_option == 'N')
      option = false;
  }

  std::cout << "La pila introducida por el usuario es: " << std::endl;
  user_stack.write();
  std::cout << std::endl;

  /**
   * @brief Obtenemos los dos primeros elementos de la pila.
   * 
   */
  double first_element = user_stack.top();
  user_stack.pop();
  double second_element = user_stack.top();
  user_stack.pop();
  
  user_stack.push(first_element);
  user_stack.push(second_element);

  std::cout << "La pila resultante es: " << std::endl;
  user_stack.write();
  std::cout << std::endl;
  return 0;
};

