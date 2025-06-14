#include <stdint.h>
#include "timer.h"
#include "interrupt.h"
#include "mem.h"

#define DIV  0xFF04
#define TIMA 0xFF05
#define TMA  0xFF06
#define TAC  0xFF07

static uint32_t ticks;
static uint8_t started;
static uint32_t speed = 1024;
static uint16_t divider;

void timer_reset_div(void)
{
	divider = 0;
}

uint8_t timer_get_div(void)
{
	return (divider >> 8);
}

void timer_set_tac(uint8_t v)
{
	const int speeds[] = {1024, 16, 64, 256};
	// Don't write to memory here - mem_write_byte() handles that
	// This function only sets the timer's internal state
	started = v&4;
	speed = speeds[v&3];
}

void timer_cycle(uint32_t delta)
{
	delta *= 4;
	divider += delta;
	if(started) {
		ticks += delta;
		if(ticks >= speed) {
			//ticks -= speed;
			ticks = 0;
			uint8_t tima_val = mem_get_byte(TIMA) + 1;
			if(tima_val >= 0x100) {
				interrupt(INTR_TIMER);
				mem_write_byte(TIMA, mem_get_byte(TMA));
			} else {
				mem_write_byte(TIMA, tima_val);
			}
		}
	}
}
