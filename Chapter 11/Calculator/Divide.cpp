// Divide.cpp: implementation of the CDivide class.
//
//////////////////////////////////////////////////////////////////////

#include "Divide.h"
#include "Register.h"
#include "LogicUnit.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDivide::CDivide()
{

}

CDivide::~CDivide()
{

}

void CDivide::DoOperation(CLogicUnit *pLogicUnit)
{
   pLogicUnit->m_MultiplyReg /= pLogicUnit->m_DisplayReg;
   pLogicUnit->m_DisplayReg = pLogicUnit->m_MultiplyReg;
   return;

}
