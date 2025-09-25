// watering_logic.c
#include <stdio.h>
#include <time.h>
#include "watering.h"
#include "actuators.h"

static time_t last_watering_time = 0;

void watering_logic(SystemConfig *config, SensorData *data) {
    time_t now = time(NULL);

    if (config->mode == MODE_AUTO) {
        if (data->soil_moisture < config->min_moisture) {
            if (difftime(now, last_watering_time) > config->sensor_check_interval) {
                printf("[LOGIC] Moisture too low. Starting pump.\n");
                turn_pump_on();
                sleep(2);
                turn_pump_off();
                last_watering_time = now;
            } else {
                set_led_state(LED_LOW_MOISTURE_ALERT);
            }
        }

        else if (data->soil_moisture > config->max_moisture){
           printf("Moisture too high (%d%%).PUMP OFF.\n",data->soil_moisture);
           turn_pump_off();
           set_led_state(LED_ERROR); 
        }

        else {
            set_led_state(LED_NORMAL);            
        }
    }
}

