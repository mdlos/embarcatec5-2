#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/time.h"

#define led_azul 12
#define led_vermelho 13
#define led_verde 11
#define botao 5

typedef enum {
    estado_desligado,
    estado_todos_ligados,
    estado_dois_ligados,
    estado_um_ligado
} estado_led;

static estado_led estado_atual = estado_desligado;
static bool timer_ativo = false;
static absolute_time_t ultimo_tempo_botao;

int64_t callback_alarme(alarm_id_t id, void *user_data);

void desligar_leds_callback() {
    switch (estado_atual) {
        case estado_todos_ligados:
            gpio_put(led_azul, 0);
            estado_atual = estado_dois_ligados;
            add_alarm_in_ms(3000, callback_alarme, NULL, false);
            break;
        case estado_dois_ligados:
            gpio_put(led_vermelho, 0);
            estado_atual = estado_um_ligado;
            add_alarm_in_ms(3000, callback_alarme, NULL, false);
            break;
        case estado_um_ligado:
            gpio_put(led_verde, 0);
            estado_atual = estado_desligado;
            timer_ativo = false;
            break;
        default:
            break;
    }
}

int64_t callback_alarme(alarm_id_t id, void *user_data) {
    desligar_leds_callback();
    return 0;
}

void verificar_botao() {
    absolute_time_t agora = get_absolute_time();
    if (absolute_time_diff_us(ultimo_tempo_botao, agora) < 200000) {
        return;
    }
    ultimo_tempo_botao = agora;

    if (!gpio_get(botao) && !timer_ativo) {
        gpio_put(led_azul, 1);
        gpio_put(led_vermelho, 1);
        gpio_put(led_verde, 1);
        estado_atual = estado_todos_ligados;
        timer_ativo = true;
        add_alarm_in_ms(3000, callback_alarme, NULL, false);
    }
}

int main() {
    stdio_init_all();

    gpio_init(led_azul);
    gpio_init(led_vermelho);
    gpio_init(led_verde);
    gpio_init(botao);

    gpio_set_dir(led_azul, GPIO_OUT);
    gpio_set_dir(led_vermelho, GPIO_OUT);
    gpio_set_dir(led_verde, GPIO_OUT);
    gpio_set_dir(botao, GPIO_IN);

    gpio_pull_up(botao);
    ultimo_tempo_botao = get_absolute_time();

    while (1) {
        verificar_botao();
        sleep_ms(10);
    }
    return 0;
}
