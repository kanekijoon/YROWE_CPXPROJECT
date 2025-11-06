#include <Adafruit_CircuitPlayground.h>


void setup() {
  //setting up CPX
  CircuitPlayground.begin();
}

void loop() {
  CircuitPlayground.clearPixels();

  //delay(500);

//setting up the code so that if a sensor is touched at a certain pressure, it will play a note (C) and a pixel lights up
  if (CircuitPlayground.readCap(A1) > 500) {
    CircuitPlayground.playTone(262,200);
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    delay(350);

  }
  //setting up the code so that if a sensor is touched at a certain pressure, it will play a note (D) and a pixel lights up
  else if (CircuitPlayground.readCap(A2) > 500) {
    CircuitPlayground.playTone(294,200);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    delay(350);
  }
  //setting up the code so that if a sensor is touched at a certain pressure, it will play a note (E) and a pixel lights up
  else if (CircuitPlayground.readCap(A3) >500) {
    CircuitPlayground.playTone(330, 200);
    CircuitPlayground.setPixelColor(3, 0,0,255);
    delay(350);
  }
  //setting up the code so that if nothing is touched, nothing happens
  else {
    CircuitPlayground.playTone(0,0);
    CircuitPlayground.setPixelColor(1,0,0,0);
    CircuitPlayground.setPixelColor(2,0,0,0);
    CircuitPlayground.setPixelColor(3,0,0,0);
  }
}