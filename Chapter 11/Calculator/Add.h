// Add.h: interface for the CAdd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADD_H__FA599AAC_17DF_11D2_B731_BD7D79977406__INCLUDED_)
#define AFX_ADD_H__FA599AAC_17DF_11D2_B731_BD7D79977406__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Operation.h"

class CAdd : public COperation  
{
public:
	void DoOperation(CLogicUnit* pLogicUnit);
	CAdd();
	virtual ~CAdd();

};

#endif // !defined(AFX_ADD_H__FA599AAC_17DF_11D2_B731_BD7D79977406__INCLUDED_)
