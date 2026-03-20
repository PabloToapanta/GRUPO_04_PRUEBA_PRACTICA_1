#include "../include/Juego.h"
#include <iostream>

// TODO (Líder / Desarrollador 4): Integrar listas y reglas del juego [cite: 109-116, 123]

Juego::Juego() {
    vidasJugador = 3;     // [cite: 119]
    turnoActual = 0;
    longitudCamino = 20;  // [cite: 55]
}

void Juego::iniciarMenu() {
    // Implementar opciones 1 al 10 con un switch [cite: 63-72]
}

void Juego::avanzarTurno() {
    // 1. Mover enemigos [cite: 111]
    // 2. Verificar rangos y aplicar daño [cite: 112, 113]
    // 3. Eliminar enemigos muertos [cite: 114]
    // 4. Descontar vidas si llegan al final [cite: 115]
    // 5. Mostrar resumen [cite: 116]
}

void Juego::mostrarEstadoGeneral() {}