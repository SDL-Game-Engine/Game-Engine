#ifndef WINDOW_H
#define WINDOW_H

/**
 * Since the SDL2 library does most of the heavy lifting in the process of 
 * actually creating a window, this class only acts as a wrapper which helps
 * in setting up the main loop of the window, creating a renderer for the 
 * screen, etc...
 **/

#include <string>
#include <SDL2/SDL.h>

#include "sprite.h"
#include "entity.h"
#include "setup.h"
#include "event.h"

class Window
{
public:
  // p_rflag toggles the resizablity of the window. 1 for on, 0 for off.
  // It is set to off by default.
  bool init(const char *p_title, int p_w, int p_h, int p_rflag = 0);

  // initializes a renderer for the created window
  bool makeGRenderer();

  SDL_Renderer *getRenderer();
  
  ENTITY loadObject(
      SDL_Renderer *p_renderer,
      std::string p_path,
      SDL_Rect p_srect,
      SDL_Rect p_drect);

  EVENT addEvent(const char *p_label, bool (*p_event)());
  EVENT removeEvent(EVENT p_event);
  
  void _checkEvents();

  void _updateState();
  
  // helper; render a single entity on screen
  void _render(ENTITY p_entity, SDL_Rect p_drect, SPRITE p_sprite = NULL);

  // utilize _render to render all objects on every loop
  void _renderAll();

  // Returns true if loop runs successfully
  bool mainLoop();

  // Update all the rendered objects based on the given events
  void _update();

  // Closes all subsystems (renderers, surfaces, etc...) and quits the window
  void close();

private:
  SDL_Window *window;

  // Window rendering based on GPU
  SDL_Renderer *renderer;

  // A list where all the textures rendered to the game are stored
  ENTITIES objects;

  // A list where all the events are stored to be processed in the main game loop
  EVENTS events;
};

#endif // WINDOW_H