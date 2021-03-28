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

- prefix
  - **h~** : handle
  - **n~** : (?)
  - **l~** : unicode (long)
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
- tbu
  - WinMain()
    ```C
    int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow);
    ```
    > _`main()`_ of Window programming (entry point)    
    - **hInstance** : current instance of application
    - **hPrevInstance** : _deplicated._ (used on 32-bit Windows)
    - **lpCmdLine** : pointer for cmd parameters
    - **nCmdShow** : choose how window will be seen on screen (NULL for default)
            
    > make window class.    
    > register window class.    
    > create window.    
    > show window.
    > do get-message loop.
    > return (end) program if loop is ended.    
    
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  
    - WNDCLASS
      ```C
      typedef struct tagWNDCLASS
      {
          UINT		style;
          WNDPROC		ipfnWndProc;
          int		cbClsExtra;
          int		cbWndExtra;
          HINSTANCE	hInstance;
          HICON		hIcon;
          HCURSOR		hCursor;
          HBRUSH		hbrBackground;
          LPCSTR		lpszMenuName;
          LPCSTR		lpszClassName;
      } WNDCLASS;
      ```
      > make window class with meta-class
      - **lpfnWndProc** : ESSENTIAL. window processor (callback funtion to bind)
      - **lpszClassName** : ESSENTIAL. window class
      - cbClsExtra, cdWndExtra : extra class memory, extra window memory (?)
      - hInstance : current application instance handle (use already-made instance handle)
      - hIcon, hCursor : handle for Icon and Cursor (use LoadCursor(), LoadIcon())
      - hbrBackground : brush for background (use GetStockObject())
      - lpszMenuName : (?)
      - style : what can user change with window (?)
        
        
    - RegisterClass()
      ```C
      void RegisterClass (WNDCLASS* WndClass);
      ```
      > register window class with this function
        
        
    - CreateWindow()
      ```C
      HWND CreateWindow ( lpszClassName, lpszWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu. hInst, lpvParam );
      ```
      > create window with registered window class    
      > returns handle    
      - lpszClassName : window class
      - lpszWindowName : window's name that will be shown on title bar
      - dwStyle : the way how windows will be shown (?)
      - x, y, nWidth, nHeight : location and size of window
      - hWndParent : parent window's handle (?)
      - hMenu : window menu's handle (?)
      - hInst : current application instance's handle
      - hpvParam : extra parameter (?)
      >     
        ```C
        #define WS_OVERLAPPEDWINDOW \
        		(WS_OVERLAPPED 	|\
        		 WS_CAPTION 	|\
        		 WS_SYSMENU	|\
        		 WS_THICKFRAME	|\
        		 WS_MINIMIZEBOX	|\
        		 WS_MAXIMIZEBOX)
        ```
        
        
    - ShowWindow()
      ```C
      void ShowWindow (hWnd, nCmdShow);
      ```
      > show created window instance on screen
      - hWnd
      - nCmdShow
        - SW_HIDE : hide window (not minimize)
        - SW_MINIMIZE : minimize window and not activate (inactive state) it
        - SW_RESTORE : show window on screen (remember window posision and size when do min/max)
        - SW_SHOW : show window on screen (?)
        - SW_SHOWNORMAL : show window on screen (?)
        
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
         
    - GetMessage()
      ```C
      BOOL GetMessage ( lpMsg, hWnd, wFilterMin, wFilterMax )
      {
          TranslateMessage( &Message );
          DispatchMessage( &Message );
      }
      ```
      > get message from queue    
      > returns bool    
      > returns false when message is WM_QUIT to finish event loop
      - lpMsg
      - hWnd
      - wFilterMin
      - wFilterMax
      >
      - event example
        - WM_QUIT : occur when user end program
        - WM_LBUTTONDOWN : occur when mouse left button clicked
        - WM_CHAR : occur when keyboard character inputed
        - WM_PAINT : occur when screen need to be drawn again
        - WM_DESTROY : occur when window deleted inside memory (normally occur WM_QUIT at the end to stop loop)
        - WM_CREATE : occur when window is created
      - message struct
        ```C
        typedef struct tagMSG
        {
            HWND	hwnd;	//window handle
            UINT	message;	//message
            WPARAM	wParam;	//window id
            LPARAM	lParam;	
            DWORD	time;	//time when event occur
            POINT	pt;	//mouse position
        } MSG;
        ```
        
        
    - TranslateMessage()
      ```C
      BOOL TranslateMessage ( CONST MSG* lpMsg );
      ```
      > translate event message into WM_CHAR type    
      > returns bool
      - lpMsg
        
        
    - DispatchMessage
      ```C
      LONG DispatchMessage ( CONST MSG* lpMsg );
      ```
      > dispatch message to operating system to call window processor    
      > 
      - lpMsg
        
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
      
  - WndProc()
    ```C
    LRESULT CALLBACK WndProc (HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
    {
        LPCTSTR text = L"window text example";
        
        switch ( iMessage )
        {
            case WM_PAINT:
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint( hWnd, &ps );	//hdc == handle device context
                
                TextOut( hdc, 10, 10, text, lstrlen(text) );
                EndPaint( hWnd, &ps );
                return 0;
            
            // ... event cases ....
            
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
        }
        return DefWindowProc( hWnd, iMessage, wParam, lParam );	// windows-default event processing
    }
    ```
    > every window own window processor one by one    
    > WIndows will call with message to proper processor when event occurs    
    > main mission of Window processor is dealing with event, message    
    - hWnd : window handle (return value of CreateWindow())
    - iMessage : event message
    - wParam : (?)
    - lParam : (?)
  
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
