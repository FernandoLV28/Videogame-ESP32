#ifndef SONG_H
#define SONG_H

#define buzzer 16

// MARCHA IMPERIAL
#define C0_NOTE 16.35
#define Db0_NOTE 17.32
#define D0_NOTE 18.35
#define Eb0_NOTE 19.45
#define E0_NOTE 20.60
#define F0_NOTE 21.83
#define Gb0_NOTE 23.12
#define G0_NOTE 24.50
#define Ab0_NOTE 25.96
#define LA0_NOTE 27.50
#define Bb0_NOTE 29.14
#define B0_NOTE 30.87
#define C1_NOTE 32.70
#define Db1_NOTE 34.65
#define D1_NOTE 36.71
#define Eb1_NOTE 38.89
#define E1_NOTE 41.20
#define F1_NOTE 43.65
#define Gb1_NOTE 46.25
#define G1_NOTE 49.00
#define Ab1_NOTE 51.91
#define LA1_NOTE 55.00
#define Bb1_NOTE 58.27
#define B1_NOTE 61.74
#define C2_NOTE 65.41
#define Db2_NOTE 69.30
#define D2_NOTE 73.42
#define Eb2_NOTE 77.78
#define E2_NOTE 82.41
#define F2_NOTE 87.31
#define Gb2_NOTE 92.50
#define G2_NOTE 98.00
#define Ab2_NOTE 103.83
#define LA2_NOTE 110.00
#define Bb2_NOTE 116.54
#define B2_NOTE 123.47
#define C3_NOTE 130.81
#define Db3_NOTE 138.59
#define D3_NOTE 146.83
#define Eb3_NOTE 155.56
#define E3_NOTE 164.81
#define F3_NOTE 174.61
#define Gb3_NOTE 185.00
#define G3_NOTE 196.00
#define Ab3_NOTE 207.65
#define LA3_NOTE 220.00
#define Bb3_NOTE 233.08
#define B3_NOTE 246.94
#define C4_NOTE 261.63
#define Db4_NOTE 277.18
#define D4_NOTE 293.66
#define Eb4_NOTE 311.13
#define E4_NOTE 329.63
#define F4_NOTE 349.23
#define Gb4_NOTE 369.99
#define G4_NOTE 392.00
#define Ab4_NOTE 415.30
#define LA4_NOTE 440.00
#define Bb4_NOTE 466.16
#define B4_NOTE 493.88
#define C5_NOTE 523.25
#define Db5_NOTE 554.37
#define D5_NOTE 587.33
#define Eb5_NOTE 622.25
#define E5_NOTE 659.26
#define F5_NOTE 698.46
#define Gb5_NOTE 739.99
#define G5_NOTE 783.99
#define Ab5_NOTE 830.61
#define LA5_NOTE 880.00
#define Bb5_NOTE 932.33
#define B5_NOTE 987.77
#define C6_NOTE 1046.50
#define Db6_NOTE 1108.73
#define D6_NOTE 1174.66
#define Eb6_NOTE 1244.51
#define E6_NOTE 1318.51
#define F6_NOTE 1396.91
#define Gb6_NOTE 1479.98
#define G6_NOTE 1567.98
#define Ab6_NOTE 1661.22
#define LA6_NOTE 1760.00
#define Bb6_NOTE 1864.66
#define B6_NOTE 1975.53
#define C7_NOTE 2093.00
#define Db7_NOTE 2217.46
#define D7_NOTE 2349.32
#define Eb7_NOTE 2489.02
#define E7_NOTE 2637.02
#define F7_NOTE 2793.83
#define Gb7_NOTE 2959.96
#define G7_NOTE 3135.96
#define Ab7_NOTE 3322.44
#define LA7_NOTE 3520.01
#define Bb7_NOTE 3729.31
#define B7_NOTE 3951.07
#define C8_NOTE 4186.01
#define Db8_NOTE 4434.92
#define D8_NOTE 4698.64
#define Eb8_NOTE 4978.03

#define E5_NOTE 659.26  // Nota E5
#define C5_NOTE 523.25  // Nota C5
#define G5_NOTE 784.00  // Nota G5
#define G4_NOTE 392.00  // Nota G4
#define E4_NOTE 329.63  // Nota E4
#define A4_NOTE 440.00  // Nota A4
#define B4_NOTE 493.88  // Nota B4
#define Bb4_NOTE 466.16 // Nota Bb4
#define F4_NOTE 349.23  // Nota F4


// DURATION OF THE NOTES
#define BPM 120    //  you can change this value changing all the others
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4

// Definiciones de las duraciones de las notas en milisegundos
#define DOUBLE_W 1400  // Blanca doble
#define DOUBLE_N 700   // Negra doble
#define DOUBLE_C 350   // Corchea doble
#define DOUBLE_NS 1050 // Negra con puntillo doble
#define C 450    // Corchea
#define N 900    // Negra
#define B 1800   // Blanca

// Fur elise
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define REST 0

// Definimos el tempo
extern int tempo;

// Clase para las melodías
class soundtracks
{
public:
  void fur_elise(void);
  void marcha_imperial(void);
  void move(void);
  void death_sound(void);
  void playTone(int note, int duration);

  // Puntero a función para melodía actual
  void (soundtracks::*currentMelody)(void);

  // Función genérica para reproducir la melodía actual
  void playCurrentMelody()
  {
    if (currentMelody)
    {
      (this->*currentMelody)(); // Llama a la melodía seleccionada
    }
  }
};

#endif
