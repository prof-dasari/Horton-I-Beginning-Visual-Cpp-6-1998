// Add.cpp: implementation of the CAdd class.
//
//////////////////////////////////////////////////////////////////////

#include "Add.h"
#include "Register.h"
#include "LogicUnit.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdd::CAdd()
{

}

CAdd::~CAdd()
{

}

void CAdd::DoOperation(CLogicUnit *pLogicUnit)
{
   pLogicUnit->m_AddReg += pLogicUnit->m_DisplayReg;
   pLogicUnit->m_DisplayReg = pLogicUnit->m_AddReg;
   return;
}
