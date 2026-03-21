#include "../include/Juego.h"
#include <iostream>
#include <limits>
#include <cmath> // Necesario para calcular la distancia absoluta (abs)

using namespace std;

// Constructor: Configuración inicial de la partida
Juego::Juego() {
    vidasJugador = 3;
    turnoActual = 0;
    longitudCamino = 20; 
}

// Interfaz principal (Opciones del 1 al 10)
void Juego::iniciarMenu() {
    int opcion = 0;
    
    // El juego corre mientras el jugador no elija salir (10) y tenga vidas
    while (opcion != 10 && vidasJugador > 0) {
        cout << "\n========================================";
        cout << "\n       TOWER DEFENSE - MENU PRINCIPAL   ";
        cout << "\n========================================\n";
        cout << "1. Registrar torre defensiva\n";
        cout << "2. Mostrar torres registradas\n";
        cout << "3. Eliminar torre\n";
        cout << "4. Registrar oleada\n";
        cout << "5. Mostrar oleadas\n";
        cout << "6. Iniciar siguiente oleada\n";
        cout << "7. Avanzar turno\n";
        cout << "8. Mostrar enemigos activos\n";
        cout << "9. Mostrar estado general del juego\n";
        cout << "10. Salir\n";
        cout << "========================================\n";
        cout << "Seleccione una opcion: ";
        
        cin >> opcion;

        // Limpieza de buffer por si el usuario ingresa una letra en vez de número
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Entrada no valida. Ingrese un numero.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                cout << "\n--- Registrar nueva torre ---\n";
                Torre t;
                cout << "Ingrese ID: "; cin >> t.id;
                cout << "Ingrese Nombre: "; cin >> t.nombre;
                cout << "Ingrese Tipo: "; cin >> t.tipo;
                cout << "Ingrese Posicion (0-" << longitudCamino << "): "; cin >> t.posicion;
                cout << "Ingrese Danio: "; cin >> t.danio;
                cout << "Ingrese Rango: "; cin >> t.rango;
                cout << "Ingrese Costo: "; cin >> t.costo;
                defensas.insertarTorre(t);
                break;
            }
            case 2:
                defensas.mostrarTorres();
                break;
            case 3: {
                int id;
                cout << "\nIngrese el ID de la torre a eliminar: "; cin >> id;
                defensas.eliminarTorre(id);
                break;
            }
            case 4: {
                cout << "\n--- Registrar nueva oleada ---\n";
                Oleada o;
                cout << "Ingrese ID Oleada: "; cin >> o.idOleada;
                cout << "Cantidad de Enemigos: "; cin >> o.cantidadEnemigos;
                cout << "Tipo de Enemigo: "; cin >> o.tipoEnemigo;
                cout << "Vida base: "; cin >> o.vidaBase;
                cout << "Velocidad base: "; cin >> o.velocidadBase;
                oleadas.registrarOleada(o);
                break;
            }
            case 5:
                oleadas.mostrarOleadas();
                break;
            case 6: {
                cout << "\n--- Iniciando siguiente oleada ---\n";
                Oleada* actual = oleadas.avanzarSiguienteOleada();
                if (actual != nullptr) {
                    cout << "Oleada " << actual->idOleada << " iniciada. (Enemigos: " << actual->tipoEnemigo << ")\n";
                }
                break;
            }
            case 7:
                avanzarTurno(); // Llamada al motor lógico
                break;
            case 8:
                enemigosActivos.recorrerAdelante();
                break;
            case 9:
                mostrarEstadoGeneral();
                break;
            case 10:
                cout << "\nSaliendo del juego... Gracias por jugar.\n";
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo.\n";
                break;
        }
    }
    
    // Mensaje de fin de partida
    if (vidasJugador <= 0) {
        cout << "\n*********************************************\n";
        cout << "  FIN DEL JUEGO: Los enemigos destruyeron tu base. \n";
        cout << "*********************************************\n";
    }
}

// Función de reporte general del sistema
void Juego::mostrarEstadoGeneral() {
    cout << "\n--- ESTADO GENERAL DEL JUEGO ---\n";
    cout << "Turno actual: " << turnoActual << "\n";
    cout << "Vidas restantes: " << vidasJugador << "\n";
    cout << "Longitud del mapa: " << longitudCamino << " posiciones\n";
    cout << "Torres construidas: " << defensas.contarTorresActivas() << "\n";
}

// Motor lógico del juego (Movimiento, Colisiones y Vidas)
void Juego::avanzarTurno() {
    turnoActual++;
    cout << "\n=== EJECUTANDO TURNO " << turnoActual << " ===\n";

    // 1. Spawneo de prueba (Esto saca un enemigo al inicio del mapa)
    Enemigo nuevo;
    nuevo.id = turnoActual; // Asignamos un ID único basado en el turno
    nuevo.tipo = "Invasor";
    nuevo.vida = 50;
    nuevo.velocidad = 2;
    nuevo.posicion = 0; // Siempre nacen en el inicio del mapa
    enemigosActivos.insertarFinal(nuevo);

    // 2. Mover a todos los enemigos actuales
    enemigosActivos.actualizarPosiciones();
    cout << "- Los enemigos han avanzado por el mapa.\n";

    // 3. FASE DE ATAQUE (Matemática de colisiones)
    for (int i = 0; i < defensas.contarTorresActivas(); i++) {
        Torre* torreActual = defensas.obtenerTorrePorIndice(i); 
        
        if(torreActual == nullptr) continue;

        // Escaneamos a todos los enemigos por cada torre
        NodoEnemigo* auxEnemigo = enemigosActivos.obtenerPrimero(); 
        
        while (auxEnemigo != nullptr) {
            // Formula de colisión: Si la distancia es menor o igual al rango de la torre
            int distancia = abs(torreActual->posicion - auxEnemigo->dato.posicion);
            
            if (distancia <= torreActual->rango && auxEnemigo->dato.vida > 0) {
                auxEnemigo->dato.vida -= torreActual->danio; // Aplicar daño
                
                cout << "-> La torre '" << torreActual->nombre << "' disparo al enemigo ID " 
                     << auxEnemigo->dato.id << " (Vida restante: " << auxEnemigo->dato.vida << ")\n";
            }
            auxEnemigo = auxEnemigo->siguiente;
        }
    }

    // 4. LIMPIEZA Y CONTROL DE VIDAS
    NodoEnemigo* auxLimpieza = enemigosActivos.obtenerPrimero();
    while (auxLimpieza != nullptr) {
        // Respaldar el siguiente nodo antes de una posible eliminación
        NodoEnemigo* siguienteNodo = auxLimpieza->siguiente; 
        
        if (auxLimpieza->dato.vida <= 0) {
            cout << "- Enemigo ID " << auxLimpieza->dato.id << " ha sido destruido.\n";
            enemigosActivos.eliminarDestruido(auxLimpieza->dato.id);
        } 
        else if (auxLimpieza->dato.posicion >= longitudCamino) {
            cout << "- ALERTA: El enemigo ID " << auxLimpieza->dato.id << " ha invadido la base.\n";
            vidasJugador--; // Restar vida al jugador
            enemigosActivos.eliminarDestruido(auxLimpieza->dato.id); // Eliminar enemigo que ya llegó
        }
        
        auxLimpieza = siguienteNodo;
    }
}