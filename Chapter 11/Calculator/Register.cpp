// Register.cpp: implementation of the CRegister class.
//
//////////////////////////////////////////////////////////////////////

#include "Register.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Constructor
CRegister::CRegister()
{
   Reset();                          // Initialize the data members
}

CRegister::~CRegister()
{

}

// Handle a decimal point
void CRegister::OnDecimalPoint()
{
   if(m_bBeginValue)           // Check if we are starting a new number
   {
      m_bBeginValue = 0;       // If so, set the indicator to zero
      m_Store = 0.0;           // and reset the value in the member m_Store
   }

   m_Factor = 1.0;             // Set the decimal point indicator
}

// Function to accept a keyed digit
void CRegister::OnDigit(const int& digit)
{
   if(m_bBeginValue)                   // Check if we are at the start of a number,
   {                                   // if so reset the CRegister components
      m_bBeginValue = 0;                   // Reset begin flag 
      m_Store = 0.0;                       // Reset storage
      m_Factor = 0.0;                      // Reset decimal point factor
   }

   if(m_Factor > 0.0)                      // Test decimal point factor,
   {                                       // positive value indicates decimals
      m_Factor *= 0.1;                     // Shift decimal place
      m_Store += digit*m_Factor;           // Add digit to storage
   }
   else
      m_Store = 10.0 * m_Store + digit;    // Add digit to storage
}

// Initialize the flag indicating a new number
void CRegister::SetBeginValue()
{
   m_bBeginValue = 1; 
}

// Reset the register
void CRegister::Reset()
{
   m_Store = 0.0;
   m_Factor = 0.0;
   m_bBeginValue = 1;
}

// Set the register value
void CRegister::Set(const double& value)
{
   m_Store = value;
}

// Get the register value
double CRegister::Get()
{
   return m_Store;
}

// += operation
CRegister& CRegister::operator+=(const CRegister& rhs)
{
   m_Store += rhs.m_Store;
   return *this;
}

// -= operation
CRegister& CRegister::operator-=(const CRegister& rhs)
{
   m_Store -= rhs.m_Store;
   return *this;
}

// *= operation
CRegister& CRegister::operator*=(const CRegister& rhs)
{
   m_Store *= rhs.m_Store;
   return *this;
}

// /= operation
CRegister& CRegister::operator/=(const CRegister& rhs)
{
   m_Store /= rhs.m_Store;
   return *this;
}
