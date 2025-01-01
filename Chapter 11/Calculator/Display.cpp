// Display.cpp: implementation of the CDisplay class.
//
//////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "Keyboard.h"
#include "Register.h"
#include "LogicUnit.h"
#include "Display.h"


#include <iostream>
#include <iomanip>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDisplay::CDisplay()
{

}

CDisplay::~CDisplay()
{

}

CDisplay::CDisplay(CCalculator* pCalc)
{
   m_pCalc = pCalc;
}

// Function to display calculated value
void CDisplay::ShowRegister(CRegister &rReg)
{
   cout << endl << setw(12) << rReg.Get() << endl;
   return;
}
