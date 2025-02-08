#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/pwm.h"

/*
* Desenvolvedor: Marco Túlio Macêdo Oliveira dos Santos
*/

#define PWM_SRV_MTR 22 // Pino que conecta o servomotor à GPIO como PWM
// Possível alterar para o o Pino 13 caso queira testar com o LED Vermelho (Alterações de intensidade suaves)

// Considerando a frequência de clock padrão (125 MHz):
// fPWM = (125 x 10^6) / (DIVISER x WRAP + 1) -> aproximadamente 50Hz
const uint16_t WRAP = 25000;
const float DIVISER = 100;

// Variáveis para controle da angulação do braço do servomotor
uint16_t flange_angle[3];
float percents[3] = {12, 7.35, 2.5}; // Duty Cycles (%) que geram 180º, 90º e 0º respectivamente

float ACTIVE_CYCLE_INC = 0.025; // Valor do incremento de ciclo ativo (%)

/*
* Função para configuração do módulo PWM
*/
void pwm_setup() {
    gpio_set_function(PWM_SRV_MTR, GPIO_FUNC_PWM); // Habiltando o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_SRV_MTR); // Obtendo um canal PWM pela GPIO

    pwm_set_clkdiv(slice, DIVISER); // Definindo o divisor do clock

    pwm_set_wrap(slice, WRAP); // Definindo o limite do contador interno

    pwm_set_enabled(slice, true); // Habilitando o pwm no slice 
}

int main() {
    stdio_init_all();
    pwm_setup();

    // Alterando a angulação do braço com base nas porcentagens setadas
    for(int i = 0; i < 3; i++) {
        flange_angle[i] = (uint16_t)(WRAP * percents[i] / 100.0); // Calcula o valor do nível
        pwm_set_gpio_level(PWM_SRV_MTR, flange_angle[i]); // Seta o nível
        sleep_ms(5000); // Aguarda 5 segundos
    }

    uint16_t level = flange_angle[2]; // Setando angulação inicial (0 graus)
    int ctrl = (WRAP * ACTIVE_CYCLE_INC / 100.0); // Declaração e inicialização da variável de controle (incremento e decremento)
    while(true) {
        pwm_set_gpio_level(PWM_SRV_MTR, level); // Define o ângulo da flange
        level += ctrl; // Modificação do nível
        if(level <= flange_angle[2] || level >= flange_angle[0]) ctrl *= -1; // Altera o controle ao chegar nos limites
        sleep_ms(10); // Aguarda 10ms para a próxima alteração. Atraso de ajuste
    }
}