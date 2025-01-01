// Display.h: interface for the CDisplay class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISPLAY_H__2C61C10B_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
#define AFX_DISPLAY_H__2C61C10B_5780_11D2_963F_00A0C94CB8B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Calculator.h"

class CRegister;
class CCalculator;

class CDisplay
{
public:
	void ShowRegister(CRegister& rReg);
    CDisplay(CCalculator* pCalc);   // Constructor
    virtual ~CDisplay();

private:
   CDisplay();                     // Private so inaccessible

private:
   CCalculator* m_pCalc;           // Pointer to the parent calculator
};

#endif // !defined(AFX_DISPLAY_H__2C61C10B_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
