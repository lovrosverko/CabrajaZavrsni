// Joystick remote code. Taking the "map" inspiration from Robodude95 (THANKS!)
#include <VirtualWire.h> // include the VirtualWire library
#define Xpin A0 // Let the X axis be defined on analog pin 0
#define Ypin A1 // Let the Y axis be defined on analog pin 1
#define Ypina A2

int joyY =0;
int joyVal;

int X = 0; // Let the value of X pin be an integer, and initially be 0
int Y = 0; // Let the value of Y pin be an integer, and initially be 0
void setup() {
  // put your setup code here, to run once:
  vw_setup(2000); // begin wireless transmission @ 2000 bps
  vw_set_tx_pin(12); // set the digital pin 12 to be the transmit pin
  Serial.begin(9600); // begin serial communication with the arduino @ 9600 baud
}

void loop() {
   joyVal = analogRead(joyY);
  joyVal = map(joyVal,0,1023,0,180);

  X = analogRead(Xpin); // Let the analog read of X axis be stored in the previously defined integer X
  Y = analogRead(Ypin); // Let the analog read of Y axis be stored in a previouslt defined integer named Y
  X = map(X, 0, 1023, 0, 10); // Map the values of X axis from 0 to 1023, to 0 to 10
  Y = map(Y, 0, 1023, 0, 10); // Map the values of Y axis from 0 to 1023, to 0 to 10
  if (X == 5 && Y == 5) { // if the value of X and Y axis is 5
    char *msg = "x"; // store the character 'x' in a char named msg
    digitalWrite(13, true); // light up the d13 LED to show transmission
    vw_send((uint8_t *)msg, strlen(msg)); // send the message 'x' via the transmitter
    vw_wait_tx(); // wait until the whole message is sent
    digitalWrite(13, false); // turn off the D13 LED once the message is sent
    Serial.println("STOPIRANO"); // print "STOPPED" in the serial monitor
  }
  if (X == 0 && Y >= 4) { // if X is equal to zero and Y is more than equal to 4
    char *msg = "w"; // store the message 'w' in a char named msg
    digitalWrite(13, true); // light up the D13 LED to show transmission
    vw_send((uint8_t *)msg, strlen(msg)); // send the message 'w' via the transmitter
    vw_wait_tx(); // wait until the whole message is sent
    digitalWrite(13, false); // turn off the D13 LED to show that message is sent
    Serial.println("NAPRIJED"); // print "GOING FORAWARD" in the serial monitor

  }
  if (X >= 3 && Y == 9) { // if X is more than equal to 3 and Y is equal to 9
    char *msg = "a"; // store the message 'a' in a char named msg
    digitalWrite(13, true); // light up the D13 LED to show transmission
    vw_send((uint8_t *)msg, strlen(msg)); // send the message 'a' via the transmitter
    vw_wait_tx(); //  wait for the message to be sent
    digitalWrite(13, false); // turn off the D13 LED to show that the message is sent
    Serial.println("LIJEVO"); // print "GOING LEFT" in the serial monitor

  }
  if (X == 10 && Y >= 4) { // if X is equal to 10 and Y is more than equal to 4
    char *msg = "s"; // store the message 's' in a char named msg
    digitalWrite(13, true); // light up the D13 LED to show transmission
    vw_send((uint8_t *)msg, strlen(msg)); //  send the message 's' via the transmitter
    vw_wait_tx(); //  wait for the message to be sent
    digitalWrite(13, false); // flash the D13 led off to show that the message is sent
    Serial.println("NAZAD"); // print "GOING BACKWARD" in the serial monitor
  }
  if ( X >= 3 && Y == 0) { // if X is greater than equal to 3 and Y is equal to 0
    char *msg = "d"; // store the message 'd', in a char named msg
    digitalWrite(13, true); // light up the D13 LED to show transmission
    vw_send((uint8_t *)msg, strlen(msg)); // send the message 'd' via the transmitter
    vw_wait_tx(); //wait until the whole message is sent
    digitalWrite(13, false); // turn off the D13 LED to show that message is sent
    Serial.println("DESNO"); // print "GOING RIGHT" in the serial monitor
  }

}
