#ifndef MICROSD_H
#define MICROSD_H

#include <SD.h>
#include <SPI.h>
#include "json.h"

#define MICROSD_PIN 5  ///< Pin de la microSD

// Gestor de operaciones en la tarjeta microSD.
class MicroSD {
public:
  String filename = "/scores.txt";  ///< Archivo para guardar puntajes

  void init();  ///< Inicializa la tarjeta microSD
  void saveScore(char *playerName, int score);  ///< Guarda puntaje
  void getTopScores(String topScores[], int topN);  ///< Obtiene los mejores puntajes
  void checkFileContent();  ///< Verifica el contenido del archivo
};

extern MicroSD microSD; // Declaración de la instancia de MicroSD

#endif
