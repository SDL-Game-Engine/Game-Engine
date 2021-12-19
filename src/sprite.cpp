#include "sprite.h"

Sprite::Sprite(SDL_Texture *p_tex, SDL_Rect p_srect, SDL_Rect p_drect)
    : texture{p_tex}, srect{p_srect}, drect{p_drect} {}

SDL_Rect &Sprite::getSRect() { return srect; }
SDL_Rect &Sprite::getDRect() { return drect; }

SDL_Texture *Sprite::getTexture() { return texture; }

void Sprite::setMovingUp(int p_flag) { movementFlags[MOVING_UP] = p_flag; }
void Sprite::setMovingDown(int p_flag) { movementFlags[MOVING_DOWN] = p_flag; }
void Sprite::setMovingLeft(int p_flag) { movementFlags[MOVING_LEFT] = p_flag; }
void Sprite::setMovingRight(int p_flag) { movementFlags[MOVING_RIGHT] = p_flag; }

void Sprite::setMovingNone(int p_flag) { movementFlags[MOVING_NONE] = p_flag; }

void Sprite::setSRect(SDL_Rect p_srect) { srect = p_srect; }
void Sprite::setDRect(SDL_Rect p_drect) { drect = p_drect; }

void Sprite::updatePosition()
{
  if (movementFlags[MOVING_UP])
  {
    drect.y -= 1;
  }
  else if (movementFlags[MOVING_DOWN])
  {
    drect.y += 1;
  }

  if (movementFlags[MOVING_LEFT])
  {
    drect.x -= 1;
  }
  else if (movementFlags[MOVING_RIGHT])
  {
    drect.x += 1;
  }
}