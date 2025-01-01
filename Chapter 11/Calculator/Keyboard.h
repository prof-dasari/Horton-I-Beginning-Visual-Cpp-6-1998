// Keyboard.h: interface for the CKeyboard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_KEYBOARD_H__2C61C10C_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
#define AFX_KEYBOARD_H__2C61C10C_5780_11D2_963F_00A0C94CB8B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Calculator.h"

class CCalculator;

class CKeyboard
{
public:
	double GetKey();
   CKeyboard(CCalculator* pCalc);
   virtual ~CKeyboard();

private:
   CKeyboard();              // Private constructor so it cannot be used

private:
   CCalculator* m_pCalc;     // Pointer to the parent Calculator
};

#endif // !defined(AFX_KEYBOARD_H__2C61C10C_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
