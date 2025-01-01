/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Oct 07 13:56:30 1998
 */
/* Compiler settings for RefreshRate.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __RefreshRate_h__
#define __RefreshRate_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IRefRate_FWD_DEFINED__
#define __IRefRate_FWD_DEFINED__
typedef interface IRefRate IRefRate;
#endif 	/* __IRefRate_FWD_DEFINED__ */


#ifndef __RefRate_FWD_DEFINED__
#define __RefRate_FWD_DEFINED__

#ifdef __cplusplus
typedef class RefRate RefRate;
#else
typedef struct RefRate RefRate;
#endif /* __cplusplus */

#endif 	/* __RefRate_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IRefRate_INTERFACE_DEFINED__
#define __IRefRate_INTERFACE_DEFINED__

/* interface IRefRate */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRefRate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B34EF5CF-7B79-11D0-96FE-002018349816")
    IRefRate : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RefreshRate( 
            /* [in] */ long HScan,
            /* [retval][out] */ long __RPC_FAR *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVRes( 
            /* [retval][out] */ long __RPC_FAR *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHRes( 
            /* [retval][out] */ long __RPC_FAR *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRefRateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRefRate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRefRate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRefRate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRefRate __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRefRate __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRefRate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRefRate __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RefreshRate )( 
            IRefRate __RPC_FAR * This,
            /* [in] */ long HScan,
            /* [retval][out] */ long __RPC_FAR *retval);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVRes )( 
            IRefRate __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *retval);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHRes )( 
            IRefRate __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *retval);
        
        END_INTERFACE
    } IRefRateVtbl;

    interface IRefRate
    {
        CONST_VTBL struct IRefRateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRefRate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRefRate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRefRate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRefRate_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRefRate_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRefRate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRefRate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRefRate_RefreshRate(This,HScan,retval)	\
    (This)->lpVtbl -> RefreshRate(This,HScan,retval)

#define IRefRate_GetVRes(This,retval)	\
    (This)->lpVtbl -> GetVRes(This,retval)

#define IRefRate_GetHRes(This,retval)	\
    (This)->lpVtbl -> GetHRes(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRefRate_RefreshRate_Proxy( 
    IRefRate __RPC_FAR * This,
    /* [in] */ long HScan,
    /* [retval][out] */ long __RPC_FAR *retval);


void __RPC_STUB IRefRate_RefreshRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRefRate_GetVRes_Proxy( 
    IRefRate __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *retval);


void __RPC_STUB IRefRate_GetVRes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRefRate_GetHRes_Proxy( 
    IRefRate __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *retval);


void __RPC_STUB IRefRate_GetHRes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRefRate_INTERFACE_DEFINED__ */



#ifndef __REFRESHRATELib_LIBRARY_DEFINED__
#define __REFRESHRATELib_LIBRARY_DEFINED__

/* library REFRESHRATELib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_REFRESHRATELib;

EXTERN_C const CLSID CLSID_RefRate;

#ifdef __cplusplus

class DECLSPEC_UUID("B34EF5D0-7B79-11D0-96FE-002018349816")
RefRate;
#endif
#endif /* __REFRESHRATELib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
