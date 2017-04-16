#include "mario_sprite.h"

// Off
#define O CRGB(0, 0, 0),

// Red
#define R CRGB(200, 0, 0),

// Green
#define G CRGB(0, 200 0),

// Blue
#define B CRGB(0, 0, 200),

// Black
#define K CRGB(20, 20, 20),

// Brown
#define N CRGB(80, 20, 10),

// Yellow
#define Y CRGB(80, 70, 0),

const CRGB mario_standing[16][12] =
{
  { O O O O R R R R R O O O },
  { O R R R R R R R R R O O },
  { O O O Y K Y Y N N N O O },
  { O Y Y Y K Y Y Y N Y N O },
  { Y Y Y K Y Y Y N N Y N O },
  { O K K K K Y Y Y Y N N O },
  { O O Y Y Y Y Y Y Y O O O },
  { O O O O N N N R N N O O },
  { O N N N R N N R N N N O },
  { N N N N R R R R N N N N },
  { Y Y N R Y R R Y R N Y Y },
  { Y Y Y R R R R R R Y Y Y },
  { Y Y R R R R R R R R Y Y },
  { O O R R R O O R R R O O },
  { O N N N O O O O N N N O },
  { N N N N O O O O N N N N },
};

const CRGB mario_running1[16][12] =
{
  { O O O O O O O O O O O O },
  { O O O O R R R R R O O O },
  { O R R R R R R R R R O O },
  { O O O Y K Y Y N N N O O },
  { O Y Y Y K Y Y Y N Y N O },
  { Y Y Y K Y Y Y N N Y N O },
  { O K K K K Y Y Y Y N N O },
  { O O Y Y Y Y Y Y Y O O O },
  { O O O O N N R N N N O O },
  { O O O N N R R N N N N O },
  { O O O R R Y R R N N N O },
  { O O O R R R R N N N N O },
  { O O O R R R Y Y N N R O },
  { O O O O R R Y Y N R O O },
  { O O O N N N R R R O O O },
  { O O O O O N N N N O O O },
};

const CRGB mario_running2[16][12] =
{
  { O O O O R R R R R O O O },
  { O R R R R R R R R R O O },
  { O O O Y K Y Y N N N O O },
  { O Y Y Y K Y Y Y N Y N O },
  { Y Y Y K Y Y Y N N Y N O },
  { O K K K K Y Y Y Y N N O },
  { O O Y Y Y Y Y Y Y O O O },
  { O O O N R R N N O O O O },
  { O Y Y N R N N N N O O O },
  { Y Y Y N N N N N N Y Y O },
  { O Y Y N N N N N R Y Y Y },
  { O O R R R R R R R N N O },
  { O O R R R R R R R R N O },
  { O O O R R R O O R R N N },
  { O O O O N N N O O O O N },
  { O O O N N N O O O O O O },
};

const CRGB mario_running3[16][16] =
{
  { O O O O O O R R R R R O O O O O },
  { O O O R R R R R R R R R O O O O },
  { O O O O O Y K Y Y N N N O O O O },
  { O O O Y Y Y K Y Y Y N Y N O O O },
  { O O Y Y Y K Y Y Y N N Y N O O O },
  { O O O K K K K Y Y Y Y N N O O O },
  { O O O O Y Y Y Y Y Y Y O O O O O },
  { O O O O O R N N N R N N N N O O },
  { Y Y Y N R N N N R R N N N N Y Y },
  { Y Y N N R R R R R R N N O Y Y Y },
  { O N O O Y R R R Y R R R O O Y Y },
  { O N N R R R R R R R R R R O O O },
  { O N N R R R R R R R R R R R O O },
  { O N N R R R O O O O R R R N N O },
  { O O O O O O O O O O O O N N N O },
  { O O O O O O O O O O O N N N O O },
};

#undef O
#undef R
#undef G
#undef B
#undef K
#undef N
#undef Y

// Constructor
mario_sprite::mario_sprite() :
  sprite(16, 16),
  state(standing)
{

}

// Paint the sprite
void mario_sprite::paint()
{
  switch(state)
  {
    case standing:
    {
      for(int x = 0; x < 12; x++)
        for(int y = 0; y < 16; y++)
          set_sprite_pixel(x, y, mario_standing[y][x]);
      break;
    }

    case running1:
    {
      for(int x = 0; x < 12; x++)
        for(int y = 0; y < 16; y++)
          set_sprite_pixel(x, y, mario_running1[y][x]);
      break;
    }

    case running2:
    {
      for(int x = 0; x < 12; x++)
        for(int y = 0; y < 16; y++)
          set_sprite_pixel(x, y, mario_running2[y][x]);
      break;
    }

    case running3:
    {
      for(int x = 0; x < 12; x++)
        for(int y = 0; y < 16; y++)
          set_sprite_pixel(x, y, mario_running1[y][x]);
      break;
    }

    case running4:
    {
      for(int x = 0; x < 16; x++)
        for(int y = 0; y < 16; y++)
          set_sprite_pixel(x, y, mario_running3[y][x]);
      break;
    }

  }
}
