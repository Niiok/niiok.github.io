---
title: "SDL Chapter 7"
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

# This document is not done. On Going!!

<!--
- [Intro](#intro)
  - How Chapter 7 works?

- [Function](#function)
  - SDL_SetHint()
  - SDL_CreateRenderer()
  - SDL_SetRenderDrawColor()
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
-->

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Intro
    
### How Chapter 7 works?
  1. init()
     1. _`SDL_Init()`_
     2. _`SDL_SetHint()`_
     3. _`SDL_CreateWindow()`_
     4. _`SDL_CreateRenderer()`_
     5. _`SDL_SetRenderDrawColor()`_
     6. _`IMG_Init()`_
  2. loadMedia()
     1. loadTexture()
        1. load PNG file on intermediate surface with _`IMG_Load()`_.
        2. create texture from loaded surface with _`SDL_CreateTextureFromSurface()`_.
           - free memory of intermediate surface with _`SDL_FreeSurface()`_.
  3. start loop untill variable _`quit`_ is true.
     1. start loop that calls _`SDL_PollEvent()`_ untill it returns 0.
        1. if _`SDL_Event`_.type is _`SDL_QUIT`_, quit is true( which means first loop will end).
        2. clear screen(render) with _`SDL_RenderClear()`_.
        3. render texture(copy) on screen with _`SDL_RenderCopy()`_.
        4. update screen(of window) with _`SDL_RenderPresent()`_ to refresh and show what we've done.
  4. close()
     1. _`SDL_DestroyTexture()`_
     2. _`SDL_DestroyRenderer()`_
     3. _`SDL_DestroyWindow()`_
     4. _`IMG_Quit()`_
     5. _`SDL_Quit()`_
  
  - now we are not using screen surface as our primary canvas anymore; instead renderer!
    - loadSueface() -> loadTexture()
    - SDL_GetWindowSurface() is gone from init()
      - instead, SDL_SetHint(), SDL_CreateRenderer() and SDL_SetRenderDrawColor() are required
    - SDL_BlitSurface() is replaced into SDL_RenderClear() and SDL_RenderCopy()
    - SDL_UpdateWindowSurface() is replaced into SDL_RenderPresent()
    - SDL_FreeSurface() is gone from close()
      - instead, SDL_DestroyTexture() and SDL_DestroyRenderer() are required
    

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Function
    
### SDL_SetHint()
  ```C
  
  ```
  - **param**
    - _``_ : 
  - **return**
    - **** on 
  > 
    

### SDL_CreateRenderer()
  ```C
  
  ```
  - **param**
    - _``_ : 
  - **return**
    - **** on 
  > 
    

### SDL_SetRenderDrawColor()
  ```C
  
  ```
  - **param**
    - _``_ : 
  - **return**
    - **** on 
  > 
    

### SDL_CreateTextureFromSurface()
  ```C
  
  ```
  - **param**
    - _``_ : 
  - **return**
    - **** on 
  > 
    

### SDL_RenderClear()
  ```C
  
  ```
  - **param**
    - _``_ : 
  - **return**
    - **** on 
  > 
    

### SDL_RenderCopy()
  ```C
  
  ```
  - **param**
    - _``_ : 
  - **return**
    - **** on 
  > 
    

### SDL_RenderPresent()
  ```C
  
  ```
  - **param**
    - _``_ : 
  - **return**
    - **** on 
  > 
    

### SDL_DestroyTexture()
  ```C
  
  ```
  - **param**
    - _``_ : 
  - **return**
    - **** on 
  > 
    

### SDL_DestroyRender()
  ```C
  
  ```
  - **param**
    - _``_ : 
  - **return**
    - **** on 
  > 
    

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Struct
    
### SDL_Renderer
    

### SDL_Texture
    

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# Term
    
### SDL_SetHint()
  - SDL_HINT_RENDER_SCALE_QUALITY
     

### SDL_CreateRender()
  - SDL_RENDERER_ACCELERATED
    
