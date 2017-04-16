#include "rainbow_mode.h"

// Constructor
rainbow_mode::rainbow_mode(int rect_count, int rect_size) :
  m_rect_count(rect_count),
  m_rect_size(rect_size),
  m_step_x(1),
  m_step_y(1)
{
  // Initialize the sparkle sprite
  m_sparkle = new sparkle_sprite(10, 5, 150);

  // Initialize the rectangle sprites
  m_rects = new rectangle_sprite * [m_rect_count];
  for(int x = 0; x < m_rect_count; x++)
  {
    m_rects[x] = new rectangle_sprite(
      m_rect_size,
      m_rect_size,
      CHSV(x * 255 / m_rect_count, 255, 255),
      true);
  }

  // Reset the state
  reset();
}

// Destructor
rainbow_mode::~rainbow_mode()
{
  for(int x = 0; x < m_rect_count; x++)
  {
    delete[] m_rects[x];
  }
  delete[] m_rects;
}

// Advance one frame of animation
void rainbow_mode::advance()
{
  // Reset the matrix
  reset_pixels();

  // Move the lead rectangle
  m_rects[0]->loc_x = (m_rects[0]->loc_x + m_step_x);
  m_rects[0]->loc_y = (m_rects[0]->loc_y + m_step_y);

  // Clamp to positive X values
  while(m_rects[0]->loc_x < 0) m_rects[0]->loc_x += MATRIX_WIDTH;

  // Update the tail rectangles to follow the lead rectangle
  for(int x = m_rect_count - 1; x >= 1; x--)
  {
    m_rects[x]->loc_x = m_rects[x-1]->loc_x;
    m_rects[x]->loc_y = m_rects[x-1]->loc_y;
  }

  // Rebound from the top of the matrix
  if(m_rects[0]->loc_y + m_rect_size >= MATRIX_HEIGHT)
  {
    if(random(0, 100) < 10) m_step_y = -2;
    else m_step_y = -1;
  }

  // Rebound from the bottom of the matrix
  else if(m_rects[0]->loc_y <= 0)
  {
    if(random(0, 100) < 10) m_step_y = 2;
    else m_step_y = 1;
  }

  // Periodically randomize the movement
  if(random(0, 100) < 3)
  {
    m_step_x = 0;
    m_step_y = 0;
    while(m_step_x == 0 && m_step_y == 0)
    {
      m_step_x = random(-2, 3);
      m_step_y = random(-2, 3);
    }
  }

  // Paint the sparkle effect
  m_sparkle->paint();

  // Paint the rectangles
  for(int x = 0; x < m_rect_count; x++) m_rects[x]->paint();

  // Refresh the matrix
  FastLED.show();
}

// Reset the state
void rainbow_mode::reset()
{
  for(int x = 0; x < m_rect_count; x++)
  {
    m_rects[x]->loc_x = 0;
    m_rects[x]->loc_y = 0;
  }
}
