/**
 * @file exercice-4.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Eliminar y liberar todos los elementos de las posiciones pares de una lista
 * @version 0.1
 * @date 2023-05-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Suponemos que no tenemos que realizar la implementacion de este ejercicio en una funcion,
 * sino que, lo podemos implementar dentro de la funcion principal del programa.
 * 
 */

#include <iostream>
#include <vector>

#include "../sll-data/sll_node_t.h"
#include "../sll-data/sll_t.h"

int main() {
  /**
   * @brief Para comenzar, se realiza la implementacion de un bucle que nos permite introducir elementos
   * a una lista que es creada por el usuario.
   * 
   * Cabe destacar que como no se especifica el tipo de lista que debera de ser implantada, suponemos
   * que se trata de una lista de numeros.
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
   * @brief Para poder eliminar y liberar todos los elementos de las posiciones pares de una lista, debemos
   * de buscar los elementos de las posiciones impares para que puedan ser eliminadas las posiciones impares
   * mediante el erase_after.
   * 
   * Cabe destacar que para poder eliminar los elementos de las posiciones pares debemos de meter dichos elementos
   * en un vector para que finalmente se puedan eliminar dichos elementos de la lista, ya que si los eliminamos en
   * tiempo real, las posiciones de los elementos de la lista seran modificados en tiempo real y por tanto se realizara
   * la eliminacion de todos los elementos de la lista al completo de manera automatica.
   * 
   */
  std::vector<sll_node_t<int>*> position_vector_list;
  sll_node_t<int>* head = number_list.get_head();
  int counter = 0;
  while (head != NULL) {
    if ((counter % 2) != 0)
      position_vector_list.push_back(head);
    head = head->get_next();
    counter++;
  }
  // Eliminamos siempre el ultimo elemento impar, ya que si eliminamos el elemento NULL de la lista, da error
  position_vector_list.pop_back();

  std::cout << "La lista de elementos antes de eliminar las posiciones pares es: " << std::endl;
  number_list.write();
  std::cout << std::endl;

  /**
   * @brief Una vez tenemos en un vector todas las posiciones impares de la lista introducida por el usuario
   * procedemos a eliminar todos aquellos elementos que se encuentran dentro de las posiciones pares.
   * 
   */
  number_list.pop_front();
  for (int i = 0; i < position_vector_list.size(); i++) 
    number_list.erase_after(position_vector_list[i]);

  std::cout << "La lista de elementos tras eliminar las posiciones pares es: " << std::endl;
  number_list.write();
  std::cout << std::endl;
  return 0;
};