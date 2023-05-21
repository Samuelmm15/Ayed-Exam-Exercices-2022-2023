# Anotaciones de posibles operaciones con matrices

## Operaciones con matrices

### Suma de matrices

Para la suma de matrices, ambas matrices deben de tener el mismo número de filas y columnas. Una vez se tiene comprobado
este aspecto, se procede a sumar los elementos de ambas matrices, elemento a elemento, y se almacenan en una nueva matriz.

### Resta de matrices

Para la resta de matrices, ambas matrices deben de tener el mismo número de filas y columnas. Una vez se tiene comprobado
este aspecto, se procede a restar los elementos de ambas matrices, elemento a elemento, y se almacenan en una nueva matriz.

### Multiplicación de matrices

Para la multiplicación de matrices, el número de columnas de la primera matriz debe de ser igual al número de filas de la
segunda matriz. Una vez se tiene comprobado este aspecto, se procede a multiplicar, la fila de la primera matriz por la 
columna de la segunda matriz, y se almacenan en una nueva matriz, de esta manera la matriz resultante tendrá el mismo número
de filas que la primera matriz y el mismo número de columnas que la segunda matriz.

### Traspuesta de una matriz

Para la traspuesta de una matriz, se intercambian las filas por las columnas, de esta manera, la matriz resultante tendrá
el mismo número de filas que la matriz original y el mismo número de columnas que la matriz original.

### Producto escalar

El producto escalar es un número que se multiplica por cada elemento de la matriz, de esta manera, la matriz resultante
tendrá el mismo número de filas y columnas que la matriz original. Por otra parte el producto escalar que no es de una matriz
hace referencia a un número que resulta de la multiplicación de manera kA, donde k es el producto escalar y A es la matriz.

### Aspectos a tener en cuenta en la programación

- Dentro de la librería `cmath`, se encuentran métodos relevantes como: sqrt, pow, abs, floor, rounded, etc, dónde, sqrt
  calcula la raíz cuadrada de un número, pow calcula la potencia de un número, abs calcula el valor absoluto de un número,
  floor redondea un número hacia abajo, rounded redondea un número hacia arriba, etc.

- Dentro de la librería `utility`, se encuentran métodos relevantes como el pair, dónde, pair es una plantilla de clase
  que permite almacenar dos objetos de tipos diferentes, por ejemplo, un par de enteros, un par de cadenas, etc.

- Dentro de la librería `vector`, se pueden crear vectores de manera genérica sin necesidad de hacer uso de las clases creadas
  dentro de las prácticas de la asignatura.

- Tener cuidado con los punteros, ya que cuando se hacen uso de punteros a una clase, cuando se hace uso de los distintos métodos
  de dicha clase que es un puntero, se debe de hacer uso de la notación de flecha, por ejemplo, si se tiene un puntero a una clase
  llamada `sll_t`, y se quiere hacer uso del método `empty()`, se debe de hacer de la siguiente manera: `p->empty()`, dónde p es
  un puntero a la clase `sll_t`.

- Tener cuidado con la recursividad, ya que se tiene que hacer uso de un caso general el cual nos permita hacer uso de dicha recursividad,
  incrementando alguno de los valores, realizando ciertas operaciones necesarias, decreementando alguno de los valores, etc. Por tanto, 
  en la recursividad tener cuidado con los casos base y los casos generales.

  Teniendo en cuenta esto anteriormente explicado sobre la recursividad, se puede decir que para poder entender mejor la recursividad,
  hay que destacar que el caso base de esta, es el caso en el que se detiene la recursividad, es decir, es el caso en el que se deja de
  llamar a la función recursiva, y el caso general es el caso en el que se llama a la función recursiva, es decir, es el caso en el que
  se sigue llamando a la función recursiva, de manera normal en este caso general o casos generales si hay distintos, se suele hacer la
  división del problema, la suma del problema o aquella operación que sea necesaria para la resolución del problema inicial.