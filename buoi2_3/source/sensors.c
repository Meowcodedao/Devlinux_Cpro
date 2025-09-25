// sensors.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sensors.h"

static int test_values[] = {20, 50, 90};
static int idx = 0;

void sensors_init(void) {
    printf("[SENSORS] Init complete.\n");
}

SensorData sensors_read(void) {
    SensorData data;

    // Lấy giá trị test theo index
    data.soil_moisture = test_values[idx];
    data.temperature = 25;

    printf("[SENSORS] Soil Moisture: %d%%, Temp: %dC\n",
           data.soil_moisture, data.temperature);

    // Tăng index để lần sau trả về case tiếp theo
    idx = (idx + 1) % (sizeof(test_values) / sizeof(test_values[0]));

    return data;
}
