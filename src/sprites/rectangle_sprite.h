#include "sprite.h"

class rectangle_sprite : public sprite
{
public:

  // Parameterless Constructor
  rectangle_sprite();

  // Constructor
  rectangle_sprite(int width, int height, CRGB color, bool filled=false);

  // Paint the sprite
  virtual void paint();

  // Set the rectangle color
  void set_color(CRGB color);

private:

  // Color
  CRGB m_color;

  // filled
  bool m_filled;
};
