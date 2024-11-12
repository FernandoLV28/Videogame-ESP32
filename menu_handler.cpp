#include "menu_handler.h"
#include "global_variables.h"

MenuHandler menuHandler;

// Índice de la letra que el jugador está seleccionando
int currentLetterIndex = 0;

void MenuHandler::setup()
{
  Serial.begin(115200);
  display.lcd_init_display();
  display.createCharacters();  
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_X, INPUT_PULLUP);
  pinMode(PIN_Y, INPUT_PULLUP);
  display.showWelcomeScreen();
}

bool MenuHandler::isButtonPressed()
{
  if (digitalRead(PIN_BUTTON) == LOW)
  {
    unsigned long currentMillis = millis();
    if (currentMillis - lastButtonPress > debounceDelay)
    {
      lastButtonPress = currentMillis;
      return true;
    }
  }
  return false;
}

void welcomeHandler(bool buttonPressed)
{
  if (buttonPressed)
  {
    currentState = MAIN_MENU;
    display.showMainMenu(mainMenuIndex);
    my_soundtrack.move();  // Sonido de transición al presionar el botón
  }
}

void mainMenuHandler(int yValue, bool joystickMoved, bool buttonPressed, unsigned long gameStartTime)
{
  int xValue = analogRead(PIN_X);
  if (DECREMENTO(yValue) && !joystickMoved)
  {
    my_soundtrack.move();  // Sonido al moverse por el menú
    mainMenuIndex++;
    if (mainMenuIndex >= mainMenuItems) mainMenuIndex = 0;
    joystickMoved = true;
    display.showMainMenu(mainMenuIndex);
  }

  if (INCREMENTO(yValue) && !joystickMoved)
  {
    my_soundtrack.move();  // Sonido al moverse por el menú
    mainMenuIndex--;
    if (mainMenuIndex < 0) mainMenuIndex = mainMenuItems - 1;
    joystickMoved = true;
    display.showMainMenu(mainMenuIndex);
  }

  if (!INCREMENTO(yValue) && !DECREMENTO(yValue))
  {
    joystickMoved = false;
  }

  if (buttonPressed)
  {
    my_soundtrack.move();  // Sonido al seleccionar una opción
    if (mainMenuIndex == 0){ // Iniciar juego
      currentState = IN_GAME;
      display.lcd_clear_display(); // Limpia la pantalla
      gameStartTime = millis();
      //my_soundtrack.fur_elise(); // Reproduce la música de fondo
    }
    else if (mainMenuIndex == 1)
    {
      currentState = HIGH_SCORES;
      display.showHighScores();
    }
    else if (mainMenuIndex == 2)
    {
      display.lcd_clear_display();
      mainMenuIndex = 0;
      currentState = WELCOME;
      display.showWelcomeScreen();
    }
  }
}

void highScoresHandler(bool buttonPressed)
{
  if (buttonPressed)
  {
    my_soundtrack.move();  // Sonido al regresar al menú principal
    currentState = MAIN_MENU;
    display.showMainMenu(mainMenuIndex);
  }
}

void inGameHandler(bool buttonPressed, unsigned long gameStartTime)
{
  if (buttonPressed)
  {
    currentState = IN_GAME_MENU;
    inGameMenuIndex = 0;
    display.showInGameMenu(inGameMenuIndex);
  }

  // Simulación de 15 segundos de juego antes de GAME_OVER
  if (millis() - gameStartTime > 15000)
  {
    currentState = ENTER_NAME;
    currentLetterIndex = 0;
    display.displayPlayerName(playerName);
  }
}

void inGameMenuHandler(int yValue, bool joystickMoved, bool buttonPressed, unsigned long gameStartTime)
{
  if (DECREMENTO(yValue) && !joystickMoved)
  {
    my_soundtrack.move();  // Sonido al moverse por el menú del juego
    inGameMenuIndex++;
    if (inGameMenuIndex >= inGameMenuItems) inGameMenuIndex = 0;
    joystickMoved = true;
    display.showInGameMenu(inGameMenuIndex);
  }

  if (INCREMENTO(yValue) && !joystickMoved)
  {
    my_soundtrack.move();  // Sonido al moverse por el menú del juego
    inGameMenuIndex--;
    if (inGameMenuIndex < 0) inGameMenuIndex = inGameMenuItems - 1;
    joystickMoved = true;
    display.showInGameMenu(inGameMenuIndex);
  }

  if (!INCREMENTO(yValue) && !DECREMENTO(yValue))
  {
    joystickMoved = false;
  }

  if (buttonPressed)
  {
    my_soundtrack.move();  // Sonido al seleccionar una opción
    if (inGameMenuIndex == 0)
    {
      currentState = IN_GAME;
      display.lcd_clear_display();
      gameStartTime = millis();
    }
    else if (inGameMenuIndex == 1)
    {
      currentState = MAIN_MENU;
      display.showMainMenu(mainMenuIndex);
    }
  }
}

