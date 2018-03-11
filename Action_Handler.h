#include <Arduino.h>

#pragma once
class Action_Handler
{
private:
	bool OUT_GPIO_Active = false;
	bool OUT_DAC_Active = false;
	bool OUT_DMX_Active = false;
	bool OUT_WS2811_Active = false;
	bool OUT_MQTT_Active = false;

	uint16_t GPIO_Universe;
	uint16_t DAC_Universe;
	uint16_t DMX_Universe;
	uint16_t WS2811_Universe;

	void GPIO_Handler();
	void DAC_Handler();
	void DMX_Handler();
	void WS2811_Handler();
	void MQTT_Handler();

public:
	Action_Handler();
	~Action_Handler();

	void configure();
	void loop();
};

