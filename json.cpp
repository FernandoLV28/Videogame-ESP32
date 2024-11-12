#include "json.h"

// Implementación de las funciones
String JSON::createScoreJson(char *playerName, int score) {
  DynamicJsonDocument doc(1024);
  doc["playerName"] = playerName;
  doc["score"] = score;

  String output;
  serializeJson(doc, output);
  Serial.println(output);
  return output;
}

void JSON::readScoreFromJson(const String &jsonStr, int &score, String &playerName) {
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, jsonStr);

  if (!error) {
    playerName = doc["playerName"].as<String>();
    score = doc["score"].as<int>();

    Serial.print("Nombre del jugador: ");
    Serial.println(playerName);
    Serial.print("Puntaje: ");
    Serial.println(score);
  } else {
    Serial.println("Error en la deserialización");
  }
}
