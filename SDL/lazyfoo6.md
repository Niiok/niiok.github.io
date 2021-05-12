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
  2. loadMedia()
  3. 
  4. 
  5. 
  10. close()
    
- SDL_image.h
  - we will use SDL_image in this chapter
  - if you're running on Windows, you need to place dll file inside proper system directory (like Windows/System32)
    - if you have dll error, use `where DLLname.dll` command to find error-able dll's location
  
    
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
    
