#include "Action_Handler.h"



Action_Handler::Action_Handler()
{
	
}


Action_Handler::~Action_Handler()
{

}

void Action_Handler::configure()
{
	
}

// ------------------ Functions ------------------

void Action_Handler::GPIO_Handler()
{
	Serial.print("GPIO_Handler");
}

void Action_Handler::DAC_Handler()
{
	Serial.print("DAC_Handler");
}

void Action_Handler::DMX_Handler()
{
	Serial.print("DMX_Handler");
}

void Action_Handler::WS2811_Handler()
{
	Serial.print("WS2811_Handler");
}

void Action_Handler::MQTT_Handler()
{
	Serial.print("MQTT_Handler");
}

// ------------------ Main-Loop ------------------


void Action_Handler::loop()
{
	if (OUT_GPIO_Active)
	{
		GPIO_Handler();
	}
	if (OUT_DAC_Active)
	{
		DAC_Handler();
	}
	if (OUT_DMX_Active)
	{
		DMX_Handler();
	}
	if (OUT_WS2811_Active)
	{
		WS2811_Handler();
	}
	if (OUT_MQTT_Active)
	{
		MQTT_Handler();
	}
}