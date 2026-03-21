#include <iostream>
#include "include/ListaSecuencial.h"

int main() {
    std::cout << "--- INICIANDO PRUEBAS DEL DESARROLLADOR 1 ---\n\n";

    ListaSecuencial misTorres;

    // 1. Creamos unas torres de prueba
    Torre t1 = {1, "Arquero", "Basica", 3, 20, 2, 100};
    Torre t2 = {2, "Canion", "Pesada", 8, 35, 3, 200};
    Torre t3 = {3, "Mago", "Magica", 15, 50, 4, 300};

    // 2. Probamos la inserción
    std::cout << "Insertando torres...\n";
    misTorres.insertarTorre(t1);
    misTorres.insertarTorre(t2);
    misTorres.insertarTorre(t3);

    // 3. Probamos la validación de seguridad (intentar meter un ID que ya existe)
    std::cout << "\nIntentando meter una torre con ID repetido (deberia dar error)...\n";
    misTorres.insertarTorre(t2);

    // 4. Mostramos cómo quedó el arreglo
    misTorres.mostrarTorres();

    // 5. Probamos eliminar una torre del medio (El Cañón, ID 2)
    std::cout << "\nEliminando la torre con ID 2...\n";
    misTorres.eliminarTorre(2);

    // 6. Volvemos a mostrar para confirmar que el Mago tapó el hueco del Cañón
    misTorres.mostrarTorres();

    std::cout << "\n--- FIN DE LAS PRUEBAS. SI VES ESTO SIN ERRORES, TU MODULO FUNCIONA ---\n";
    return 0;
}