// encuesta.cpp
// =============================================================
// Implementación de las funciones del programa de encuesta.
// Aquí está la lógica real de cada función declarada en .h
// =============================================================

#include "encuesta.h"

// Esta función sirve para que el usuario escriba los nombres de las INDUSTRIAS.
// Usamos un arreglo de strings para guardar esos nombres.
void ingresarindustrias(string Industrias[]) {
    cout << "Ingrese el nombre de la Industria " << NUM_INDUSTRIAS << " industrias:\n";
    for (int i = 0; i < NUM_INDUSTRIAS; i++) {
        // Este for recorre desde 0 hasta NUM_ISDUSTRIAS - 1 (porque los arreglos empiezan en 0)
        // Así llenamos todas las posiciones del arreglo "INDUSTRIAS"
        cout << "Industrias " << i + 1 << ": ";
        cin >> Industrias[i]; // Guardamos el nombre que el usuario escribe en la posición i
    }
}

// Esta función genera aleatoriamente las ventas de cada Industria.
// Cada venta es evaluado por varias personas y se calcula un promedio de ventas.
void generarVentas (int ventas [][NUM_ANOS]) {
    // Este for externo recorre Industrias.
    for (int d = 0; d < NUM_INDUSTRIAS; d++) {
        // Este for interno recorre todos los servicios por cada Insdustria
        for (int s = 0; s < NUM_ANOS; s++) {
            // ¿Por qué dos for? Porque estamos trabajando con una MATRIZ bidimensional: departamentos × servicios
            int suma = 0; // Esta variable suma todas las calificaciones dadas al servicio

            // Este tercer for simula que varias personas califican ese servicio
            for (int persona = 0; persona < NUM_PERSONAS; persona++) {
                suma += (rand() % 1000000 + 1); // Genera un número aleatorio entre 1 y 1000000 (como si una persona calificara)
            }

            // Guardamos el promedio de las calificaciones en la celda correspondiente
            // calificaciones[d][s] significa: fila d (Industrias), columna s (años)
            ventas[d][s] = suma / NUM_PERSONAS;
        }
    }
}

// Esta función muestra en pantalla los resultados de la encuesta.
// Muestra cada departamento, la calificación que le dieron a cada servicio y los organiza en forma de tabla.
void mostrarResultados(string industrias[], string anos[], int ventas[][NUM_ANOS]) {
    cout << "\n--- Resultados de las ventas de cada Industria ---\n\n";
    cout << "Industria\t";
    for (int s = 0; s < NUM_ANOS; s++) {
        cout << anos[s] << "\t"; // Muestra el nombre de cada servicio como encabezado de columna
    }
    cout << "\n--------------------------------------------------------------\n";

    for (int d = 0; d < NUM_INDUSTRIAS; d++) {
        // Imprimimos el nombre del departamento en la fila
        cout << industrias[d] << "\t\t";
        for (int s = 0; s < NUM_ANOS; s++) {
            // Imprimimos la calificación de cada servicio para ese departamento
            cout << ventas[d][s] << "\t";
        }
        cout << "\n"; // Salto de línea al final de cada fila
    }
}

// Esta función calcula los promedios nacionales de cada servicio y determina cuál fue el mejor y el peor evaluado.
// También explica paso a paso qué está ocurriendo para facilitar la comprensión.
void calcularPromedios(string anos[], int ventas[][NUM_ANOS]) {
    float promedios[NUM_ANOS] = {0}; // Arreglo para guardar los promedios de cada servicio a nivel nacional

    // En esta parte usamos dos ciclos anidados:
    // El primero (con variable s) recorre los servicios.
    // El segundo (con variable d) recorre los departamentos.
    // Así sumamos todas las calificaciones que recibió cada servicio en cada departamento.
    for (int s = 0; s < NUM_ANOS; s++) {
        for (int d = 0; d < NUM_INDUSTRIAS; d++) {
            // Sumamos la calificación del servicio s en el departamento d
            promedios[s] += ventas[d][s];
        }
        // Una vez sumados todos los departamentos, dividimos entre el número total para obtener el promedio
        promedios[s] /= NUM_INDUSTRIAS;
    }

    // Ahora imprimimos todos los promedios obtenidos
    cout << "\n--- Promedios Ventas ---\n";

    float maxProm = 0, minProm = 10; // Estas variables almacenan el mejor y peor promedio
    string mejorIndustria, peorIndustria; // Aquí se guardarán los nombres de los servicios correspondientes

    for (int s = 0; s < NUM_ANOS; s++) {
        cout << anos[s] << ": " << promedios[s] << "/10\n"; // Mostramos el promedio de cada servicio

        // Aquí comparamos para encontrar el mejor servicio evaluado
        if (promedios[s] > maxProm) {
            maxProm = promedios[s];
            mejorIndustria = anos[s];
        }
        // Y aquí encontramos el peor
        if (promedios[s] < minProm) {
            minProm = promedios[s];
            peorIndustria = anos[s];
        }
    }

    // Finalmente mostramos los resultados de mejor y peor servicio
    cout << "\n Mejor venta: " << mejorIndustria << " (" << maxProm << "/10)\n";
    cout << "Peor venta: " << peorIndustria << " (" << minProm << "/10)\n";
}
