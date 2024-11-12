#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include <cstdint>

// Definiciones del menú
extern int currentState;          // Estado actual del juego
extern int mainMenuIndex;         // Índice del menú principal
extern int inGameMenuIndex;       // Índice del menú dentro del juego
extern int gameOverMenuIndex;     // Índice del menú de Game Over

// Definiciones de los pines
const int PIN_X = 35;             // Pin del joystick eje X
const int PIN_Y = 34;             // Pin del joystick eje Y
const int PIN_BUTTON = 32;        // Pin del botón

// Definición de las macros para el movimiento del joystick
#define INCREMENTO(a) (a > VALOR_INICIAL + 300 ? 1 : 0)
#define DECREMENTO(a) (a < VALOR_INICIAL - 300 ? 1 : 0)

// Definiciones de los valores del joystick
const int VALOR_INICIAL = 1900;   // Valor inicial del joystick
const int VALOR_TOPE = 4095;      // Valor máximo del joystick

// Declaraciones de las variables de los obstáculos y el jugador
extern int8_t obstacle1[2];       // Coordenadas del primer obstáculo
extern int8_t obstacle2[2];       // Coordenadas del segundo obstáculo
extern int8_t player[2];          // Coordenadas del jugador

// Declaraciones de los elementos de los menús y puntuaciones
extern int score;                  // Puntuación actual del jugador
extern const int mainMenuItems;    // Elementos del menú principal
extern const char *menuItems[];    // Elementos del menú principal
extern const int inGameMenuItems;  // Elementos del menú dentro del juego
extern const char *inGameItems[];  // Elementos del menú dentro del juego
extern const int gameOverMenuItems;// Elementos del menú de Game Over
extern const char *gameOverItems[];// Elementos del menú de Game Over
extern char playerName[3];         // Nombre del jugador

#endif
