// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T&);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;

  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

  // PROBLEMAS TEMA5
  void intercambio(void);
  stack_l_t<T> inverso(void);
  void eliminaImpares(void);
  void divide(stack_l_t<T> &mayores, stack_l_t<T> &menores, T caracter);
  T maximo(void);

private:
  dll_t<T> l_;
};

// PROB1 T5
template<class T> void stack_l_t<T>::intercambio(void) {
  assert(!empty());
  T elem1 = top();
  pop();
  T elem2 = top();
  pop();
  push(elem1);
  push(elem2);
}

// PROB2 T5
template<class T> stack_l_t<T> stack_l_t<T>::inverso(void) {
  assert(!empty());
  stack_l_t<T> inversa;
  while(!empty())	{
    inversa.push(top());    // INSERTA top EN NUEVA PILA
    pop();                  // BORRA ELEMENTO DE LA PILA ORIGINAL    
  }
  return inversa;  
}

// PROB3 T5
template<class T> void stack_l_t<T>::eliminaImpares(void){
  assert(!empty());
  stack_l_t<T> aux;
  while(!empty())	{
    aux.push(top());        // COPIA DE LA PILA EN ORDEN INVERSO 
    pop();                  
  }
  while(!aux.empty())	{
    aux.pop();              // ELIMINA DATO IMPAR DE aux 
    if(!aux.empty()) {
      push(aux.top()) ;     // COPIA ELEMENTO PAR
      aux.pop();            // ELIMINA DATO DE aux
    }
  }
}

// PROB4 T5
template<class T> void stack_l_t<T>::divide(stack_l_t<T>& mayores, 
          stack_l_t<T>& menores, T valor){
  assert(!empty());
  while(!empty()) {
    if (top() >= valor) mayores.push(top());
    else menores.push(top());
    pop();
  }
}

// PROB5 T5
template<class T> T stack_l_t<T>::maximo(void) {
  assert(!empty());
  T elem1, elem2;
  while(!empty())	{
    elem1 = top();
    pop();
    if (!empty()) {
      elem2 = top();
      pop();
      push(elem1 > elem2 ? elem1 : elem2);
    }    
  }
  return elem1;
}

// operaciones
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
}

template<class T> const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

template<class T> bool stack_l_t<T>::empty(void) const {
  return l_.empty();
}

// E/S
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
   os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
      os << std::setw(2) << aux->get_data() << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}


#endif  // STACKL_H_
