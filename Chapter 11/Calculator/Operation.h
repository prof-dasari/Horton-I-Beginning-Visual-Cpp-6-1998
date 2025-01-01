// Operation.h: interface for the COperation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATION_H__FA599AAA_17DF_11D2_B731_BD7D79977406__INCLUDED_)
#define AFX_OPERATION_H__FA599AAA_17DF_11D2_B731_BD7D79977406__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLogicUnit;

class COperation  
{
public:
	//Pure virtual function
	virtual void DoOperation(CLogicUnit* pLogicUnit) =0;
	COperation();
	virtual ~COperation();

};

#endif // !defined(AFX_OPERATION_H__FA599AAA_17DF_11D2_B731_BD7D79977406__INCLUDED_)
