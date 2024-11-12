#include "global_variables.h"

// Definiciones de las variables globales
int currentState = 0;           // Estado actual del juego
int mainMenuIndex = 0;          // Índice del menú principal
int inGameMenuIndex = 0;        // Índice del menú dentro del juego
int gameOverMenuIndex = 0;      // Índice del menú de Game Over

int8_t obstacle1[2] = {0, 0};   // Coordenadas del primer obstáculo
int8_t obstacle2[2] = {15, 1};  // Coordenadas del segundo obstáculo
int8_t player[2] = {7, 0};      // Coordenadas del jugador

int score = 0;                  // Puntuación actual del jugador

const int mainMenuItems = 3;     // Elementos del menú principal
const char *menuItems[] = {"Jugar", "Puntajes Altos", "Salir"};  // Menú principal

const int inGameMenuItems = 2;   // Elementos del menú dentro del juego
const char *inGameItems[] = {"Reanudar", "Salir"};  // Menú dentro del juego

const int gameOverMenuItems = 2; // Elementos del menú de Game Over
const char *gameOverItems[] = {"Jugar de nuevo", "Salir"};  // Menú de Game Over

char playerName[3] = {'A', 'B', 'C'}; // Nombre del jugador
