---
title: "CWnd"
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


- Create()
  - almost same with CreateWindow()'s method version 
