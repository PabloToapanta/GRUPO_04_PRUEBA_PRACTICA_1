# Informe de Proyecto: Tower Defense en C++

##  Enlace al Repositorio
**GitHub:** https://github.com/PabloToapanta/GRUPO_04_PRUEBA_PRACTICA_1.git

##  Integrantes del Equipo
* **Desarrollador 1:** [Nombre y Apellido] - Módulo de Torres (Lista Secuencial)
* **Desarrollador 2:** [Nombre y Apellido] - Módulo de Enemigos (Lista Doble)
* **Desarrollador 3:** Estiven Chiluisa - Módulo de Oleadas (Lista Circular)
* **Desarrollador 4 :** Pablo Toapanta - Motor del Juego e Integración

---

## Módulo 1: Sistema de Torres (Lista Secuencial)
*(Responsable: [Nombre del Desarrollador 1])*

### 1. Justificación de la Estructura de Datos
[El desarrollador 1 debe explicar aquí por qué se usó un arreglo manual, destacando que las torres son estáticas y es rápido acceder a ellas por índice].

### 2. Estructura del Nodo (Torre)
[El desarrollador 1 debe listar los atributos principales del struct Torre: id, nombre, daño, rango, etc.].

### 3. Lógica de Funciones Implementadas
* **insertarTorre:** [Explicación de cómo controla el límite y evita IDs duplicados].
* **eliminarTorre:** [Explicación de cómo desplaza los elementos a la izquierda para tapar el hueco].
* **buscar / mostrar:** [Breve explicación de los recorridos].

---

## Módulo 2: Sistema de Enemigos (Lista Doblemente Enlazada)
*(Responsable: [Nombre del Desarrollador 2])*

### 1. Justificación de la Estructura de Datos
[El desarrollador 2 debe explicar las ventajas del doble puntero (siguiente y anterior) para gestionar datos dinámicos que cambian de posición y mueren constantemente].

### 2. Estructura del Nodo (Enemigo)
[El desarrollador 2 debe listar los atributos: id, vida, velocidad, posicion, etc., y los punteros del nodo].

### 3. Lógica de Funciones Implementadas
* **insertarFinal:** [Explicación de cómo conecta el nuevo nodo ajustando el puntero 'ultimo'].
* **eliminarDestruido:** [Explicación de cómo reconecta los punteros vecinos para no romper la lista al borrar un enemigo en el medio].
* **actualizarPosiciones:** [Explicación de la fórmula posición += velocidad].

---

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

---

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
