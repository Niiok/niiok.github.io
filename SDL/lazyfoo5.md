# SDL_Chapter_5

- [Intro](#intro)
  - How Chapter_5 works?

- [Function](#function)
  - SDL_ConvertSurface()
  - SDL_BlitScaled()

- [Struct](#struct)
  - SDL_PixelFormat

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
  - _`src`_ : the existing SDL_Surface structure to convert
  - _`fmt`_ : the SDL_PixelFormat structure that the new surface is optimized for
  - _`flags`_ : the flags are unused and should be set to 0; this is a leftover from SDL 1.2's API
  - **return**
    - **new surface** on success
    - **NULL** on failure
  > get surface _`src`_ and convert it into specific format that _`fmt`_ indicating.    
    
    - SDL_BlitScaled()
  ```C
  int SDL_BlitScaled( SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect );
  ```
  - _`src`_ : the SDL_Surface structure to be copied from
  - _`srcrect`_ : the SDL_Rect structure representing the rectangle to be copied, or NULL to copy entire surface
  - _`dst`_ : the SDL_Surface structure that is the blit target
  - _`dstrect`_ : the SDL_Rect structure representing the rectangle that is copied into, or NULL to copy into the entire surface
  - **return**
    - **0** on success
    - **negative integer as error code** on failure
  > Simiral with _`SDL_BlitSurface()`_ but blit scaled surface.    
  > this function call _`SDL_LowerBlitScaled()`_ internally.    
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Struct
    
- SDL_PixelFormat
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Term
    
- nothing new
    
