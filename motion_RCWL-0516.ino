/*
 * RCWL-0516
 * microwave proximity sensor
 *
 * https://www.youtube.com/watch?v=IJoPkKlxFXA
 *
 * pins:
 * 3V3 - 3.3V output (up to 100ma) (uses its own 3.3V regulator)
 * GND - ground
 * OUT - goes high (3.3V) for 2 seconds when motion it detected
 * VIN - 4-28 VDC input
 * CDS - low disables the motion detector
 *       leave disconnected to enable it all the time
 * 
 * cds turns the device off when the room lights are on
 * I have 100Kohm cds (ldr)
 * I used a 10k pullup resistor (one side to 3.3V, the other side to the cds pin)
 * and the cds cell (one side to the cds pin and the other side to gnd)
 * lights off:  motion detector works
 * lights on: motion detector disabled
 */


#define motionPin 4   // D2

int count = 0;
bool isMotion = false;


void setup() {
  // start serial port
  Serial.begin(115200);
  Serial.print(F("\n\n motion test\n\n"));

  pinMode(motionPin, INPUT);
}


void loop() {
  int val = digitalRead(motionPin);
  if (val == HIGH) {
    if (!isMotion) {
      // motion started
      isMotion = true;
      Serial.print(F("motion started "));
      Serial.println(++count);
    }
  }
  else {
    if (isMotion) {
      // motion ended
      isMotion = false;
      Serial.println(F("motion ended"));
    }
  }
  delay(100);
}
