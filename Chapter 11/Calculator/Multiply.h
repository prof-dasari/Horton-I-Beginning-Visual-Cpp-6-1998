// Multiply.h: interface for the CMultiply class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIPLY_H__FA599AAB_17DF_11D2_B731_BD7D79977406__INCLUDED_)
#define AFX_MULTIPLY_H__FA599AAB_17DF_11D2_B731_BD7D79977406__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Operation.h"

class CMultiply : public COperation  
{
public:
	void DoOperation(CLogicUnit* pLogicUnit);
	CMultiply();
	virtual ~CMultiply();

};

#endif // !defined(AFX_MULTIPLY_H__FA599AAB_17DF_11D2_B731_BD7D79977406__INCLUDED_)
