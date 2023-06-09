#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const int8_t Xaxis  = A0;
const int8_t Yaxis  = A1;

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

struct {
  uint16_t x_;
  uint16_t y_;
} msg;


void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  msg.x_ = analogRead(Xaxis);
  msg.y_ = analogRead(Yaxis);
  radio.write(&msg, sizeof(msg));
    Serial.println("Send: (" + String(msg.x_) + ", " + String(msg.y_) + ")");
}