void gameOverHandler(int yValue, bool joystickMoved, bool buttonPressed, unsigned long gameStartTime)
{
  if (DECREMENTO(yValue) && !joystickMoved)
  {
    my_soundtrack.move();  // Sonido al moverse por el menú de Game Over
    gameOverMenuIndex++;
    if (gameOverMenuIndex >= gameOverMenuItems) gameOverMenuIndex = 0;
    joystickMoved = true;
    display.showGameOverMenu(gameOverMenuIndex);
  }

  if (INCREMENTO(yValue) && !joystickMoved)
  {
    my_soundtrack.move();  // Sonido al moverse por el menú de Game Over
    gameOverMenuIndex--;
    if (gameOverMenuIndex < 0) gameOverMenuIndex = gameOverMenuItems - 1;
    joystickMoved = true;
    display.showGameOverMenu(gameOverMenuIndex);
  }

  if (!INCREMENTO(yValue) && !DECREMENTO(yValue))
  {
    joystickMoved = false;
  }

  if (buttonPressed)
  {
    my_soundtrack.move();  // Sonido al seleccionar una opción
    if (gameOverMenuIndex == 0)
    {
      currentState = IN_GAME;
      display.lcd_clear_display();
      gameStartTime = millis();
    }
    else if (gameOverMenuIndex == 1)
    {
      currentState = MAIN_MENU;
      display.showMainMenu(mainMenuIndex);
    }
  }
}
/*
void enterNameHandler(int yValue, bool &joystickMoved, bool buttonPressed) {
    // Verificar que el índice esté dentro del rango válido
    if (currentLetterIndex < 0 || currentLetterIndex >= sizeof(playerName) - 1) {
        currentLetterIndex = 0; // Restablecer el índice si está fuera de los límites
    }

    // Detectar movimiento en el joystick para cambiar la letra
    if (DECREMENTO(yValue) && !joystickMoved) {
        playerName[currentLetterIndex]++;
        if (playerName[currentLetterIndex] > 'Z') playerName[currentLetterIndex] = 'A';
        joystickMoved = true;
    } else if (INCREMENTO(yValue) && !joystickMoved) {
        playerName[currentLetterIndex]--;
        if (playerName[currentLetterIndex] < 'A') playerName[currentLetterIndex] = 'Z';
        joystickMoved = true;
    }

    // Restablecer el estado del joystick si no hay movimiento
    if (!INCREMENTO(yValue) && !DECREMENTO(yValue)) joystickMoved = false;

    // Manejar el botón presionado para avanzar al siguiente carácter
    if (buttonPressed) {
        currentLetterIndex++;
        // Verificar si se completó el ingreso del nombre
        if (currentLetterIndex > 2) {
            playerName[3] = '\0'; // Asegurar que el nombre esté terminado con un carácter nulo
            currentState = GAME_OVER;
            gameOverMenuIndex = 0;
            display.lcd_clear_display();
            display.saveValue(playerName, score);
            display.showGameOverMenu(gameOverMenuIndex);
        } else {
            display.displayPlayerName(playerName); // Mostrar el nombre del jugador en la pantalla
        }
    } else {
        display.displayPlayerName(playerName); // Mostrar el nombre del jugador en la pantalla
    }
}
*/
void enterNameHandler(int yValue, bool &joystickMoved, bool buttonPressed) {
    // Asegurarse de que el índice esté dentro del rango válido
    if (currentLetterIndex < 0 || currentLetterIndex >= 3) {
        currentLetterIndex = 0; // Restablecer el índice si está fuera de los límites
    }

    // Detectar movimiento en el joystick para cambiar la letra
    if (DECREMENTO(yValue) && !joystickMoved) {
        playerName[currentLetterIndex]++;
        if (playerName[currentLetterIndex] > 'Z') {
            playerName[currentLetterIndex] = 'A'; // Reiniciar a 'A' si pasa de 'Z'
        }
        joystickMoved = true;
    } else if (INCREMENTO(yValue) && !joystickMoved) {
        playerName[currentLetterIndex]--;
        if (playerName[currentLetterIndex] < 'A') {
            playerName[currentLetterIndex] = 'Z'; // Reiniciar a 'Z' si pasa de 'A'
        }
        joystickMoved = true;
    }

    // Restablecer el estado del joystick si no hay movimiento
    if (!INCREMENTO(yValue) && !DECREMENTO(yValue)) joystickMoved = false;

    // Manejar el botón presionado para avanzar al siguiente carácter
    if (buttonPressed) {
        currentLetterIndex++;
        // Verificar si se completó el ingreso del nombre
        if (currentLetterIndex >= 3) { // Cambiamos de 2 a 3 para permitir 3 caracteres
            playerName[3] = '\0'; // Asegurar que el nombre esté terminado con un carácter nulo
            currentState = GAME_OVER; // Cambiar el estado a GAME_OVER
            gameOverMenuIndex = 0;
            display.lcd_clear_display();
            display.saveValue(playerName, score);
            display.showGameOverMenu(gameOverMenuIndex);
        } else {
            display.displayPlayerName(playerName); // Mostrar el nombre del jugador en la pantalla
        }
    } else {
        display.displayPlayerName(playerName); // Mostrar el nombre del jugador en la pantalla
    }
}




void MenuHandler::handleMenuNavigation()
{
  int yValue = analogRead(PIN_Y);
  bool joystickMoved = false;
  buttonPressed = isButtonPressed();

  switch (currentState)
  {
  case WELCOME:
    welcomeHandler(buttonPressed);
    break;

  case MAIN_MENU:
    mainMenuHandler(yValue, joystickMoved, buttonPressed, gameStartTime);
    break;

  case HIGH_SCORES:
    highScoresHandler(buttonPressed);
    break;

  case IN_GAME:
    inGameHandler(buttonPressed, gameStartTime);
    break;

  case IN_GAME_MENU:
    inGameMenuHandler(yValue, joystickMoved, buttonPressed, gameStartTime);
    break;

  case GAME_OVER:
    gameOverHandler(yValue, joystickMoved, buttonPressed, gameStartTime);
    break;

  case ENTER_NAME:
    enterNameHandler(yValue, joystickMoved, buttonPressed);
    break;
  }
}
