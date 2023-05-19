// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// COMENTARIOS: clase TAD cola implementada con un vector circular

#pragma once

#include <iostream>
#include <cassert>
#include <vector>

#include "round_vector_t.h"

const unsigned char MAX_STACK_SIZE = 20;

using namespace std;

template <class T>
class queue_v_t
{
public:
  // constructor, constructor por defecto y destructor
	queue_v_t(const int);
	queue_v_t(void);
	~queue_v_t(void);

	bool empty(void) const;
	bool full(void) const;
	int size(void) const;
	
	void push(const T& dato);
	void pop(void);
	const T& front(void) const;
	const T& back(void) const;

	void write(ostream& os = cout) const;

	/// Implementación de los distintos ejercicios solicitados
	/// Exercice-1
	void inverse(void);
	/// Exercice-2
	void divide_into_two_queues(void);
	/// Exercice-3
	void merge_queues(queue_v_t<T>, queue_v_t<T>);
	/// Exercice-4
	void delete_duplicated(void);
	
private:
	round_vector_t<T> v_;
	int         		  front_;
	int       				back_;
};

template<class T>
queue_v_t<T>::queue_v_t(const int max_sz):
v_(max_sz),
front_(0),
back_(-1)
{}

template<class T>
queue_v_t<T>::queue_v_t(void):
v_(MAX_STACK_SIZE),
front_(0),
back_(-1)
{}

template<class T>
queue_v_t<T>::~queue_v_t(void)
{}

template<class T>
bool
queue_v_t<T>::empty(void) const
{
	return (back_ < front_);
}

template<class T>
bool
queue_v_t<T>::full(void) const
{
	return (size() >= v_.get_size() - 1);
}

template<class T>
int
queue_v_t<T>::size(void) const
{
 	return back_ - front_ + 1;
}

template<class T>
void
queue_v_t<T>::push(const T& dato)
{
	assert(!full());
	back_++;
	v_.at(back_) = dato;
}

template<class T>
void
queue_v_t<T>::pop(void)
{
	assert(!empty());			
	front_++;
}

template<class T>
const T&
queue_v_t<T>::front(void) const
{
	assert(!empty());
	return v_.at(front_);
}

template<class T>
const T&
queue_v_t<T>::back(void) const
{
	assert(!empty());
	return v_.at(back_);
}

template<class T>
void
queue_v_t<T>::write(ostream& os) const
{
	for(int i = back_; i >= front_; i--)
		os << v_.at(i) << " ";  
	os << endl;
}

template<class T>
ostream&
operator<<(ostream& os, const queue_v_t<T>& q)
{
	q.write(os);
	return os;
}

/// Implementación de los distintos ejercicios solicitados
/// Exercice-1
/**
 * @brief Implementación de un método de la clase que permita invertir el orden de los elementos de una
 * cola, usando su es necesario una estructura auxiliar para ello.
 * 
*/
template<class T>
void queue_v_t<T>::inverse(void) {
	/**
	 * @brief Para comenzar, obtenemos cada uno de los distintos elementos que se encuentran dentro
	 * de la cola original y los metemos dentro del vector que usamos como estructura adicional para
	 * poder cumplir con el objetivo.
	 * 
	 */
	std::vector<T> auxiliary_vector;
	for (int i = 0; i < size(); i++) {
		auxiliary_vector.push_back(front());
		pop();
	}

	/**
	 * @brief Para continuar, una vez que no tenemos nada dentro de la cola original, trasladamos los
	 * elementos del vector usado de manera auxiliar a la nueva cola inversa.
	 * 
	 */
	for (int i = auxiliary_vector.size() - 1; i >= 0; i--) {
		push(auxiliary_vector[i]);
	}
};

