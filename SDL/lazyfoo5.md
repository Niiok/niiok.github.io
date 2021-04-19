# SDL_Chapter_5

- [Intro](#intro)
  - How Chapter_5 works?

- [Function](#function)
  - SDL_ConvertSurface()
  - SDL_BlitScaled()

- [Struct](#struct)
  - nothing new

- [Term](#term)
  - nothing new

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Intro
    
- How Chapter_5 works?
  1. init()
    1. _`SDL_Init()`_
    2. _`SDL_CreateWindow()`_
    3. _`SDL_GetWindowSurface()`_
  2. loadMedia()
    1. loadSurface()
      1. load BMP file on intermediate surface with _`SDL_LoadBMP()`_.
      2. optimize loaded intermediate surface into optimized surface with _`SDL_ConvertSurface()`_.
        - free memory of intermediate surface with _`SDL_FreeSurface()`_.
  3. start loop untill variable _`quit`_ is true.
    1. start loop that calls _`SDL_PollEvent()`_ untill it returns 0.
      1. if _`SDL_Event`_.type is _`SDL_QUIT`_, quit is true( which means first loop will end).
      2. copy screen(Blit) scaled one with _`SDL_BlitScaled()`_.
      3. update window with _`SDL_UpdateWindowSurface()`_ to refresh and show what we've done.
  4. close()
    1. _`SDL_FreeSurface()`_
    2. _`SDL_DestroyWindow()`_
    3. _`SDL_Quit()`_
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Function
    
- SDL_ConvertSurface()
  ```C
  SDL_Surface* SDL_ConvertSurface( SDL_Surface* src, const SDL_PixelFormat* fmt, Uint32 flags );
  ```
  - _`src`_ : 
  - _`fmt`_ : 
  - _`flags`_ : 
  - **return**
    - **** on 
  > 
    
    - SDL_BlitScaled()
  ```C
  
  ```
  - _``_ : 
  - **return**
    - **** on 
  > 
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Struct
    
- nothing new
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Term
    
- nothing new
    
