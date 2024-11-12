#ifndef PARALLEL_TASK_H
#define PARALLEL_TASK_H

#include "menu_handler.h"
#include "juego.h"
#include "lcd_handler.h"

// Definición de los núcleos
#define NUCLEO_PRINCIPAL 1
#define NUCLEO_SECUNDARIO 0

// Tamaño de pila para cada tarea
#define STACK_SIZE_MENU 8000
#define STACK_SIZE_OBSTACLE 8000
#define STACK_SIZE_PLAYER 5000
#define STACK_SIZE_PAUSE 2000

// Instancia externa de MenuHandler utilizada en las tareas paralelas.
extern MenuHandler menuHandler;
extern Juego myJuego;
extern LCDHandler display;

// Declaración de handles para las tareas del menú y del juego.
extern TaskHandle_t HiloMenu;
extern TaskHandle_t HiloMenu2;
extern TaskHandle_t HiloObstaculo1;
extern TaskHandle_t HiloObstaculo2;
extern TaskHandle_t HiloPlayerMov;
extern TaskHandle_t HiloPausa;

// Declaraciones de las variables de los obstáculos y el jugador.
extern int8_t obstacle1[2];
extern int8_t obstacle2[2];
extern int8_t player[2];
extern int score;

// Clase que gestiona las tareas paralelas en el videojuego usando FreeRTOS.
class ParallelTask {
public:
    static void startTasks();                       ///< Inicia todas las tareas paralelas.
    static void menuTask(void *pvParameters);       ///< Tarea del menú.
    static void menuTask2(void *pvParameters);      ///< Segunda tarea del menú (usada para el in-game menu).
    static void obstacleTask(void *pvParameters);   ///< Tarea para los obstáculos.

//    static void obstacle1Task(void *pvParameters);   ///< Tarea para el obstáculo 1.
//    static void obstacle2Task(void *pvParameters);   ///< Tarea para el obstáculo 2.

    static void playerMov(void *pvParameters);      ///< Tarea del movimiento del jugador.
    static void checkingPause(void *pvParameters);  ///< Tarea para chequear si se pausa el juego.
};

#endif // PARALLEL_TASK_H

// Declaración de los handles de las tareas.
TaskHandle_t HiloMenu;
TaskHandle_t HiloMenu2;
TaskHandle_t HiloObstaculo1;
TaskHandle_t HiloObstaculo2;
TaskHandle_t HiloPlayerMov;
TaskHandle_t HiloPausa;

// Inicia las tareas paralelas en el videojuego.
void ParallelTask::startTasks() {
    menuHandler.setup(); // Inicialización del menú y pantalla.

    // Creación de la tarea principal del menú.
    xTaskCreatePinnedToCore(
        ParallelTask::menuTask,
        "MenuTask",
        STACK_SIZE_MENU,
        NULL,
        1,
        &HiloMenu,
        NUCLEO_PRINCIPAL
    );
}

// Tarea encargada de la gestión del menú principal del juego.
void ParallelTask::menuTask(void *pvParameters) {
    while (true) {
        menuHandler.handleMenuNavigation(); // Maneja la navegación del menú.

        if (currentState == IN_GAME) {
            score = 10; // Inicialización del puntaje.
            Serial.println("Iniciando el juego...");

            // Posiciones iniciales de los obstáculos y el jugador
            obstacle1[0] = 0; obstacle1[1] = 0;
            obstacle2[0] = 15; obstacle2[1] = 1;
            player[0] = 7; player[1] = 0;

            // Dibuja los obstáculos y el jugador en sus posiciones iniciales
            display.print(4, obstacle1[0], obstacle1[1]); // Dibuja el obstáculo 1
            display.print(4, obstacle2[0], obstacle2[1]); // Dibuja el obstáculo 2
            display.print(5, player[0], player[1]);       // Dibuja el jugador

            int obstacleId1 = 1;
            int obstacleId2 = 2;

            // Verifica si las tareas ya están creadas
            if (HiloObstaculo1 == NULL) {
                xTaskCreatePinnedToCore(
                    ParallelTask::obstacleTask,
                    "obstacle1Mov",
                    STACK_SIZE_OBSTACLE,
                    &obstacleId1,
                    2,
                    &HiloObstaculo1,
                    NUCLEO_PRINCIPAL
                );  
            }

            if (HiloObstaculo2 == NULL) {
                xTaskCreatePinnedToCore(
                    ParallelTask::obstacleTask,
                    "obstacle2Mov",
                    STACK_SIZE_OBSTACLE,
                    &obstacleId2,
                    2,
                    &HiloObstaculo2,
                    NUCLEO_PRINCIPAL
                );
            }

            if (HiloPlayerMov == NULL) {
                xTaskCreatePinnedToCore(
                    ParallelTask::playerMov,
                    "playerMov",
                    STACK_SIZE_PLAYER,
                    NULL,
                    3,
                    &HiloPlayerMov,
                    NUCLEO_PRINCIPAL
                );
            }

            if (HiloPausa == NULL) {
                xTaskCreatePinnedToCore(
                    ParallelTask::checkingPause,
                    "checkPause",
                    STACK_SIZE_PAUSE,
                    NULL,
                    1,
                    &HiloPausa,
                    NUCLEO_SECUNDARIO
                );
            }
            
            vTaskSuspend(HiloMenu); // Suspende la tarea del menú en lugar de eliminarla.
        }

        vTaskDelay(150 / portTICK_PERIOD_MS);
    }
}


