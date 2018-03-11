#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Action_Handler.h"
#include "Artnet_Handler.h"


Action_Handler ActionHandler;
Artnet_Handler ArtnetHandler;

MQTT_Handler MQTTHandler


void setup()
{
	ActionHandler.configure();
	ArtnetHandler.configure();
	MQTTHandler.configure();
}

void loop()
{
	ActionHandler.loop();
}
