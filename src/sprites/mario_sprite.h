#include "sprite.h"

// Animation state
enum mario_state
{
  running1,
  running2,
  running3,
  running4,
  standing
};

class mario_sprite : public sprite
{
public:

  // Constructor
  mario_sprite();

  // Paint the sprite
  virtual void paint();

  // State
  mario_state state;

};
