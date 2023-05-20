/**
 * @file exercice-1-september-2020.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de un método recursivo que permita invertir el orden de una lista simplemente enlazada, sin
 * necesidad de emplear o de hacer uso de una estructura de datos auxiliar.
 * 
 * Cabe destacar que el método a implementar se trata de un método privado, que será llamado desde el exterior mediante
 * un método público que permitirá invocar dicho método privado.
 * @version 0.1
 * @date 2023-05-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Para comenzar con la implementación del ejercicio solicitado, se realizará la implementación
 * del método privado en primera instancia y después se mostrará como se debe de implementar el método público.
 * 
 */
template<class T>
sll_node_t<T>* sll_t<T>::inv_r_(sll_node_t<T>* nodo) {
	sll_node_t<T>* auxiliary_next_node = nodo->get_next();

	if (nodo == head_) {
		head_->get_next(NULL);
	}

	if (auxiliary_next_node == NULL) {
		head_ = nodo;
		return nodo;
	}

	auxiliary_next_node = inv_r_(auxiliary_next_node);
	auxiliary_next_node->set_next(nodo);
	return nodo;
};

/**
 * @brief Cabe destacar que la filosofía usada anteriormente tiene base en que se hace uso del atributo head_
 * de manera que se va sustituyendo este en todas las interacciones con la lista simplemente enlazada como 
 * un elemento siempre como si cada elemento fuera la cabeza de la lista, y por tanto cuando se alcanza el limite
 * final de la lista simplemente enlzada, todos los elementos en cada una de las interacciones corresponden
 * como el head_ de la lista, por tanto estos se van introduciendo como resultado de cada una de las intereacciones
 * en la lista simplemente enlazada resultante.
 *  
 */

/// Representación del método público usado para invocar el método privado implementado anteriormente
template<class T>
void sll_t<T>::inv_r() {
	if (!empty())
		inv_r(head_);
};