/// Exercice-2
/**
 * @brief Implementación de un método de la clase que permita dividir una cola original en dos colas
 * distintas. La primera de ella debe de contener los elementos que se encontraban en las posiciones
 * pares, mientras que la segunda de ellas, debe de contener los elementos que se encontraban en las
 * posiciones impares.
 * 
 * Hay que tener en cuenta que la cola de elementos pares se dejará dentro de la cola original del
 * objeto invocante, mientras que la segunda cola de elementos impares será devuelta como parámetro.
 * 
*/
template<class T>
void queue_v_t<T>::divide_into_two_queues(void) {
	queue_v_t<T> inserted_queue;
	std::vector<T> auxiliary_pair_vector;
	std::vector<T> auxiliary_unpair_vector;
	int static_size = size();
	for (int i = 0; i < static_size; i++) {
		if ((i % 2) == 0) {
			auxiliary_pair_vector.push_back(front());
			pop();
		} else if ((i % 2) != 0) {
			auxiliary_unpair_vector.push_back(front());
			pop();
		}
	}

	/**
	 * @brief En este punto ya tenemos dividida la cola original en dos vectores, uno de ellos contiene
	 * los elementos de las posiciones pares y el otro el de las posiciones impares.
	 *
	 * Para comenzar trasladamos los elementos pares a su correspondiente cola y posteriormente
	 * trasladamos los elementos de las posiciones impares a su correspondiente cola.
	 *  
	 */
	for (int i = 0; i < auxiliary_pair_vector.size(); i++) {
		push(auxiliary_pair_vector[i]);
	}

	for (int i = 0; i < auxiliary_unpair_vector.size(); i++) {
		inserted_queue.push(auxiliary_unpair_vector[i]);
	}

	write();
	cout << endl;
	cout << "La cola de elementos de las posiciones impares: " << endl;
	inserted_queue.write();
	cout << endl;
};

/// Exercice-3
/**
 * @brief Implementación de un método que permita fusionar dos colas que se pasan como parámetros
 * a dicho método y permitir fusionar dichas colas en una única cola tomando valores de una y otra,
 * pero, en el caso de que tengan distinto tamaño, establecer el resto de elementos de la de mayor
 * tamaño al final de la cola fusionada.
 * 
*/
template<class T>
void queue_v_t<T>::merge_queues(queue_v_t<T> first_queue, queue_v_t<T> second_queue) {
	if (first_queue.size() == second_queue.size()) { /// Caso de colas iguales
		int static_size = first_queue.size();
		for (int i = 0; i < static_size; i++) {
			push(first_queue.front());
			first_queue.pop();
			push(second_queue.front());
			second_queue.pop();
		}
	} else if (first_queue.size() > second_queue.size()) { /// Caso en que 1 > 2
		int static_size = first_queue.size();
		int static_size_2 = second_queue.size();
		for (int i = 0; i < static_size; i++) {
			if (i < static_size_2) {
				push(first_queue.front());
				first_queue.pop();
				push(second_queue.front());
				second_queue.pop();
			} else {
				push(first_queue.front());
				first_queue.pop();
			}
		}
	} else if (second_queue.size() > first_queue.size()) { /// Caso en que 2 > 1
		int static_size = second_queue.size();
		int static_size_2 = first_queue.size();
		for (int i = 0; i < static_size; i++) {
			if (i < static_size_2) {
				push(first_queue.front());
				first_queue.pop();
				push(second_queue.front());
				second_queue.pop();
			} else {
				push(second_queue.front());
				second_queue.pop();
			}
		}
	}
};

/// Exercice-4
	/**
	 * @brief Implementación de un método de la clase que permite eliminar los elementos repetidos
	 * que se encuentren dentro de la cola.
	 * 
	*/
template<class T>
void queue_v_t<T>::delete_duplicated(void) {
	/**
	 * @brief Para poder comprobar aquellos elementos que se encuentran duplicados dentro
	 * de la cola original, vamos a hacer uso de una estructura auxiliar de tipo vector que nos permita
	 * realizar comprobaciones para ver si el elemento que va a ser introducido en dicho vector
	 * auxiliar se encuentra duplicado o no.
	 * 
	 */
	std::vector<T> auxiliary_vector;
	auxiliary_vector.push_back(front());
	pop();
	while (!empty()) {
		bool introduce_flag = true;
		for (int i = 0; i < auxiliary_vector.size(); i++) {
			if (front() == auxiliary_vector[i])
				introduce_flag = false;
		}
		if (introduce_flag == true) {
			auxiliary_vector.push_back(front());
			pop();
		} else
			pop();
	}

	/**
	 * @brief En este punto hemos obtenido el vector con todos los elementos no repetidos, es por ello
	 * que los introducimos de nuevo en la cola.
	 * 
	 */
	for (int i = 0; i < auxiliary_vector.size(); i++) {
		push(auxiliary_vector[i]);
	}
};
