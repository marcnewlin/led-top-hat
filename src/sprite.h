#ifndef SPRITE_H
#define SPRITE_H

#include <FastLED.h>

#include "matrix.h"

class sprite
{
public:

  // Constructor
  sprite(int width, int height, int loc_x=0, int loc_y=0);

  // Width
  const int width;

  // Height
  const int height;

  // Coordinates
  int loc_x;
  int loc_y;

  // Paint the sprite onto the matrix
  virtual void paint()=0;

protected:

  // Set a pixel within the sprite's coordinate space
  void set_sprite_pixel(int x, int y, CRGB color);

  // Draw a line through two points
  void draw_line(float x1, float y1, float x2, float y2, CRGB color);

};

#endif // SPRITE_H
