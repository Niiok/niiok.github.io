---
title: "SDL Chapter 3"
author: "Niiok"
categories: ["SDL"]
date: 1970-01-01T00:00:00+00:00
weight: 1

ShowToc: false
TocOpen: false

# searchHidden: true

#cover:
#    image: "<image path/url>"    # can also paste direct link from external site
#    alt: "<alt text>"
#    caption: "<text>"
#    relative: false 	# To use relative path for cover image, used in hugo Page-bundles

#ShowBreadCrumbs: false
---

- [Intro](#intro)
  - How Chapter_3 works?

- [Function](#function)
  - SDL_PollEvent()

- [Struct](#struct)
  - SDL_Event

- [Term](#term)
  - SDL_Event.type
    - SDL_QUIT

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Intro
    
- How Chapter_3 works?
  1. Init()
     1. _`SDL_Init()`_
     2. _`SDL_CreateWindow()`_
     3. _`SDL_GetWindowSurface()`_
  2. loadMedia()
     1. _`SDL_LoadBMP()`_
  3. start loop untill variable _`quit`_ is true.
     1. start loop that calls _`SDL_PollEvent()`_ untill it returns 0.
        1. if _`SDL_Event`_.type is _`SDL_QUIT`_, quit is true( which means first loop will end).
        2. copy screen(Blit) with _`SDL_BlitSurface()`_.
        3. update window with _`SDL_UpdateWindowSurface()`_ to refresh and show what we've done.
  4. close()
     1. _`SDL_FreeSurface()`_
     2. _`SDL_DestroyWindow()`_
     3. _`SDL_Quit()`_
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Function
    
- SDL_PollEvent()
  ```C
  int SDL_PollEvent( SDL_Event* event );
  ```
  - _`event`_ : the SDL_Event structure to be filled with the next event from the queue, or NULL
  - **return**
    - **1** if queue contains any event inside
    - **0** if there's no event in queue    
  > when this function called, event at head will be removed from queue and stored to _`event`_.    
  >   (return value 1 shows this works happend) (NULL inside queue won't works like this)    
  > this function implicitly contains SDL_PumpEvent().    
    

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Struct
    
- SDL_Event    
  > general cross-platform event struct     
  > contains event data    
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Term
    
- SDL_Event..type
  - SDL_QUIT
    
