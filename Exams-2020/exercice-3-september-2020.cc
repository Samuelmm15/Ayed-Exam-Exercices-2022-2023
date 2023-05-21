/**
 * @file exercice-3-september-2020.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de un método de la clase matrix_t que permite que dos matrices introducidas
 * como parámetros de dicho método se puedan convertir en la matriz resultante del
 * objeto invocante de dicho método.
 * 
 * Además, cabe destacar que el parámetro by_rows se trata de un booleano que nos permite determinar
 * si la concatenación se deberá de realizar por filas o por columnas, comprobando en dichos
 * casos si tiene el mismo número de columnas o el mismo número de filas.
 * @version 0.1
 * @date 2023-05-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */



/// Implementación del método de la clase matrix_t
template<class T>
void matrix_t<T>::concatenate(const matrix_t<T>& u, const matrix_t<T>& v, const bool by_rows) {
    if (by_rows == true) { /// Mismo número de filas
        /**
         * @brief Para comenzar, dependiendo del booleano se establece un número de filas o de columnas como
         * condición, para este caso la matriz resultante debe de tener el mismo número de filas que 
         * la matriz original.
         *  
         */
        resize(u.get_m(), u.get_n() + v.get_n()); /// Se reserva el mismo número de filas, y el sumatorio de columnas de ambas matrices.
        for (int i = 0; i < get_m(); i++) {
            int columns = 0;
            for (int j = 0; j < u.get_n(); j++) {
                item(i, columns) = u.item(i, j);
                columns++;
            }
            for (k = 0; k < v.get_n(); k++) {
                item(i, columns) = v.item(i, k);
                columns++;
            }
        }
    } else { /// Mismo número de columnas
        /**
         * @brief Para este caso, debemos de tener en cuenta que lo que se tiene como igual es el número de columnas, por
         * tanto, antes de comenzar debemos de realizar un resize de manera que se tenga en la matriz resultante el mismo
         * número de columnas que las matrices que han sido pasadas como parámetros.
         * 
         */
        resize(u.get_m() + v.get_m(), u.get_n()); /// Se reserva el sumatorio del número de filas y se tiene el mismo número de columnas que las matrices originales
        /// Recorremos de manera completa la primera matriz
        for (int i = 0; i < u.get_m(); i++) {
            for (j = 0; j < u.get_n(); j++) {
                item(i, j) = u.item(i, j);
            }
        }
        int row = u.get_m() - 1; /// Debido a que el tamaño es 2, por tanto, la fila es la fila 1, no la dos, si no daría error
        for (int i = 0; i < v.get_m(); v++) {
            for (j = 0; j < v.get_n(); j++) {
                item (row, j) = v.item(i, j);
            }
            row++;
        }
    }
};