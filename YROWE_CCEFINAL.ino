#include <Adafruit_CircuitPlayground.h>

uint8_t currentPixel = 0;   // Pixel that is lit during cycling
uint32_t chaseColor = 0xFF0000; //color setup for the pixel
bool rightButtonPressed; //setting up the right button variable (this was with taking from the professor's example)
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  //coding so that if the right button is pressed = 1 or not = 0...this is for p5js
  rightButtonPressed = CircuitPlayground.rightButton();
  if (rightButtonPressed) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println();
  //the coding for the chase animation of the neopixels
  if (CircuitPlayground.leftButton()) {
    // BUTTON HELD → ONE-PIXEL CHASE

    // Turn all pixels off
    CircuitPlayground.clearPixels();

    // Light only the current pixel
    CircuitPlayground.setPixelColor(currentPixel, chaseColor);

    // Move to next pixel
    currentPixel = (currentPixel + 1) % 10;

    delay(100);  // speed of chase

  } else {
    // BUTTON RELEASED → HOLD ONE PIXEL

    CircuitPlayground.clearPixels();
    CircuitPlayground.setPixelColor(currentPixel, chaseColor);

    // No movement when button is released
    delay(20);
  }
}