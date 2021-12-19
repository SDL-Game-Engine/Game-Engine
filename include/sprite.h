#ifndef SPRITE_H
#define SPRITE_H

/**
 * Defines the basic characteristics of any object rendered to a window.
 * Background image, ground to stand on, characters, NPCs, etc... are all
 * defined by or inherit behavior from this base class. It will be used
 * to represent stationary objects.
 **/

#include <SDL2/SDL.h>
#include <string>

#include "setup.h"

class Sprite
{
public:
  Sprite(SDL_Texture *p_tex, SDL_Rect p_srect, SDL_Rect p_drect);
  SDL_Rect &getSRect();
  SDL_Rect &getDRect();

  void setSRect(SDL_Rect p_srect);
  void setDRect(SDL_Rect p_drect);

  SDL_Texture *getTexture();

  void setMovingUp(int p_flag);
  void setMovingDown(int p_flag);
  void setMovingLeft(int p_flag);
  void setMovingRight(int p_flag);

  void setMovingNone(int p_flag);

  // Displacement method
  void updatePosition();

private:
  // Portion of the source image the texture is generated from
  SDL_Rect srect;

  // Portion of the texture about to be rendered to the screen
  SDL_Rect drect;

  SDL_Texture *texture;

  // Movement flag container
  int movementFlags[MOVING_SIZE];
};

#endif // SPRITE_H