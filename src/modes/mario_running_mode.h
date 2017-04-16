#ifndef MARIO_RUNNING_MODE_H
#define MARIO_RUNNING_MODE_H

#include "mode.h"
#include "sprites/mario_sprite.h"

class mario_running_mode
{
public:

  // Constructor
  mario_running_mode();

  // Destructor
  ~mario_running_mode();

  // Advance one frame of animation
  virtual void advance();

  // Reset the state
  virtual void reset();

private:

  // Mario sprite
  mario_sprite * m_mario;
};

#endif // MARIO_RUNNING_MODE_H
