// buttons.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "button.h"
#include "actuators.h"

void buttons_init(void) {
    printf("[BUTTONS] Ready. Press 'a'=toggle auto/manual, 'w'=water manually, 'q'=quit.\n");
}

void handle_buttons(SystemConfig *config) {
    int c = getchar();
    if (c == 'a') {
        config->mode = (config->mode == MODE_AUTO) ? MODE_MANUAL : MODE_AUTO;
        printf("[BUTTON] Mode switched to: %s\n",
               config->mode == MODE_AUTO ? "AUTO" : "MANUAL");
        if (config->mode == MODE_MANUAL) turn_pump_off();
    } else if (c == 'w' && config->mode == MODE_MANUAL) {
        printf("[BUTTON] Manual watering triggered.\n");
        turn_pump_on();
        sleep(2);
        turn_pump_off();
    } else if (c == 'q') {
        printf("[BUTTON] Quit signal detected.\n");
        exit(0);
    }
}

