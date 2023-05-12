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
  void inverse_queue_elements(void);

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
  vector<T> node_vector;
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


#endif  // QUEUE_H_
