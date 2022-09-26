#include <ArduinoJson.h>
#include <stdio.h>

#include <ArduinoJson/Serialization/CountingDecorator.hpp>


class Base64 :public Dynamic {

  virtual size_t writeJson(Dynamic::WriteFunc writer){
    char data[] = "test";
    writer(data,4);
    return 4;
  }
};



int main() {
  char output[1280];
  output[0] = '\0';
  DynamicJsonDocument doc(1024);
  doc["sensor"] = "gps";
  doc["image"] = Base64();

  //serializeJson(doc, output);

  printf("%s\n ", output);
  return 0;
}
