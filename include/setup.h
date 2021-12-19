/**
 * This file will hold all the acronyms, screen settings, and all other general
 * settings and has direct control of all the resources in the library.
 * There are two sections:
 *  1. BUILTIN: Labels that define the library's internal components. It should
 *      NOT be tampered with, or else everything would not work.
 *  2. CUSTOM: Labels that define the general layout of the game. Customize to
 *      your heart's content (the values, not the labels themselves!).
 **/

#ifndef SETUP_H
#define SETUP_H

#include <vector>
#include <memory>

// CUSTOM DEFINITIONS
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600



// BUILTIN DEFINITIONS
#define SPRITE std::shared_ptr<Sprite>
#define SPRITES std::vector<SPRITE>

#define ENTITY std::shared_ptr<Entity>
#define ENTITIES std::vector<ENTITY>

#define EVENT std::shared_ptr<Event>
#define EVENTS std::vector<EVENT>

#define PROPERTY std::shared_ptr<Property>
#define PROPERTIES std::vector<PROPERTY>

#define MAKE_SPRITE std::make_shared<Sprite>
#define MAKE_ENTITY std::make_shared<Entity>

#define MAKE_PROP std::make_shared<Property>
#define MAKE_EVENT std::make_shared<Event>

// Movement flags
enum MOVEMENT_FLAGS {
  MOVING_UP,
  MOVING_DOWN,
  MOVING_LEFT,
  MOVING_RIGHT,
  MOVING_NONE,
  MOVING_SIZE
};

#endif // SETUP_H