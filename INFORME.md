# Informe de Proyecto: Tower Defense en C++

##  Enlace al Repositorio
**GitHub:** [Pega aquí el enlace de tu repositorio]

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
*(Responsable: [Tu Nombre])*

### 1. Justificación de la Integración
[Aquí explicarás cómo la clase `Juego` orquesta las tres estructuras de datos sin romper el encapsulamiento, y cómo se maneja el "tablero imaginario" matemático].

### 2. Lógica del Turno (Matemática de Colisiones)
[Aquí explicarás detalladamente cómo usas la distancia absoluta (`abs()`) para calcular si el enemigo entró en el rango de visión de la torre].

### 3. Control del Flujo de Partida
[Breve explicación del menú de consola y las condiciones de derrota (pérdida de vidas)].

---

## Instrucciones de Compilación y Ejecución
Para compilar este proyecto desde la terminal usando G++, ubicarse en la carpeta raíz del proyecto y ejecutar:
`g++ src/*.cpp -o TowerDefense`

Para iniciar el juego:
`./TowerDefense` (En Linux/Mac)
`TowerDefense.exe` (En Windows)
