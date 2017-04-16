#include "matrix.h"

// Set the color of a single pixel
void set_pixel(int x, int y, CRGB color)
{
  leds[pixel_lookup[x][y]] = color;
}

// Set all pixels to black (off)
void reset_pixels()
{
  for(int x = 0; x < LED_COUNT; x++)
  {
    leds[x] = CRGB::Black;
  }
}

// Initialize the LED matrix
void setup_leds()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_COUNT);

  // Starting index on each 8x32 panel
  int index[] = { 255, 256, 512, 1023 };

  // Build the lookup table of X/Y coordinate to pixel index
  for(int x = 0; x < 32; x++)
  {
    if(x % 2 == 0)
    {
      for(int y = 8; y < 16; y++) pixel_lookup[x][y] = index[0]--;
      for(int y = 0; y < 8; y++) pixel_lookup[x][7 - y] = index[1]++;
      for(int y = 0; y < 8; y++) pixel_lookup[x + 32][7 - y] = index[2]++;
      for(int y = 8; y < 16; y++) pixel_lookup[x + 32][y] = index[3]--;
    }
    else
    {
      for(int y = 0; y < 8; y++) pixel_lookup[x][15 - y] = index[0]--;
      for(int y = 0; y < 8; y++) pixel_lookup[x][y] = index[1]++;
      for(int y = 0; y < 8; y++) pixel_lookup[x + 32][y] = index[2]++;
      for(int y = 0; y < 8; y++) pixel_lookup[x + 32][15 - y] = index[3]--;
    }
  }
}
