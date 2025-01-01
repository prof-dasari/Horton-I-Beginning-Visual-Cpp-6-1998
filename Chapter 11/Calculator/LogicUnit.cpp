// LogicUnit.cpp: implementation of the CLogicUnit class.
//
//////////////////////////////////////////////////////////////////////

#include "Operation.h"
#include "Register.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Calculator.h"
#include "Display.h"
#include "Keyboard.h"
#include "LogicUnit.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLogicUnit::CLogicUnit()
{

}

CLogicUnit::~CLogicUnit()
{
   // Just to be on the safe side...
   delete m_pAddSubtract;
   delete m_pMultiplyDivide;
}

CLogicUnit::CLogicUnit(CCalculator *pCalc)
{
   m_pCalc = pCalc;                // Save pointer to parent calculator
   m_pMultiplyDivide = 0;        // Initialize pointer to NULL
   m_pAddSubtract = 0;           // Initialize pointer to NULL'
   Reset();                      // Reset the logic unit

}

// Send a point to display register
void CLogicUnit::OnDecimalPoint()
{
   m_DisplayReg.OnDecimalPoint();
}

// Send a digit to the display register
void CLogicUnit::OnDigit(const int& digit)
{
   m_DisplayReg.OnDigit(digit);
}

// Reset the logic unit
void CLogicUnit::Reset()
{
   // Reset all the registers
   m_MultiplyReg.Reset();
   m_AddReg.Reset();
   m_DisplayReg.Reset();

  // Avoid memory leak when the user presses 'C' to clear the calculator 
   delete m_pMultiplyDivide; 
   delete m_pAddSubtract;

   // Set operations pointers to null
   m_pMultiplyDivide = 0;
   m_pAddSubtract = 0;
}

// Process a multiply message
void CLogicUnit::OnMultiply()
{
   if(m_pMultiplyDivide)                         // Check for previous
   {                                             // multiply or divide.
      m_pMultiplyDivide->DoOperation(this);      // If so, do it.
      delete m_pMultiplyDivide;                  // Now delete the
   }                                             // operation object.
   else
      // No previous operation queued so save the display register
      m_MultiplyReg = m_DisplayReg;

   m_pMultiplyDivide = new CMultiply();           // Queue a new operation.

   // Signal start of value in display
   m_DisplayReg.SetBeginValue();
   return;
}

// Process a divide message
void CLogicUnit::OnDivide()
{
   if(m_pMultiplyDivide)                         // Check for previous 
   {                                             // multiply or divide.
      m_pMultiplyDivide->DoOperation(this);      // If so, do it.
      delete m_pMultiplyDivide;                  // Now delete the
   }                                             // operation object.
   else
      // No previous operation queued so save the display register
      m_MultiplyReg = m_DisplayReg;

   m_pMultiplyDivide = new CDivide();            // Queue a new operation.

   // Signal start of value in display
   m_DisplayReg.SetBeginValue();
   return;
}

// Process an add message
void CLogicUnit::OnAdd()
{
   if(m_pMultiplyDivide)                   // m_pMultiplyDivide is a pointer
   {                                       // to any previous * or / object
      // Execute * or / first if it exists
      m_pMultiplyDivide->DoOperation(this);
      delete m_pMultiplyDivide;            // Now delete the object
      m_pMultiplyDivide = 0;               // and set pointer in logic unit
   }                                       // to null

   if(m_pAddSubtract)                      // m_pAddSubtract is a pointer to
   {                                       // any previous + or - object
      m_pAddSubtract->DoOperation(this);   // Execute previous + or -
      delete m_pAddSubtract;               // Now delete object
   }
   else
      // If there was none, save the display register
      m_AddReg = m_DisplayReg;

   // Create a new operation object & signal start of value in display
   m_pAddSubtract = new CAdd();
   m_DisplayReg.SetBeginValue();
   return;
}

// Process a subtract message
void CLogicUnit::OnSubtract()
{
   if(m_pMultiplyDivide)                   // m_pMultiplyDivide is a pointer
   {                                       // to any previous * or / object
      // Execute * or / first if it exists
      m_pMultiplyDivide->DoOperation(this);
      delete m_pMultiplyDivide;            // Now delete the object and set
      m_pMultiplyDivide = 0;               // pointer in logic unit to null
   }

   if(m_pAddSubtract)                      // m_pAddSubtract is a pointer to
   {                                       // any previous + or - object
      m_pAddSubtract->DoOperation(this);   // Execute previous + or -
      delete m_pAddSubtract;               // Now delete object
   }
   else
      // If there was none, save the display register
      m_AddReg = m_DisplayReg;

   // Create a new operation object & signal start of value in display
   m_pAddSubtract = new CSubtract();
   m_DisplayReg.SetBeginValue();
   return;
}

// Process an Enter message
void CLogicUnit::OnEnter()
{
   if(m_pMultiplyDivide)                   // m_pMultiplyDivide is a pointer
   {                                       // to any previous * or / object
      m_pMultiplyDivide->DoOperation(this);// Execute previous * or /
      delete m_pMultiplyDivide;            // Now delete the object
      m_pMultiplyDivide = 0;               // and set pointer in logic
   }                                       // unit to null

   if(m_pAddSubtract)                      // m_pAddSubtract is a pointer to 
   {                                       // any previous + or - object
      m_pAddSubtract->DoOperation(this);   // Execute previous + or -
      delete m_pAddSubtract;               // Now delete object
      m_pAddSubtract = 0;                  // Set pointer to null
   }

   // Show result in display
   m_pCalc->GetDisplay()->ShowRegister(m_DisplayReg);
   m_DisplayReg.SetBeginValue();           // Set start of value flag
   return;
}

double CLogicUnit::GetDisplayValue()
{
	return m_DisplayReg.Get();
}

double CLogicUnit::OnRightParenthesis()
{
   if(m_pMultiplyDivide)                   // m_pMultiplyDivide is a pointer
   {                                       // to any previous * or / object
      m_pMultiplyDivide->DoOperation(this);// Execute previous * or /
      delete m_pMultiplyDivide;            // Now delete the object
      m_pMultiplyDivide = 0;               // and set pointer in LU to null
   }

   if(m_pAddSubtract)                      // m_pAddSubtract is a pointer to 
   {                                       // any previous + or - object
      m_pAddSubtract->DoOperation(this);   // Execute previous + or -
      delete m_pAddSubtract;               // Now delete object
      m_pAddSubtract = 0;                  // Set pointer to null
   }

   return m_DisplayReg.Get();              // Return the register value
}

// Process a left parenthesis message
void CLogicUnit::OnLeftParenthesis()
{
   CCalculator* pCalc = new CCalculator();     // Create a calculator

   // Run the calculator and set the result in the display register
   m_DisplayReg.Set(pCalc->Run());
   delete pCalc;                               // Destroy the calculator
}
