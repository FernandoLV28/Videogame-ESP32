#include "microsd.h"
#include "json.h" // Asegúrate de que json.h también esté bien estructurado

JSON json; // Instancia de la clase JSON

void MicroSD::init() {
  if (!SD.begin(MICROSD_PIN)) {
    Serial.println("Error al inicializar la microSD");
  } else {
    Serial.println("MicroSD inicializada correctamente");
  }
}

void MicroSD::saveScore(char *playerName, int score) {
  String jsonData = json.createScoreJson(playerName, score);
  File file = SD.open(filename, FILE_APPEND);
  if (file) {
    file.println(jsonData);
    file.close();
  } else {
    Serial.println("Error al abrir el archivo para escribir");
  }
}

void MicroSD::getTopScores(String topScores[], int topN) {
  File file = SD.open(filename, FILE_READ);
  if (!file) {
    topScores[0] = "No hay puntajes";
    return;
  }

  String allScores[100]; 
  int scoreValues[100];
  String playerNames[100];
  int count = 0;

  while (file.available() && count < 100) {
    allScores[count] = file.readStringUntil('\n');
    json.readScoreFromJson(allScores[count], scoreValues[count], playerNames[count]);
    count++;
  }
  file.close();

  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (scoreValues[i] < scoreValues[j]) {
        int tempScore = scoreValues[i];
        scoreValues[i] = scoreValues[j];
        scoreValues[j] = tempScore;
        String tempName = playerNames[i];
        playerNames[i] = playerNames[j];
        playerNames[j] = tempName;
      }
    }
  }

  for (int i = 0; i < topN && i < count; i++) {
    topScores[i] = playerNames[i] + ":" + String(scoreValues[i]);
  }
}

void MicroSD::checkFileContent() {
  File file = SD.open(filename, FILE_READ);
  if (file) {
    while (file.available()) {
      Serial.println(file.readStringUntil('\n'));
    }
    file.close();
  } else {
    Serial.println("Error al abrir el archivo");
  }
}
