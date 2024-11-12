#include "song.h"
#include "Arduino.h"

int tempo = 80;

// Implementación de la función "playTone"
void soundtracks ::playTone(int note, int duration){
  if (note != REST)
  {
    tone(buzzer, note, duration);
  }
}

void soundtracks :: fur_elise (void){
  const int melody[] PROGMEM = {

  //starts from 1 ending on 9
  NOTE_E5, 16, NOTE_DS5, 16, //1
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,//6
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4 , 4, REST, 8, //9 - 1st ending

  //repaets from 1 ending on 10
  NOTE_E5, 16, NOTE_DS5, 16, //1
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,//6
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16, //10 - 2nd ending
  //continues from 11
  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16, 
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16, //12
  
  NOTE_C5, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16, //13
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, REST, 16,
  REST, 16, NOTE_E5, 16, NOTE_E6, 16, REST, 16, REST, 16, NOTE_DS5, 16,
  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16, //19
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16, //24 (1st ending)
  
  //repeats from 11
  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16, 
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16, //12
  
  NOTE_C5, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16, //13
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, REST, 16,
  REST, 16, NOTE_E5, 16, NOTE_E6, 16, REST, 16, REST, 16, NOTE_DS5, 16,
  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16, //19
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_C5, 16, NOTE_C5, 16, NOTE_C5, 16, //25 - 2nd ending

  //continues from 26
  NOTE_C5 , 4, NOTE_F5, -16, NOTE_E5, 32, //26
  NOTE_E5, 8, NOTE_D5, 8, NOTE_AS5, -16, NOTE_A5, 32,
  NOTE_A5, 16, NOTE_G5, 16, NOTE_F5, 16, NOTE_E5, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_AS4, 8, NOTE_A4, 8, NOTE_A4, 32, NOTE_G4, 32, NOTE_A4, 32, NOTE_B4, 32,
  NOTE_C5 , 4, NOTE_D5, 16, NOTE_DS5, 16,
  NOTE_E5, -8, NOTE_E5, 16, NOTE_F5, 16, NOTE_A4, 16,
  NOTE_C5 , 4,  NOTE_D5, -16, NOTE_B4, 32,
  
  
  NOTE_C5, 32, NOTE_G5, 32, NOTE_G4, 32, NOTE_G5, 32, NOTE_A4, 32, NOTE_G5, 32, NOTE_B4, 32, NOTE_G5, 32, NOTE_C5, 32, NOTE_G5, 32, NOTE_D5, 32, NOTE_G5, 32, //33
  NOTE_E5, 32, NOTE_G5, 32, NOTE_C6, 32, NOTE_B5, 32, NOTE_A5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_E5, 32, NOTE_D5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_D5, 32,
  NOTE_C5, 32, NOTE_G5, 32, NOTE_G4, 32, NOTE_G5, 32, NOTE_A4, 32, NOTE_G5, 32, NOTE_B4, 32, NOTE_G5, 32, NOTE_C5, 32, NOTE_G5, 32, NOTE_D5, 32, NOTE_G5, 32,

  NOTE_E5, 32, NOTE_G5, 32, NOTE_C6, 32, NOTE_B5, 32, NOTE_A5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_E5, 32, NOTE_D5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_D5, 32, //36
  NOTE_E5, 32, NOTE_F5, 32, NOTE_E5, 32, NOTE_DS5, 32, NOTE_E5, 32, NOTE_B4, 32, NOTE_E5, 32, NOTE_DS5, 32, NOTE_E5, 32, NOTE_B4, 32, NOTE_E5, 32, NOTE_DS5, 32,
  NOTE_E5, -8, NOTE_B4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, -8, NOTE_B4, 16, NOTE_E5, 16, REST, 16,

  REST, 16, NOTE_DS5, 16, NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, //40
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,

  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, //46
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16,
  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16,
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16,
  NOTE_C5, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, REST, 16,
  REST, 16, NOTE_E5, 16, NOTE_E6, 16, REST, 16, REST, 16, NOTE_DS5, 16,

  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_D5, 16, //54
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, //60
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, REST, 16, REST, 8, 
  NOTE_CS5 , -4, 
  NOTE_D5 , 4, NOTE_E5, 16, NOTE_F5, 16,
  NOTE_F5 , 4, NOTE_F5, 8, 
  NOTE_E5 , -4,
  NOTE_D5 , 4, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4 , 4, NOTE_A4, 8,
  NOTE_A4, 8, NOTE_C5, 8, NOTE_B4, 8,
  NOTE_A4 , -4,
  NOTE_CS5 , -4,

  NOTE_D5 , 4, NOTE_E5, 16, NOTE_F5, 16, //72
  NOTE_F5 , 4, NOTE_F5, 8,
  NOTE_F5 , -4,
  NOTE_DS5 , 4, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_AS4 , 4, NOTE_A4, 8,
  NOTE_GS4 , 4, NOTE_G4, 8,
  NOTE_A4 , -4,
  NOTE_B4 , 4, REST, 8,
  NOTE_A3, -32, NOTE_C4, -32, NOTE_E4, -32, NOTE_A4, -32, NOTE_C5, -32, NOTE_E5, -32, NOTE_D5, -32, NOTE_C5, -32, NOTE_B4, -32,

  NOTE_A4, -32, NOTE_C5, -32, NOTE_E5, -32, NOTE_A5, -32, NOTE_C6, -32, NOTE_E6, -32, NOTE_D6, -32, NOTE_C6, -32, NOTE_B5, -32, //80
  NOTE_A4, -32, NOTE_C5, -32, NOTE_E5, -32, NOTE_A5, -32, NOTE_C6, -32, NOTE_E6, -32, NOTE_D6, -32, NOTE_C6, -32, NOTE_B5, -32,
  NOTE_AS5, -32, NOTE_A5, -32, NOTE_GS5, -32, NOTE_G5, -32, NOTE_FS5, -32, NOTE_F5, -32, NOTE_E5, -32, NOTE_DS5, -32, NOTE_D5, -32,

  NOTE_CS5, -32, NOTE_C5, -32, NOTE_B4, -32, NOTE_AS4, -32, NOTE_A4, -32, NOTE_GS4, -32, NOTE_G4, -32, NOTE_FS4, -32, NOTE_F4, -32, //84
  NOTE_E4, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,

  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16, //88
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16, 
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4, -8, REST, -8,
  REST, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16,
  NOTE_D5 , 4, REST, 8,
  REST, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16,
  
  NOTE_B4, -8, NOTE_E4, 16, NOTE_E5, 8, //96
  NOTE_E5, 8, NOTE_E6, -8, NOTE_DS5, 16,
  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,

  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16, //102
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4 , -4,
  };

  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
    int wholenote = (60000 * 4) / tempo;
    int divider, noteDuration;

    for (int thisNote = 0; thisNote < notes * 2; thisNote += 2) {
      divider = melody[thisNote + 1];
      if (divider > 0) {
        noteDuration = (wholenote) / divider;
      } else {
        noteDuration = (wholenote) / abs(divider) * 1.5;
      }
      playTone(melody[thisNote], noteDuration * 0.9);
      delay(noteDuration);
      noTone(buzzer);
    }
}

