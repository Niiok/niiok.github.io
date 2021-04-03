# MFC

- MFC is Microsoft Foundation Class. 
- composed with combination of Win32 api and class (object-oriented)
- MFC is almost depricated by many alternatives like .net WPF and other crossplatform GUI libraries
- declare field HWnd inside header file to create child windows
  - you need to call _`Create()`_ method of them to replace _`CreateWindow()`_ of win32
- since MFC works as OOP wrapper of win32, message dealing system how win32 do with CALLBACK function is replaced by MessageMap macro inside HWnd

- SDI
  - CWinApp
  - CFrameWind
  - CView
  - CDocument

- MDI

- Dialog based


- MessageMap
  - do work of CALLBACK funtion on MFC
  - composed with two macros (at top of source);
    - _`BEGIN_MESSAGE_MAP( CustumView, CView )`_
    - _`END_MESSAGE_MAP()`_
  - examples
    - _`OnCreate()`_ : mapped with _`WM_CREATE`_ (ON_WM_CREATE())
    - _`OnSize()`_ : mapped with _`WM_SIZE`_ (ON_WM_SIZE())
    - _`OnPaint()`_ : mapped with _`WM_PAINT`_ (ON_WM_PAINT())
    - _`OnClose()`_ : mapped with _`WM_CLOSE`_ (ON_WM_CLOSE())
    - _`ON_COMMAND( CHILD_ID, OnCustumFunction )`_
      - this is macro inside message map
      - unlike default mapping like _`ON_WM_CREATE()`_, this macro has two parameters
        - _`CHILD_ID`_ : UINT value (normally defined by macro)
        - _`OnCustumFunction`_ : void (*) (void) type function
      - calls _`OnCustumFunction()`_ when control with _`CHILD_ID`_ occur WM_COMMAND message
  - message processing class
    > almost messages occur in CView type object. so message will be sent in CView's MessageMap.    
    > but if there's no proper MessageMap in CView type object, it will be sent to CDocument type object's MessageMap.    
    > if there's no MessageMap, next is CFrameWnd.    
    > and next is CwinApp.    
    >    CView -> CDocument -> CFrameWnd -> CWinApp     

- CWinApp
  - _`InitInstance()`_ : called when mfc program started
  - _`Run()`_ : loop function
  - _`ExitInstance()`_ : called when mfc progran ended

- AfxMessageBox()
  ```C
  void AfxMessageBox( _T("text") );
  ```
  - work as MessageBox of win32

