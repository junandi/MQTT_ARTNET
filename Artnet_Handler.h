#ifndef ARTNET_HANDLER_H
#define ARTNET_HANDLER_H

#include "Config.h"
#include "Com_Handler.h"
#include "Artnet.h"


class Artnet_Handler : private Com_Handler
{
private:
	
public:
	Artnet artnet;

	Artnet_Handler();
	~Artnet_Handler();

	void configure(char* ssid=SSID , char* password=PASSWORD);
};

#endif