/**
 * @file exercice_1.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de un método o función que permita introducir un nodo detrás de otro, siendo estos pasados a esta función
 * como parámetro de esta.
 * @version 0.1
 * @date 2023-05-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Para poder comenzar, debemos de implementar la función que introduzca los nodos uno detras de otro a
 * la lista que es creada o que se le pasa como parámetro también a dicha función.
 * 
 */

#include <iostream>

#include "../dll-data/dll_node_t.h"
#include "../dll-data/dll_t.h"

/**
 * @brief Antes de comenzar con la implementación de la función que se encarga de añadir uno detrás de otro
 * los nodos que se le pasan a dicha función como parámetro, suponemos que la lista que se implementa es de
 * tipo double.
 * 
 */

// Puede que el ejercicio no solicite un nuevo método, no lo pide por ningún lado.
// dll_t<double> Node_Add_Function(dll_node_t<double>* new_node, dll_t<double> before_double_list) {
//   std::cout << "Accede" << std::endl;
//   before_double_list.push_back(new_node);
//   before_double_list.write();
//   return before_double_list;
// };

/**
 * @brief Realizamos la implementación de la función principal del programa, siendo esta la que se encarga
 * de la ejecución de manera correcta de la función anteriormente creada.
 *  
 */

int main() {
  /**
   * @brief Para comenzar solicitamos al usuario de manera iterativa que introduzca un nuevo nodo para que
   * se pueda actualizar la lista de dobules
   * 
   */
    bool option = true;
    dll_t<double> final_list;
    double number;
    while (option) {
      std::cout << "Introduzca un valor para introducir a la lista de valores: ";
      std::cin >> number;
      dll_node_t<double>* new_data = new dll_node_t<double> (number);
      final_list.push_back(new_data);
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
    std::cout << "A decidido dejar de introducir valores dentro de la lista, su resultado final es: " << std::endl;
    final_list.write();
  return 0;
};