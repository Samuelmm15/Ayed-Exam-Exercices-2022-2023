/// IMPLEMENTACIÓN DE LOS DISTINTOS EJERCICIOS COMO MÉTODOS DE LA PROPIA CLASE LISTA SIMPLEMENTE ENLAZADA

// AUTOR: Samuel Martín Morales
// FECHA: 29/03/2023
// EMAIL: alu0101359526@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef SLLT_H_
#define SLLT_H_

// Inclusión de las librerías necesarias
#include <iostream>
#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T> class sll_t {
 public:
  // constructor
  sll_t(void) : head_(NULL) {}

  // destructor
  ~sll_t(void);

  // getters
  sll_node_t<T>* get_head(void) const { return head_; };
  
  bool empty(void) const;

  // operaciones
  void push_front(sll_node_t<T>*);
  sll_node_t<T>* pop_front(void);

  void insert_after(sll_node_t<T>*, sll_node_t<T>*);
  sll_node_t<T>* erase_after(sll_node_t<T>*);

  sll_node_t<T>* search(const T&) const;

  /// Implementación de los distintos ejercicios como métodos de la clase
  /// Exercice-1
  void delete_last_element(void);
  /// Exercice-2
  void exchange_first_second_element(void);
  /// Exercice-3
  void duplicate_all_elements(void);


  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  sll_node_t<T>* head_;
};


// destructor
template <class T> sll_t<T>::~sll_t(void) {
  while (!empty()) {
    sll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

// Comprobar si lista vacía
template <class T> bool sll_t<T>::empty(void) const {
  return head_ == NULL;
}

// operaciones
template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n->set_next(head_);
  head_ = n;
}

template <class T> sll_node_t<T>* sll_t<T>::pop_front(void) { 
  assert(!empty());
  sll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev,
					       sll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) { 
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T>* aux = prev->get_next();
  
  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const {
  sll_node_t<T>* aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();
    
  return aux;
}

// E/S
template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

/// IMPLEMENTACIÓN DE LOS DISTINTOS EJERCICIOS
// Exercice-1
/**
 * @brief Implementación de un método de la clase sll_t que permita eliminar y liberar
 * el último elemento de una lista simplemente enlazada que haya sido creada.
 * 
 */
template<class T> 
void sll_t<T>::delete_last_element(void) {
  /**
   * @brief Para comenzar con la eliminación del último elemento de la lista, debemos de 
   * saber cuantos elementos tiene dicha lista y una vez se tiene el numero de elementos
   * que se encuentran dentro de la lista, se recorre el puntero que apunta desde el head hasta
   * el final, permitiendo eliminar únicamente el último elemento cuando este recorra todos los
   * elementos desde el principio hasta el final.
   * 
   */
  sll_node_t<T>* auxiliary_head = head_;
  int counter = 0;
  while(auxiliary_head != NULL) {
    counter++;
    auxiliary_head = auxiliary_head->get_next();
  }

  /**
   * @brief En este punto se apunta con el puntero hasta la penúltima posición de la lista, para poder
   * eliminar dicho elemento.
   * 
   * Cabe destacar que hay que quitar dos, porque para poder obtener el último elemento de
   * la lista, hay que tener en cuenta que el primer elemento, es decir, el head, ya se cuenta
   * para la primera implementación, ya que no se recorre la lista desde la posición cero,
   * sino desde la posición 1.
   * 
   */
  auxiliary_head = head_;
  for (int i = 0; i < counter - 2; i++) {
    std::cout << i << std::endl;
    auxiliary_head = auxiliary_head->get_next();
  }

  /// Ponemos el último nodo de la lista como nulo para eliminarlo y liberarlo.
  erase_after(auxiliary_head);
};

/// Exercice-2
/**
 * @brief Implementación de un método de la clase que permita intercambiar el primer y el segundo
 * elemento de la lista.
*/
template<class T>
void sll_t<T>::exchange_first_second_element(void) {
  /// Para comenzar obtenemos el primer y el segundo elemento de la lista simplemente enlazada.
  sll_node_t<T>* first_element = head_;
  sll_node_t<T>* second_element = head_->get_next();

  /// Realizamos la eliminación de estos dos elementos para poder intercambiarlos al introducirlos de nuevo en la lista.
  head_->set_next(NULL);
  head_ = second_element->get_next(); /// Ponemos que la cabeza de la lista es el tercer elemento

  /// Introducimos los elementos en la lista de manera inversa para que se hayan intercambiado por tanto
  push_front(first_element);
  push_front(second_element);
};

/// Exercice-3
/**
 * @brief Implementación de un método de la clase que permita duplicar todos los elementos
 * de la lista e introducirlos a continuación de este elemento que ha sido tomado como original.
*/
template<class T>
void sll_t<T>::duplicate_all_elements(void) {
  /// Hacemos uso de un bucle que nos permita recorrer todos los elementos que se encuentran dentro
  /// de la lista.
  sll_node_t<T>* auxiliary = head_;
  while (auxiliary != NULL) {
    sll_node_t<T>* auxiliary_addition = auxiliary;
    auxiliary_addition->set_next(auxiliary->get_next());
    insert_after(auxiliary, auxiliary_addition);
    // std::cout << auxiliary->get_data() << std::endl;
    // std::cout << auxiliary->get_next()->get_data() << std::endl;
    auxiliary = auxiliary->get_next();
    auxiliary = auxiliary->get_next();
    std::cout << auxiliary->get_data() << std::endl;

  }
};

#endif  // SLLT_H_