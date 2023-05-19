# Anotaciones a tener en cuenta de los distintos tipos de clases usadas en el proyecto

## Clase: `sll_node_t`

### Atributos
- `data`: Puntero al dato que contiene el nodo
- `next`: Puntero al siguiente nodo de la lista

### Métodos
- `sll_node_t()`: Constructor por defecto
- `sll_node_t(T data)`: Constructor con parámetro
- `~sll_node_t()`: Destructor
- `T get_data()`: Devuelve el dato que contiene el nodo
- `void set_data(T data)`: Establece el dato que contiene el nodo
- `sll_node_t<T>* get_next()`: Devuelve el siguiente nodo de la lista
- `void set_next(sll_node_t<T>* next)`: Establece el siguiente nodo de la lista

## Clase: `sll_t`

### Atributos
- `head_`: Puntero al primer nodo de la lista

### Métodos
- `sll_t()`: Constructor por defecto
- `~sll_t()`: Destructor
- `bool empty()`: Devuelve `true` si la lista está vacía, `false` en caso contrario
- `get_head()`: Devuelve el primer nodo de la lista
- `push_front(T data)`: Inserta un nodo al principio de la lista
- `pop_front()`: Elimina el primer nodo de la lista
- `insert_after(sll_node_t<T>* prev_node, T data)`: Inserta un nodo después de un nodo dado
- `erase_after(sll_node_t<T>* prev_node)`: Elimina el nodo que está después de un nodo dado
- `void write(ostream& os)`: Escribe la lista en un flujo de salida
- `search(T data)`: Devuelve un puntero al nodo que contiene el dato dado, `nullptr` en caso de no encontrarlo.

## Clase: `dll_node_t`

### Atributos
- `data`: Puntero al dato que contiene el nodo
- `next`: Puntero al siguiente nodo de la lista
- `prev`: Puntero al nodo anterior de la lista

### Métodos
- `dll_node_t()`: Constructor por defecto
- `dll_node_t(T data)`: Constructor con parámetro
- `~dll_node_t()`: Destructor
- `T get_data()`: Devuelve el dato que contiene el nodo
- `void set_data(T data)`: Establece el dato que contiene el nodo
- `dll_node_t<T>* get_next()`: Devuelve el siguiente nodo de la lista
- `void set_next(dll_node_t<T>* next)`: Establece el siguiente nodo de la lista
- `dll_node_t<T>* get_prev()`: Devuelve el nodo anterior de la lista
- `void set_prev(dll_node_t<T>* prev)`: Establece el nodo anterior de la lista

## Clase: `dll_t`

### Atributos
- `head_`: Puntero al primer nodo de la lista
- `tail_`: Puntero al último nodo de la lista
- `sz_`: Tamaño de la lista

### Métodos
- `dll_t()`: Constructor por defecto
- `~dll_t()`: Destructor
- `bool empty()`: Devuelve `true` si la lista está vacía, `false` en caso contrario
- `get_head()`: Devuelve el primer nodo de la lista
- `get_tail()`: Devuelve el último nodo de la lista
- `push_front(T data)`: Inserta un nodo al principio de la lista
- `pop_front()`: Elimina el primer nodo de la lista
- `push_back(T data)`: Inserta un nodo al final de la lista
- `pop_back()`: Elimina el último nodo de la lista
- `erase(dll_node_t<T>* node)`: Elimina un nodo dado

## Clase: `stack_l_t`

### Atributos
- `l_`: Lista enlazada

### Métodos
- `stack_l_t()`: Constructor por defecto
- `~stack_l_t()`: Destructor
- `bool empty()`: Devuelve `true` si la pila está vacía, `false` en caso contrario
- `T top()`: Devuelve el elemento de la cima de la pila
- `void pop()`: Elimina el elemento de la cima de la pila
- `void push(T data)`: Inserta un elemento en la cima de la pila
- `void write(ostream& os)`: Escribe la pila en un flujo de salida


## Clase: `stack_v_t`

### Atributos
- `v_`_: vector que hará de ayuda para la creación de la pila.
-  `top_`: valor del top de la pila.

### Métodos
- `stack_v_t()`: Constructor por defecto
- `~stack_v_t()`: Destructor
- `bool empty()`: Devuelve `true` si la pila está vacía, `false` en caso contrario
- `T top()`: Devuelve el elemento de la cima de la pila
- `void pop()`: Elimina el elemento de la cima de la pila
- `void push(T data)`: Inserta un elemento en la cima de la pila
- `void write(ostream& os)`: Escribe la pila en un flujo de salida


## Clase: `queue_l_t`

### Atributos
- `l_`: Lista enlazada

### Métodos
- `queue_l_t()`: Constructor por defecto
- `~queue_l_t()`: Destructor
- `bool empty()`: Devuelve `true` si la cola está vacía, `false` en caso contrario
- `T front()`: Devuelve el elemento del frente de la cola
- `T back()`: Devuelve el elemento del final de la cola
- `void pop()`: Elimina el elemento del frente de la cola
- `void push(T data)`: Inserta un elemento en el final de la cola
- `int size()`: Devuelve el tamaño de la cola
- `void write(ostream& os)`: Escribe la cola en un flujo de salida

## Clase: `queue_v_t`

### Atributos
- `v_`_: vector que hará de ayuda para la creación de la cola.
- `front_`: valor del frente de la cola.
- `back_`: valor del final de la cola.

### Métodos
- `queue_v_t()`: Constructor por defecto
- `~queue_v_t()`: Destructor
- `bool empty()`: Devuelve `true` si la cola está vacía, `false` en caso contrario
- `T front()`: Devuelve el elemento del frente de la cola
- `T back()`: Devuelve el elemento del final de la cola
- `void pop()`: Elimina el elemento del frente de la cola
- `void push(T data)`: Inserta un elemento en el final de la cola
- `int size()`: Devuelve el tamaño de la cola
- `void write(ostream& os)`: Escribe la cola en un flujo de salida
- `bool full()`: Devuelve `true` si la cola está llena, `false` en caso contrario

