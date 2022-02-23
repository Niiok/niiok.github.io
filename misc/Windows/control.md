# Windows Control

- controls are useful preset of child window
  - but control is little different with normal child window
    - control doesn't need class registing
    - control send message(WM_COMMAND) to its parent window's callback function (window processor)
- send **WM_COMMAND** to parent window
  - control gives parameters with **wParam** and **lParam**
    - wParam
      - 4 bytes
      - first 2 bytes contains **Notify code**, notifying what kind of message control made
        - can get with _`HIWORD(wParam)`_
      - last 2 bytes contains **control's ID**
        - can get with _`LOWORD(wParam)`_
    - lParam
      - control's handle

- controls
  - button
  - editor
  - combo box
  - list box
  - text
  - spin
  - progress bar
  
  - MessageBox()
    ```C
    int MessageBox( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType );
    ```
    > make instant message box
    - hWnd : message box owner's handle
    - lpText : text inside message box
    - lpCaption : tutle bar text
    - uType : button type of message box
      - MB_OK
      - MB_OKCANCEL
      - MB_YESNO

