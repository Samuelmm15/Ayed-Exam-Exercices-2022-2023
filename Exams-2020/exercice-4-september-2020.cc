/**
 * @file exercice-4-september-2020.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Programa basado en listas simples enlazadas.
 * @version 0.1
 * @date 2023-05-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/// Comenzamos con la implementación del método de suma para la clase sparse_vector.
void sparse_vector::add(const sparse_vector& u, const sparse_vector& v) {
    /// Cabe destacar que el vector invocante del método es el que adquiere el resultado de la suma de cada uno de los elementos de los sparse_vector.
    assert(!u.empty() || !v.empty());
    assert(u.size() == v.size());
    sparse_node* u_head = u.head();
    sparse_node* v_head = v.head();
    while ((u_head != NULL) && (v_head != NUll)) {
        if (u_head->get_inx() == v_head->get_inx()) {
            double result = u_head->get_val() + v->get_val();
            sparse_node* result_node = new sparse_node(u_head->get_inx(), result);
            insert_tail(result_node);
            u_head = u_head->get_next();
            v_head = v_head->get_next();
        } else {
            if (u_head->get_inx() < v_head->get_inx()) {
                sparse_node* result_node = new sparse_node(u_head->get_inx(), u_head->get_val());
                u_head = u_head->get_next();
                insert_tail(result_node);
            } else if (v_head->get_inx() < u_head->get_inx()) {
                sparse_node* result_node = new sparse_node(v_head->get_inx(), v_head->get_val());
                v_head = v_head->get_next();
                insert_tail(result_node);
            }
        }
        if (v_head == NULL) {
            while (u_head != NULL){
                sparse_node* result_node = new sparse_node(u_head->get_inx(), u_head->get_val());
                insert_tail(result_node);
                u_head = u_head->get_next();
            }
        } else if (u_head == NULL) {
            while (v_head != NULL) {
                sparse_node* result_node = new sparse_node(v_head->get_inx(), v_head->get_val());
                insert_tail(result_node);
                v_head = v_head->get_next();
            }
        }
    }
};