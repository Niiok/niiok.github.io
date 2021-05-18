---
layout: post
title: "SDL_Chapter_7"
categories: SDL
author:
- Niiok
meta: ""
---

# This document is not done. On Going!!

- [Intro](#intro)
  - How Chapter_7 works?

- [Function](#function)
  - SDL_SetHint()
  - SDL_CreateRenderer()
  - SetRenderDrawColor()
  - SDL_CreateTextureFromSurface()
  - SDL_RenderClear()
  - SDL_RenderCopy()
  - SDL_RenderPresent()
  - SDL_DestroyTexture()
  - SDL_DestroyRender()

- [Struct](#struct)
  - SDL_Renderer
  - SDL_Texture

- [Term](#term)
  - SDL_SetHint()
    - SDL_HINT_RENDER_SCALE_QUALITY
  - SDL_CreateRender()
    - SDL_RENDERER_ACCELERATED

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Intro
    
- How Chapter_7 works?
  1. init()
     1. _`SDL_Init()`_
     2. _`SDL_SetHint()`_
     3. _`SDL_CreateWindow()`_
     4. _`SDL_CreateRenderer()`_
     5. _`SDL_SetRenderDrawColor()`_
     6. _`IMG_Init()`_
  2. loadMedia()	// not done
     1. loadTexture()
        1. load PNG file on intermediate surface with _`IMG_Load()`_.
        2. optimize loaded intermediate surface into optimized surface with _`SDL_ConvertSurface()`_.
           - free memory of intermediate surface with _`SDL_FreeSurface()`_.
  3. start loop untill variable _`quit`_ is true.	// not done
     1. start loop that calls _`SDL_PollEvent()`_ untill it returns 0.
        1. if _`SDL_Event`_.type is _`SDL_QUIT`_, quit is true( which means first loop will end).
        2. copy screen(Blit) with _`SDL_BlitSurface()`_ from chosen PNG surface to screen surface.
        3. update window with _`SDL_UpdateWindowSurface()`_ to refresh and show what we've done.
  4. close()
     1. _`SDL_DestroyTexture()`_
     2. _`SDL_DestroyRenderer()`_
     3. _`SDL_DestroyWindow()`_
     4. _`IMG_Quit()`_
     5. _`SDL_Quit()`_
  
  - now we are not using screen surface anymore; instead renderer!
    - loadSueface() -> loadTexture()
    - SDL_GetWindowSurface() is gone from init()
    - SDL_FreeSurface() is gone from close()

    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Function
    
- 
  ```C
  
  ```
  - _``_ : 
  - **return**
    - **** on 
  > 
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Struct
    
- 
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Term
    
- 
    
