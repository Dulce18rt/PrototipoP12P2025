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
#define NUM_DEPARTAMENTOS 5

// Número de ciudadanos que responden la encuesta en cada departamento
#define NUM_PERSONAS 30

// Número de servicios públicos a evaluar
#define NUM_SERVICIOS 4

// ==================== FUNCIONES ====================

// Permite al usuario ingresar los nombres de los departamentos
void ingresarDepartamentos(string departamentos[]);

// Genera calificaciones aleatorias (1-10) por servicio en cada departamento
void generarEncuesta(int calificaciones[][NUM_SERVICIOS]);

// Muestra una tabla con los resultados por departamento y por servicio
void mostrarResultados(string departamentos[], string servicios[], int calificaciones[][NUM_SERVICIOS]);

// Calcula qué servicio tiene mejor y peor promedio nacional
void calcularPromedios(string servicios[], int calificaciones[][NUM_SERVICIOS]);

#endif
