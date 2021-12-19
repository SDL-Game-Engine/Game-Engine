#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.h"

bool Window::init(const char *p_title, int p_w, int p_h, int p_rflag)
{
  bool success = true;
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not be initialized! SDL Error: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    switch (p_rflag)
    {
    case 0:
      window = SDL_CreateWindow(
          p_title,
          SDL_WINDOWPOS_CENTERED,
          SDL_WINDOWPOS_CENTERED,
          p_w, p_h,
          SDL_WINDOW_SHOWN);
      break;

    case 1:
      window = SDL_CreateWindow(
          p_title,
          SDL_WINDOWPOS_CENTERED,
          SDL_WINDOWPOS_CENTERED,
          p_w, p_h,
          SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
      break;

    default:
      printf("Invalid rflag!\n");
      success = false;
    }

    if (!window)
    {
      printf("Window could not be initialized!\n\n");
      success = false;
    }
  }

  return success;
}

bool Window::makeGRenderer()
{
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer)
  {
    printf("Window renderer could not be initialized! SDL Error: %s\n\n", SDL_GetError());
    return false;
  }

  return true;
}

SDL_Renderer *Window::getRenderer()
{
  return renderer;
}

ENTITY Window::loadObject(
    SDL_Renderer *p_renderer,
    std::string p_path,
    SDL_Rect p_srect,
    SDL_Rect p_drect)
{
  SDL_Texture *texture = IMG_LoadTexture(p_renderer, p_path.c_str());

  if (!texture)
  {
    printf("Sprite %s could not be loaded! SDL_image Error: %s\n\n", p_path.c_str(), SDL_GetError());

    close();
    SDL_Delay(3000);
  }

  // Wrap it with Entity to have full control over it in Window
  ENTITY entity = MAKE_ENTITY(MAKE_SPRITE(texture, p_srect, p_drect));

  // Add it to sprite list to make controlling it much easier
  objects.push_back(entity);

  return entity;
}

EVENT Window::addEvent(const char *p_label, bool (*p_event)())
{
  EVENT e = MAKE_EVENT(p_label, p_event);
  events.push_back(e);

  return e;
}

EVENT Window::removeEvent(EVENT event)
{
  EVENT removed = NULL;
  for (int i = 0; i < events.size(); i++)
  {
    if (events[i] == event)
    {
      removed = events[i];
      events.erase(events.begin() + i);
    }
  }

  return removed;
}

void Window::_checkEvents()
{
  for (EVENT e : events)
    e->runProps();
}

void Window::_updateState()
{
  for (ENTITY e : objects)
  {
    for (SPRITE s : e->getSprites())
    {
      s->updatePosition();
    }
  }
}

void Window::_render(ENTITY p_entity, SDL_Rect p_drect, SPRITE p_sprite)
{
  if (p_sprite)
  {
    SPRITE result = p_entity->getSprite(p_sprite);
    if (result)
    {
      p_sprite->setDRect(p_drect);
      SDL_RenderCopy(renderer, p_sprite->getTexture(), &p_sprite->getSRect(), &p_sprite->getDRect());
    }
  }
  else // Render all if no specific sprite is given
  {
    for (SPRITE s : p_entity->getSprites())
    {
      SDL_RenderCopy(renderer, s->getTexture(), &s->getSRect(), &s->getDRect());
    }
  }
}

void Window::_renderAll()
{
  for (ENTITY e : objects)
  {
    for (SPRITE s : e->getSprites())
    {
      SDL_RenderCopy(renderer, s->getTexture(), &s->getSRect(), &s->getDRect());
    }
  }
}

bool Window::mainLoop()
{
  bool success = true;

  if (renderer)
  {
    bool quit = false;
    SDL_Event e;

    // Main loop of the game
    while (!quit)
    {
      while (SDL_PollEvent(&e))
      {
        if (e.type == SDL_QUIT)
        {
          quit = true;
        }
      }

      _update();
    }
  }
  else
  {
    printf("A renderer has not been created yet!\n");
    printf("Window could not be displayed! Closing...\n");

    close();
    SDL_Delay(3000);

    success = false;
  }

  return success;
}

void Window::_update()
{
  SDL_RenderClear(renderer);

  _checkEvents();
  _updateState();
  _renderAll();

  SDL_RenderPresent(renderer);
}

void Window::close()
{
  SDL_Quit();
}