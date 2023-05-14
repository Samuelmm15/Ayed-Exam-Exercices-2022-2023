/**
 * @file queue_l_t.h
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief Esta es la implementacion de la clase cola, la cual, los distintos ejercicios seran
 * implementados dentro de dicha clase como metodos publicos de esta, ademas que se hara uso de
 * la funcion principal del programa para poder comprobar los resultados.
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>
#include <vector>
/**
 * NOTA: Hay que destacar que para poder hacer uso de pair en c++, es necesario el empleo de
 * la libreria utility que nos permite hacer uso de `std::pair`.
*/
#include <utility>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class queue_l_t {
 private:
  dll_t<T>    l_;

 public:
  // constructor
  queue_l_t(void) : l_() {}

  // destructor
  ~queue_l_t(void) {}

  // operaciones
  bool empty(void) const;
  int size(void) const;
  void push(const T& dato);
  void pop(void);
  const T& front(void) const;
  const T& back(void) const;

  // Implementacion de los distintos ejercicios soliciatados para el tema 6
  // Exercice-1
  void inverse_queue_elements(void);
  // Exercice-2
  pair<queue_l_t<T>, queue_l_t<T>> divide_into_two_queues(queue_l_t<T> pair_queue, queue_l_t<T> unpair_queue);
  // Exercice-3
  void merge_two_queues(queue_l_t<T> first_queue, queue_l_t<T> second_queue);
  // Exercice-4
  void delete_duplicated_elements(void);

  // E/S
  std::ostream& write(std::ostream& os = std::cout) const;
};


// operaciones
template<class T> bool queue_l_t<T>::empty(void) const {
  return l_.empty();
}

template<class T> int queue_l_t<T>::size(void) const {
  return l_.get_size();	
}

template<class T> void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

template<class T> void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

template<class T> const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

template<class T> const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

 // E/S
template<class T> std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const queue_l_t<T>& q) {
  q.write(os);
  return os;
}

/// Implementacion de los distintos ejercicios soliciatados para el tema 6

/**
 * @brief Ejercicio 1.
 * 
 * Se trata de un metodo publico de la clase el cual se encarga de invertir los elementos de la cola,
 * haciendo uso de una estructura auxiliar para ello.
 * 
 * Cabe destacar que la estructura auxiliar que vamos a usar es el vector, que queda implementado
 * gracias a la libreria estandar vector.
 */
template<class T>
void queue_l_t<T>::inverse_queue_elements(void) {
  std::vector<T> node_vector;
  while (!empty()) {
    node_vector.push_back(front());
    pop();
  }

  /**
   * @brief En este punto ya tenemos todos los elementos dentro de la estructura auxiliar, que nos
   * permite crear la cola de nuevo, pero de manera inversa.
   * 
   */
  for (int i = node_vector.size() - 1; i >= 0; i--) {
    push(node_vector[i]);
  }
};

/**
 * @brief Implementacion del segundo ejercicio solicitado, el cual solicita que a partir del objeto que
 * ha sido creado, cuando se haga uso de este metodo, se produzca la creacion de dos colas nuevas las
 * cuales, la primera de ella tiene los elementos que se encuentran en las posiciones pares de la cola
 * , mientras que la segunda de estas colas contiene los elementos que se encuentran en las posiciones
 * impares de esta, cabe destacar que se puede producir que la cola original que fue introducida
 * por el usuario, puede quedar vacia.
 * 
 * Para la implementacion de esto anterior, vamos a hacer uso de dos atributos para el metodo que permita
 * la creacion de dos colas distitnas que cumplan con la operacion.
 * 
 * NOTA: Hay que tener en cuenta que para poder devolver multiples valores en metodos en c++ se puede
 * hacer uso de los pares que nos dejan devolver multiples valores, para este caso las dos lista que 
 * tenemos implementadas.
 * 
 */
template<class T>
std::pair<queue_l_t<T>, queue_l_t<T>> queue_l_t<T>::divide_into_two_queues(queue_l_t<T> pair_queue, queue_l_t<T> unpair_queue) {
  int counter = 0;
  while (!empty()) {
    if ((counter % 2) == 0) {
      pair_queue.push(front());
      pop();
    } else if ((counter % 2) != 0) {
      unpair_queue.push(front());
      pop();
    }
    counter++;
  }
  std::pair<queue_l_t<T>, queue_l_t<T>> final_result;
  final_result.first = pair_queue;
  final_result.second = unpair_queue;
  return final_result;
};

/**
 * @brief Implementacion del tercer ejercicio, este solicita que a partir de dos colas que son introducidas
 * como parametros del metodo generar como atributo de la clase la cola resultante que posee la cola
 * que se trata la union de las otras dos colas, de manera que se toman como valores los valores de ambas
 * colas de manera alterna.
 * 
 */
template <class T>
void queue_l_t<T>::merge_two_queues(queue_l_t<T> first_queue, queue_l_t<T> second_queue) {
  if (first_queue.size() == second_queue.size()) { /// First == Second
    while (!first_queue.empty()) {
      push(first_queue.front());
      first_queue.pop();
      push(second_queue.front());
      second_queue.pop();
    }
  } else if (first_queue.size() > second_queue.size()) { /// First > Second
    while(!first_queue.empty()) {
      if (second_queue.empty()) {
        push(first_queue.front());
        first_queue.pop();
      } else {
        push(first_queue.front());
        first_queue.pop();
        push(second_queue.front());
        second_queue.pop();
      }
    }
  } else if (second_queue.size() > first_queue.size()) { /// First < Second
    while(!second_queue.empty()) {
      if (first_queue.empty()) {
        push(second_queue.front());
        second_queue.pop();
      } else {
        push(first_queue.front());
        first_queue.pop();
        push(second_queue.front());
        second_queue.pop();
      }
    }
  }
};

/**
 * @brief Implementacion del cuarto ejercicio, se encarga de eliminar los elementos duplicados de una cola
 * para ello necesitamos del empleo de una estructura auxiliar que permita la comprobacion de elementos
 * duplicados.
 * 
 * La estructura que vamos a hacer uso es un vector, ya que nos permite introducir aquellos elementos 
 * para poder comprobar si estas duplicados.
 * 
 */
template<class T>
void queue_l_t<T>::delete_duplicated_elements(void) {
  std::vector<T> auxiliary_vector;
  /// Inicializamos el vector, con el primer elemento de la cola para que exista un posible elemento
  /// dentro de esta
  auxiliary_vector.push_back(front());
  pop();

  while(!empty()) {
    bool delete_operation = false;
    for (int i = 0; i < auxiliary_vector.size(); i++) {
      if (auxiliary_vector[i] == front()) {
        delete_operation = true;
      }
    }
    if (delete_operation == false) {
      auxiliary_vector.push_back(front());
      pop();
    } else 
      pop(); // Eliminamos de la cola, ya que dicho elemento se encuentra dentro de la estrcutura auxiliar
  }

  for (int i = 0; i < auxiliary_vector.size(); i++) {
    push(auxiliary_vector[i]);
  }
};


#endif  // QUEUE_H_
