// Divide.h: interface for the CDivide class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIVIDE_H__FA599AAE_17DF_11D2_B731_BD7D79977406__INCLUDED_)
#define AFX_DIVIDE_H__FA599AAE_17DF_11D2_B731_BD7D79977406__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Operation.h"

class CDivide : public COperation  
{
public:
	void DoOperation(CLogicUnit* pLogicUnit);
	CDivide();
	virtual ~CDivide();

};

#endif // !defined(AFX_DIVIDE_H__FA599AAE_17DF_11D2_B731_BD7D79977406__INCLUDED_)
