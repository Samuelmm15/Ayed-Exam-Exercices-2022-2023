// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// COMENTARIOS: programa de prueba del TAD cola
// Se compila con:
// g++ main_queue.cpp -o main_queue

//#include <cstdio>
#include <utility>

#include "queue_v_t.h"
#include "queue_l_t.h"

int main(void)
{
	queue_v_t<char> cola_vector;

	for (int i = 0; i < 10; i++)
	{
		cola_vector.push('a' + i);
		cout << cola_vector;
	}

	cout << endl;

	// queue_v_t<char> cola_2_vector;

	// for (int i = 0; i < 10; i++)
	// {
	// 	cola_2_vector.push('a' + i);
	// 	cout << cola_2_vector;
	// }

	cout << endl;

	// while (!cola_vector.empty())
	// {
	// 	cola_vector.pop();
	// 	cout << cola_vector;
	// }

	/// IMPLEMENTACIÓN DE LOS MÉTODOS Y LAS OPERACIONES DENTRO DE LA COLA DE TIPO LISTA

	// queue_l_t<char> cola_lista;

	// for (int i = 0; i < 10; i++)
	// {
	// 	cola_lista.push('a' + i);
	// }

	// cout << endl;

	// /**
	//  * @brief En este punto llamamos al metodo creado para el ejercicio 1, que nos permite
	//  * ver el resultado final del ejercicio.
	//  * 
	//  */
	// cout << "La cola de manera original es:" << endl;
	// cola_lista.write();
	// cout << endl;
	// cout << "Resultado final del ejercicio 1, cola de manera inversa:" << endl;
	// cola_lista.inverse_queue_elements();
	// cola_lista.write();
	// cout << endl;
	// queue_l_t<char> pair_queue;
	// queue_l_t<char> unpair_queue;
	// cout << "Resultado final del ejercicio 2, cola dividida en dos colas distintas: " << endl;
	// pair<queue_l_t<char>, queue_l_t<char>> result = cola_lista.divide_into_two_queues(pair_queue, unpair_queue);

	// cout << "Cola par: " << endl;
	// result.first.write();
	// cout << endl;
	// cout << "Cola impar: " << endl;
	// result.second.write();
	// cout << endl;

	// /// Comprobacion del tercer ejercicio implementado
	// queue_l_t<char> cola_lista_2;

	// for (int i = 0; i < 10; i++)
	// {
	// 	cola_lista_2.push('a' + i);
	// }

	// cout << endl;

	// /**
	//  * @brief En este punto llamamos al metodo creado para el ejercicio 1, que nos permite
	//  * ver el resultado final del ejercicio.
	//  * 
	//  */
	// cout << "La cola de manera original es:" << endl;
	// cola_lista_2.write();
	// cout << endl;

	// queue_l_t<char> cola_resultante;
	// cola_resultante.merge_two_queues(cola_lista, cola_lista_2);
	
	// cout << "El resultado final tras la fusion de las colas es: " << endl;
	// cola_resultante.write();
	// cout << endl;

	// while (!cola_lista.empty())
	// {
	// 	cola_lista.pop();
	// 	cout << cola_lista;
	// }

	// /**
	//  * @brief Comprobacion del ultimo ejercicio del tema 6
	//  * 
	//  */
	// queue_l_t<char> cola_lista;

	// for (int i = 0; i < 10; i++)
	// {
	// 	cola_lista.push('a' + i);
	// }
	// cola_lista.push('a');
	// cola_lista.push('e');

	// cout << endl;

	// cout << "La cola antes de eliminar los duplicados es: " << endl;
	// cola_lista.write();
	// cout << endl;

	// cola_lista.delete_duplicated_elements();

	// cout << "La cola despues de eliminar los duplicados es: " << endl;
	// cola_lista.write();
	// cout << endl;

	/// IMPLEMENTACIÓN DE LAS OPERACIONES Y DE LOS ELEMENTOS DE LA COLA TIPO VECTOR

	cout << "La cola original es: " << endl;
	cola_vector.write();
	cout << endl;

	/// Exercice-1
	// cout << "Tras la operación de inversión se tiene: " << endl;
	// cola_vector.inverse();
	// cola_vector.write();
	// cout << endl;

	/// Exercice-2
	// cout << "Las cola de elementos de las posiones pares: " << endl;
	// queue_v_t<char> queue_to_insert;
	// cola_vector.divide_into_two_queues();

	/// Exercice-3
	// cout << "La segunda cola original es: " << endl;
	// cola_2_vector.write();
	// cout << endl;

	// queue_v_t<char> final_queue;
	// final_queue.merge_queues(cola_vector, cola_2_vector);
	// cout << "Tras la fusión de las dos colas introducidas, se tiene la siguiente cola resultante: ";
	// final_queue.write();
	// cout << endl;

	/// Exercice-4
	cola_vector.push('a');
	cola_vector.push('b');
	cout << "La cola original es: " << endl;
	cola_vector.write();
	cout << endl;
	cola_vector.delete_duplicated();
	cout << "Tras la eliminación de los elementos duplicados se tiene la siguiente cola resultante: " << endl;
	cola_vector.write();
	cout << endl;

	return 0;
}
