
#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

#include "Com_Handler.h"
#include "MQTT.h"

#pragma once
class MQTT_Handler : private Com_Handler
{
public:
	MQTT_Handler();
	~MQTT_Handler();
};

#endif
