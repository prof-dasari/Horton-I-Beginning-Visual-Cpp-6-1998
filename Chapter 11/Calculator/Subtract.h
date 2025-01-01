// Subtract.h: interface for the CSubtract class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUBTRACT_H__FA599AAD_17DF_11D2_B731_BD7D79977406__INCLUDED_)
#define AFX_SUBTRACT_H__FA599AAD_17DF_11D2_B731_BD7D79977406__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Operation.h"

class CSubtract : public COperation  
{
public:
	void DoOperation(CLogicUnit* pLogicUnit);
	CSubtract();
	virtual ~CSubtract();

};

#endif // !defined(AFX_SUBTRACT_H__FA599AAD_17DF_11D2_B731_BD7D79977406__INCLUDED_)
