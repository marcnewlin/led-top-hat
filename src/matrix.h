#ifndef MATRIX_H
#define MATRIX_H

#include <FastLED.h>

#define MATRIX_WIDTH 64
#define MATRIX_HEIGHT 16
#define LED_COUNT MATRIX_WIDTH*MATRIX_HEIGHT
#define DATA_PIN  1

// LED buffer
static CRGB leds[LED_COUNT];

// Pixel index to X/Y lookup table
static uint16_t pixel_lookup[MATRIX_WIDTH][MATRIX_HEIGHT];

// Set all pixels to black (off)
void reset_pixels();

// Set the color of a single pixel
void set_pixel(int x, int y, CRGB color);

// Initialize the LED matrix
void setup_leds();

#endif // MATRIX_H