// Segunda tarea del menú, utilizada para reanudar el juego tras la pausa.
void ParallelTask::menuTask2(void *pvParameters) {
    while (true) {
        menuHandler.handleMenuNavigation(); // Maneja la navegación del menú en modo pausa.

        if (currentState == IN_GAME) {
            // Reanuda las tareas del jugador y los obstáculos.
            vTaskResume(HiloPlayerMov);
            vTaskResume(HiloObstaculo1);
            vTaskResume(HiloObstaculo2);

            vTaskDelete(NULL); // Elimina la tarea actual después de reanudar el juego.
        }

        if (currentState == MAIN_MENU) {
            vTaskResume(HiloMenu); // Reanuda la tarea del menú principal.
            vTaskDelete(NULL);     // Elimina la tarea actual.
        }

        vTaskDelay(150 / portTICK_PERIOD_MS);
    }
}

/*
// Tarea para los obstáculos.
void ParallelTask::obstacleTask(void *pvParameters) {
    int obstacleId = *((int*)pvParameters); // Obtenemos el ID del obstáculo a partir del parámetro pasado.
    int8_t *obstacle = (obstacleId == 1) ? obstacle1 : obstacle2;

    // Mensaje de depuración
    Serial.printf("Moviendo obstáculo %d a la posición (%d, %d)\n", obstacleId, obstacle[0], obstacle[1]);

    for (;;) {
        display.moveObstacle(obstacle, obstacleId); // Mueve el obstáculo correspondiente.
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
*/

// Tarea para los obstáculos.
void ParallelTask::obstacleTask(void *pvParameters) {
    int obstacleId = *((int*)pvParameters); // Obtenemos el ID del obstáculo a partir del parámetro pasado.
    int8_t *obstacle = (obstacleId == 1) ? obstacle1 : obstacle2;

    // Inicializar la posición del obstáculo
    obstacle[0] = 0; // Posición inicial X
    obstacle[1] = random(0, 2); // Posición inicial Y (0 o 1)

    // Mensaje de depuración
    Serial.printf("Moviendo obstáculo %d a la posición inicial (%d, %d)\n", obstacleId, obstacle[0], obstacle[1]);

    // Determinar la dirección inicial del movimiento
    int8_t step = (obstacleId == 1) ? 1 : -1; // La dirección puede ser de izquierda a derecha o viceversa

    for (;;) {
        // Mueve el obstáculo y actualiza su posición
        display.moveObstacle(obstacle, obstacleId); // Mueve el obstáculo correspondiente.

        // Verifica si el obstáculo ha salido de la pantalla
        if (obstacle[0] >= 16 || obstacle[0] < 0) {
            // Reinicia la posición en el borde opuesto
            obstacle[0] = (obstacle[0] >= 16) ? 0 : 15; // Si sale por la derecha, vuelve a la izquierda; si sale por la izquierda, vuelve a la derecha
            obstacle[1] = random(0, 2); // Cambia la posición Y al azar entre 0 y 1
            Serial.printf("Reiniciando obstáculo %d a la posición (%d, %d)\n", obstacleId, obstacle[0], obstacle[1]);
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}


/*
//Tareas para el movimiento de los obstaculos
void ParallelTask::obstacle1Task(void *pvParameters)
{
  for (;;)
  {
    display.moveObstacle(obstacle1, 1); // Mueve el obstáculo 1.
    obstacle1[0] = 0; // Restablece la posición.
    obstacle1[1] = 0;
    score += 10; // Incrementa el puntaje.
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL); // Elimina la tarea al completar el ciclo.
}

void ParallelTask::obstacle2Task(void *pvParameters)
{
  for (;;)
  {
    display.moveObstacle(obstacle2, 2); // Mueve el obstáculo 2.
    obstacle2[0] = 15; // Restablece la posición.
    obstacle2[1] = 1;
    score += 10; // Incrementa el puntaje.
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL); // Elimina la tarea al completar el ciclo.
}
*/
// Tarea encargada del movimiento del jugador.
void ParallelTask::playerMov(void *pvParameters) {
    for (;;) {
        myJuego.movimiento(); // Mueve el jugador.
        // Mensaje de depuración para verificar la posición del jugador
        Serial.printf("Posición del jugador: (%d, %d)\n", player[0], player[1]);

        // Verifica si el jugador ha chocado.
        if (myJuego.hasCrashed()) {
            vTaskDelete(HiloObstaculo1);
            vTaskDelete(HiloObstaculo2);
            currentState = ENTER_NAME;

            // Reanuda la tarea del menú principal.
            vTaskResume(HiloMenu);
            vTaskDelete(NULL); // Elimina la tarea del jugador.
        }

        vTaskDelay(50 / portTICK_PERIOD_MS); // Pequeño retardo para suavizar el movimiento.
    }
}

// Tarea para verificar si el juego está en pausa.
void ParallelTask::checkingPause(void *pvParameters) {
    for (;;) {
        if (menuHandler.isButtonPressed()) {
            vTaskSuspend(HiloPlayerMov);
            vTaskSuspend(HiloObstaculo1);
            vTaskSuspend(HiloObstaculo2);

            currentState = IN_GAME_MENU;
            display.showInGameMenu(inGameMenuIndex);

            // Crea la segunda tarea del menú para gestionar la reanudación.
            xTaskCreatePinnedToCore(
                ParallelTask::menuTask2,
                "MenuTask-2",
                STACK_SIZE_MENU,
                NULL,
                1,
                &HiloMenu2,
                NUCLEO_PRINCIPAL
            );

            vTaskDelete(NULL); // Elimina la tarea actual de pausa.
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
