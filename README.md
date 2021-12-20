# Game-Engine
A Progressing Game Engine made with SDL

- download and extract the SDL2 library
- put the include folder's contents inside of that of this one
- put the lib folder's contents inside of this one's
- put the .dll files (only SDL2 and SDL2_image are needed for now) inside project root folder
- everything should be set by now so run `make` with one of the following configs:
  - `debug`: all warnings shown, every component included (even if unnecessary) -> Windows
  - `release`: no warnings, optimized to max, and stripped of all extra components -> Windows
  - `all`: for Linux users, same as release

# Development Roadmap

## V 1.0.0
* Phase 1
    - Simplify window init -> Done
    - Sprite definition -> Done
    - Set up lambda closure methods for sprites -> Done
    - Custom sprite rendering and events -> Done
    - User input based rendering
    - Game Rules
* Phase 2
    - Built-in presets that help the programmer develop games faster
    - Add joystick support
    - Set up multi-threading if possible
    - Modify makefile for cross-platform compilation
    - Documentation and error handling

## Future Features
  - Image manipulation
  - More openGL implementation for better performance
  - Framework...

# Technologies Used
![SDL](https://www.libsdl.org/media/SDL_logo.png) &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/240px-ISO_C%2B%2B_Logo.svg.png" width="100px">

# Developers 

* [Dagmawi Babi ](https://github.com/dagmawibabi)
* [Yohannes Jo ](https://github.com/yohannes-jo) 

# License

 [MIT License](LICENSE)
