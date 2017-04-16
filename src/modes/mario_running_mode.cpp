#include "mario_running_mode.h"

// Constructor
mario_running_mode::mario_running_mode()
{
  m_mario = new mario_sprite();
  reset();
}

// Destructor
mario_running_mode::~mario_running_mode()
{
  delete[] m_mario;
}

// Advance one frame of animation
void mario_running_mode::advance()
{
  // Clear the matrix buffer
  reset_pixels();

  // Advance the animation
  switch(m_mario->state)
  {
    case running1:
    {
      m_mario->state = running2;
      break;
    }

    case running2:
    {
      m_mario->state = running3;
      break;
    }

    case running3:
    {
      m_mario->state = running4;
      m_mario->loc_x -= 2;
      break;
    }

    case running4:
    {
      m_mario->loc_x += 2;
      m_mario->state = running1;
      break;
    }

    case standing:
    {
      m_mario->state = standing;
      break;
    }
  }

  // Wrap the X axis
  while(m_mario->loc_x < 0) m_mario->loc_x += MATRIX_WIDTH;

  // Paint the sprite
  m_mario->paint();

  // Refresh the matrix
  FastLED.show();

  // Step the location for the next fram e
  m_mario->loc_x -= 4;

  // Wait 70ms (timing could be moved externally too)
  delay(70);
}

// Reset the state
void mario_running_mode::reset()
{
  m_mario->state = running1;
  m_mario->loc_x = 0;
}
