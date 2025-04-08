// encuesta.cpp
// =============================================================
// Implementación de las funciones del programa de encuesta.
// Aquí está la lógica real de cada función declarada en .h
// =============================================================

#include "encuesta.h"

// Esta función sirve para que el usuario escriba los nombres de los departamentos que participarán en la encuesta.
// Usamos un arreglo de strings para guardar esos nombres.
void ingresarDepartamentos(string departamentos[]) {
    cout << "Ingrese los nombres de los " << NUM_DEPARTAMENTOS << " departamentos:\n";
    for (int i = 0; i < NUM_DEPARTAMENTOS; i++) {
        // Este for recorre desde 0 hasta NUM_DEPARTAMENTOS - 1 (porque los arreglos empiezan en 0)
        // Así llenamos todas las posiciones del arreglo "departamentos"
        cout << "Departamento " << i + 1 << ": ";
        cin >> departamentos[i]; // Guardamos el nombre que el usuario escribe en la posición i
    }
}

// Esta función genera aleatoriamente las calificaciones de los servicios en cada departamento.
// Cada servicio es evaluado por varias personas y se calcula un promedio para ese servicio en ese departamento.
void generarEncuesta(int calificaciones[][NUM_SERVICIOS]) {
    // Este for externo recorre todos los departamentos
    for (int d = 0; d < NUM_DEPARTAMENTOS; d++) {
        // Este for interno recorre todos los servicios por cada departamento
        for (int s = 0; s < NUM_SERVICIOS; s++) {
            // ¿Por qué dos for? Porque estamos trabajando con una MATRIZ bidimensional: departamentos × servicios
            int suma = 0; // Esta variable suma todas las calificaciones dadas al servicio

            // Este tercer for simula que varias personas califican ese servicio
            for (int persona = 0; persona < NUM_PERSONAS; persona++) {
                suma += (rand() % 10 + 1); // Genera un número aleatorio entre 1 y 10 (como si una persona calificara)
            }

            // Guardamos el promedio de las calificaciones en la celda correspondiente
            // calificaciones[d][s] significa: fila d (departamento), columna s (servicio)
            calificaciones[d][s] = suma / NUM_PERSONAS;
        }
    }
}

// Esta función muestra en pantalla los resultados de la encuesta.
// Muestra cada departamento, la calificación que le dieron a cada servicio y los organiza en forma de tabla.
void mostrarResultados(string departamentos[], string servicios[], int calificaciones[][NUM_SERVICIOS]) {
    cout << "\n--- Resultados de la Encuesta por Departamento ---\n\n";
    cout << "Departamento\t";
    for (int s = 0; s < NUM_SERVICIOS; s++) {
        cout << servicios[s] << "\t"; // Muestra el nombre de cada servicio como encabezado de columna
    }
    cout << "\n--------------------------------------------------------------\n";

    for (int d = 0; d < NUM_DEPARTAMENTOS; d++) {
        // Imprimimos el nombre del departamento en la fila
        cout << departamentos[d] << "\t\t";
        for (int s = 0; s < NUM_SERVICIOS; s++) {
            // Imprimimos la calificación de cada servicio para ese departamento
            cout << calificaciones[d][s] << "\t";
        }
        cout << "\n"; // Salto de línea al final de cada fila
    }
}

// Esta función calcula los promedios nacionales de cada servicio y determina cuál fue el mejor y el peor evaluado.
// También explica paso a paso qué está ocurriendo para facilitar la comprensión.
void calcularPromedios(string servicios[], int calificaciones[][NUM_SERVICIOS]) {
    float promedios[NUM_SERVICIOS] = {0}; // Arreglo para guardar los promedios de cada servicio a nivel nacional

    // En esta parte usamos dos ciclos anidados:
    // El primero (con variable s) recorre los servicios.
    // El segundo (con variable d) recorre los departamentos.
    // Así sumamos todas las calificaciones que recibió cada servicio en cada departamento.
    for (int s = 0; s < NUM_SERVICIOS; s++) {
        for (int d = 0; d < NUM_DEPARTAMENTOS; d++) {
            // Sumamos la calificación del servicio s en el departamento d
            promedios[s] += calificaciones[d][s];
        }
        // Una vez sumados todos los departamentos, dividimos entre el número total para obtener el promedio
        promedios[s] /= NUM_DEPARTAMENTOS;
    }

    // Ahora imprimimos todos los promedios obtenidos
    cout << "\n--- Promedios Nacionales por Servicio ---\n";

    float maxProm = 0, minProm = 10; // Estas variables almacenan el mejor y peor promedio
    string mejorServicio, peorServicio; // Aquí se guardarán los nombres de los servicios correspondientes

    for (int s = 0; s < NUM_SERVICIOS; s++) {
        cout << servicios[s] << ": " << promedios[s] << "/10\n"; // Mostramos el promedio de cada servicio

        // Aquí comparamos para encontrar el mejor servicio evaluado
        if (promedios[s] > maxProm) {
            maxProm = promedios[s];
            mejorServicio = servicios[s];
        }
        // Y aquí encontramos el peor
        if (promedios[s] < minProm) {
            minProm = promedios[s];
            peorServicio = servicios[s];
        }
    }

    // Finalmente mostramos los resultados de mejor y peor servicio
    cout << "\nServicio mejor evaluado: " << mejorServicio << " (" << maxProm << "/10)\n";
    cout << "Servicio peor evaluado: " << peorServicio << " (" << minProm << "/10)\n";
}
