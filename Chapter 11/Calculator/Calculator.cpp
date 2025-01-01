// Calculator.cpp: implementation of the CCalculator class.
//
//////////////////////////////////////////////////////////////////////

#include "Keyboard.h"
#include "Register.h"
#include "LogicUnit.h"
#include "Display.h"
#include "Calculator.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCalculator::CCalculator()
{
   m_pDisplay = new CDisplay(this);          // Create the display
   m_pLogicUnit = new CLogicUnit(this);      // Create the logic unit
   m_pKeyboard = new CKeyboard(this);        // Create the keyboard
}

CCalculator::~CCalculator()
{
   // Free up memory allocated in the constructor
   delete m_pDisplay;
   delete m_pLogicUnit;
   delete m_pKeyboard;
}

// Copy constructor
CCalculator::CCalculator(const CCalculator &rCalculator)
{
	CCalculator(); // Create new display, logic unit and keyboard
}

// Assignment operator
CCalculator& CCalculator::operator =(const CCalculator &rhs)
{
	return *this;	// Return the address of the lhs
}

CLogicUnit* CCalculator::GetLogicUnit()
{
   return m_pLogicUnit;                // Return pointer to the logic unit
}

double CCalculator::Run()
{
   return m_pKeyboard->GetKey();       // Start keyboard input
}

CDisplay* CCalculator::GetDisplay()
{
	return m_pDisplay;
}
