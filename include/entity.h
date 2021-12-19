#ifndef ENTITY_H
#define ENTITY_H

/**
 * The Entity class wraps a list of sprites that define a single independent
 * 'entity' put into a game. Particle effects, a group of characters, etc...
 * all need to be defined as a single entity consisting of various parts.
 **/

#include "sprite.h"
#include "setup.h"

class Entity
{
public:
  Entity(SPRITES p_sprites);
  Entity(SPRITE p_sprite);

  void addSprite(SPRITE p_sprite);

  SPRITE getSprite(SPRITE p_sprite);
  SPRITES getSprites();

private:
  // Where it stores all its defining elements
  SPRITES sprites;
};

#endif // ENTITY_H