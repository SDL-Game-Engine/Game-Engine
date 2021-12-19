# Game-Engine
A Progressing Game Engine made with SDL

- download and extract the SDL2 library
- put the include folder's contents inside of that of this one
- put the lib folder's contents inside of this one's
- put the .dll files (only SDL2 and SDL2_image are needed for now) inside project root folder
- everything should be set by now so run `make` with one of the following configs:
  - `debug`: all warnings shown, every component included (even if unnecessary) -> Windows
  - `release`: no warnings, optimised to max, and stripped of all extra components -> Windows
  - `all`: for Linux users, same as release