#include <ArduinoJson.h>
#include <stdio.h>

class Base64 : public DynamicData {
 public:
  Base64(const char* data, size_t size) : data(data), dataSize(size) {}
  Base64() : data(0), dataSize(0) {}

  void encodeTriplet(const char (&input)[3], char (&output)[4]) {
    output[0] = base64_chars[(input[0] & 0xfc) >> 2];
    output[1] =
        base64_chars[((input[0] & 0x03) << 4) + ((input[1] & 0xf0) >> 4)];
    output[2] =
        base64_chars[((input[1] & 0x0f) << 2) + ((input[2] & 0xc0) >> 6)];
    output[3] = base64_chars[input[2] & 0x3f];
  }

  virtual size_t sizeRaw() {
    return strlen(data);
  }

  virtual size_t sizeJson() {
    return 4 * (1 + ((sizeRaw() - 1) / 3));
  }

  virtual void writeJsonTo(DynamicData::WriteJsonFunc writer) {
    uint j = 0;
    char input[3];
    char output[4];

    for (uint i = 0; i < sizeRaw(); ++i) {
      input[j++] = data[i];
      if (j == 3) {
        encodeTriplet(input, output);
        writer(output, 4);
        j = 0;
      }
    }
    if (j != 0) {
      for (uint i = j; i < 3; ++i) {
        input[i] = '\0';
      }
      encodeTriplet(input, output);

      for (uint i = j + 1; i < 4; ++i) {
        output[i] = '=';
      }
      writer(output, 4);
    }
  }

 private:
  const char* data;
  size_t dataSize;
  static const char* base64_chars;
};
const char* Base64::base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";






int main() {
  char output[1280];
  const char binaryData[] =
      "test big data in memory which cand be stored encoded as base64 again "
      "because we must save memory!!";
  size_t size =
      strlen(binaryData);  // only for example (i must know size of binary data)

  DynamicJsonDocument doc(1024);
  doc["sensor"] = "gps";
  doc["binary"] = Base64(binaryData, size);

  serializeJson(doc, output);

  printf("%s\n ", output);
  return 0;
}
