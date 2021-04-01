# MFC

- MFC is Microsoft Foundation Class. 
- composed with combination of Win32 api and class (object-oriented)
- MFC is almost depricated by many alternatives like .net WPF and other crossplatform GUI libraries

- SDI
  - CWinApp
  - CFrameWind
  - CView
  - CDocument

- MDI

- Dialog based


- MessageMap
  - do work of CALLBACK funtion on MFC
  - _`OnCreate()`_ : mapped with _`WM_CREATE`_ (ON_WM_CREATE())
  - _`OnSize()`_ : mapped with _`WM_SIZE`_ (ON_WM_SIZE())
  - _`OnPaint()`_ : mapped with _`WM_PAINT`_ (ON_WM_PAINT())
  - _`OnClose()`_ : mapped with _`WM_CLOSE`_ (ON_WM_CLOSE())

- CRect
  - composed with 4 integers
  - first 2 are x and y of left top vertex
  - last 2 are x and y of right bottom vertex

