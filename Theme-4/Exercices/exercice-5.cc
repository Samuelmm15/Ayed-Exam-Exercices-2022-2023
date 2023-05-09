/**
 * @file exercice-5.cc
 * @author Samuel Martín Morales (alu0101359526)
 * @brief Eliminar todos los nodos de las posiciones pares de una lista introducida por el usuario
 * y trasladar duchos nodos en el mismo orden a una nueva lista que haya sido creada.
 * @version 0.1
 * @date 2023-05-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Suponemos que el usuario debe de introducir la lista doblemente enlazada por teclado, 
 * ademas de que suponemos que se trata de una lista de `double`, por tanto, los valores
 * que sean introducidos en la lista sera `double`.
 * 
 * Tambien suponemos que la implementacion de esta operacion es en la funcion principal del programa
 * ya que para probar el programa y todo es mejor tenerlo en dicha funcion, ademas que no solicitan
 * de la creacion de una nueva funcion o metodo para ello.
 * 
 */

#include <iostream>
#include <vector>

#include "../dll-data/dll_node_t.h"
#include "../dll-data/dll_t.h"

int main() {
  /**
   * @brief Para comenzar con la implementacion, introducimos los valores de la lista doblemente enlazada
   * por teclado, solicitando cada uno de los datos al usuario que hace uso del programa.
   * 
   */
  bool option = true;
    dll_t<double> user_introduced_list;
    double number;
    while (option) {
      std::cout << "Introduzca un valor para introducir a la lista de valores: ";
      std::cin >> number;
      dll_node_t<double>* new_data = new dll_node_t<double> (number);
      user_introduced_list.push_back(new_data);
      std::cout << std::endl;
      std::cout << "Desea terminar con la introducción de valores dentro de la lista? (y/n): ";
      char answer;
      std::cin >> answer;
      std::cout << std::endl;
      if (answer == 'y' || answer == 'Y') {
        option = true;
      } else if (answer == 'n' || answer == 'N') {
        option = false;
      }
    }

  std::cout << "La lista introducida antes de realizar la eliminacion de los elementos que se encuentran en las posiciones pares es: " << std::endl;
  user_introduced_list.write();
  std::cout << std::endl;

  /**
   * @brief Una vez tenemos la lista introducida por el usurio, obtenemos los elementos que se
   * encuentran en las posiciones pares de la lista doblemente enlazada.
   * 
   * Para ello, introducimos cada uno de los elementos de la lista que se encuentran en las posiciones
   * pares en una nueva lista que contiene los elementos que se encuentran dentro de las posiciones del
   * vector original.
   * 
   */
  dll_t<double> final_list;
  dll_node_t<double>* head = user_introduced_list.get_head();
  std::vector<dll_node_t<double>*> auxiliary;
  int counter = 0;
  while (head != NULL) {
    if ((counter % 2) == 0) {
      /**
       * @brief TENER CUIDADO CON ESTO DE AQUI DEBAJO, YA QUE AL INTRODUCIR EL NODO DIRECTAMENTE
       * DENTRO DE UNA NUEVA LISTA LO QUE OCURRE ES QUE EL PUNTERO PASA A SER EL NUEVO PUNTERO DENTRO
       * DE LA NUEVA LISTA Y DEJA DE EXISTIR DENTRO DE LA LISTA ORIGINAL, POR TANTO, ES MEJOR INTRODUCIR
       * LOS NODOS DENTRO DE UN VECTOR DE NODOS.
       * 
       */
      // final_list.push_back(head);
      auxiliary.push_back(head);
      std::cout << counter << std::endl;
    }
    head = head->get_next();
    counter++;
  }

  /**
   * @brief Una vez tenemos los elementos que se encuentran en las posiciones pares de la primera lista
   * y añadidas en una nueva lista, procedemos a eliminar los elementos que se encuentran en dichas
   * posiciones.
   * 
   */
  for (int i = 0; i < auxiliary.size(); i++) {
    user_introduced_list.erase(auxiliary[i]);
    final_list.push_back(auxiliary[i]);
  }
  
  std::cout << "La lista tras eliminar los elementos en las posiciones pares es: " << std::endl;
  user_introduced_list.write();
  std::cout << std::endl;
  std::cout << "La lista de los elementos que se encontraban en las posiciones pares es: " << std::endl;
  final_list.write();
  std::cout << std::endl;

  return 0;
};