---
title: "SDL Chapter 2"
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
  - How Chapter 2 works?

- [Function](#function)
  - SDL_LoadBMP()
  - SDL_FreeSurface()
  - SDL_BlitSurface()

- [Struct](#struct)
  - nothing new

- [Term](#term)
  - nothing new
-->

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Intro
    
### How Chapter 2 works?
  1. Init()
     1. _`SDL_Init()`_
     2. _`SDL_CreateWindow()`_
     3. _`SDL_GetWindowSurface()`_
  2. loadMedia()
      1. _`SDL_LoadBMP()`_
  3. copy image(Blit) into surface with _`SDL_BlitSurface()`_.
  4. update window with _`SDL_UpdateWindowSurface()`_ to refresh and show what we've done.
     - you can delay loop( for window lasting) with _`SDL_Delay()`_.	
  5. close()
     1. _`SDL_FreeSurface()`_
     2. _`SDL_DestroyWindow()`_
     3. _`SDL_Quit()`_
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Function
    
### SDL_LoadBMP()
  ```C
  SDL_Surface* SDL_LoadBMP( const char* file );
  ```
  - **param**
    - _`file`_ : the file containing a BMP image
  - **return**
    - **surface that contain BMP** on success
    - **NULL** on failure    
  > Gets SDL_Surface object from BMP file and returns its address.    
      

### SDL_FreeSurface()
  ```C
  void SDL_FreeSurface( SDL_Surface* surface );
  ```
  - **param**
    - _`surface`_ : the SDL_Surface to free
  - **return** is void    
  > free surface object on memory.    
    

### SDL_BlitSurface()
  ```C
  int SDL_BlitSurface( SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect );
  ```
  - **param**
    - _`src`_ : the SDL_Surface structure to be copied from
    - _`srcrect`_ : the SDL_Rect structure representing the rectangle to be copied, or NULL to copy the entire surface
    - _`dst`_ : the SDL_Surface structure that is the blit target
    - _`dstrect`_ : the SDL_Rect structure representing the rectangle that is copied into
  - **return**
    - **0** on blit success
    - **negative integer as error code** on failure    
  > Blit image into surface's rect area or entire surface.    
    

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Struct
    
- nothing new
    
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Term
    
- nothing new
    
