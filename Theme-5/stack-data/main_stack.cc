// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_stack.cc -o main_stack
// EJECUCIÓN: ./main_stack

#include <iostream>

#include "stack_v_t.h"
#include "stack_l_t.h"

using namespace std;

// DESCOMENTAR EN FUNCION DEL PROBLEMA A RESOLVER

/****************************************************
 * SOLUCIONES CON ESTRUCTURA DE DATOS ESTÁTICA
*****************************************************/

//*****************************************************
// PROBLEMA1
int main(void) {  
  
  stack_v_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 8; i++) {
    pila_vector.push('a' + i);    
  }
  pila_vector.write();
  cout << endl;

  pila_vector.intercambio();
  pila_vector.write();
  cout << endl;

  return 0;
}
//*/

/******************************************************
// PROBLEMA2
int main(void) {  
  
  stack_v_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 8; i++) {
    pila_vector.push('a' + i);    
  }
  pila_vector.write();
  cout << endl;

  pila_vector.inverso().write();
  cout << endl;

  return 0;
}
*/

/******************************************************
// PROB3. ELIMINAR ELEMENTOS DE POSICIONES IMPARES
// EL ELEMENTO DEL FONDO DE LA PILA ES IMPAR
  int main(void) {  
  
  stack_v_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 8; i++) {
    pila_vector.push('a' + i);    
  }
  pila_vector.write();
  cout << endl;

  pila_vector.eliminaImpares();
  pila_vector.write();
  cout << endl;

  return 0;
}
*/
  
/******************************************************
// PROB4. A PARTIR DE UN VALOR, DIVIDIR PILA
// EN 2, UNA CON LOS MAYORES O IGUALES Y
// OTR CON LOS MENORES
// PROBLEMA2
int main(void) { 
  stack_v_t<int> pila_vector_int;
  pila_vector_int.push(2);
  pila_vector_int.push(1);
  pila_vector_int.push(6);
  pila_vector_int.push(3);
  pila_vector_int.push(5);
  pila_vector_int.push(4);
  cout << "**** PILA ORIGINAL ****" << endl;
  pila_vector_int.write();
  cout << endl;
  stack_v_t<int> mayores,menores;
  int valor = 4;
  pila_vector_int.divide(mayores,menores,valor);
  cout << "**** MAYORES ****" << endl;
  mayores.write();
  cout << endl;
  cout << "**** MENORES ****" << endl;
  menores.write();
  cout << endl;
  
  return 0;
}
*/

/******************************************************
// PROB5. OBTENER EL VALOR MAXIMO DE LA PILA
// REEMPLAZANDO SUCESIVAMENTE DOS ELEMENTOS DEL TOP
// POR EL MAXIMO DE AMBOS
int main (void)
{
  stack_v_t<int> pila_vector_int;
  pila_vector_int.push(2);
  pila_vector_int.push(1);
  pila_vector_int.push(6);
  pila_vector_int.push(3);
  pila_vector_int.push(5);
  pila_vector_int.push(4);
  cout << "**** PILA ORIGINAL ****" << endl;
  pila_vector_int.write();
  cout << endl;
  cout << "El valor maximo es... " << pila_vector_int.maximo() << endl;

  return 0;
}
*/

/****************************************************
 * SOLUCIONES CON ESTRUCTURA DE DATOS DINÁMICA
*****************************************************/

/*****************************************************
// PROBLEMA1
int main(void) {  
  
  stack_l_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 8; i++) {
    pila_vector.push('a' + i);    
  }
  pila_vector.write();
  cout << endl;

  pila_vector.intercambio();
  pila_vector.write();
  cout << endl;

  return 0;
}
*/

/******************************************************
// PROBLEMA2
int main(void) {  
  
  stack_l_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 8; i++) {
    pila_vector.push('a' + i);    
  }
  pila_vector.write();
  cout << endl;

  pila_vector.inverso().write();
  cout << endl;

  return 0;
}
*/

/******************************************************
// PROB3. ELIMINAR ELEMENTOS DE POSICIONES IMPARES
// EL ELEMENTO DEL FONDO DE LA PILA ES IMPAR
  int main(void) {  
  
  stack_l_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 8; i++) {
    pila_vector.push('a' + i);    
  }
  pila_vector.write();
  cout << endl;

  pila_vector.eliminaImpares();
  pila_vector.write();
  cout << endl;

  return 0;
}
*/
  
/******************************************************
// PROB4. A PARTIR DE UN VALOR, DIVIDIR PILA
// EN 2, UNA CON LOS MAYORES O IGUALES Y
// OTR CON LOS MENORES
// PROBLEMA2
int main(void) { 
  stack_v_t<int> pila_vector_int;
  pila_vector_int.push(2);
  pila_vector_int.push(1);
  pila_vector_int.push(6);
  pila_vector_int.push(3);
  pila_vector_int.push(5);
  pila_vector_int.push(4);
  cout << "**** PILA ORIGINAL ****" << endl;
  pila_vector_int.write();
  cout << endl;
  stack_v_t<int> mayores,menores;
  int valor = 4;
  pila_vector_int.divide(mayores,menores,valor);
  cout << "**** MAYORES ****" << endl;
  mayores.write();
  cout << endl;
  cout << "**** MENORES ****" << endl;
  menores.write();
  cout << endl;
  
  return 0;
}
*/

/******************************************************
// PROB5. OBTENER EL VALOR MAXIMO DE LA PILA
// REEMPLAZANDO SUCESIVAMENTE DOS ELEMENTOS DEL TOP
// POR EL MAXIMO DE AMBOS
int main (void)
{
  stack_v_t<int> pila_vector_int;
  pila_vector_int.push(2);
  pila_vector_int.push(1);
  pila_vector_int.push(6);
  pila_vector_int.push(3);
  pila_vector_int.push(5);
  pila_vector_int.push(4);
  cout << "**** PILA ORIGINAL ****" << endl;
  pila_vector_int.write();
  cout << endl;
  cout << "El valor maximo es... " << pila_vector_int.maximo() << endl;

  return 0;
}
*/
