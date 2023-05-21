/**
 * @file exercice-1.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Considere la clase sll_t<T>. Implementar un método iterativo que invierta el orden de la lista usando la clase cola queue_v_t<T>.
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cmath>

/**
 * @brief Cabe destacar que la función que va a ser implementada a continuación, se trata de un método de la clase lista simplemente enlazada,
 * es por ello que suponemos que dicha clase posee cada uno de los métodos y elementos que se necesitan para poder invertir el orden de la 
 * lista introducida.
 * 
 */
void sll_t<T>::reverse(void) {
  /**
   * @brief Para poder entender el funcionamiento del algoritmo, la operación que vamos a realizar, es la de recorrer la lista desde el principio
   * hasta el final añadiendo cada uno de los elementos en la cola que usaremos como auxiliary para poder invertir la lista, una vez tenemos
   * todos los elementos dentro de la cola, eliminamos los elementos de la lista original y añadimos los elementos de la cola dentro de la lista
   * final, de manera inversa.
   *  
   */
  sll_node_t<T>* auxiliary = head_;
  queu_v_t<T> auxiliary_queue;
  while (auxiliary != NULL) {
    auxiliary_queue.push_back(auxiliary->get_data());
    auxiliary = auxiliary->get_next();
  }

  /// En este punto la cola ya tiene todos los elementos de la lista, a continuación realizamos la eliminación de cada uno de los nodos de la lista.
  head_ = NULL; /// Establecemos la cabeza de la lista como nula, indicando y rompiendo todos los enlaces con cada uno de los punteros que existian.

  /// Finalmente introducimos todos los elementos de la cola de manera inversa en la lista resultante.
  for (int i = 0; i < auxiliary_queue.get_size(); i++) {
    sll_node_t<T>* new_node = new sll_node_t<T>(auxiliary_queue[i]);
    push_front(new_node); /// En este punto tenemos los elementos introducidos en la lista resultante de manera inversa
  }
};