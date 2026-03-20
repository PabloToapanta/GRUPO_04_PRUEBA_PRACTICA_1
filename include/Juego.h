#ifndef JUEGO_H
#define JUEGO_H

#include "ListaSecuencial.h"
#include "ListaDobleEnlazada.h"
#include "ListaCircular.h"

class Juego {
private:
    ListaSecuencial defensas;
    ListaDobleEnlazada enemigosActivos;
    ListaCircular oleadas;
    int vidasJugador;
    int turnoActual;
    int longitudCamino; 

public:
    Juego();
    void iniciarMenu();             // [cite: 63]
    void avanzarTurno();            // [cite: 110]
    void mostrarEstadoGeneral();    // [cite: 72]
};

#endif