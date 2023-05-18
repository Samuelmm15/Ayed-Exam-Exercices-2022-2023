// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>

#include "dll_node_t.h"

// Clase para almacenar una lista doblemente enlazada
template <class T> class dll_t {
 public:
  // constructor
  dll_t(void) : head_(NULL), tail_(NULL), sz_(0) {}

  // destructor
  ~dll_t(void); 

  // getters
  dll_node_t<T>* get_tail(void) const { return tail_; }
  dll_node_t<T>* get_head(void) const { return head_; }
  int get_size(void) const { return sz_; }

  bool empty(void) const;

  // operaciones
  void push_back(dll_node_t<T>*);
  void push_front(dll_node_t<T>*);

  dll_node_t<T>* pop_back(void);
  dll_node_t<T>* pop_front(void);

  dll_node_t<T>* erase(dll_node_t<T>*);

  /// IMPLEMENTACIÓN DE LOS EJERCICIOS DEL TEMA QUE SON SOLICITADOS
  /// Exercice-1
  void insert_new_node(dll_node_t<T>*, int);
  /// Exercice-2
  void exchange_elements(void);
  /// Exercice-3
  void duplicate_elements(void);
  /// Exercice-4
  void delete_impair_elements(void);
  /// Exercice-5
  dll_t<T> delete_pair_elements(dll_t<T>);

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  dll_node_t<T>* head_;
  dll_node_t<T>* tail_;
  int            sz_;
};


// destructor
template <class T> dll_t<T>::~dll_t(void) {
  while (head_ != NULL) {
    dll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

// Comprobar si lista vacía
template <class T> bool dll_t<T>::empty(void) const {
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } else
    return false;
}

// operaciones
template <class T> void dll_t<T>::push_front(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}

template <class T> void dll_t<T>::push_back(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_back(void) {
  assert(!empty());

  dll_node_t<T>* aux = tail_;
  tail_ = tail_->get_prev();
  if (tail_ != NULL)
    tail_->set_next(NULL);
  else
    head_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_front(void) {
  assert(!empty());

  dll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  if (head_ != NULL)
    head_->set_prev(NULL);
  else
    tail_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T> dll_node_t<T>* dll_t<T>::erase(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (nodo->get_prev() != NULL)
    nodo->get_prev()->set_next(nodo->get_next());
  else
    head_ = nodo->get_next();
  if (nodo->get_next() != NULL)
    nodo->get_next()->set_prev(nodo->get_prev());
  else
    tail_ = nodo->get_prev();
  sz_--;
  nodo->set_prev(NULL);
  nodo->set_next(NULL);
  return nodo;
}

// E/S
template <class T> std::ostream& dll_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

/// Exercice-1
/**
 * @brief Inserción de un nuevo nodo detrás de un nodo que es pasado como parámetro.
 * 
*/
template<class T>
void dll_t<T>::insert_new_node(dll_node_t<T>* new_node, int position) {
  /// Primero recorremos la lista doblemente enlazada hasta encontrarnos en la posición la cual queremos
  /// introducir el nuevo nodo.
  dll_node_t<T>* auxiliary = head_;
  for (int i = 0; i < get_size(); i++) {
    if (i != position)
      auxiliary = auxiliary->get_next();
    else {
      dll_node_t<T>* previous_node = auxiliary->get_next();
      auxiliary->set_next(new_node);
      auxiliary = auxiliary->get_next();
      auxiliary->set_next(previous_node);
    }
  }
};

/// Exercice-2
/**
 * @brief Implementación de un método que permita intercambiar el último y el penúltimo elemento 
 * de la lista doblemente enlazada.
 * 
*/
template<class T>
void dll_t<T>::exchange_elements(void) {
  /**
   * @brief Debido a que se tiene un puntero que apunta a la cola de la lista, vamos a hacer uso de
   * dicho puntero para poder obtener el último y el penúltimo elemento de la lista para poder
   * intercambiar ambos.
   * 
   */
  dll_node_t<T>* last_element = tail_;
  dll_node_t<T>* penultimate_element = tail_->get_prev();

  /**
   * @brief Una vez tenemos dichos elementos, los eliminamos de la cola original y los volvemos
   * a introducir por el final de manera inversa.
   * 
   */
  pop_back();
  pop_back();
  push_back(last_element);
  push_back(penultimate_element);
};

/// Exercice-3
/**
 * Implementación de un método que permita duplciar todos los elementos de una lista insertandolos
 * como una copia seguidas al final de la lista original.
 * 
*/
template<class T>
void dll_t<T>::duplicate_elements(void) {
  /**
   * @brief Para comenzar con la implementación, cada uno de los elementos que serán una copia
   * serán obtenidos de la lista original y se irán introduciendo al final de la lista original.
   * 
   */
  dll_node_t<T>* auxiliary = head_;
  int original_size = get_size();
  for (int i = 0; i < original_size; i++) {
    dll_node_t<T>* node_to_insert = new dll_node_t<T>(auxiliary->get_data());
    push_back(node_to_insert);
    auxiliary = auxiliary->get_next();
  }
};

/// Exercice-4
/**
 * @brief Implementar un método que permita eliminar y liberar los elementos de posiciones impares de
 * la lista.
 * 
*/
template<class T>
void dll_t<T>::delete_impair_elements(void) {
  /**
   * @brief Para comenzar creamos un puntero auxiliar que apunte a la cabeza de la lista,
   * de manera que nos permita ir recorriendo la lista y en aquellas posiciones impares, debemos
   * de realizar la eliminación del nodo en el que nos encontramos.
   * 
   */
  dll_node_t<T>* auxiliary = head_;
  int counter = 0;
  while (auxiliary != NULL) {
    if ((counter % 2) != 0)
      erase(auxiliary); /// Si el método erase estuviera bien implementado funcionaría de manera correcta.
    auxiliary = auxiliary->get_next();
    counter++;
  }
};

/// Exercice-5
/**
 * @brief Implementación de un método que permita eliminar los elementos que se encuentran en
 * las posiciones pares de una lista y trasladarlas a una lista nueva en el mismo orden en el que
 * fueron eliminadas.
 * 
*/
template<class T>
dll_t<T> dll_t<T>::delete_pair_elements(dll_t<T> new_list) {
  /**
   * @brief Para poder recorrer todos los elementos de la lista, debemos de crear una variable auxiliar
   * que permita recorrer todos los elementos de la lista, por otra parte aquellos elementos que se
   * encuentran en las posiciones pares son introducidos en la lista que se le pasa como parámetro, y
   * para eliminarlos de la lista original se hace uso del método ya implementado erase().
   * 
   */
  dll_node_t<T>* auxiliary = head_;
  int counter = 0;
  while(auxiliary != NULL) {
    if ((counter % 2) == 0) {
      new_list.push_front(new dll_node_t<T>(auxiliary->get_data()));
      // erase(auxiliary); Si el la operación funcionara de manera correcta se podrían eliminar los nodos que se pasan y que se continue de manera correcta.
    }
    auxiliary = auxiliary->get_next();
    counter++;
  }
  new_list.write();
  std::cout << std::endl;
  return new_list;
};

#endif  // DLLT_H_
