#include "sparkle_sprite.h"

// Constructor
sparkle_sprite::sparkle_sprite(int count, int min, int max) :
  sprite(MATRIX_WIDTH, MATRIX_HEIGHT),
  m_count(count),
  m_min(min),
  m_max(max)
{

}

// Paint the sprite
void sparkle_sprite::paint()
{
  for(int i = 0; i < m_count; i++)
  {
    int intensity = random(m_min, m_max);
    set_pixel(random(0, MATRIX_WIDTH), random(0, MATRIX_HEIGHT), CRGB(intensity, intensity, intensity));
  }
}
