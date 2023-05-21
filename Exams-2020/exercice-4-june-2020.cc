/**
 * @file exercice-4-june-2020.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de un método de la clase sll_t<T> que permita invertir el orden de la lista.
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Para la implementación de dicho método se hará uso de bucles y punteros auxiliares que nos permitan invertir el orden
 * de la lista que se encuentra dentro del objeto a través del cual se invoca dicho método.
 * 
 */
template<class T>
void sll_t<T>::inverse(void) {
    sll_node_t<T>* auxiliary_head = get_head(); /// 1 -> 2 -> 3 -> 4
    /**
     * @brief Para comenzar con la implementación del método que se encarga de invertir los elementos,
     * hacemos uso de una lista adicinal que nos permita 
     *  
     */
    sll_node_t<T>* auxiliary_prev;
    sll_node_t<T>* new_links;
    while (auxiliary_head != NULL) {
        if (auxiliary_head == get_head()) {
            auxiliary_prev = auxiliary_head; /// 1
            auxiliary_head = auxiliary_head->get_next();
            new_links = auxiliary_head; /// 2
            new_links->set_next(auxiliary_prev);  /// 2 -> 1
        } else {
            auxiliary_prev = new_links; /// 2 -> 1
            auxiliary_head = auxiliary_head.get_next(); /// 3
            new_links = auxiliary_head; /// 3
            new_links = new_links->set_next(auxiliary_prev); /// 3 -> 2 -> 1
        }
    }
    set_head(new_links); /// 4 -> 3 -> 2 -> 1
};