void soundtracks::marcha_imperial(void) {
    tone(buzzer, LA3_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, LA3_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, LA3_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, F3_NOTE, E + S);
    delay(1 + E + S);
    tone(buzzer, C4_NOTE, S);
    delay(1 + S);

    tone(buzzer, LA3_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, F3_NOTE, E + S);
    delay(1 + E + S);
    tone(buzzer, C4_NOTE, S);
    delay(1 + S);
    tone(buzzer, LA3_NOTE, H);
    delay(1 + H);

    tone(buzzer, E4_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, E4_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, E4_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, F4_NOTE, E + S);
    delay(1 + E + S);
    tone(buzzer, C4_NOTE, S);
    delay(1 + S);

    tone(buzzer, Ab3_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, F3_NOTE, E + S);
    delay(1 + E + S);
    tone(buzzer, C4_NOTE, S);
    delay(1 + S);
    tone(buzzer, LA3_NOTE, H);
    delay(1 + H);

    tone(buzzer, LA4_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, LA3_NOTE, E + S);
    delay(1 + E + S);
    tone(buzzer, LA3_NOTE, S);
    delay(1 + S);
    tone(buzzer, LA4_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, Ab4_NOTE, E + S);
    delay(1 + E + S);
    tone(buzzer, G4_NOTE, S);
    delay(1 + S);

    tone(buzzer, Gb4_NOTE, S);
    delay(1 + S);
    tone(buzzer, E4_NOTE, S);
    delay(1 + S);
    tone(buzzer, F4_NOTE, E);
    delay(1 + E);
    delay(1 + E); // PAUSE
    tone(buzzer, Bb3_NOTE, E);
    delay(1 + E);
    tone(buzzer, Eb4_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, D4_NOTE, E + S);
    delay(1 + E + S);
    tone(buzzer, Db4_NOTE, S);
    delay(1 + S);

    tone(buzzer, C4_NOTE, S);
    delay(1 + S);
    tone(buzzer, B3_NOTE, S);
    delay(1 + S);
    tone(buzzer, C4_NOTE, E);
    delay(1 + E);
    delay(1 + E); // PAUSE QUASI FINE RIGA
    tone(buzzer, F3_NOTE, E);
    delay(1 + E);
    tone(buzzer, Ab3_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, F3_NOTE, E + S);
    delay(1 + E + S);
    tone(buzzer, C4_NOTE, S);
    delay(1 + S);

    tone(buzzer, LA3_NOTE, Q);
    delay(1 + Q);
    tone(buzzer, F3_NOTE, E + S);
    delay(1 + E + S);
    tone(buzzer, C4_NOTE, S);
    delay(1 + S);
    tone(buzzer, LA3_NOTE, H);
    delay(1 + H);

    delay(2 * H);
}

