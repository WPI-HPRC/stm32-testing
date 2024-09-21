#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

File dataFile;
char *data = "abcdefg";

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  delay(1000);
  if (!SD.begin(D7)) {
    Serial.println("SD init fail");
  } else {
    Serial.println("SD init suceeded");
  }
  // NOTE: SD.h limits file names to 8 characters
  dataFile = SD.open("aaaaaaaaa", FILE_WRITE);
  if (dataFile) {
    Serial.println("file opened successfully");
  } else {
    Serial.println("File open failed");
  }
  Serial.println(dataFile.name());
}

void loop() {
  Serial.println(data);
  Serial.println(millis());
  dataFile.write(data, strlen(data));
  dataFile.flush();
  delay(1000);
}
