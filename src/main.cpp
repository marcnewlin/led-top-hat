#include "matrix.h"

#include "modes/mario_running_mode.h"
#include "modes/rainbow_mode.h"

int main()
{
  // Initialize the matrix
  setup_leds();

  // Cap the brightness at ~40%
  FastLED.setBrightness(100);

  // // Mario Running Animation
  // mario_running_mode * mario = new mario_running_mode();
  // while(true)
  // {
  //   mario->advance();
  // }

  // Sparkling Rainbow Animation
  int rect_count = 32;
  int rect_size = 3;
  rainbow_mode * rainbow = new rainbow_mode(rect_count, rect_size);
  while(true)
  {
    rainbow->advance();
  }
}
