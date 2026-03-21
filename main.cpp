#include <iostream>
#include "include/ListaSecuencial.h"
#include "include/ListaDobleEnlazada.h"
int main() {
    /*Juego miPartida;
    miPartida.iniciarMenu(); // Llama al menú principal [cite: 63]
    return 0;*/
    ListaDobleEnlazada misEnemigos;

    Enemigo e1 = {1, " Orco ", 100, 2, 0, 10}; //enemigo de prueba
    
    std::cout << "Insertando enemigo..." << std::endl; //hacemos uso de la funcion insertar enemigo
    misEnemigos.insertarFinal(e1);

    misEnemigos.recorrerAdelante();//probamos las funciones de mostrar y mover
    std::cout << "Avanzando posiciones..." << std::endl;
    misEnemigos.actualizarPosiciones();
    misEnemigos.recorrerAdelante();

    std::cout << "Eliminando enemigo..." << std::endl; //eliminamos enemigo
    misEnemigos.eliminarDestruido(1);
    misEnemigos.recorrerAdelante();

    return 0;
}