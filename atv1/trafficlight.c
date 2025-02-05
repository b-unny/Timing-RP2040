#include"pico/stdlib.h"
#include"hardware/timer.h"
#include"hardware/pwm.h"
#include<stdio.h>

#define PIN_R 13
#define PIN_G 11
#define BRIGHT 100

volatile int isledon = 0;

const int estados[5][2] = {{0,0},{BRIGHT, 0},{0,0},{BRIGHT,BRIGHT},{0, BRIGHT}};

void init_pins();
void setup_pwm(uint pino, int nivel);
bool callback(repeating_timer_t *time);
void switch_leds();

int main()
{
	gpio_init_all();
	init_pins();

	repeating_timer_t timer;
					
	add_repeating_timer_ms(3000, callback, NULL, &timer);

	while(true)
	{
		printf("Semaforo: ON!");
		sleep_ms(1000);
	}	
}

void init_pins()
{
	gpio_init(PIN_R);
	gpio_init(PIN_G);

	gpio_set_dir(PIN_R, GPIO_OUT);
	gpio_set_dir(PIN_G, GPIO_OUT);

	setup_pwm(PIN_R, 0);
	setup_pwm(PIN_G, 0);
}

bool callback(repeating_timer_t *time)
{
	switch_leds();
	return true;
}

void setup_pwm(uint pino, int nivel)
{
	gpio_set_function(pino, GPIO_FUNC_PWM);
	uint slice = pwm_gpio_to_slice_num(pino);
	pwm_set_wrap(slice, 255);
	pwm_set_chan_level(slice, pwm_pin_to_channel(pino), nivel);
	pwm_set_enabled(slice, true);
}

void switch_leds()
{
	setup_pwm(PIN_R, estados[isledon][0];
	setup_pwm(PIN_G, estados[isledon][1];
	isledon = (isledon+1)%5;
}

// ordem do led: off -> red -> off ->  ylw -> green -> repeat...
