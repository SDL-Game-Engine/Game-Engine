#include "entity.h"

Entity::Entity(SPRITES p_sprites) : sprites(p_sprites) {}

Entity::Entity(SPRITE p_sprite)
{
  sprites.push_back(p_sprite);
}



void Entity::addSprite(SPRITE p_sprite) { sprites.push_back(p_sprite); }

SPRITE Entity::getSprite(SPRITE p_sprite)
{
  for (SPRITE s : sprites)
  {
    if (s == p_sprite)
    {
      return s;
    }
  }

  // NOT FOUND
  return NULL;
}

SPRITES Entity::getSprites() { return sprites; }

