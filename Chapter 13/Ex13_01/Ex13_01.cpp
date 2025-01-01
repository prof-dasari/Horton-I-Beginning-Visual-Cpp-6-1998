// EX13_01.CPP
// An elementary MFC program
#include <afxwin.h>                        // For the class library

// Application class definition
class COurApp:public CWinApp
{
   public:
      virtual BOOL InitInstance();
};

// Window class definition
class COurWnd:public CFrameWnd
{
   public:
      // Class constructor
      COurWnd()
      {
         Create(0, "Our Dumb MFC Application");
      }
};

// Function to create an instance of the main window
BOOL COurApp::InitInstance(void)
{
   // Construct a window object in the free store
   m_pMainWnd = new COurWnd;
   m_pMainWnd->ShowWindow(m_nCmdShow);     // ...and display it
   return TRUE;
}

// Application object definition at global scope
COurApp AnApplication;                     // Define an application object
