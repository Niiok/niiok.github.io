---
title: "MFC classes"
author: "Niiok"
categories: ["Window"]
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


- CObject
  - CCmdTarget
    - CWinThread
      - CWinApp
    - CDocumen
    - CDocTemPlate
      - CSingleDocTemplace
      - CMultiDocTemplatet
    - CWnd (Window Support)
      - CFrameWnd (Frame Windows)
        - CMDIChildWnd
          - (user MDI windows)
        - CMDIFrameWnd
          - (user MDI workspaces)
        - CMiniFrameWnd
        - (user SDI windows)
        - COleIPFrameWnd
      - CSplitterWnd
      - CControlBar (Control Bars)
        - CDialogBar
        - COleResizeBar
        - CReBar
        - CStatusBar
        - CToolBar
      - CPropertySheet (Property Sheets)
      - CDialog (Dialog Boxes)
        - CCommonDialog
          - CColorDialog
          - CFileDialog
          - CFindReplaceDialog
          - CFontDialog
          - COleDialog
            - COleBusyDialog
            - COleChangeIconDialog
            - COleChangeSourceDialog
            - COleConvertDialog
            - COleInsertDialog
            - COleLinksDialog
              - COleUpdateDialog
            - COlePasteSpecialDialog
            - COlePropertiesDialog
          - CPageSetupDialog
          - CPrintDialog
          - CPrintDialogEx
        - COlePropertyPage
        - CPropertyPage
        - (user dialog boxes)
        - CDHtmlDialog
          - CMultiPageDHtmlDialog
      - CView (Views)
        - CCtrlView
          - CEditView
          - CListView
          - CRichEditView
          - CTreeView
        - CScrollView
          - (user scroll views)
          - CFormView
            - (user form views)
            - CDaoRecordView
            - CHtmlEditView
            - CHtmlView
            - COleDBRecordView
            - CRecordView
              - (user record views)
    - (Controls)
      - CAnimateCtrl
      - CComboBox
      - CDateTimeCtrl
      - CEdit
      - CHeaderCtrl
      - CHtmlEditCtrl
      - CHotKeyCtrl
      - CIPAdressCtrl
      - CLinkCtrl
      - CListBox
      - CListCtrl
      - CMonthCalCtrl
      - COleControl
      - CProgressCtrl
      - CReBarCtrl
      - CRichEditCtrl
      - CScrollBar
      - CSliderCtrl
      - CSpinButtonCtrl
      - CStatic
      - CStatusBarCtrl
      - CTabCtrl
      - CToolBarCtrl
      - CToolTipCtrl
      - CTreeCtrl
  - CDC
    - CClientDC
    - CMetaFileDC
    - CPaintDC
    - CWindowDC
  - CGdiObject
    - CBitMap
    - CBrush
    - CFont
    - CPalette
    - CPen
    - CRgn
  - CFile
    - CMemFile
      - CShareFile
    - COleStreamFile
      - CMonikerFile
        - CAsyncMonikerFile
          - CDataPathProperty
            - CCachedDataPathProperty
    - CSocketFile
    - CStdioFile
      - CInternetFile
        - CGopherFile
        - CHttpFile
  - CRecentFileList
  - (Arrays)
    - CArray (template)
    - CByteArray
    - CDWordArray
    - CObArray
    - CPtrArray
    - CStringArray
    - CUIntArray
    - CWordArray
    - (arrays of user types)
  - (Lists)
    - CList (template)
    - CPtrList
    - CObList
    - CStringList
    - (lists of user types)
  - (Maps)
    - CMap (template)
    - CMapWordToPtr
    - CMapPtrToWord
    - CMapPtrToPtr
    - CMapWordToOb
    - CMapStringToPtr
    - CMapStrngToOb
    - CMapStringToString
- CPoint
- CRect
  > composed with 4 integers    
  > first 2 are x and y of left top vertex    
  > last 2 are x and y of right bottom vertex    
-CSize
-CString
 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- Create()
  - almost same with CreateWindow()'s method version 
