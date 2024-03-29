// Blinks an LED attached to a MCP23XXX pin.
//nouveau git
// ok to include only the one needed
// both included here to make things simple for example
//#include <Adafruit_MCP23X08.h>
#include <Adafruit_MCP23X17.h>

#define LED_PIN 0     // MCP23XXX pin LED is attached to
#define BUTTON_PIN 1

// only used for SPI
#define CS_PIN 4

// uncomment appropriate line
//Adafruit_MCP23X08 mcp;
Adafruit_MCP23X17 mcp;

void setup() {
  Serial.begin(115200);
  //while (!Serial);
  Serial.println("MCP23xxx Blink Test!");

  // uncomment appropriate mcp.begin
  //if (!mcp.begin_I2C()) {
  if (!mcp.begin_SPI(CS_PIN)) {
    Serial.println("Error.");
    while (1);
  }

  // configure pin for output
  mcp.pinMode(LED_PIN, OUTPUT);

  // configure button pin for input with pull up
  mcp.pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.println("Looping...");
}

void loop() {
  /*
  mcp.digitalWrite(LED_PIN, HIGH);
  delay(500);
  mcp.digitalWrite(LED_PIN, LOW);
  delay(500);
*/

    // LOW = pressed, HIGH = not pressed
  mcp.digitalWrite(LED_PIN, !mcp.digitalRead(BUTTON_PIN));
  

}