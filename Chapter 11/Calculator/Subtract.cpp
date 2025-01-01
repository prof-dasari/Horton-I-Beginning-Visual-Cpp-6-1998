// Subtract.cpp: implementation of the CSubtract class.
//
//////////////////////////////////////////////////////////////////////

#include "Subtract.h"
#include "Register.h"
#include "LogicUnit.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSubtract::CSubtract()
{

}

CSubtract::~CSubtract()
{

}

void CSubtract::DoOperation(CLogicUnit *pLogicUnit)
{
   pLogicUnit->m_AddReg -= pLogicUnit->m_DisplayReg;
   pLogicUnit->m_DisplayReg = pLogicUnit->m_AddReg;
   return;
}
