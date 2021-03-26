# Windows

- event driven
  1. when events happen, they stored into message form
  2. message stored into system queue
  3. OS was checking for system queue
  4. OS send message to aplication's thread message queue
  5. application was checking for thread message queue
  6. application calls event-matching callback function 

- window programming
  - SDK (Software Development Kit) : low level programming with winAPI
  - MFC (Microsoft Foundation Class) : useful library constructed by SDK
  - RAD (Rapid Application Development) : faster and easier than MFC


- tbu
  - WinMain()
    ```C
    int WINAPI WinMain ( HINSTANCE hinstance, ...
    
    ```
    WNDCLASS WndClass;
    hWnd = CreateWindow(IpsClass, )
    ShowWindow(hWnd, nCmdShow);
  
    while(GetMessage(&Message, 0, 0 ,0))	//search for message and call callback functions
  - WndProc()
    ```C
    LRESULT CALLBACK WndProc ( HWND UINT, WPARAM, LPARAM );
    ```
