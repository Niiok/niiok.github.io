---
layout: summary
title: "SDL_Chapter_1"
categories: SDL
author:
- Niiok
meta: ""
---

- [Intro](#intro)
  - How Chapter_1 works?
  - SDL.h
  - main

- [Function](#function)
  - SDL_Init()
  - SDL_GetError()
  - SDL_CreateWindow()
  - SDL_GetWindowSurface()
  - SDL_FillRect()
  - SDL_MapRGB()
  - SDL_UpdateWindowSurface()
  - SDL_Delay()
  - SDL_DestroyWindow()
  - SDL_Quit()

- [Struct](#struct)
  - SDL_Window
  - SDL_Surface
  
- [Term](#term)
  - SDL_Init()
    - SDL_INIT_VIDEO
  - SDL_CreateWindow()
    - SDL_WINDOWPOS_UNDEFINED
    - SDL_WINDOW_SHOWN

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Intro
    
- How Chapter_1 works?
  1. Init SDL with _`SDL_Init()`_.
  2. Create window with _`SDL_CreateWindow()`_.
  3. Get surface with _`SDL_GetWindowSurface()`_.
    - do something with surface. (like SDL_FillRect()).
  4. Update surface with _`SDL_UpdateWindowSurface()`_.
    - you can delay loop( for window lasting) with SDL_Delay().
  5. If you done all your jobs with SDL, Destroy window with _`SDL_DestroyWindow()`_.
  6. Don't forget calling _`SDL_Quit()`_ for terminating all jobs!
    
- SDL.h
  - main header file for sdl.
  - includes video, (will be updated)
  - when you setup SDL.h and other libraries, check
    - include (-I)
    - library (-L)
    - link (-l)
    - dll (windows)
    
- main
  - main function type is decided for cross-platform.
    ```C
    int main( int argc, char* args[] )
    ```
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Function
    
- SDL_Init()
  ```C
  int SDL_Init( Uint32 flags );
  ```
  - _`flags`_ : subsystem initialization flags
  - **return**
    - **0** on success
    - **negative integer as error code** on failure    
  > you need to call this function to use SDL functions.    
  > input flags you'll use as parameter.    
    

- SDL_GetError()
  ```C
  const char* SDL_GetError( void );
  ```
  - **return**
    - **character array** on message with information about error
    - **empty array** on no error happen    
  > this function will return character string that describe recent error.    
  > this function will be your reliable best friend.    
    

- SDL_CreateWindow()
  ```C
  SDL_Window* SDL_CreateWindow( const char* title, int x, int y, int w, int h, Uint32 flags );
  ```
  - _`title`_ : the title of the window. un UTF-8 encoding
  - _`x`_ : the x position of the window. SDL_WINDOWPOS_CENTERED or SDL_WINDOWPOS_UNDEFINED
  - _`y`_ : the y position of the window. SDL_WINDOWPOS_CENTERED or SDL_WINDOWPOS_UNDEFINED
  - _`w`_ : the width of the window. in screen coordinates
  - _`h`_ : the height of the window. in screen coordinates
  - _`flags`_ : 0, or one or more SDL_WindowFlags OR'd together (?)
  - **return**
    - **window object's address** on success
    - **NULL** on failure    
  > every SDL_Video works on SDL_Window object.    
  > this function will create and return proper window for your OS.    
    

- SDL_GetWindowSurface()
  ```C
  SDL_Surface* SDL_GetWindowSurface( SDL_Window* window );
  ```
  - _`window`_ : the window to query
  - **return**
    - **surface object that asociated with the window's address** on success
    - **NULL** on failure    
  > after SDL_Window created, you can read and write SDL_Surface from/to SDL_Window.    
  > this function will get address of SDL_Surface that asociated with parameter SDL_Window.    
    

- SDL_FillRect()
  ```C
  int SDL_FillRect( SDL_Surface* dst, const SDL_Rect* rect, Uint32 color );
  ```
  - _`dst`_ : the SDL_Surface structure that is the drawing target
  - _`rect`_ : the SDL_Rect structure representing the rectangle to fill, or NULL to fill the entire surface
  - _`color`_ : the color to fill with (SDL_MapRGB() or SDL_MapRGBA())
  - **return**
    - **0** on success
    - **negative integer as error code** on failure    
  > this function is one kind of draw function.    
  > SDL_Rect for area, SDL_Surface as target, and SDL_MapRGB(A) will choose color.    
    

- SDL_MapRGB()
  ```C
  Uint32 SDL_MapRGB( const SDL_PixelFormat* format, Uint8 r, Uint8 g, Uint8 b );
  ```
  - _`format`_ : an SDL_PixelFormat structure describing the pixel format
  - _`r`_ : the red component of the pixel in the range 0~255
  - _`g`_ : the green component of the pixel in the range 0~255
  - _`b`_ : the blue component of the pixel range 0~255
  - **return**
    - **pixel value** on everytime    
  > simple but cross-platform color returning function.    
    

- SDL_UpdateWindowSurface()
  ```C
  int SDL_UpdateWindowSurface( SDL_Window* window );
  ```
  - _`window`_ : the window to update
  - **return**
    - **0** on success
    - **negative integer as error code** on failure    
  > SDL_Window object will reload SDL_Surface asociated with it without changing it.    
    

- SDL_Delay()
  ```C
  void SDL_Delay( Uint32 ms );
  ```
  - _`ms`_ : the number of milliseconds to delay
  - **return** is void    
  > simple but cross-platform sleep function.    
    
- SDL_DestroyWindow()
  ```C
  void SDL_DestroyWindow( SDL_Window* window );
  ```
  - _`window`_ : the window to destroy
  - **return** is void    
  > call this function when you're done with that SDL_Window object.    
    

- SDL_Quit()
  ```C
  void SDL_Quit( void );
  ```
  - **parameter and return are both void.**    
  > this function called after all SDL jobs are done.    
  > SDL recommend to call this function essentially at end of program.    
    

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Struct
    
- SDL_Window
    

- SDL_Surface
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Term
    
  - SDL_Init()
    - Uint32 flags
      - SDL_INIT_TIMER: timer subsystem
      - SDL_INIT_AUDIO: audio subsystem
      - SDL_INIT_VIDEO: video subsystem; automatically initializes the events subsystem
      - SDL_INIT_JOYSTICK: joystick subsystem; automatically initializes the events subsystem
      - SDL_INIT_HAPTIC: haptic (force feedback) subsystem
      - SDL_INIT_GAMECONTROLLER: controller subsystem; automatically initializes the joystick subsystem
      - SDL_INIT_EVENTS: events subsystem
      - SDL_INIT_EVERYTHING: all of the above subsystems
      - SDL_INIT_NOPARACHUTE: compatibility; this flag is ignored
    

  - SDL_CreateWindow()
    - int x,y
      - SDL_WINDOWPOS_CENTERED
      - SDL_WINDOWPOS_UNDEFINED
    - Uint32 flag
      - SDL_WINDOW_SHOWN : shown window
      - SDL_WINDOW_FULLSCREEN: fullscreen window
      - SDL_WINDOW_FULLSCREEN_DESKTOP: fullscreen window at desktop resolution
      - SDL_WINDOW_OPENGL: window usable with an OpenGL context
      - SDL_WINDOW_VULKAN: window usable with a Vulkan instance
      - SDL_WINDOW_METAL: window usable with a Metal instance
      - SDL_WINDOW_HIDDEN: window is not visible
      - SDL_WINDOW_BORDERLESS: no window decoration
      - SDL_WINDOW_RESIZABLE: window can be resized
      - SDL_WINDOW_MINIMIZED: window is minimized
      - SDL_WINDOW_MAXIMIZED: window is maximized
      - SDL_WINDOW_INPUT_GRABBED: window has grabbed input focus
      - SDL_WINDOW_ALLOW_HIGHDPI: window should be created in high-DPI mode if supported (>= SDL 2.0.1)
    

