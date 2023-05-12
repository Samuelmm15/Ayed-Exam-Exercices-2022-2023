/**
 * @file exercice-5.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Dada una pila obtener el maximo de sus elementos en base e ir desapilando los dos primeros elementos en el top
 * de la pila y reemplezarlos por el maximo de ambos sucesivamente.
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Para poder probar el funcionamiento de el algoritmo que se pretende implantar, realizamos la implementación
 * del algoritmo en la función principal del programa, es por ello que, para comenzar, solicitamos al usuario
 * que realice la introducción de una nueva pila, de tipo `double`, ya que suponemos que la lista a implementar es
 * de dicho tipo.
 * 
 */

#include <iostream>
#include <vector>

#include "../stack-data/stack_l_t.h"

int main() {
  /**
   * @brief Comenzamos con la introduccion de la pila por parte del usuario.
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
   * @brief Para la implementacion del algoritmo solicitado, hacemos uso de una pila auxiliar, la cual seran introducidos
   * el maximo de los dos elementos que son sacados de la pila original, para ello, hacemos uso de un vector auxiliar
   * el cual nos servira para añadir los elementos a la pila final de manera correcta en el orden original.
   * 
   * NOTA: cabe destacar que consideramos que la pila de valores introducida es par, ya que si resulta que no es par
   * el algoritmo deja de funcionar, y ya que, la clase pila no tiene un metodo que devuelva el numero de elementos
   * que se encuentran dentro de la pila, pues consideramos que la pila introducida es par, ya que si no es par no funciona.
   * 
   */
  std::vector<double> auxiliary_vector;
  stack_l_t<double> final_stack;
  while(user_stack.empty() != true) {
    double first_value = user_stack.top();
    user_stack.pop();
    double second_value = user_stack.top();
    user_stack.pop();
    /**
     * @brief Una vez tenemos los dos elementos del top de la pila, los comparamos y dejamos el elemento de mayor valor.
     * 
     */
    if (first_value > second_value)
      auxiliary_vector.push_back(first_value);
    else if (second_value > first_value)
      auxiliary_vector.push_back(second_value);
  }

  /**
   * @brief Ya tenemos los valores de pares que son mayores unos que otros, de esta manera los introducimos en la pila
   * resultante.
   * 
   */
  for (int i = auxiliary_vector.size() - 1; i >= 0; i--) {
    final_stack.push(auxiliary_vector[i]);
  }

  std::cout << "La pila resultante es: " << std::endl;
  final_stack.write();
  std::cout << std::endl;
  return 0;
};