void soundtracks ::move(void){
  // Primer tono
  tone(buzzer, 500, 80); // Frecuencia de 500 Hz, duración de 80 ms
  delay(80);             // Pausa de 80 ms

  // Segundo tono, un poco más agudo
  tone(buzzer, 600, 60); // Frecuencia de 600 Hz, duración de 60 ms
  delay(60);             // Pausa de 60 ms
}

void soundtracks::death_sound(void) {
    tone(buzzer, E5_NOTE, 100); // Nota E5
    delay(150); // Espera
    tone(buzzer, E5_NOTE, 100); // Nota E5 repetida
    delay(150); // Espera
    tone(buzzer, E5_NOTE, 100); // Nota E5 repetida
    delay(150); // Espera

    tone(buzzer, C5_NOTE, 100); // Cambio a C5
    delay(150); // Espera

    tone(buzzer, E5_NOTE, 100); // Vuelta a E5
    delay(150); // Espera

    tone(buzzer, G5_NOTE, 100); // Nota G5
    delay(150); // Espera
    tone(buzzer, G4_NOTE, 100); // Nota G4, descenso en tono
    delay(150); // Espera

    // Sección final del sonido de muerte
    tone(buzzer, C5_NOTE, 400); // Nota C5 larga
    delay(450); // Espera
    tone(buzzer, G4_NOTE, 400); // Nota G4 larga
    delay(450); // Espera
    tone(buzzer, E4_NOTE, 400); // Nota E4 larga
    delay(450); // Espera
    tone(buzzer, A4_NOTE, 300); // Nota A4
    delay(350); // Espera
    tone(buzzer, B4_NOTE, 300); // Nota B4
    delay(350); // Espera
    tone(buzzer, Bb4_NOTE, 200); // Nota Bb4
    delay(250); // Espera
    tone(buzzer, A4_NOTE, 300); // Nota A4
    delay(350); // Espera

    tone(buzzer, G4_NOTE, 200); // Nota G4
    delay(250); // Espera
    tone(buzzer, F4_NOTE, 200); // Nota F4
    delay(250); // Espera
    tone(buzzer, E4_NOTE, 200); // Nota E4
    delay(250); // Espera
    tone(buzzer, G4_NOTE, 200); // Nota G4
    delay(250); // Espera
    tone(buzzer, A4_NOTE, 200); // Nota A4
    delay(250); // Espera
    tone(buzzer, F4_NOTE, 400); // Nota F4 larga
    delay(450); // Espera
    tone(buzzer, G4_NOTE, 400); // Nota G4 larga
    delay(450); // Espera
    tone(buzzer, E4_NOTE, 400); // Nota E4 larga
    delay(450); // Espera
}

