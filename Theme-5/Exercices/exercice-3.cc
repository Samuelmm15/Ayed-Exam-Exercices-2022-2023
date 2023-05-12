/**
 * @file exercice-3.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Eliminar todos los elementos de las posiciones impares de una pila, apoyandose en otra pila para ello, cabe
 * destacar que debemos de considerar el elemento en el fondo de la pila como impar.
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Para poder comprender el funcionamiento del algoritmo que va a ser implantado, se va a hacer uso de un contador
 * que permita determinar las posiciones de la pila, permitiendo que cuando la pila original se encuentre en una posicion
 * impar, este nodo sea eliminado y los nodos que se encuentren dentro de posiciones pares sean transladadas a una nueva
 * pila que se trata de una pila auxiliar.
 * 
 */

#include <iostream>

/**
 * @brief Como podemos observar a continuacion esta pila la cual estamos usando se trata de una pila dinamica.
 * 
*/
#include "../stack-data/stack_l_t.h"

int main() {
  /**
   * @brief Para comenzar con la implementacion, vamos a solicitar al usuario del programa que introduzca distintos
   * elementos de tipo double en una nueva lista, ya que suponemos que la lista que se solicita es de tipo double.
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
   * @brief Una vez tenemos la lista introducida por el usuario, realizamos la eliminacion de los elementos que 
   * se encuentran en las posiciones impares, haciendo por tanto uso de una pila auxiliar para ello.
   * 
   */
  int counter = 0;
  stack_l_t<double> auxiliary_stack;
  while (user_stack.empty() != true) {
    if ((counter % 2) == 0) {
      auxiliary_stack.push(user_stack.top());
      user_stack.pop();
    } else if ((counter % 2) != 0) {
      user_stack.pop();
    }
    counter++;
  }

  std::cout << "Los elementos que se encontraban en las posiciones impares de la pila han sido eliminados, la pila resultante es: " << std::endl;
  auxiliary_stack.write();
  std::cout << std::endl;
  return 0;
};