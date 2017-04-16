#include "mode.h"

#ifndef MARIO_RUNNING_MODE_H
#define MARIO_RUNNING_MODE_H

class mario_running_mode
{
public:

  // Advance one frame of animation
  virtual void advance();

  // Reset the state
  virtual void reset();
};

#endif // MARIO_RUNNING_MODE_H
