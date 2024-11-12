#ifndef LCD_HANDLER_H
#define LCD_HANDLER_H

#include <LiquidCrystal_I2C.h>
#include "microsd.h"

extern MicroSD microSD;

// Definiciones de enumeraciones y otras declaraciones
enum State {
    WELCOME,
    MAIN_MENU,
    HIGH_SCORES,
    IN_GAME,
    IN_GAME_MENU,
    GAME_OVER,
    ENTER_NAME
};

class LCDHandler {
public:
    LCDHandler();  // Constructor
    void lcd_init_display();
    void lcd_clear_display();
    void lcd_set_cursor(int column, int row);
    void createCharacters(void);
    void showWelcomeScreen();
    void showMainMenu(int index);
    void showInGameMenu(int index);
    void showGameOverMenu(int index);
    void showHighScores();
    void displayPlayerName(char *playerName);
    void saveValue(char *playerName, int score);
    void print(int type, int x, int y);  // Actualización de la declaración
    void moveObstacle(int8_t obstacle[2], uint8_t obstacleType);

private:
    LiquidCrystal_I2C lcd; // Instancia de LCD
};

// Declaraciones de los caracteres personalizados (extern para evitar múltiples definiciones)
extern byte topLeft[8];
extern byte topRight[8];
extern byte bottomRight[8];
extern byte bottomLeft[8];
extern byte obstacle[8];
extern byte playerByte[8];

#endif
