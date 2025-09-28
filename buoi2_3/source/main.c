#include <stdio.h>
#include <unistd.h>
#include "config.h"
#include "sensors.h"
#include "actuators.h"
#include "button.h"
#include "watering.h"

int main() {
    SystemConfig config = {
        .min_moisture = 30,
        .max_moisture = 70,
        .max_watering_time = 10,
        .sensor_check_interval = 5,
        .mode = MODE_AUTO
    };

    sensors_init();
    actuators_init();
    buttons_init();

    while (1) {
        SensorData data = sensors_read();       
        handle_buttons(&config);                
        watering_logic(&config, &data);         
        sleep(1);                               
    }

    return 0;
}

