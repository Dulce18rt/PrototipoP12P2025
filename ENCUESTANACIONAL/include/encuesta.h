// encuesta.h
// =============================================================
// CABECERA del programa de encuesta nacional de servicios.
// Aqu� definimos las constantes y declaramos las funciones.
// =============================================================

#ifndef ENCUESTA_H
#define ENCUESTA_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// ==================== CONSTANTES ====================

// N�mero de departamentos a evaluar
#define NUM_INDUSTRIAS 5

// N�mero de personas
#define NUM_PERSONAS 30

// N�mero de servicios p�blicos a evaluar
#define NUM_ANOS 4

// ==================== FUNCIONES ====================

// Permite al usuario ingresar los nombres de los departamentos
void ingresarindustrias(string Industrias[]);

// Genera calificaciones aleatorias (1-10) por servicio en cada departamento
void generarVentas(int ventas[][NUM_ANOS]);

// Muestra una tabla con los resultados por departamento y por servicio
void mostrarResultados(string industrias[], string anos[], int ventas[][NUM_ANOS]);

// Calcula qu� servicio tiene mejor y peor promedio nacional
void calcularPromedios(string anos[], int ventas[][NUM_ANOS]);

#endif
