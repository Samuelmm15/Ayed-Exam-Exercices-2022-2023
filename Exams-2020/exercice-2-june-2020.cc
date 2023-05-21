/**
 * @file exercice-2-june-2020.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de una función externa a la clase matrix_t que permita el cálculo del producto de dos matrices
 * que se le pasan como parámetros de dicha función.
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Para la implementación de dicha función, vamos a suponer que se trata de una función externa de la función
 * principal del programa, es por ello, que teniendo esto en cuenta, la matriz resultante tras la operación
 * será devuelta tras la ejecución de dicha función.
 * 
 * NOTA: el cálculo del producto de matrices se debe de realizar filas por columnas. La única condición que 
 * se debe de cumplir para poder realizar e implementar dicha operación es que el número de columnas de la primera
 * matriz debe de coincidir con el número de filas de la segunda matriz.
 * 
 */
/// Hacemos uso de plantilla de función ya que como no sabemos el tipo de dato el cual se va a hacer uso para la operación de matrices, pues es necesario hacer uso
/// de la plantilla de función.
template<class T>
matrix_t<T> matrix_multiplication(matrix_t<T>& matrix_1, matrix_t<T>& matrix_2) {
    /// El funcionamiento de assert se basa principalmente en que si la condición que ponemos dentro es verdadera, el programa funciona de manera correcta
    /// y continua con su funcionamiento, en cambio cuando se produce que la condición falla por alguno de los motivos, se produce que que se finaliza el programa
    /// en el punto donde se posiciona el assert.
    assert(matrix_1.get_n() == matrix_2.get_m());
    matrix_t<T> matrix_result(matrix_1.get_m(), matrix_2.get_n()); /// Matriz resultante corresponde con el número de filas de la matriz 1 y el número de columnas de la matriz 2

    for (int i = 0; i < matrix_1.get_m(); i++) {
        for (int j = 0; j < matrix_2.get_n(); j++) {
            vector_t<T> row_matrix_1 = matrix_1.row(i);
            vector_t<T> col_matrix_2 = matrix_2.col(j);
            T total_result = row_matrix_1.scal_prod(col_matrix_2);
            matrix_result.set(i, j, total_result);   
        }
    }
};

int main() {
    /**
     * @brief Contenido necesario para la llamada de la función implementada anteriormente.
     * 
     */
    return 0;
};
