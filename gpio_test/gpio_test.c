#include <stdio.h>
#include "pico/stdlib.h"

int main(){
    setup_default_uart();

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    uint sw_pin=15;

    gpio_init(sw_pin);
    gpio_set_dir(sw_pin, GPIO_IN);

    uint8_t i=0;

    while(1){
        gpio_put(PICO_DEFAULT_LED_PIN, 1);
        sleep_ms(200);
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
        sleep_ms(200);
        printf("%d,%d\n",i++,gpio_get(sw_pin));

    }
}