#include "rectangle_sprite.h"

// Parameterless Constructor
rectangle_sprite::rectangle_sprite() : sprite(0, 0) { }

// Constructor
rectangle_sprite::rectangle_sprite(int width, int height, CRGB color, bool filled) :
  sprite(width, height),
  m_color(color),
  m_filled(filled)
{

}

// Paint the sprite
void rectangle_sprite::paint()
{
  // Border only
  if(!m_filled)
  {
    for(uint8_t x = 0; x < width; x++)
    {
      set_sprite_pixel(x, 0, m_color);
      set_sprite_pixel(x, height-1, m_color);
    }

    for(uint8_t y = 0; y < height; y++)
    {
      set_sprite_pixel(0, y, m_color);
      set_sprite_pixel(width-1, y, m_color);
    }
  }

  // Filled rectangle
  else
  {
    for(uint8_t x = 0; x < width; x++)
    {
      for(uint8_t y = 0; y < height; y++)
      {
        set_sprite_pixel(x, y, m_color);
      }
    }
  }
}

// Set the rectangle color
void rectangle_sprite::set_color(CRGB color)
{
  m_color = color;
}
