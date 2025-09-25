#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

typedef enum {MODE_AUTO, MODE_MANUAL } SystemMode;
typedef enum { PUMP_OFF, PUMP_ON } PumpState;
typedef enum {LED_NORMAL, LED_WATERING, LED_LOW_MOISTURE_ALERT,LED_ERROR } LedState;


typedef struct{
   uint8_t soil_moisture;
   uint8_t temperature; 
} SensorData;


typedef struct{
    uint8_t min_moisture;
    uint8_t max_moisture;
    uint16_t max_watering_time;
    uint16_t sensor_check_interval;
    SystemMode mode;
} SystemConfig;

#endif 
