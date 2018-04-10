#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[]= "502952a5609943d080f7def462423e02";
char ssid[]= "GRACA";
char pass[]= "19283544HT";

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library
  sensors.begin();
  Blynk.begin(auth, ssid, pass);
}
void loop(void)
{
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("DONE");
  Serial.print("Temperature is: ");
  Serial.print(sensors.getTempCByIndex(0)); 
  delay(1000);
  Blynk.run();
}
