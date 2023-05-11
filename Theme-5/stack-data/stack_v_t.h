// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKV_H_
#define STACKV_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "vector_t.h"

#define MAX_STACK_SIZE 20

// Clase para pilas mediante estructura estática
template<class T> class stack_v_t {
 public:
  // constructores
  stack_v_t(int max_sz) : v_(max_sz), top_(-1) {}
  stack_v_t(void) : v_(MAX_STACK_SIZE), top_(-1) {}

  // destructor
  ~stack_v_t(void) {}

  // operaciones
  void push(const T& dato);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;
  bool full(void) const;

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

  // PROBLEMAS TEMA5
  void intercambio(void);
  stack_v_t<T> inverso(void);
  void eliminaImpares(void);
  void divide(stack_v_t<T> &mayores, stack_v_t<T> &menores, T valor);
  T maximo(void);

 private:
  vector_t<T> v_;
  int         top_;
};

// PROB1 T5
template<class T> void stack_v_t<T>::intercambio(void) {
  assert(!empty());			
  T elem1 = top();
  pop();
  assert(!empty());
  T elem2 = top();
  pop();
  push(elem1);
  push(elem2);
}

// PROB2 T5
template<class T> stack_v_t<T> stack_v_t<T>::inverso(void) {
  assert(!empty());
  stack_v_t<T> inversa;
  while(!empty())	{
    inversa.push(top());    // INSERTA top EN NUEVA PILA
    pop();                  // BORRA ELEMENTO DE LA PILA ORIGINAL    
  }
  return inversa;  
}

// PROB3 T5
template<class T> void stack_v_t<T>::eliminaImpares(void){
  assert(!empty());
  stack_v_t<T> aux;
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
template<class T> void stack_v_t<T>::divide(stack_v_t<T>& mayores, 
          stack_v_t<T>& menores, T valor){
  assert(!empty());
  while(!empty()) {
    if (top() >= valor) mayores.push(top());
    else menores.push(top());
    pop();
  }
}

// PROB5 T5
template<class T> T stack_v_t<T>::maximo(void) {
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
template<class T> void stack_v_t<T>::push(const T& dato) {
  assert(!full());
  v_[++top_] = dato;
}

template<class T> void stack_v_t<T>::pop(void) {
  assert(!empty());			
  top_--;
}

template<class T> const T& stack_v_t<T>::top(void) const {
  assert(!empty());
  return v_[top_];
}

template<class T> bool stack_v_t<T>::empty(void) const {
  return (top_ < 0);
}

template<class T> bool stack_v_t<T>::full(void) const {
  return (top_ == v_.get_size() - 1);
}

// E/S
template<class T> std::ostream& stack_v_t<T>::write(std::ostream& os) const {
  for(int i = top_; i >= 0; i--)
  //  os << " │ " << std::setw(2) << v_[i] << "  │" << std::endl;
  //os << " └─────┘" << std::endl;
    os << std::setw(2) << v_[i] << std::endl;
  return os;
}


#endif  // STACKV_H_
