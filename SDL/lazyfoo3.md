# SDL_Chapter_XX

- [Intro](#intro)
  - How Chapter_3 works?

- [Function](#function)
  - SDL_PollEvent()

- [Class](#class)
  - SDL_Event

- [Term](#term)
  - SDL_Event
    - SDL_QUIT

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Intro
    
- How Chapter_3 works?
  1. Init()
    1. _`SDL_Init()`_
    2. _`SDL_CreateWindow()`_
    3. _`SDL_SDL_GetWindowSurface()`_
  2. loadMedia()
    1. _`SDL_LoadBMP()`_
  3. start loop untill variable _`quit`_ is true.
    1. start loop that calls _`SDL_PollEvent()`_ untill it returns 0.
      1. if _`SDL_Event`_.type is _`SDL_QUIT`_, quit is true( which means first loop will end).
      2. copy screen(Blit) with _`SDL_BlitSurface()`_.
      3. update window with _`SDL_UpdateWindowSurface()`_ to refresh and show what we've done.
  5. close()
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

## Class
    
- SDL_Event
  > general cross-platform event class     
  > contains event data    
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Term
    
- SDL_Event
  - .type
    - SDL_QUIT
    
