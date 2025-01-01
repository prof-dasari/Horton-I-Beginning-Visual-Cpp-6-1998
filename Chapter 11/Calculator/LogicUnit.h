// LogicUnit.h: interface for the CLogicUnit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGICUNIT_H__2C61C10A_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
#define AFX_LOGICUNIT_H__2C61C10A_5780_11D2_963F_00A0C94CB8B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Calculator.h"

class CCalculator;
class CRegister;
class COperation;

class CLogicUnit  
{
public:
	double GetDisplayValue();
    // Process messages from the keyboard
    void Reset();
    void OnEnter();
    void OnAdd();
    void OnSubtract();
    void OnDivide();
    void OnMultiply();
    void OnDecimalPoint();
    void OnDigit(const int& digit);
    void OnLeftParenthesis();
    double OnRightParenthesis();
	CLogicUnit(CCalculator* pCalc);		// Constructor
	virtual ~CLogicUnit();

private:
	CLogicUnit();						// Default not to be used

private:
    COperation* m_pMultiplyDivide;      // Pointer to CMultiply or CDivide
    COperation* m_pAddSubtract;         // Pointer to CAdd or CSubtract
    CRegister m_DisplayReg;             // Value to be displayed
    CRegister m_AddReg;                 // Result of add or subtract
    CRegister m_MultiplyReg;            // Result of divide or multiply
 	CCalculator* m_pCalc;				// Pointer to the parent calculator

	// Operations classes need to be friends
friend class CMultiply;
friend class CDivide;
friend class CAdd;
friend class CSubtract;

};


#endif // !defined(AFX_LOGICUNIT_H__2C61C10A_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
