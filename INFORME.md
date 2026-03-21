# Módulo de Oleadas
En esta sección se describe la implementación del módulo encargado de gestionar la progresión de las oleadas dentro del juego. Este componente permite organizar, recorrer y reutilizar los niveles de forma eficiente mediante una estructura de datos adecuada.

## 1. Justificación de la Estructura de Datos

### Lista Circular Simplemente Enlazada

Se optó por el uso de una lista circular simplemente enlazada debido a que este tipo de estructura permite recorrer las oleadas de forma continua. En este modelo, cada nodo apunta al siguiente y el último nodo vuelve a enlazarse con el primero, formando un ciclo y como su nombre lo dice de manera circular.

**Ventajas principales:**

* **Ciclo continuo:** Permite repetir las oleadas automáticamente sin necesidad de reconstruir la estructura.
* **Eficiencia en la gestión:** Se evita la recreación de datos cuando se reinicia el juego o se desea repetir niveles.
* **Control simplificado:** Se utiliza un puntero al último nodo (ultimo) para mantener la circularidad y un puntero auxiliar (oleadaActual) para controlar el avance dentro de la lista.

## 2. Estructura del Nodo (Oleada)

Cada nodo de la lista representa una oleada y contiene la información necesaria para el desarrollo del juego.

**Atributos principales:**

* **idOleada:** Identificador único de la oleada.
* **cantidadEnemigos:** Número de enemigos que se generarán.
* **vidaBase:** Nivel de vida de los enemigos en esa oleada.
* **velocidadBase:** Velocidad base de los enemigos.
* **tipoEnemigo:** Clasificación de los enemigos

Estos datos permiten ajustar la dificultad de forma progresiva en cada ciclo.

## 3. Lógica de Funciones Implementadas

A continuación, se describen las funciones principales desarrolladas en este módulo:

   **registrarOleada**

Permite insertar una nueva oleada al final de la lista.

Si la lista está vacía entonces el nodo se apunta a sí mismo permitiendo el inicio de la circularidad.
Si ya existen elementos entonces el nuevo nodo se enlaza correctamente para mantener la estructura circular.
Se actualiza el puntero ultimo para reflejar el nuevo final de la lista.

   **avanzarSiguienteOleada**

Avanza el puntero oleadaActual hacia la siguiente oleada.

Permite recorrer la lista de forma secuencial.
Retorna una referencia a la oleada actual para su uso en el sistema (generación de enemigos).
Mantiene el ciclo continuo gracias a la estructura circular.
  
  **reiniciarCiclo**

Reinicia el recorrido de las oleadas.

Ubica el puntero oleadaActual en el primer nodo de la lista.
Permite comenzar nuevamente el ciclo de niveles sin modificar la estructura.

   **mostrarOleadas**

Recorre la lista circular y muestra la información de cada oleada.

Inicia desde el primer nodo.
Utiliza un ciclo controlado para evitar recorridos infinitos.
Imprime los datos relevantes de cada oleada en consola.
