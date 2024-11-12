#include "lcd_handler.h"
#include "microsd.h"
#include "global_variables.h"

LCDHandler display;
MicroSD microSD;

// Definición de los caracteres personalizados para el LCD
byte topLeft[8] = {
    B01111,
    B10000,
    B10111,
    B10100,
    B10100,
    B10100,
    B10100,
    B10111
};

byte topRight[8] = {
    B11110,
    B00001,
    B11101,
    B00101,
    B00101,
    B00101,
    B00101,
    B11101
};

byte bottomRight[8] = {
    B00001,
    B00001,
    B01101,
    B00001,
    B11001,
    B00001,
    B00001,
    B11110
};

byte bottomLeft[8] = {
    B10000,
    B10000,
    B10010,
    B10111,
    B10010,
    B10000,
    B10000,
    B01111
};

byte obstacle[8] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
};

byte playerByte[8] = {
    B00100,
    B00100,
    B00100,
    B00100,
    B01110,
    B11111,
    B11111,
    B01110
};

// Constructor de la clase LCDHandler
LCDHandler::LCDHandler() : lcd(0x27, 16, 2) {} // Inicializa el LCD en la dirección 0x27 con 16 columnas y 2 filas

// Inicializar la pantalla LCD
void LCDHandler::lcd_init_display() {
    lcd.init();
    lcd.backlight(); // Encender el retroiluminado
}

// Limpiar la pantalla LCD
void LCDHandler::lcd_clear_display() {
    lcd.clear();
}

// Establecer el cursor en una posición específica
void LCDHandler::lcd_set_cursor(int column, int row) {
    lcd.setCursor(column, row);
}

// Crear los caracteres personalizados
void LCDHandler::createCharacters() {
    lcd.createChar(0, topLeft);
    lcd.createChar(1, topRight);
    lcd.createChar(2, bottomRight);
    lcd.createChar(3, bottomLeft);
    lcd.createChar(4, obstacle);
    lcd.createChar(5, playerByte);
}

// Mostrar la pantalla de bienvenida
void LCDHandler::showWelcomeScreen() {
    lcd.setCursor(4, 0);
    lcd.print("Bienvenido!");
    lcd.setCursor(4, 1);
    lcd.print("Presiona");

    lcd.setCursor(1, 0);
    lcd.write(0); // Carácter personalizado
    lcd.write(1); // Carácter personalizado

    lcd.setCursor(1, 1);
    lcd.write(3); // Carácter personalizado
    lcd.write(2); // Carácter personalizado
}

// Mostrar el menú principal
void LCDHandler::showMainMenu(int index) {
    lcd_clear_display();
    for (int i = 0; i < mainMenuItems; i++) {
        lcd.setCursor(0, i);
        if (i == index) {
            lcd.print("> "); // Resaltar el ítem seleccionado
        } else {
            lcd.print("  ");
        }
        lcd.print(menuItems[i]);
    }
}

// Mostrar el menú dentro del juego
void LCDHandler::showInGameMenu(int index) {
    lcd_clear_display();
    for (int i = 0; i < inGameMenuItems; i++) {
        lcd.setCursor(0, i);
        if (i == index) {
            lcd.print("> "); // Resaltar el ítem seleccionado
        } else {
            lcd.print("  ");
        }
        lcd.print(inGameItems[i]);
    }
    lcd.setCursor(7, 1);
    lcd.print("|Score:");
    lcd.print(score); // Mostrar la puntuación actual
}

// Mostrar el menú de Game Over
void LCDHandler::showGameOverMenu(int index) {
    microSD.saveScore(playerName, score); // Guardar el puntaje en la microSD
    lcd_clear_display();
    for (int i = 0; i < gameOverMenuItems; i++) {
        lcd.setCursor(0, i);
        if (i == index) {
            lcd.print("> "); // Resaltar el ítem seleccionado
        } else {
            lcd.print("  ");
        }
        lcd.print(gameOverItems[i]);
    }
}

// Guardar el puntaje del jugador en la tarjeta microSD
void LCDHandler::saveValue(char *playerName, int score) {
    microSD.saveScore(playerName, score); // Guardar el nombre y el puntaje
    playerName[0] = ' '; // Limpiar el nombre del jugador
    playerName[1] = ' ';
    playerName[2] = ' ';
}

// Mostrar los puntajes más altos
void LCDHandler::showHighScores() {
    lcd_clear_display();
    lcd.setCursor(0, 0);
    lcd.print("Puntajes Altos:");
    lcd.setCursor(0, 1);
    int topN = 4;
    String topScores[4];
    microSD.getTopScores(topScores, topN);
    if (topScores[0] == "No hay puntajes") {
        lcd.print("No hay puntajes");
        return;
    } else {
        String output;
        for (int i = 0; i < topN; i++) {
            if (topScores[i] == "") {
                break; // Detener la impresión si no hay más puntajes
            }
            output += String(i + 1) + "." + String(topScores[i]) + "|";
        }
        lcd.print(output); // Mostrar los puntajes en pantalla
    }
}

// Mostrar el nombre del jugador
void LCDHandler::displayPlayerName(char *playerName) {
    lcd_clear_display();
    lcd.setCursor(0, 0);
    lcd.print("Nombre: ");
    lcd.setCursor(0, 1);
    lcd.print(playerName); // Mostrar el nombre del jugador
}

// Mover un obstáculo en la pantalla
void LCDHandler::moveObstacle(int8_t obstacle[2], uint8_t obstacleType) {
    int8_t step = (obstacleType == 1) ? 1 : -1; // Determina la dirección del movimiento

    // Dibuja el obstáculo en la posición inicial
    print(4, obstacle[0], obstacle[1]); 

    // Pausar para simular el movimiento
    delay(300); 

    // Borrar el obstáculo en la posición anterior
    lcd.setCursor(obstacle[0], obstacle[1]);
    lcd.print(" "); 

    // Mover el obstáculo en la dirección indicada
    while (obstacle[0] < 16 && obstacle[0] > -1) {
        obstacle[0] += step; // Mueve el obstáculo
        
        // Dibuja el obstáculo en la nueva posición
        print(4, obstacle[0], obstacle[1]);
        
        // Pausar para simular el movimiento
        delay(300);

        // Borra el obstáculo en la nueva posición
        lcd.setCursor(obstacle[0], obstacle[1]);
        lcd.print(" ");
    }
}


void LCDHandler::print(int type, int x, int y) {
    // Establecer el cursor en la posición (x, y)
    lcd.setCursor(x, y);
    
    // Imprimir el carácter correspondiente basado en el tipo
    switch (type) {
        case 0:
            lcd.write(0); // Carácter personalizado 0
            break;
        case 1:
            lcd.write(1); // Carácter personalizado 1
            break;
        case 2:
            lcd.write(2); // Carácter personalizado 2
            break;
        case 3:
            lcd.write(3); // Carácter personalizado 3
            break;
        case 4:
            lcd.write(4); // Carácter del obstáculo
            break;
        case 5:
            lcd.write(5); // Carácter del jugador
            break;
        default:
            // Comportamiento por defecto: borrar el espacio
            lcd.print(" "); // Borrar el espacio si no hay tipo definido
            break;
    }
}
