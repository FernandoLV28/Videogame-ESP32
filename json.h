#ifndef JSON_H
#define JSON_H

#include <ArduinoJson.h>

class JSON {
public:
  JSON() {}

  String createScoreJson(char *playerName, int score);  // Declaración
  void readScoreFromJson(const String &jsonStr, int &score, String &playerName);  // Declaración
};

#endif
