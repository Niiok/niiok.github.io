# SDL_Chapter_6

- [Intro](#intro)
  - How Chapter_6 works?
  - SDL_image.h

- [Function](#function)
  - IMG_Init()
  - IMG_GetError()

- [Struct](#struct)
  - 

- [Term](#term)
  - IMG_Init()
    - IMG_INIT_PNG

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Intro
    
- How Chapter_6 works?
  1. init()
    1. _`SDL_Init()`_
    2. _`SDL_CreateWindow()`_
    3. _`IMG_Init()`_
    4. _`SDL_GetWindowSurface()`_
  2. loadMedia()
    1. loadSurface()
      1. load PNG file on intermediate surface with _`IMG_Load()`_.
      2. optimize loaded intermediate surface into optimized surface with _`SDL_ConvertSurface()`_.
        - free memory of intermediate surface with _`SDL_FreeSurface()`_.
  3. start loop untill variable _`quit`_ is true.
    1. start loop that calls _`SDL_PollEvent()`_ untill it returns 0.
      1. if _`SDL_Event`_.type is _`SDL_QUIT`_, quit is true( which means first loop will end).
      2. copy screen(Blit) with _`SDL_BlitSurface()`_ from chosen PNG surface to screen surface.
      3. update window with _`SDL_UpdateWindowSurface()`_ to refresh and show what we've done.
  4. close()
    1. _`SDL_FreeSurface()`_
    2. _`SDL_DestroyWindow()`_
    3. _`IMG_Quit()`_
    4. _`SDL_Quit()`_
    
- SDL_image.h
  - we will use SDL_image in this chapter
  - if you're running on Windows, you need to place dll file inside proper system directory (like Windows/System32)
    - if you have dll error, use `where DLLname.dll` command to find error-able dll's location
  - writer is using IMG_2.0.4 version on SDL_2.0.9 version
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Function
    
- IMG_Init()
  ```C
  
  ```
  - _``_ : 
  - **return**
    - **flags that loaded successfully** on both entire, partial success
    - **flag that different with input** on both entire, partial failure
  > 
    
- IMG_GetError()
  ```C
  
  ```
  - _``_ : 
  - **return**
    - **char array with recent error information** on error
    - **empty array** on no error happen
  > SDL_image version of SDL_GetError()    
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Struct
    
- 
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Term
    
- 
    
