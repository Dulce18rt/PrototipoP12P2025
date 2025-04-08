// main.cpp
// =============================================================
// Este es el programa principal de la encuesta nacional.
// Aquí se llaman todas las funciones necesarias.
// =============================================================

#include "encuesta.h"

int main() {
    srand(time(0)); // Inicializa la semilla para aleatoriedad

    // ==== DECLARACIÓN DE VARIABLES PRINCIPALES ====

    // Vector de nombres de departamentos
    string departamentos[NUM_DEPARTAMENTOS];

    // Vector con nombres de servicios públicos fijos
    string servicios[NUM_SERVICIOS] = {
        "Salud", "Educacion", "Transporte", "Seguridad"
    };

    // Matriz de calificaciones [departamento][servicio]
    int calificaciones[NUM_DEPARTAMENTOS][NUM_SERVICIOS] = {0};

    char repetir;

    do {
        ingresarDepartamentos(departamentos);             // Paso 1: ingresar nombres
        generarEncuesta(calificaciones);                  // Paso 2: generar datos aleatorios
        mostrarResultados(departamentos, servicios, calificaciones); // Paso 3: mostrar resultados
        calcularPromedios(servicios, calificaciones);     // Paso 4: calcular promedios

        // ¿Repetir?
        cout << "\nDesea realizar otra encuesta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}
