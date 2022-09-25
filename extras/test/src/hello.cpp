#include <ArduinoJson.h>
#include <stdio.h>

class Dynamic {
  template <class T>
  virtual size_t writeTo(T writer) = 0;
};



int main() {
  char output[1280];
  output[0] = '\0';
  DynamicJsonDocument doc(1024);
  doc["sensor"] = "gps";
  doc["image"] = Dynamic();

  //serializeJson(doc, output);

  printf("%s\n ", output);
  return 0;
}
