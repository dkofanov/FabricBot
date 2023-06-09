#include <SPI.h> 
#include <nRF24L01.h> 
#include <RF24.h> 
#include <Servo.h> 
#include <FastLED.h> 
 
#define LED_PIN     3 
 
#define S1          5
#define S2          6
#define D1          4
#define D2          7

#define STEERING_SERVO_PIN 2      
 
const int8_t Xaxis  = A0;     
const int8_t Yaxis  = A1;     
uint16_t     X = 0, Y = 0;    
 
 
Servo steer_servo; 
 
#define NUM_LEDS    20 
 
CRGB leds[NUM_LEDS]; 
RF24 radio(9, 10); // CE, CSN 
 
const byte address[6] = "00001"; 
 
struct { 
  uint16_t x_; 
  uint16_t y_; 
} msg; 
 
 
void setup() { 
    Serial.begin(9600); 
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); 
 
    steer_servo.attach(STEERING_SERVO_PIN);       
 
    pinMode(S1, OUTPUT);                    
    pinMode(S2, OUTPUT); 
    pinMode(D1, OUTPUT); 
    pinMode(D2, OUTPUT); 
 
    radio.begin(); 
    radio.openReadingPipe(0, address); 
    radio.setPALevel(RF24_PA_MIN); 
    radio.startListening(); 
} 
 
void loop() { 
    leds[0] = CRGB(255, 0, 255); 
  leds[1] = CRGB(255, 0, 255); 
  leds[2] = CRGB(255, 0, 255); 
    FastLED.show(); 
 
    if (radio.available()) { 
      radio.read(&msg, sizeof(msg)); 
      Serial.println("Recieve: (" + String(msg.x_) + ", " + String(msg.y_) + ")"); 
    } 
 
    X = map(msg.x_, 0, 1023, 150, 30);        
    Y = map(msg.y_, 0, 1023, 450, 60);        
 
    if (X < 50 || X > 130) { 
      if (Y > 300) Y = 400; 
      else if (Y < 210) Y = 110; 
    } 
 
      steer_servo.write(X);
 
    if (Y > 255) { 
        if (X > 130) { 
          analogWrite(S2, map(Y-255, 0, 255, 0, 155));   
        } else { 
          analogWrite(S2, Y - 255); 
        } 
        digitalWrite(D2, LOW); 
    } else { 
        analogWrite(S2, 255 - Y); 
        digitalWrite(D2, HIGH); 
    } 
 
    if (Y > 255) { 
      if (X < 50) { 
        analogWrite(S1, map(Y-255, 0, 255, 0, 155));   
      } else { 
        analogWrite(S1, Y - 255); 
      }  
      digitalWrite(D1, HIGH); 
    } else { 
        analogWrite(S1, 255 - Y); 
        digitalWrite(D1, LOW); 
    } 
}
