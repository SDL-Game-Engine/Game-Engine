/**
 * The practical implementation of the engine is not supposed to include
 * the complexities abstracted away by my library.
 **/

#include "dibaq.h"

bool sensor() { return true; }

int main(int argc, char *argv[])
{
  // Customize SCREEN_WIDTH and SCREEN_HEIGHT in setup.h
  // Set the r_flag to 1 if you want a resizable screen
  Window *game = Dibaq_Game_Init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 0);

  // If game screen couldn't be initialized, return.
  if (!game)
    return 1;
  
  // if game couldn't be run for some reason, return.
  if (!game->mainLoop())
    return 1;

  game->close();
  return 0;
}