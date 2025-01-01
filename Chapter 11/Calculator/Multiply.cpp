// Multiply.cpp: implementation of the CMultiply class.
//
//////////////////////////////////////////////////////////////////////

#include "Multiply.h"
#include "Register.h"
#include "LogicUnit.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMultiply::CMultiply()
{

}

CMultiply::~CMultiply()
{

}

void CMultiply::DoOperation(CLogicUnit *pLogicUnit)
{
   pLogicUnit->m_MultiplyReg *= pLogicUnit->m_DisplayReg;
   pLogicUnit->m_DisplayReg = pLogicUnit->m_MultiplyReg;
   return;
}
