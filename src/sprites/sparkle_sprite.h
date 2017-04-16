#include "sprite.h"

class sparkle_sprite : public sprite
{
public:

  // Constructor
  sparkle_sprite(int count=3, int min=5, int max=100);

  // Paint the sprite
  virtual void paint();

private:

  // Number of LEDs on at a time
  int m_count;

  // Minimum brightness
  int m_min;

  // Maximum brightness
  int m_max;
};
