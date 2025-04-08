// main.cpp
// =============================================================
// Este es el programa principal del calculo de ventas de cada Industria.
// Aquí se llaman todas las funciones necesarias.
// =============================================================

#include "encuesta.h"

int main() {
    srand(time(0)); // Inicializa la semilla para aleatoriedad

    // ==== DECLARACIÓN DE VARIABLES PRINCIPALES ====

    // Vector de nombres de Industrias
    string industrias[NUM_INDUSTRIAS];

    // Vector con nombres de los años correspondientes
    string anos [NUM_ANOS] = {
        "2015", "2016", "2017", "2018"
    };

    // Matriz de datos de ventas [industrias][años]
    int ventas [NUM_INDUSTRIAS][NUM_ANOS] = {0};

    char repetir;

    do {
        ingresarindustrias(industrias);             // Paso 1: ingresar nombres
        generarVentas(ventas);                  // Paso 2: generar datos aleatorios
        mostrarResultados(industrias, anos, ventas); // Paso 3: mostrar resultados
        calcularPromedios(anos, ventas);     // Paso 4: calcular promedios

        // ¿Repetir?
        cout << "\nDesea realizar otro Proceso? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}
