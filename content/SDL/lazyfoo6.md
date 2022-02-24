---
title: "SDL Chapter 6"
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
  - How Chapter_6 works?
  - SDL_image.h

- [Function](#function)
  - IMG_Init()
  - IMG_GetError()
  - IMG_Load()
  - IMG_Quit()

- [Struct](#struct)
  - nothing new

- [Term](#term)
  - IMG_Init()
    - IMG_INIT_PNG
    - IMG_INIT_JPG
    - IMG_INIT_TIF
    - IMG_INIT_*

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
  - SDL_image is used in this chapter
  - if you're running on Windows, you need to place dll file inside proper system directory (like Windows/System32)
    - if you have dll error, use `where <dll_name.dll>` command to find error-able dll's location
  - writer is using IMG_2.0.4 version on SDL_2.0.9 version
    

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Function
    
- IMG_Init()
  ```C
  int IMG_Init( int flags );
  ```
  - _`flsgs`_ : bit flag indicates which image format to use while program
  - **return**
    - **flags that loaded successfully** on both entire, partial success
    - **0** on failure
  > IMG_isJPG(), IMG_isPNG(), IMG_isTIF() doesn't requires its initialization.    
  > you can check currently loaded system with calliing this function with 0.    
    

- IMG_GetError()
  ```C
  char* IMG_GetError( void );
  ```
  - **return**
    - **char array with recent error information** on error
    - **empty array** on no error happen
  > IMG version of SDL_GetError()    
    

- IMG_Load()
  ```C
  SLD_Surface* IMG_Load( const char* file );
  ```
  - _`file`_ : image file name string (char array/pointer)
  - **return**
    - **image-loaded surface's address** on success
    - **NULL** on error
  > this function calls IMG_LoadTyped_RW() inside logic.    
  > since this function returns surface, call SDL_FreeSurface() after use of this surface.    
    

- IMG_Quit()
  ```C
  void IMG_Quit( void );
  ```
  - **parameter and return are both void**
  > this function called after all IMG jobs are done.    
  > SDL recommend to call this function essentially at end of program if you used IMG subsystem.    
    

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Struct
    
- nothing new
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

## Term
    
- IMG_Init()
  - IMG_INIT_PNG
  - IMG_INIT_JPG
  - IMG_INIT_TIF
  - IMG_INIT_*
    
