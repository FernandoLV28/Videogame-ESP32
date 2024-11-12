#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#include "lcd_handler.h"
#include "song.h"

// Instancia del controlador de LCD para la visualización y de sonido para la música
extern LCDHandler display;
extern soundtracks my_soundtrack; // Para agregar sonido en la navegación

class MenuHandler
{
private:
  unsigned long gameStartTime = 0;         ///< Tiempo de inicio del juego.
  unsigned long lastButtonPress = 0;       ///< Marca de tiempo del último botón presionado.
  const unsigned long debounceDelay = 200; ///< Retardo para la rebote del botón.
  bool buttonPressed = false;              ///< Indica si un botón ha sido presionado.
  bool isResumed = false;

public:
  void setup();
  bool isButtonPressed();
  void handleMenuNavigation();
};

// Ahora declaramos la instancia extern de MenuHandler después de que la clase ha sido definida
extern MenuHandler menuHandler;

#endif
