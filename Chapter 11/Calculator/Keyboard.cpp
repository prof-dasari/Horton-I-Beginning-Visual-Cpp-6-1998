// Keyboard.cpp: implementation of the CKeyboard class.
//
//////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "Display.h"
#include "Register.h"
#include "LogicUnit.h"
#include "Keyboard.h"

#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CKeyboard::CKeyboard()
{

}

CKeyboard::~CKeyboard()
{

}

CKeyboard::CKeyboard(CCalculator* pCalc)
{
   m_pCalc = pCalc;
}

// Keyboard Manager function
double CKeyboard::GetKey()
{
   // Get a pointer to the logic unit
   CLogicUnit* pLogicUnit = m_pCalc->GetLogicUnit();

   char chKey = 0;                 // Key press stored here
   int bnExit = 0;                  // Flag to end calculator operation

   while(!bExit)                   // Get key presses until there's
   {                               // a reason not to...
      chKey = cin.get();           // Get a key depression

      switch (chKey)               // Test key press
      {
         case ' ':                 // For blank...
            break;                 // ...do nothing

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
            // For any digit send numeric value of digit to the logic unit
            pLogicUnit->OnDigit(chKey - '0');
            break;

         case '.':
            // Send decimal point to the logic unit
            pLogicUnit->OnDecimalPoint();
            break;

         case '(':                               // Left parenthesis
            pLogicUnit->OnLeftParenthesis();
            break;

         case ')':                               // Right parenthesis
            return pLogicUnit->OnRightParenthesis();
            break;

         case '*': 
            pLogicUnit->OnMultiply();            // Send a multiply message
            break;

         case '/':
            pLogicUnit->OnDivide();              // Send a divide message
            break;

         case '+':
            pLogicUnit->OnAdd();                 // Send an add message
            break;

         case '-':
            pLogicUnit->OnSubtract();            // Send a subtract message
            break;

         case 'Q': case 'q':                     // Quit key pressed
            bExit = 1;                           // So set flag to exit
            break;

         case 'c': case 'C':                     // Clear key pressed
            pLogicUnit->Reset();                 // so reset the logic unit
            break;

         case '\n':                              // Enter key pressed
            pLogicUnit->OnEnter();               // Send Enter message
            break;

         default:                                // Wrong key pressed
            bExit = 1;                           // so set flag to exit
      }
   }
   return pLogicUnit->GetDisplayValue();   // Return current display value
}
