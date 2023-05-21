/**
 * @file exercice-1-july-2020.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de un método de la clase sll_t<T> que permita invertir la cola que se encuentra dentro del objeto que invoca dicho método.
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Para la implementación de dicho método se va ha hacer uso de la clase queue_l_t<T>, ya que hace uso de una lista doblemente enlazada
 * para su implementación, lo que nos permite mayores opciones que si hacemos uso de la clase que ha sido implementada mediante vectores.
 * 
 */
template<class T>
void sll_t<T>::reverse(void) {
    sll_node_t<T>* auxiliary_head = head_;
    queue_l_t<sll_node_t<T>*> auxiliary_queue;

    /**
     * @brief Comenzamos con la implementación del bucle que se encarga de almacenar y liberar cada uno de los elementos que se 
     * encuentran dentro de la lista simplemente enlazada.
     * 
     */
    while (auxiliary_head != NULL) {
        auxiliary_queue.push_back(auxiliary_head);
        auxiliary_head = auxiliary_head->get_next();
        pop();
    }

    /**
     * @brief En este punto tenemos todos los elementos de la lista simplemente enlazada dentro de la cola, por tanto, a continuación
     * sacamos cada uno de los elementos de la cola para poder introducirlos dentro de la lista simplemente enlazada resultante.
     * 
     */
    int static_size = auxiliary_queue.get_size();
    for (int i = 0; i < static_size; i++) {
        push_front(auxiliary_queue.front());
        auxiliary_queue.pop();
    }
};