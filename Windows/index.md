# Windows

- event driven
  1. when events happen, they stored into message form
  2. message stored into system queue
  3. OS was checking for system queue
  4. OS send message to aplication's thread message queue
  5. application was checking for thread message queue (GetMessage)
  6. application calls event-matching callback function (TranslateMessage, DispatchMessage)

- window programming
  - SDK (Software Development Kit) : low level programming with winAPI
  - MFC (Microsoft Foundation Class) : useful library constructed by SDK
  - RAD (Rapid Application Development) : faster and easier than MFC

- handle
  - index, object, instance, name, pointer, address
  - 32bit integer
  - start with h-
  - HWND, HPEN, HBRUSH, HDC

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
- tbu
  - WinMain()
    ```C
    int WINAPI WinMain ( HINSTANCE hinstance, ...
    
    ```
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  
  - WNDCLASS WndClass
    > make window class with meta-class
    - lpfnWndProc
    - cbClsExtra, cdWndExtra
    - hIcon, hCursor
    - hbrBackground
    - lpszMenuName
    - lpszClassName
    - Style
  
  - RegisterClass()
    > register window class with this function
  
  - CreateWindow()
    ```C
    HWND CreateWindow ( lpszClassName, lpszWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu. hInst, lpvParam );
    ```
    > create window with registered window class    
    > returns handle
    - lpszClassName
    - lpszWindowName
    - dwStyle
    - x, y, nWidth, nHeight
    - hWndParent
    - hMenu
    - hInst
    - hpvParam
  
  - ShowWindow()
    > show created window instance on screen
    - hWnd
    - nCmdShow
  
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  
  - GetMessage()
    ```C
    BOOL GetMessage ( lpMsg, hWnd, wFilterMin, wFilterMax );
    ```
    > get message from queue    
    > returns bool    
    > returns false when message is WM_QUIT to finish event loop
    - lpMsg
    - hWnd
    - wFilterMin
    - wFilterMax
  
  - TranslateMessage()
    ```C
    BOOL TranslateMessage ( lpMsg );
    ```
    > translate event message into WM_CHAR type    
    > returns bool
    - lpMsg
  
  - DispatchMessage
    ```C
    BOOL DispatchMessage ( lpMsg );
    ```
    > dispatch message to operating system to call window processor    
    > returns bool
    - lpMsg
  
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  
  - WndProc()
    ```C
    LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);
    ```
  
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  
  - example
    ```C
    WNDCLASS WndClass;
    hWnd = CreateWindow(IpsClass, )
    ShowWindow(hWnd, nCmdShow);
  
    while(GetMessage(&Message, 0, 0 ,0))	//search for message and call callback functions
    ```
  - WndProc()
    ```C
    LRESULT CALLBACK WndProc ( HWND UINT, WPARAM, LPARAM );
    ```
