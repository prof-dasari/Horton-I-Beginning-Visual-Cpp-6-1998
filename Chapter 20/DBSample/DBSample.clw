; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCustomerView
LastTemplate=CRecordView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DBSample.h"
LastPage=0

ClassCount=10
Class1=CDBSampleApp
Class2=CDBSampleDoc
Class3=CProductView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=10
Resource1=IDD_DBSAMPLE_FORM
Resource2=IDD_ABOUTBOX
Class5=CProductSet
Class7=COrderSet
Resource3=IDR_MAINFRAME
Class8=COrderView
Class9=CCustomerSet
Resource4=IDD_ORDERS_FORM
Class10=CCustomerView
Resource5=IDD_CUSTOMER_FORM
Resource6=IDD_DBSAMPLE_FORM (English (U.S.))
Resource7=IDD_ABOUTBOX (English (U.S.))
Resource8=IDR_MAINFRAME (English (U.S.))
Resource9=IDD_ORDERS_FORM (English (U.S.))
Resource10=IDD_CUSTOMER_FORM (English (U.S.))

[CLS:CDBSampleApp]
Type=0
HeaderFile=DBSample.h
ImplementationFile=DBSample.cpp
Filter=N

[CLS:CDBSampleDoc]
Type=0
HeaderFile=DBSampleDoc.h
ImplementationFile=DBSampleDoc.cpp
Filter=N

[CLS:CProductView]
Type=0
HeaderFile=ProductView.h
ImplementationFile=ProductView.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=CProductView


[CLS:CProductSet]
Type=0
HeaderFile=ProductSet.h
ImplementationFile=ProductSet.cpp
Filter=N

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


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=DBSample.cpp
ImplementationFile=DBSample.cpp
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

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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

[DLG:IDD_DBSAMPLE_FORM]
Type=1
Class=CProductView
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PRODUCTID,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CATEGORYID,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PRODUCTNAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_UNITPRICE,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_UNITSINSTOCK,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_UNITSONORDER,edit,1350631552
Control13=IDC_ORDERS,button,1342242816

[TB:IDR_MAINFRAME]
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

[CLS:COrderSet]
Type=0
HeaderFile=OrderSet.h
ImplementationFile=OrderSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=COrderSet

[DB:COrderSet]
DB=1
DBType=ODBC
ColumnCount=19
Column1=[Order Details].[OrderID], 4, 4
Column2=[ProductID], 4, 4
Column3=[UnitPrice], 2, 21
Column4=[Quantity], 5, 2
Column5=[Discount], 7, 4
Column6=[Orders].[OrderID], 4, 4
Column7=[CustomerID], 12, 5
Column8=[EmployeeID], 4, 4
Column9=[OrderDate], 11, 16
Column10=[RequiredDate], 11, 16
Column11=[ShippedDate], 11, 16
Column12=[ShipVia], 4, 4
Column13=[Freight], 2, 21
Column14=[ShipName], 12, 40
Column15=[ShipAddress], 12, 60
Column16=[ShipCity], 12, 15
Column17=[ShipRegion], 12, 15
Column18=[ShipPostalCode], 12, 10
Column19=[ShipCountry], 12, 15

[DLG:IDD_ORDERS_FORM]
Type=1
Class=COrderView
ControlCount=10
Control1=IDC_STATIC,static,1342308608
Control2=IDC_ORDERID,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PRODUCTID,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_QUANTITY,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_CUSTOMERID,edit,1350631552
Control9=IDC_PRODUCTS,button,1342242816
Control10=IDC_CUSTOMER,button,1342242816

[CLS:COrderView]
Type=0
HeaderFile=OrderView.h
ImplementationFile=OrderView.cpp
BaseClass=CRecordView
Filter=D
VirtualFilter=RVWC
LastObject=COrderView

[CLS:CCustomerSet]
Type=0
HeaderFile=CustomerSet.h
ImplementationFile=CustomerSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CCustomerSet

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

[DLG:IDD_CUSTOMER_FORM]
Type=1
Class=CCustomerView
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CUSTOMERID,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMPANYNAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_ADDRESS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_CITY,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_PHONE,edit,1350631552
Control11=IDC_ORDERS,button,1342242816
Control12=IDC_PRODUCTS,button,1342242816

[CLS:CCustomerView]
Type=0
HeaderFile=CustomerView.h
ImplementationFile=CustomerView.cpp
BaseClass=CRecordView
Filter=D
VirtualFilter=RVWC
LastObject=CCustomerView

[DLG:IDD_DBSAMPLE_FORM (English (U.S.))]
Type=1
Class=?
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PRODUCTID,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CATEGORYID,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PRODUCTNAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_UNITPRICE,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_UNITSINSTOCK,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_UNITSONORDER,edit,1350631552
Control13=IDC_ORDERS,button,1342242816

[DLG:IDD_CUSTOMER_FORM (English (U.S.))]
Type=1
Class=?
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CUSTOMERID,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMPANYNAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_ADDRESS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_CITY,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_PHONE,edit,1350631552
Control11=IDC_ORDERS,button,1342242816
Control12=IDC_PRODUCTS,button,1342242816

[DLG:IDD_ORDERS_FORM (English (U.S.))]
Type=1
Class=?
ControlCount=10
Control1=IDC_STATIC,static,1342308608
Control2=IDC_ORDERID,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PRODUCTID,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_QUANTITY,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_CUSTOMERID,edit,1350631552
Control9=IDC_PRODUCTS,button,1342242816
Control10=IDC_CUSTOMER,button,1342242816

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
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

