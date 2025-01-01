/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Oct 09 14:29:15 1998
 */
/* Compiler settings for C:\ary\VC6_apps\ATLSignal\ATLSignal.idl:
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

const IID IID_ISignal = {0xCACE7C2D,0x5C4E,0x11D2,{0x96,0x3F,0x00,0xA0,0xC9,0x4C,0xB8,0xB3}};


const IID LIBID_ATLSIGNALLib = {0xCACE7C21,0x5C4E,0x11D2,{0x96,0x3F,0x00,0xA0,0xC9,0x4C,0xB8,0xB3}};


const IID DIID__ISignalEvents = {0xCACE7C2F,0x5C4E,0x11D2,{0x96,0x3F,0x00,0xA0,0xC9,0x4C,0xB8,0xB3}};


const CLSID CLSID_Signal = {0xCACE7C2E,0x5C4E,0x11D2,{0x96,0x3F,0x00,0xA0,0xC9,0x4C,0xB8,0xB3}};


#ifdef __cplusplus
}
#endif

