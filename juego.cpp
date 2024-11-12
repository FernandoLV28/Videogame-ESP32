#include "juego.h"
#include "song.h"

soundtracks my_soundtrack;
Juego myJuego;

// Método para mover al jugador
void Juego::movimiento() {
    // Leer los valores del joystick
    int xValue = analogRead(PIN_X);
    int yValue = analogRead(PIN_Y);

    // Detectar movimiento en el eje X
    if (xValue < 100) { // Mover a la izquierda
        xMoved = true;
        playerMovX = 1; // Asigna dirección izquierda
    } else if (xValue > 3900) { // Mover a la derecha
        xMoved = true;
        playerMovX = -1; // Asigna dirección derecha
    } else {
        xMoved = false; // No se está moviendo en el eje X
        playerMovX = 0; // Restablecer dirección
    }

    // Detectar movimiento en el eje Y
    if (yValue < 100) { // Mover hacia arriba
        yMoved = true;
        playerMovY = 1; // Asigna dirección hacia arriba
    } else if (yValue > 3900) { // Mover hacia abajo
        yMoved = true;
        playerMovY = -1; // Asigna dirección hacia abajo
    } else {
        yMoved = false; // No se está moviendo en el eje Y
        playerMovY = 0; // Restablecer dirección
    }

    // Movimiento en el eje X
    if (xMoved) {
        int futureMov = player[0] + playerMovX;
        if (futureMov >= 0 && futureMov < 16) { // Verifica límites
            movePoint(futureMov, player[1]);
        }
    }

    // Movimiento en el eje Y
    if (yMoved) {
        int futureMov = player[1] + playerMovY;
        if (futureMov >= 0 && futureMov < 2) { // Verifica límites
            movePoint(player[0], futureMov);
        }
    }
}


// Método para mover el punto del jugador
void Juego::movePoint(int newX, int newY) {
    display.print(32, player[0], player[1]); // Borra la posición anterior
    player[0] = newX;
    player[1] = newY;
    display.print(5, player[0], player[1]); // Dibuja la nueva posición

    Serial.print("X Pos: ");
    Serial.print(player[0]);
    Serial.print(" Y Pos: ");
    Serial.println(player[1]);
}

// Método para verificar si el jugador ha chocado
bool Juego::hasCrashed() {
    bool returnVal = false;
    if ((player[0] == obstacle1[0] && player[1] == obstacle1[1]) || 
        (player[0] == obstacle2[0] && player[1] == obstacle2[1])) {
        returnVal = true;
        Serial.println("Murió");
        // my_soundtrack.death_sound();
    }
    return returnVal;
}

// Método para iniciar al jugador
void Juego::startPlayer() {
    display.print(5, player[0], player[1]); // Dibuja al jugador en la pantalla
}
