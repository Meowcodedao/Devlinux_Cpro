// actuators.c
#include <stdio.h>
#include "actuators.h"

static PumpState pump_state = PUMP_OFF; // Trạng thái bơm

void actuators_init(void) {
    pump_state = PUMP_OFF;
    set_led_state(LED_NORMAL);
}

void turn_pump_on(void) {
    pump_state = PUMP_ON;
    printf("[ACTUATOR] Pump ON\n");
    set_led_state(LED_WATERING);
}

void turn_pump_off(void) {
    pump_state = PUMP_OFF;
    printf("[ACTUATOR] Pump OFF\n");
    set_led_state(LED_NORMAL);
}

void set_led_state(LedState state) {
    switch (state) {
        case LED_NORMAL: printf("[LED] Green (Normal)\n"); break;
        case LED_WATERING: printf("[LED] Yellow (Watering)\n"); break;
        case LED_LOW_MOISTURE_ALERT: printf("[LED] Red (Low Moisture)\n"); break;
        case LED_ERROR: printf("[LED] Red (Error)\n"); break;
    }
}

