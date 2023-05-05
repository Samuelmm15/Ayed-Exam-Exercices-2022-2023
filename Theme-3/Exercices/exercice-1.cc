/**
 * EJERCICIO 1, TEMA 3:
 * Eliminar y liberar el último elemento de una lista, devolviendo el dato.
*/

#include <iostream>

#include "../sll-data/sll_node_t.h"
#include "../sll-data/sll_t.h"

/**
 * Suponemos que se trata de una lista simple de números enteros que son introducidos
 * por el usuario de manera manual y que en algún momento del programa eliminamos el
 * último elemento de la lista que ha introducido el usuario, liberamos este último
 * elemento y devolvemos el dato de este.
*/

// Cabe destacar que realizamos toda esta operación en la función principal del programa para poder comprobar el funcionamiento de este
int main() {
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

  std::cout << std::endl;
  std::cout << "Ya termino de introdcir elementos en la lista de números, comenzamos con la operación..." << std::endl;

  sll_node_t<int>* head = number_list.get_head();
  sll_node_t<int>* list_element = head;
  int counter = 0;
  while (head != NULL) {
    head = head->get_next();
    // if (counter == 1) 
    //   list_element = list_element->get_next();
    // counter = 1;
  }
  std::cout << "La lista antes de eliminar el último elemento es: " << std::endl;
  number_list.write();
  std::cout << std::endl;
  number_list.erase_after(list_element);
  std::cout << "La lista después de eliminar el último elemento es: " << std::endl;
  number_list.write();
  std::cout << std::endl;
  // std::cout << "El último elemento de la lista es: " << list_element->get_data() << std::endl;
  return 0;
}
