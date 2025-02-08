#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/pwm.h"

#define PWM_SRV_MTR 22 // Pino que conecta o servomotor à GPIO como PWM
const uint16_t WRAP = 25000;
const float DIVISER = 100;
const uint16_t DUTY_CICLE = 3000;

/*
* Função para configuração do módulo PWM
*/
void pwm_setup() {
    gpio_set_function(PWM_SRV_MTR, GPIO_FUNC_PWM);

    uint slice = pwm_gpio_to_slice_num(PWM_SRV_MTR);

    pwm_set_clkdiv(slice, DIVISER);

    pwm_set_wrap(slice, WRAP);

    pwm_set_gpio_level(PWM_SRV_MTR, DUTY_CICLE);

    pwm_set_enabled(slice, true);
}

int main() {
    stdio_init_all();
    pwm_setup();
}
