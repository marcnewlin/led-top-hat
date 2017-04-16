#ifndef RAINBOW_MODE_H
#define RAINBOW_MODE_H

#include "mode.h"
#include "sprites/rectangle_sprite.h"
#include "sprites/sparkle_sprite.h"

class rainbow_mode
{
public:

  // Constructor
  rainbow_mode(int rect_count, int rect_size);

  // Destructor
  ~rainbow_mode();

  // Advance one frame of animation
  virtual void advance();

  // Reset the state
  virtual void reset();

private:

  // Rectangle sprites
  rectangle_sprite ** m_rects;

  // Sparkle sprite
  sparkle_sprite * m_sparkle;

  // Rectangle count
  int m_rect_count;

  // Rectangle size
  int m_rect_size;

  // X step
  int m_step_x;

  // Y step
  int m_step_y;
};

#endif // RAINBOW_MODE_H
