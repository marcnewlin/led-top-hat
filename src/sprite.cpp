#include "sprite.h"

// Constructor
sprite::sprite(int width, int height, int loc_x, int loc_y) :
  width(width),
  height(height),
  loc_x(loc_x),
  loc_y(loc_y)
{

}

// Draw a line through two points
void sprite::draw_line(float x1, float y1, float x2, float y2, CRGB color)
{
  float slope = (y2-y1) / (x2-x1);
  for(int x = x1; x <= x2; x++)
  {
    int y = slope * (float)x + y1;
    set_sprite_pixel(x, y, color);
  }
}

// Set a pixel within the sprite's coordinate space
void sprite::set_sprite_pixel(int x, int y, CRGB color)
{
  // Make sure this pixel is within the sprite boundaries
  if(y < 0 || y > height) return;
  while(x < 0) x += MATRIX_WIDTH;
  while(x >= MATRIX_WIDTH) x -= MATRIX_WIDTH;

  // Get the absolute matrix coordinates
  int matrix_x = (x + loc_x) % MATRIX_WIDTH;
  int matrix_y = y + loc_y;

  // Make sure this pixel is within the matrix boundaries
  // if(matrix_x >= MATRIX_WIDTH || matrix_y >= MATRIX_HEIGHT) return;
  if(matrix_x < 0 || matrix_y < 0) return;
  if(matrix_x >= MATRIX_WIDTH || matrix_y >= MATRIX_HEIGHT) return;

  // Set the pixel in the matrix buffer
  set_pixel(matrix_x, matrix_y, color);
}
