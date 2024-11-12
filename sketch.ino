#include "parallel_task.h"
#include "juego.h"
#include "lcd_handler.h"
#include "global_variables.h"

#define BAUDRATE 115200

void setup() {
  Serial.begin(BAUDRATE);
  
  // Inicializa la pantalla LCD
  display.lcd_init_display();
  display.createCharacters();
  
  // Inicia las tareas paralelas
  ParallelTask::startTasks();
}

void loop() {
  delay(10);
}
