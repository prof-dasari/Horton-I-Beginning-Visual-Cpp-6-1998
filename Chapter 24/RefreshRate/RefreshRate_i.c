/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Oct 07 13:56:30 1998
 */
/* Compiler settings for RefreshRate.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IRefRate = {0xB34EF5CF,0x7B79,0x11D0,{0x96,0xFE,0x00,0x20,0x18,0x34,0x98,0x16}};


const IID LIBID_REFRESHRATELib = {0xB34EF5C2,0x7B79,0x11D0,{0x96,0xFE,0x00,0x20,0x18,0x34,0x98,0x16}};


const CLSID CLSID_RefRate = {0xB34EF5D0,0x7B79,0x11D0,{0x96,0xFE,0x00,0x20,0x18,0x34,0x98,0x16}};


#ifdef __cplusplus
}
#endif

