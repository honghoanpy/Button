/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/


#ifndef Button_h
#define Button_h
#include "Arduino.h"

// #define LEVEL_HIGH

class Button
{
	public:
		Button(uint8_t pin = 2, bool lvl = LOW);
		void begin();
		bool read();
		bool toggled();
		bool pressed();
		bool pressedHold(uint32_t time);
		bool released();
		bool has_changed();
		uint32_t time_changed();
#ifdef 	LEVEL_HIGH
		const static bool PRESSED = LOW;
		const static bool RELEASED = HIGH;
#else
		const static bool PRESSED = HIGH;
		const static bool RELEASED = LOW;
#endif
	
	private:
		bool     _level_press;
		uint8_t  _pin;
		uint16_t _delay;
		bool     _state;
		bool     _has_changed;
		uint32_t _ignore_until;
		uint32_t _time_changed;
};

#endif
