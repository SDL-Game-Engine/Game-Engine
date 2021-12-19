#ifndef INIT_H
#define INIT_H

#include "setup.h"
#include "window.h"

Window *Dibaq_Game_Init(const char *p_title, int p_w, int p_h, int p_rflag = 0)
{
  Window *window = new Window();

  if (!window->init("Test", p_w, p_h, p_rflag))
  {
    window->close();
  }

  window->makeGRenderer();

  return window;
}

#endif // INIT_H