// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// COMENTARIOS: programa de prueba del TAD cola
// Se compila con:
// g++ main_queue.cpp -o main_queue

//#include <cstdio>
#include "queue_v_t.h"
#include "queue_l_t.h"

int main(void)
{
	// queue_v_t<char> cola_vector;

	// for (int i = 0; i < 10; i++)
	// {
	// 	cola_vector.push('a' + i);
	// 	cout << cola_vector;
	// }

	// cout << endl;

	// while (!cola_vector.empty())
	// {
	// 	cola_vector.pop();
	// 	cout << cola_vector;
	// }

	queue_l_t<char> cola_lista;

	for (int i = 0; i < 10; i++)
	{
		cola_lista.push('a' + i);
	}

	cout << endl;

	/**
	 * @brief En este punto llamamos al metodo creado para el ejercicio 1, que nos permite
	 * ver el resultado final del ejercicio.
	 * 
	 */
	cout << "La cola de manera original es:" << endl;
	cola_lista.write();
	cout << endl;
	cout << "Resultado final del ejercicio 1, cola de manera inversa:" << endl;
	cola_lista.inverse_queue_elements();
	cola_lista.write();
	cout << endl;


	// while (!cola_lista.empty())
	// {
	// 	cola_lista.pop();
	// 	cout << cola_lista;
	// }

	return 0;
}
