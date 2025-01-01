; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSketcherView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sketcher.h"
LastPage=0

ClassCount=9
Class1=CSketcherApp
Class2=CSketcherDoc
Class3=CSketcherView
Class4=CMainFrame

ResourceCount=14
Resource1=IDR_CURSOR_MENU
Resource2=IDD_SCALE_DLG
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDD_ABOUTBOX
Resource4=IDR_SKETCHTYPE
Class7=CPenDialog
Resource5=IDD_PENWIDTH_DLG
Class8=CScaleDialog
Resource6=IDR_MAINFRAME
Class9=CTextDialog
Resource7=IDD_TEXT_DLG
Resource8=IDR_MAINFRAME (English (U.S.))
Resource9=IDD_SCALE_DLG (English (U.S.))
Resource10=IDD_PENWIDTH_DLG (English (U.S.))
Resource11=IDD_ABOUTBOX (English (U.S.))
Resource12=IDR_CURSOR_MENU (English (U.S.))
Resource13=IDR_SKETCHTYPE (English (U.S.))
Resource14=IDD_TEXT_DLG (English (U.S.))

[CLS:CSketcherApp]
Type=0
HeaderFile=Sketcher.h
ImplementationFile=Sketcher.cpp
Filter=N

[CLS:CSketcherDoc]
Type=0
HeaderFile=SketcherDoc.h
ImplementationFile=SketcherDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_ELEMENT_TEXT

[CLS:CSketcherView]
Type=0
HeaderFile=SketcherView.h
ImplementationFile=SketcherView.cpp
Filter=C
LastObject=CSketcherView
BaseClass=CScrollView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M
BaseClass=CMDIChildWnd
VirtualFilter=mfWC
LastObject=CChildFrame


[CLS:CAboutDlg]
Type=0
HeaderFile=Sketcher.cpp
ImplementationFile=Sketcher.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_ELEMENT_LINE
Command10=ID_ELEMENT_RECTANGLE
Command11=ID_ELEMENT_CIRCLE
Command12=ID_ELEMENT_CURVE
Command13=ID_ELEMENT_TEXT
Command14=ID_COLOR_BLACK
Command15=ID_COLOR_RED
Command16=ID_COLOR_GREEN
Command17=ID_COLOR_BLUE
Command18=ID_PENWIDTH
Command19=ID_VIEW_SCALE
CommandCount=19

[MNU:IDR_SKETCHTYPE]
Type=1
Class=CSketcherView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_VIEW_SCALE
Command18=ID_ELEMENT_LINE
Command19=ID_ELEMENT_RECTANGLE
Command20=ID_ELEMENT_CIRCLE
Command21=ID_ELEMENT_CURVE
Command22=ID_ELEMENT_TEXT
Command23=ID_COLOR_BLACK
Command24=ID_COLOR_RED
Command25=ID_COLOR_GREEN
Command26=ID_COLOR_BLUE
Command27=ID_PENWIDTH
Command28=ID_WINDOW_NEW
Command29=ID_WINDOW_CASCADE
Command30=ID_WINDOW_TILE_HORZ
Command31=ID_WINDOW_ARRANGE
Command32=ID_APP_ABOUT
CommandCount=32

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[MNU:IDR_CURSOR_MENU]
Type=1
Class=CSketcherView
Command1=ID_MOVE
Command2=ID_DELETE
Command3=ID_SENDTOBACK
Command4=ID_ELEMENT_LINE
Command5=ID_ELEMENT_RECTANGLE
Command6=ID_ELEMENT_CIRCLE
Command7=ID_ELEMENT_CURVE
Command8=ID_ELEMENT_TEXT
Command9=ID_COLOR_BLACK
Command10=ID_COLOR_RED
Command11=ID_COLOR_GREEN
Command12=ID_COLOR_BLUE
CommandCount=12

[DLG:IDD_PENWIDTH_DLG]
Type=1
Class=CPenDialog
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_PENWIDTH0,button,1342177289
Control5=IDC_PENWIDTH1,button,1342177289
Control6=IDC_PENWIDTH2,button,1342177289
Control7=IDC_PENWIDTH3,button,1342177289
Control8=IDC_PENWIDTH4,button,1342177289
Control9=IDC_PENWIDTH5,button,1342177289

[CLS:CPenDialog]
Type=0
HeaderFile=PenDialog.h
ImplementationFile=PenDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CPenDialog
VirtualFilter=dWC

[DLG:IDD_SCALE_DLG]
Type=1
Class=CScaleDialog
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SCALELIST,listbox,1352728833

[CLS:CScaleDialog]
Type=0
HeaderFile=ScaleDialog.h
ImplementationFile=ScaleDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CScaleDialog

[DLG:IDD_TEXT_DLG]
Type=1
Class=CTextDialog
ControlCount=3
Control1=IDC_EDITTEXT,edit,1350631428
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816

[CLS:CTextDialog]
Type=0
HeaderFile=TextDialog.h
ImplementationFile=TextDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTextDialog

[DLG:IDD_PENWIDTH_DLG (English (U.S.))]
Type=1
Class=?
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_PENWIDTH0,button,1342177289
Control5=IDC_PENWIDTH1,button,1342177289
Control6=IDC_PENWIDTH2,button,1342177289
Control7=IDC_PENWIDTH3,button,1342177289
Control8=IDC_PENWIDTH4,button,1342177289
Control9=IDC_PENWIDTH5,button,1342177289

[DLG:IDD_SCALE_DLG (English (U.S.))]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SCALELIST,listbox,1352728833

[DLG:IDD_TEXT_DLG (English (U.S.))]
Type=1
Class=?
ControlCount=3
Control1=IDC_EDITTEXT,edit,1350631428
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816

[MNU:IDR_SKETCHTYPE (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_VIEW_SCALE
Command18=ID_ELEMENT_LINE
Command19=ID_ELEMENT_RECTANGLE
Command20=ID_ELEMENT_CIRCLE
Command21=ID_ELEMENT_CURVE
Command22=ID_ELEMENT_TEXT
Command23=ID_COLOR_BLACK
Command24=ID_COLOR_RED
Command25=ID_COLOR_GREEN
Command26=ID_COLOR_BLUE
Command27=ID_PENWIDTH
Command28=ID_WINDOW_NEW
Command29=ID_WINDOW_CASCADE
Command30=ID_WINDOW_TILE_HORZ
Command31=ID_WINDOW_ARRANGE
Command32=ID_APP_ABOUT
CommandCount=32

[MNU:IDR_CURSOR_MENU (English (U.S.))]
Type=1
Class=?
Command1=ID_MOVE
Command2=ID_DELETE
Command3=ID_SENDTOBACK
Command4=ID_ELEMENT_LINE
Command5=ID_ELEMENT_RECTANGLE
Command6=ID_ELEMENT_CIRCLE
Command7=ID_ELEMENT_CURVE
Command8=ID_ELEMENT_TEXT
Command9=ID_COLOR_BLACK
Command10=ID_COLOR_RED
Command11=ID_COLOR_GREEN
Command12=ID_COLOR_BLUE
CommandCount=12

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_ELEMENT_LINE
Command10=ID_ELEMENT_RECTANGLE
Command11=ID_ELEMENT_CIRCLE
Command12=ID_ELEMENT_CURVE
Command13=ID_ELEMENT_TEXT
Command14=ID_COLOR_BLACK
Command15=ID_COLOR_RED
Command16=ID_COLOR_GREEN
Command17=ID_COLOR_BLUE
Command18=ID_PENWIDTH
Command19=ID_VIEW_SCALE
CommandCount=19

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

