// actuators.h
#ifndef ACTUATORS_H
#define ACTUATORS_H

#include "config.h"

void actuators_init(void);
void turn_pump_on(void);
void turn_pump_off(void);
void set_led_state(LedState state);

#endif

