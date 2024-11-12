#ifndef JUEGO_H
#define JUEGO_H

#include "lcd_handler.h"
#include "song.h"
#include "global_variables.h"

// Instancia para reproducir sonidos.
extern soundtracks my_soundtrack;

// Instancia de la pantalla LCD.
extern LCDHandler display;

class Juego {
  public:
    void movimiento( void );       ///< Función principal de movimiento del jugador.
    bool hasCrashed( void );       ///< Verifica si el jugador ha chocado con un obstáculo.
    void startPlayer( void );      ///< Inicia al jugador en su posición inicial.

  private:
    int lastXValue = 2900;         ///< Valor inicial centrado del eje X.
    int lastYValue = 2900;         ///< Valor inicial centrado del eje Y.
    int centerVal = 2900;          ///< Valor del centro del joystick.

    int playerMovX = 0;            ///< Movimiento en el eje X.
    int playerMovY = 0;            ///< Movimiento en el eje Y.

    const int threshold = 800;     ///< Umbral de sensibilidad para detectar movimientos.

    bool xMoved = false;           ///< Bandera para indicar movimiento en X.
    bool yMoved = false;           ///< Bandera para indicar movimiento en Y.
    
    bool joystickXReleased = true; ///< Bandera para indicar si el joystick en X fue liberado.
    bool joystickYReleased = true; ///< Bandera para indicar si el joystick en Y fue liberado.

    void movePoint( int, int );    ///< Mueve al jugador a una nueva posición (X,Y).
};

extern Juego myJuego;

#endif // JUEGO_H
