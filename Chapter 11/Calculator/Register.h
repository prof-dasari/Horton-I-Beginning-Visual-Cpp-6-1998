// Register.h: interface for the CRegister class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGISTER_H__2C61C10D_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
#define AFX_REGISTER_H__2C61C10D_5780_11D2_963F_00A0C94CB8B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRegister  
{
public:
    CRegister& operator-=(const CRegister& rhs);
    CRegister& operator+=(const CRegister& rhs);
    CRegister& operator/=(const CRegister& rhs);
    CRegister& operator*=(const CRegister& rhs);
    void Reset();                     // Reset the data members
    void SetBeginValue();             // Set the m_BeginValue flag
    double Get();                     // Get the value of m_Store
    void Set(const double& value);    // Set the value of m_Store
    void OnDecimalPoint();              // Function to handle a decimal point
    void OnDigit(const int& digit);     // Function to handle a keyed digit
	CRegister();
	virtual ~CRegister();

private:
	int m_bBeginValue;
	double m_Store;
	double m_Factor;
};

#endif // !defined(AFX_REGISTER_H__2C61C10D_5780_11D2_963F_00A0C94CB8B3__INCLUDED_)
