// Calculator.h: interface for the CCalculator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCULATOR_H__2C61C109_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
#define AFX_CALCULATOR_H__2C61C109_5780_11D2_963F_00A0C94CB8B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDisplay;
class CLogicUnit;
class CKeyboard;

class CCalculator  
{
public:
	CDisplay* GetDisplay();
	CLogicUnit* GetLogicUnit();
    double Run();
    CCalculator& operator=(const CCalculator& rhs);
	CCalculator(const CCalculator& rCalculator);
	CCalculator();
	virtual ~CCalculator();

private:
	CKeyboard* m_pKeyboard;
	CLogicUnit* m_pLogicUnit;
	CDisplay* m_pDisplay;
};

#endif // !defined(AFX_CALCULATOR_H__2C61C109_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
