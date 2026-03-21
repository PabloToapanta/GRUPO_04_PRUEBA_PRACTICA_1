# Informe de Proyecto: Tower Defense en C++

##  Enlace al Repositorio
**GitHub:** https://github.com/PabloToapanta/GRUPO_04_PRUEBA_PRACTICA_1.git

##  Integrantes del Equipo
* **Desarrollador 1:** David Rodriguez - Módulo de Torres (Lista Secuencial)
* **Desarrollador 2:** Jeampierre Ortiz - Módulo de Enemigos (Lista Doble)
* **Desarrollador 3:** Estiven Chiluisa - Módulo de Oleadas (Lista Circular)
* **Desarrollador 4 :** Pablo Toapanta - Motor del Juego e Integración

---

## Módulo 1: Sistema de Torres (Lista Secuencial)
*(Responsable: [David Rodriguez)*

### 1. Justificación de la Estructura de Datos
Para la gestión de todas las defensas se implementó una (Lista Secuencial) basándose en un arreglo estático manejándose manualmente por una variable contadora. La estructura fue elegida ya que el jugador al colocar las torres defensivas en cierta posición estas no deben moverse ya que son una estructura física no movible esto hace que al no requerir movimiento constante muestra un resultado muy eficiente en consumo de la memoria y cumpliendo la restricción de no utilizar contenedores predefinidos de C++.

### 2. Estructura del Nodo (Torre)
(struct Torre) Es el nodo base de la lista donde se almacenan los atributos para el cálculo de ataques y estadística en el tablero, sus campos son:
**id:** identificador de la torre
**nombre y tipo:** estas son cadenas de texto donde se definen la clase de la torre ataque o cañón
**posición:** indica la coordenada donde se plantó la torre en el mapa lineal
**daño (danio):** son los puntos de vida que se resta al enemigo
**rango:** Distancia hacia adelante y atrás de la torre o el rango que es capaz de vigilar
**costo:** Valor de construcción de defensas

### 3. Lógica de Funciones Implementadas
* **insertarTorre:** Antes de añadir una nueva torre lo que hace el sistema es una verificación de dos pasos donde primero se verifica que la variable contadora no superó el límite físico del arreglo (100 espacios) eso evita el desbordamiento de memoria y segundo invoca el método de búsqueda para asegurarse que el id ingresado no exista, si las condiciones se cumplen la torre se guardará y se incrementa en uno (O(1).)
* **eliminarTorre:** Dado que planteamos una estructura de la torre estática no se puede desconectar, se requiere reorganizar la memoria. El método no necesariamente busca la torre a destruir en cambio se ejecuta un bucle que desplaza cada elemento que está a la derecha de ese índice una posición hacia la izquierda (arregloTorres[i] = arregloTorres[i + 1]). Finalmente, reduce la variable contadora, garantizando que el arreglo no quede con huecos vacíos ni memoria fragmentada.
* **buscar / mostrar:** Tiene una forma más compleja pero funciona mediante un recorrido secuencial (for) que inicia en el índice 0 y termina con (cantidadActual - 1), el método (buscar) compara los parámetros solicitados con el id de cada iteración y retorna su dirección de memoria si hay una coincidencia (nullptr) y el método mostrar extrae e imprime los datos de cada objeto

---

## Módulo 2: Sistema de Enemigos (Lista Doblemente Enlazada)
*(Responsable: [Jeampierre Ortiz])*

### 1. Justificación de la Estructura de Datos
Se seleccionó una Lista Doblemente Enlazada debido a la naturaleza altamente dinámica de los enemigos en un Tower Defense. A diferencia de un arreglo estático, esta estructura permite:
*	**Inserción y eliminación eficiente**: Los enemigos aparecen en el inicio y pueden ser destruidos en cualquier punto del trayecto; la lista doble permite eliminarlos simplemente reconectando los punteros de los nodos vecinos, sin necesidad de desplazar el resto de los elementos.
*	**Recorrido Bidireccional**: El uso de punteros siguiente y anterior facilita tanto el avance de los enemigos hacia la base como posibles mecánicas de retroceso o inspección de la cola hacia el frente.
*	**Gestión de Memoria**: Permite un control estricto de la memoria RAM mediante la creación y destrucción de nodos en tiempo de ejecución, evitando el desperdicio de espacio.

### 2. Estructura del Nodo (Enemigo)
Cada nodo de la lista almacena un objeto de tipo Enemigo y dos punteros de control. Atributos del objeto Enemigo:
*	id: Identificador único numérico.
*	tipo: Nombre de la unidad (ej. Orco, Troll).
*	vida: Puntos de resistencia actuales.
*	velocidad: Cantidad de casillas que avanza por turno.
*	posicion: Ubicación actual en el camino (de 0 a 20).
Punteros del NodoEnemigo:
*	siguiente: Dirección del enemigo que va más adelante en el camino.
*	anterior: Dirección del enemigo que viene detrás.

### 3. Lógica de Funciones Implementadas
Para asegurar la robustez del módulo, se implementaron las siguientes funciones:
*	insertarFinal: Esta función es la encargada de insertar enemigos a la lista; cada vez que una Oleada genera un atacante, este se conecta al final de la lista en la posición cero. Se añadió una validación de ID único para evitar conflictos de datos antes de reservar memoria para el nuevo nodo.
*	eliminarDestruido: Busca un enemigo por su ID y procede a reajustar los punteros de los nodos vecinos (anterior y siguiente) para "coser" la lista antes de liberar la memoria física con delete. Esto asegura que la cadena de atacantes nunca se rompa al eliminar un nodo intermedio.
*	actualizarPosiciones: Recorre toda la lista mediante un puntero auxiliar aux para modificar el atributo posición de cada enemigo. Se aplica la fórmula matemática posicion += velocidad cada vez que el motor del juego procesa un nuevo turno.
*	recorrerAdelante (Visualización): Implementa un recorrido desde el puntero primero hasta el ultimo. Se mejoró la salida por consola utilizando tabuladores (\t) y encabezados para mostrar las estadísticas de los enemigos de forma tabular y legible.
*	Destructor (~ListaDobleEnlazada): Garantiza la limpieza total de la memoria al finalizar el programa, recorriendo la lista y eliminando cada nodo pendiente para evitar fugas de memoria (memory leaks).


## Módulo 3: Sistema de Oleadas (Lista Circular Simplemente Enlazada)
*(Responsable: Estiven Chiluiza)*

En esta sección se describe la implementación del módulo encargado de gestionar la progresión de las oleadas dentro del juego. Este componente permite organizar, recorrer y reutilizar los niveles de forma eficiente mediante una estructura de datos adecuada.

### 1. Justificación de la Estructura de Datos
Se optó por el uso de una lista circular simplemente enlazada debido a que este tipo de estructura permite recorrer las oleadas de forma continua. En este modelo, cada nodo apunta al siguiente y el último nodo vuelve a enlazarse con el primero, formando un ciclo y como su nombre lo dice de manera circular.

**Ventajas principales:**
* **Ciclo continuo:** Permite repetir las oleadas automáticamente sin necesidad de reconstruir la estructura.
* **Eficiencia en la gestión:** Se evita la recreación de datos cuando se reinicia el juego o se desea repetir niveles.
* **Control simplificado:** Se utiliza un puntero al último nodo (`ultimo`) para mantener la circularidad y un puntero auxiliar (`oleadaActual`) para controlar el avance dentro de la lista.

### 2. Estructura del Nodo (Oleada)
Cada nodo de la lista representa una oleada y contiene la información necesaria para el desarrollo del juego.

**Atributos principales:**
* **idOleada:** Identificador único de la oleada.
* **cantidadEnemigos:** Número de enemigos que se generarán.
* **vidaBase:** Nivel de vida de los enemigos en esa oleada.
* **velocidadBase:** Velocidad base de los enemigos.

Estos datos permiten ajustar la dificultad de forma progresiva en cada ciclo.

### 3. Lógica de Funciones Implementadas
* **registrarOleada:** Permite insertar una nueva oleada al final de la lista. Si la lista está vacía, el nodo se apunta a sí mismo, iniciando la circularidad. Si ya existen elementos, el nuevo nodo se enlaza correctamente para mantener la estructura circular. Se actualiza el puntero `ultimo` para reflejar el nuevo final de la lista.
* **avanzarSiguienteOleada:** Avanza el puntero `oleadaActual` hacia la siguiente oleada. Permite recorrer la lista de forma secuencial y retorna una referencia a la oleada actual para su uso en la generación de enemigos, manteniendo el ciclo continuo.
* **reiniciarCiclo:** Reinicia el recorrido de las oleadas. Ubica el puntero `oleadaActual` en el primer nodo de la lista, permitiendo comenzar nuevamente el ciclo de niveles sin modificar la estructura.
* **mostrarOleadas:** Recorre la lista circular y muestra la información. Inicia desde el primer nodo usando un ciclo controlado (`do-while`) para evitar recorridos infinitos, imprimiendo los datos relevantes.

## Módulo 4: Motor del Juego e Integración
*(Responsable: Líder del Equipo)*

En esta sección se describe la arquitectura central del sistema. El archivo `Juego.cpp` actúa como el controlador principal que orquesta la interacción entre las tres estructuras de datos independientes (Torres, Enemigos y Oleadas) y define las reglas del entorno de simulación.

### 1. Justificación de la Integración y el Tablero Virtual
Para mantener los principios de la Programación Orientada a Objetos, la integración se realizó respetando estrictamente el **encapsulamiento**. La clase `Juego` no accede directamente a los punteros ni a los arreglos privados de las listas; en su lugar, se comunica a través de métodos de acceso seguros (getters) como `obtenerPrimero()` y `obtenerTorrePorIndice()`. 

Adicionalmente, se optó por una optimización de memoria al **no crear una matriz o arreglo físico** para representar el tablero. El mapa de juego es una abstracción matemática definida por la variable `longitudCamino` (con límite de 20 posiciones). La ubicación de los elementos se gestiona puramente a través de sus coordenadas numéricas (`posicion`), lo que hace que el sistema sea mucho más rápido y consuma menos recursos.

### 2. Lógica del Turno (Matemática de Colisiones)
El núcleo del motor del juego reside en el método `avanzarTurno()`, el cual se ejecuta secuencialmente en cuatro fases:

1. **Aparición (Spawn):** Se extraen los datos de la lista circular de oleadas para instanciar nuevos enemigos en la posición inicial (0).
2. **Movimiento:** Se recorre la lista doblemente enlazada, sumando el atributo `velocidad` a la `posicion` actual de cada enemigo.
3. **Cálculo de Colisiones y Daño:** En lugar de buscar en casillas físicas, el motor cruza la lista secuencial de torres con la lista doble de enemigos. Se importó la librería estándar `<cmath>` para calcular la distancia absoluta entre ambos elementos mediante la fórmula: `distancia = abs(torre.posicion - enemigo.posicion)`. Si esta `distancia` es menor o igual al `rango` de visión de la torre, se confirma la colisión y se descuenta el daño a la vida del enemigo.
4. **Limpieza de Memoria:** Se recorre la lista de enemigos evaluando su estado. Si la vida llega a 0, el nodo es eliminado de la memoria. 

### 3. Control del Flujo de Partida
El sistema cuenta con una interfaz de consola (CLI) interactiva basada en un menú principal de 10 opciones. 

**Características clave de la interfaz:**
* **Validación de entradas:** Se implementó protección contra errores de tipeo utilizando `cin.fail()`, `cin.clear()` y `cin.ignore()`. Esto evita que el programa colapse o entre en un bucle infinito si el usuario ingresa accidentalmente un carácter no numérico.
* **Condición de Derrota:** El motor monitorea constantemente la posición de los enemigos en la fase de limpieza. Si un enemigo supera el límite establecido (`posicion >= longitudCamino`), se invoca su eliminación y se descuenta una de las 3 vidas iniciales del jugador. El bucle del menú principal (`while`) se rompe automáticamente si las vidas llegan a 0, finalizando la ejecución del programa.

---

## Instrucciones de Compilación y Ejecución
Para compilar este proyecto desde la terminal usando G++, ubicarse en la carpeta raíz del proyecto y ejecutar:
`g++ src/*.cpp -o TowerDefense`

Para iniciar el juego:
`./TowerDefense` (En Linux/Mac)
`TowerDefense.exe` (En Windows)
