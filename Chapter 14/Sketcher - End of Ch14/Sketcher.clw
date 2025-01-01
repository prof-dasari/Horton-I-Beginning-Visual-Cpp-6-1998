; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSketcherDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sketcher.h"
LastPage=0

ClassCount=6
Class1=CSketcherApp
Class2=CSketcherDoc
Class3=CSketcherView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_SKETCHTYPE
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDR_MAINFRAME

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
LastObject=ID_ELEMENT_RECTANGLE

[CLS:CSketcherView]
Type=0
HeaderFile=SketcherView.h
ImplementationFile=SketcherView.cpp
Filter=C
LastObject=ID_COLOR_BLACK


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


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
Command13=ID_COLOR_BLACK
Command14=ID_COLOR_RED
Command15=ID_COLOR_GREEN
Command16=ID_COLOR_BLUE
CommandCount=16

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
Command17=ID_ELEMENT_LINE
Command18=ID_ELEMENT_RECTANGLE
Command19=ID_ELEMENT_CIRCLE
Command20=ID_ELEMENT_CURVE
Command21=ID_COLOR_BLACK
Command22=ID_COLOR_RED
Command23=ID_COLOR_GREEN
Command24=ID_COLOR_BLUE
Command25=ID_WINDOW_NEW
Command26=ID_WINDOW_CASCADE
Command27=ID_WINDOW_TILE_HORZ
Command28=ID_WINDOW_ARRANGE
Command29=ID_APP_ABOUT
CommandCount=29

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

