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
        SensorData data = sensors_read();       // Đọc cảm biến
        handle_buttons(&config);                // Xử lý nút bấm
        watering_logic(&config, &data);         // Áp dụng logic tưới
        sleep(1);                               // Nghỉ 1s
    }

    return 0;
}

