#ifndef MODE_H
#define MODE_H

class mode
{
public:

  // Advance one frame of animation
  virtual void advance();

  // Reset the state
  virtual void reset();
};

#endif // MODE_H
