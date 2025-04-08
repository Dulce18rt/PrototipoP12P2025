// encuesta.h
// =============================================================
// CABECERA del programa de encuesta nacional de servicios.
// Aquí definimos las constantes y declaramos las funciones.
// =============================================================

#ifndef ENCUESTA_H
#define ENCUESTA_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// ==================== CONSTANTES ====================

// Número de departamentos a evaluar
#define NUM_INDUSTRIAS 5

// Número de personas
#define NUM_PERSONAS 30

// Número de servicios públicos a evaluar
#define NUM_ANOS 4

// ==================== FUNCIONES ====================

// Permite al usuario ingresar los nombres de los departamentos
void ingresarindustrias(string Industrias[]);

// Genera calificaciones aleatorias (1-10) por servicio en cada departamento
void generarVentas(int ventas[][NUM_ANOS]);

// Muestra una tabla con los resultados por departamento y por servicio
void mostrarResultados(string industrias[], string anos[], int ventas[][NUM_ANOS]);

// Calcula qué servicio tiene mejor y peor promedio nacional
void calcularPromedios(string anos[], int ventas[][NUM_ANOS]);

#endif
