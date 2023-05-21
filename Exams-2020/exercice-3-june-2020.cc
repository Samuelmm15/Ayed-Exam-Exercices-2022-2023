/**
 * @file exercice-3-june-2020.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de una función que se encargue de convertir un número entero positivo en un número binario,
 * haciendo uso de una pila para ello.
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Cabe destacar que para la implementación de dicha función, se hará uso de stack_l_t<T>, ya que hace
 * uso de listas doblemente enlazadas para su implementación, lo que nos permite una implementación del algoritmo
 * solicitado de una manera más simple, sencilla y cómoda de implementar.
 * 
 */
void a_binario(unsigned int e) {
  stack_l_t<int> auxiliary_stack;
  if (e == 0) {
    std::cout << e << "-> 0" << std::endl;
  } else if (e == 1) {
    std::cout << e << "-> 1" << std::endl;
  } else if (e > 1) {
    int rest;
    while (e > 1) {
        rest = e % 2;
        auxiliary_stack.push(rest);
        e = e / 2;
    }
    auxiliary_stack.push(e); /// Es necesario introducir este último valor al final de pila, ya que es el último valor necesario para completar la conversión del número entero a binario
    int static_size = auxiliary_stack.get_size();
    for (int i = 0; i < static_size; i++) {
        std::cout << auxiliary_stack.top();
        auxiliary_stack.pop(); /// Eliminamos el elemento que se encuentra en el top de la pila para que el nuevo top sea el siguiente valor de la pila
    }
  }
};