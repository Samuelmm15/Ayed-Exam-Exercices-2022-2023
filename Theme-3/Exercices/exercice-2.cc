/**
 * @file exercice-2.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Intercambiar el orden del primer elemento y el segundo de una lista simplemente enlazada
 * @version 0.1
 * @date 2023-05-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Hay que tener en cuenta que esto va a ser implementado en la funcion principal del programa
 * ya que, no nos solicitan realizar ningun metodo en especifico para realizar la operacion, por tanto
 * esto sera implementado en la funcion principal de nuestro programa.
 */

#include <iostream>

#include "../sll-data/sll_node_t.h"
#include "../sll-data/sll_t.h"

int main() {
  /**
   * @brief Primero vamos a realizar la implementacion de un bucle que permita al usuario introducir
   * todos los elementos necesarios dentro de una lista.
   * 
   * Cabe destacar que la lista a implementar sera de numeros, ya que, no se especifica por ningun lado
   * el tipo de lista la cual se quiere que sea implementada.
   * 
   */
  std::cout << "Bienvenido al programa, para comenzar debe de introducir los distintos elementos a la lista para poder realizar la operación" << std::endl;
  char option = 'y';
  sll_t<int> number_list;
  int numero;
  while (option != 'n') {
    std::cout << "Introduzca los elementos de la lista hasta que termine de introducirla en la base de datos: ";
    std::cin >> numero;
    sll_node_t<int>* list_element = new sll_node_t<int> (numero);
    number_list.push_front(list_element);
    std::cout << std::endl;
    std::cout << "Desea seguir introduciendo elementos en la lista? (y/n): ";
    std::cin >> option;
  }

  /**
   * @brief La segunda parte que sera implementada sera la de intercambiar el primer elemento y el ultimo
   * elemento de la lista que ha sido introducida por el usuario, para ello se crearan dos variables
   * auxiliares que nos permitan encontrar el primer elemento de la lista y el segundo elemento de la lista.
   * 
   */
  sll_node_t<int>* head = number_list.get_head();
  sll_node_t<int>* first_element = head;
  sll_node_t<int>* second_element = head->get_next();
  std::cout << "La lista antes de eliminar los elementos es: " << std::endl;
  number_list.write();
  std::cout << std::endl;

  /**
   * @brief Una vez tenemos el primero y el segundo procedemos a eliminar estos elementos de la lista
   * 
   */
  number_list.erase_after(first_element);
  number_list.pop_front();

  /**
   * @brief Una vez eliminamos el primer y el segundo elemento de la lista, los introducimos de nuevo por delante
   * de manera inversa
   * 
   */
  number_list.push_front(first_element);
  number_list.push_front(second_element);
  std::cout << "La lista despues de intercambiar el primer y segundo elemento es: " << std::endl;
  number_list.write();
  std::cout << std::endl;
  return 0;
};