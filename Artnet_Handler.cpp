// doku see:      https://artisticlicence.com/WebSiteMaster/User%20Guides/art-net.pdf
// ArtnetSender:  https://github.com/hobbyquaker/mqtt-dmx-controller
// Artnetmonitor: https://www.lightjams.com/artnetominator/

#include "Artnet_Handler.h"



void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data, IPAddress remoteIP);
void onSync(IPAddress remoteIP);


Artnet_Handler::Artnet_Handler()
{
	
}


Artnet_Handler::~Artnet_Handler()
{

}

// ------------------ Functions ------------------

void Artnet_Handler::configure(char* ssid, char* password)
{//based on https://github.com/natcl/Artnet/blob/master/examples/ESP/ArtnetNeoPixelESPSync/ArtnetNeoPixelESPSync.ino

	Serial.begin(115200);

	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(250);
		Serial.print(".");
	}
	Serial.println("");
	Serial.print("Connected to ");
	Serial.println(ssid);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

	//Serial.begin(115200);
	artnet.begin();
	artnet.setBroadcast(_broadcast);

	// this will be called for each DMX-packet received
	artnet.setArtDmxCallback(onDmxFrame);
	// this will be called for each Sync-packet received
	artnet.setArtSyncCallback(onSync);
}

// ------------------ Callback-Functions ------------------

// get fired on DMX-packet received
void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data, IPAddress remoteIP)
{
	// print out our data
	Serial.print("universe number = ");
	Serial.print(universe);
	//Serial.print(artnet.getUniverse());
	Serial.print("\tdata length = ");
	Serial.print(length);
	//Serial.print(artnet.getLength());
	Serial.print("\tsequence n0. = ");
	Serial.print(sequence);
	//Serial.println(artnet.getSequence());
	Serial.print("DMX data: ");
	Serial.print(*data);
	/*
	for (int i = 0; i < data.getLength(); i++)
	{
		Serial.print(artnet.getDmxFrame()[i]);
		Serial.print("  ");
	}*/
	Serial.print("IPAdress: ");
	Serial.print(remoteIP);
	Serial.println();
	Serial.println();


	/* e.g. 
	// read universe and put into the right part of the display buffer
	for (int i = 0; i < length / 3; i++)
	{
		int led = i + (universe - startUniverse) * (previousDataLength / 3);
		if (led < numLeds)
			leds.setPixelColor(led, data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
	}
	previousDataLength = length;*/
}

// Execute Actions: Executed on Sync-packet received
void onSync(IPAddress remoteIP)
{
	Serial.println("onSync not implemented!");
	//e.g. leds.show();
}
