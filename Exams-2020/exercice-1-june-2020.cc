/**
 * @file exercice-1-june-2020.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de una función palíndroma recursiva que permita comprobar si una cadena que se le pasa como parámetro es palíndroma o no.
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/// Cabe destacar que la función a implementar debe de contener e implementar un algoritmo recursivo.
bool is_pal(const vector_t<char>& string, int left, int right) {
    /**
     * @brief Voy a tener en cuenta que el int left y el int right hacen referencia a las posiciones del principio y del final
     * del vector, por tanto, por cada interacción se puede realizar la comprobación de cada uno de estos elementos del vector,
     * es por ello que, se va realizando la comprobación en cada una de las interacciones y si se produce que en alguna de ellas
     * alguno de estos dos no coincide, pues se genera que se retorne un false, en el caso en el que estos dos sean iguales en numero
     * y siempre se haya producido que coinciden, pues se puede retornar true y por tanto se puede establecer que la cadena introducida
     * es palíndroma.
     * 
     * NOTA: hay que tener en cuenta que suponemos que left coresponde con la posición cero del vector y que right corresponde con
     * la posición size() - 1 del vector, además que estos dos son pasados de manera correcta.
     * 
     */
    if (string[left] == string[right]) {
        if (left >= right) {
            return true;
        } else {
            is_pal(string, left++, right--);
        }
    } else {
        return false;
    }
};