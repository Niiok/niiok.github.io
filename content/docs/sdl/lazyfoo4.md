---
title: "SDL Chapter 4"
author: "Niiok"
categories: ["SDL"]
date: 1970-01-01T00:00:00+00:00
weight: 1


# searchHidden: true

#cover:
#    image: "<image path/url>"    # can also paste direct link from external site
#    alt: "<alt text>"
#    caption: "<text>"
#    relative: false 	# To use relative path for cover image, used in hugo Page-bundles

#ShowBreadCrumbs: false
---

<!--
- [Intro](#intro)
  - How Chapter 4 works?

- [Function](#function)
  - nothing new

- [Struct](#struct)
  - nothing new

- [Term](#term)
  - (enum(not official))KeyPressSurfaces
    - KEY_PRESS_SURFACE_DEFAULT
    - KEY_PRESS_SURFACE_UP
    - KEY_PRESS_SURFACE_DOWN
    - KEY_PRESS_SURFACE_LEFT
    - KEY_PRESS_SURFACE_RIGHT
    - KEY_PRESS_SURFACE_TOTAL 
  - SDL_Event.type
    - SDL_KEYDOWN
  - SDL_Event.key.keysym.sym
    - SDLK_UP
    - SDLK_DOWN
    - SDLK_LEFT
    - SDLK_RIGHT
-->

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Intro
    
### How Chapter 4 works?
  1. init()
     1. _`SDL_Init()`_
     2. _`SDL_CreateWindow()`_
     3. _`SDL_GetWindowSurface()`_
  2. loadMedia()
     1. put surfaces in SDL_Surface* array( is global variable) with _`SDL_LoadBMP()`_.
  3. start loop untill variable _`quit`_ is true.
     1. start loop that calls _`SDL_PollEvent()`_ untill it returns 0.
        1. if _`SDL_Event.type`_ is _`SDL_QUIT`_, quit is true( which means first loop will end).
           - else if _`SDL_Event.type`_ is _`SDL_KEYDOWN`_, choose mapped sruface to key inside _`SDL_Surface* array`_( is global variable).
        2. copy screen(Blit) with _`SDL_BlitSurface()`_ from chosen surface to screen surface.
        3. update window with _`SDL_UpdateWindowSurface()`_ to refresh and show what we've done.
  4. close()
     1. free surfacees in SDL_Surface* array( is global varable) with _`SDL_FreeSurface()`_.
     2. _`SDL_DestroyWindow()`_
     3. _`SDL_Quit()`_
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Function
    
- nothing new
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Struct
    
- nothing new
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Term
    
### (enum(not official))KeyPressSurfaces
  - KEY_PRESS_SURFACE_DEFAULT
  - KEY_PRESS_SURFACE_UP
  - KEY_PRESS_SURFACE_DOWN
  - KEY_PRESS_SURFACE_LEFT
  - KEY_PRESS_SURFACE_RIGHT
  - KEY_PRESS_SURFACE_TOTAL    
  > these enum will have global SDL_Surface* array for having mapped surface.    
    
### SDL_Event.type
  - SDL_KEYDOWN
    
### SDL_Event.key.keysym.sym
  - SDLK_UP
  - SDLK_DOWN
  - SDLK_LEFT
  - SDLK_RIGHT
    
