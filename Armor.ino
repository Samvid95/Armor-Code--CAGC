// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            12

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4
#define pressureSensorPin2 A7

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // delay for half a second

int pressureSensorPin = 10;
int pressureSensorPin1 = 9;
//int pressureSensorPin2 = 7;


int sensorValue = 0;
int sensorValue1 = 0;
int sensorValue2 =0;
int onPixels;

void setup() {
  pinMode(pressureSensorPin,INPUT_PULLUP);
  pinMode(pressureSensorPin1,INPUT_PULLUP);
  pinMode(pressureSensorPin2, INPUT_PULLUP);
  onPixels = 4;
  Serial.print("The number of pixels ON are(at Setup) : " + onPixels);
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  sensorValue = analogRead(pressureSensorPin);
  sensorValue1 = analogRead(pressureSensorPin1);
  sensorValue2 = analogRead(pressureSensorPin2);
  
  if(sensorValue < 30 || sensorValue1 < 30 || sensorValue2<30){
    onPixels--; 
    
   }
   for(int i=0; i<onPixels;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
   }
   for(int i=onPixels; i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
   }
  delay(delayval);

  
  delay(delayval);
  
  if(sensorValue1 < 30){
    Serial.print("The sensor1's value is: ");
    Serial.println(sensorValue1);
  }
  
  if(sensorValue2 < 30){
    Serial.print("The sensor2's value is: ");
    Serial.println(sensorValue2);
  }

  if(sensorValue < 30){
    Serial.print("The sensor's value is: ");
    Serial.println(sensorValue);
  }
}
