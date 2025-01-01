; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCustomerView
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DBSimpleUpdate.h"
LastPage=0

ClassCount=11
Class1=CDBSimpleUpdateApp
Class2=CDBSimpleUpdateDoc
Class3=COrderDetailsView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource7=IDD_DBSIMPLEUPDATE_FORM (English (U.S.))
Class5=COrderDetailsSet
Resource3=IDD_DBSIMPLEUPDATE_FORM
Resource4=IDD_CUSTOMER_FORM
Resource5=IDR_MAINFRAME (English (U.S.))
Resource6=IDD_ABOUTBOX (English (U.S.))
Class7=CCustomerSet
Class8=CCustomerView
Class9=CProductSet
Class10=CProductView
Class11=COrderSet
Resource8=IDD_PRODUCT_FORM

[CLS:CDBSimpleUpdateApp]
Type=0
HeaderFile=DBSimpleUpdate.h
ImplementationFile=DBSimpleUpdate.cpp
Filter=N

[CLS:CDBSimpleUpdateDoc]
Type=0
HeaderFile=DBSimpleUpdateDoc.h
ImplementationFile=DBSimpleUpdateDoc.cpp
Filter=N

[CLS:COrderDetailsView]
Type=0
HeaderFile=OrderDetailsView.h
ImplementationFile=OrderDetailsView.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=COrderDetailsView


[CLS:COrderDetailsSet]
Type=0
HeaderFile=OrderDetailsSet.h
ImplementationFile=OrderDetailsSet.cpp
Filter=N

[DB:COrderDetailsSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[OrderID], 4, 4
Column2=[ProductID], 4, 4
Column3=[UnitPrice], 2, 21
Column4=[Quantity], 5, 2
Column5=[Discount], 7, 4


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=DBSimpleUpdate.cpp
ImplementationFile=DBSimpleUpdate.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_RECORD_FIRST
Command11=ID_RECORD_PREV
Command12=ID_RECORD_NEXT
Command13=ID_RECORD_LAST
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=16
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_EDIT_UNDO
Command16=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT

[DLG:IDD_DBSIMPLEUPDATE_FORM]
Type=1
Class=COrderDetailsView

[DLG:IDD_DBSIMPLEUPDATE_FORM (English (U.S.))]
Type=1
Class=COrderDetailsView
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_ORDERID,edit,1350633600
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PRODUCTID,edit,1350633600
Control5=IDC_STATIC,static,1342308352
Control6=IDC_UNITPRICE,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_QUANTITY,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_DISCOUNT,edit,1350631552
Control11=IDC_EDITORDER,button,1342242816
Control12=IDC_NEWORDER,button,1342242816
Control13=IDC_CANCEL,button,1073807360

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CUSTOMER_FORM]
Type=1
Class=CCustomerView
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NEWORDERID,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ORDERDATE,SysDateTimePick32,1476460576
Control6=IDC_STATIC,static,1342308352
Control7=IDC_REQUIREDDATE,SysDateTimePick32,1342242848
Control8=IDC_STATIC,static,1342308352
Control9=IDC_COMPANYNAME,edit,1350633600
Control10=IDC_SELECTPRODUCTS,button,1342242816
Control11=IDC_CANCEL,button,1342242816

[DLG:IDD_PRODUCT_FORM]
Type=1
Class=CProductView
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NEWORDERID,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COMPANYNAME,edit,1350633600
Control6=IDC_STATIC,static,1342308352
Control7=IDC_PRODUCTNAME,edit,1350633600
Control8=IDC_STATIC,static,1342308352
Control9=IDC_ORDERQUANTITY,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_ORDERDISCOUNT,edit,1350631552
Control12=IDC_SELECTPRODUCT,button,1342242816
Control13=IDC_DONE,button,1342242816

[CLS:CCustomerSet]
Type=0
HeaderFile=CustomerSet.h
ImplementationFile=CustomerSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CCustomerSet]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[CustomerID], 12, 5
Column2=[CompanyName], 12, 40
Column3=[ContactName], 12, 30
Column4=[ContactTitle], 12, 30
Column5=[Address], 12, 60
Column6=[City], 12, 15
Column7=[Region], 12, 15
Column8=[PostalCode], 12, 10
Column9=[Country], 12, 15
Column10=[Phone], 12, 24
Column11=[Fax], 12, 24

[CLS:CCustomerView]
Type=0
HeaderFile=CustomerView.h
ImplementationFile=CustomerView.cpp
BaseClass=CRecordView
Filter=D
LastObject=CCustomerView
VirtualFilter=RVWC

[CLS:CProductSet]
Type=0
HeaderFile=ProductSet.h
ImplementationFile=ProductSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CProductSet]
DB=1
DBType=ODBC
ColumnCount=10
Column1=[ProductID], 4, 4
Column2=[ProductName], 12, 40
Column3=[SupplierID], 4, 4
Column4=[CategoryID], 4, 4
Column5=[QuantityPerUnit], 12, 20
Column6=[UnitPrice], 2, 21
Column7=[UnitsInStock], 5, 2
Column8=[UnitsOnOrder], 5, 2
Column9=[ReorderLevel], 5, 2
Column10=[Discontinued], -7, 1

[CLS:CProductView]
Type=0
HeaderFile=ProductView.h
ImplementationFile=ProductView.cpp
BaseClass=CRecordView
Filter=D
LastObject=CProductView
VirtualFilter=RVWC

[CLS:COrderSet]
Type=0
HeaderFile=OrderSet.h
ImplementationFile=OrderSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:COrderSet]
DB=1
DBType=ODBC
ColumnCount=14
Column1=[OrderID], 4, 4
Column2=[CustomerID], 12, 5
Column3=[EmployeeID], 4, 4
Column4=[OrderDate], 11, 16
Column5=[RequiredDate], 11, 16
Column6=[ShippedDate], 11, 16
Column7=[ShipVia], 4, 4
Column8=[Freight], 2, 21
Column9=[ShipName], 12, 40
Column10=[ShipAddress], 12, 60
Column11=[ShipCity], 12, 15
Column12=[ShipRegion], 12, 15
Column13=[ShipPostalCode], 12, 10
Column14=[ShipCountry], 12, 15

