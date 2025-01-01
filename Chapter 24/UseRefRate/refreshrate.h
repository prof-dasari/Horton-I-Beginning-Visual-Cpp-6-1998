// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IRefRate wrapper class

class IRefRate : public COleDispatchDriver
{
public:
   IRefRate() {}     // Calls COleDispatchDriver default constructor
   IRefRate(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
   IRefRate(const IRefRate& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
   long RefreshRate(long HScan);
   long GetVRes();
   long GetHRes();
};
