#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include "microsd.h"
#include "lcd_handler.h"
#include "menu_handler.h"
#include "parallel_task.h"

//Instancias globales para la gestión del videojuego.

MicroSD microSD;            ///< Manejo de la tarjeta microSD.
LCDHandler display;         ///< Manejo de la pantalla LCD.
MenuHandler menuHandler;    ///< Manejo del menú del videojuego.
ParallelTask parallelTask;  ///< Manejo de tareas paralelas.
Juego myJuego;              ///< Manejo del juego.

#endif
