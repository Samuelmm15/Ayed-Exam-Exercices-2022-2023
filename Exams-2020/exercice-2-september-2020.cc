/**
 * @file exercice-2-september-2020.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Implementación de una función recursiva que se denomina como la función de Ackerman.
 * @version 0.1
 * @date 2023-05-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */


/// Implementación de la función de la función de Ackerman
int Ackerman_function(int m, int n) {
	if (m == 0) 
		return n + 1;
	else if ((m > 0) && (n == 0))
		return Ackerman_function(m - 1, n);
	else if ((m > 0) && (n > 0))
		return Ackerman_function(m - 1, Ackerman_function(m, n - 1));
};