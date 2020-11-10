// HIDdll.h : main header file for the HIDDLL DLL
//

#if !defined(AFX_HIDDLL_H__9923E160_6337_4385_8102_40E09E0E4410__INCLUDED_)
#define AFX_HIDDLL_H__9923E160_6337_4385_8102_40E09E0E4410__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

extern "C" {
#include "hidsdi.h"
}
#include "setupapi.h"
#include "stdlib.h"

#define HID_DEVICE_SUCCESS				0x00
#define HID_DEVICE_NOT_FOUND			0x01
#define HID_DEVICE_NOT_OPENED			0x02
#define HID_DEVICE_ALREADY_OPENED		0x03
#define	HID_DEVICE_TRANSFER_TIMEOUT		0x04
#define HID_DEVICE_TRANSFER_FAILED		0x05
#define HID_DEVICE_CANNOT_GET_HID_INFO	0x06
#define HID_DEVICE_HANDLE_ERROR			0x07
#define HID_DEVICE_INVALID_BUFFER_SIZE	0x08
#define HID_DEVICE_SYSTEM_CODE			0x09
#define HID_DEVICE_UNKNOWN_ERROR		0xFF

// Max number of USB Devices allowed
#define MAX_USB_DEVICES	64

// Max number of reports that can be requested at time
#define MAX_REPORT_REQUEST_XP	512
#define MAX_REPORT_REQUEST_2K	200

#define DEFAULT_REPORT_INPUT_BUFFERS	0

#define MAX_SERIAL_STRING_LENGTH	256

/////////////////////////////////////////////////////////////////////////////
// CHIDdllApp
// See HIDdll.cpp for the implementation of this class
//

class CHIDdllApp : public CWinApp
{
public:
	//WORD GetConnectedDeviceNum(WORD vid, WORD pid);
	//int GetConnectedDeviceNum(void);
	CHIDdllApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHIDdllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CHIDdllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


extern "C" __declspec(dllexport) int __stdcall API_USBGetSerNum(HANDLE commHandle, int DeviceAddress,unsigned char *buffer);
extern "C" __declspec(dllexport) int __stdcall API_USBAll(HANDLE commHandle,int DeviceAddress,int cmdSize, unsigned char *cmd,  unsigned char *returnlen, unsigned char *pbuffer);


extern "C" __declspec(dllexport) int  __stdcall API_USBGetConnectedDeviceNum(void);
extern "C" __declspec(dllexport) int  __stdcall API_USBOpenWithNum(HANDLE * hcomm,int deviceIndex, WORD numInputBuffers);
extern "C" __declspec(dllexport) BOOL __stdcall API_USBCloseComm(HANDLE commHandle);
extern "C" __declspec(dllexport) int __stdcall API_USBControlLED(HANDLE commHandle, int DeviceAddress,unsigned char freq, unsigned char duration, unsigned char *buffer);
extern "C" __declspec(dllexport) int __stdcall API_USBControlBuzzer(HANDLE commHandle, int DeviceAddress,unsigned char freq, unsigned char duration,unsigned char *buffer);
/////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
//ISO14443 Functions.
// ISO14443 Type-A Functions 
extern "C" __declspec(dllexport) int __stdcall API_USBMF_Request(
                                                   HANDLE commHandle, int DeviceAddress, 
                                                   unsigned char inf_mode, unsigned char *Buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_Anticoll(
	                                            HANDLE commHandle, int DeviceAddress,
	                                            unsigned char *flag,unsigned char *uid);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_Select(
	                                            HANDLE commHandle, int DeviceAddress,
	                                            unsigned char *uid, unsigned char len, unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_Halt(
	                                            HANDLE commHandle, int DeviceAddress);


//Mifare application functions. for Type A

extern "C" __declspec(dllexport) int __stdcall API_USBMF_Read(
                                                   HANDLE commHandle, int DeviceAddress,
                                                   unsigned char mode,  unsigned char blk_add, unsigned char num_blk,
							  unsigned char *snr, unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_Write(
	                                            HANDLE commHandle, int DeviceAddress,
	                                            unsigned char mode, unsigned char blk_add, unsigned char num_blk,
							  unsigned char *key, unsigned char *text, unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_InitVal(
	                                            HANDLE commHandle, int DeviceAddress,
	                                            unsigned char mode, unsigned char sec_num,
							  unsigned char *key, int value, unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall  API_USBMF_Dec(
	                                            HANDLE commHandle, int DeviceAddress,
	                                            unsigned char mode,unsigned char sec_num,
                                                   unsigned char *key, int *value, unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_Inc(
	                                            HANDLE commHandle, int DeviceAddress,
	                                            unsigned char mode,unsigned char sec_num,
                                                   unsigned char *key, int *value, unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_GET_SNR(
	                                            HANDLE  commHandle,int DeviceAddress, 
	                                            unsigned char mode,unsigned char cmd,unsigned char *flag, 
	                                            unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_Value(
	                                            HANDLE  commHandle,int DeviceAddress, 
	                                            unsigned char mode,unsigned char add_blk,int value);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_PowerOn(
	                                            HANDLE  commHandle,int DeviceAddress, 
	                                            unsigned char mode,unsigned char cmd,unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_TransferCMD(
	                                            HANDLE   commHandle,int DeviceAddress, 
	                                            unsigned char mode, unsigned char *cmd, unsigned char *cmdlength, 
												unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_RST_Antenna(
	                                           HANDLE  commHandle,int DeviceAddress,unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_Copy_Block(
	                                           HANDLE  commHandle,int DeviceAddress,
	                                           unsigned char add_blk, unsigned char key, 
	                                           unsigned char *keyvalue,unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBMF_Auth(
	                                           HANDLE  commHandle,int DeviceAddress,
	                                           unsigned char mode, unsigned char add_blk, unsigned char *keyvalue);







///////ISO15693///
//extern "C" __declspec(dllexport) int __stdcall API_ISO15693_TransCmd(HANDLE commHandle, int DeviceAddress, int cmdSize, unsigned char *cmd,  unsigned char *returnlen, unsigned char *pbuffer);
//////////////////////////////////////////////////////////////////////
//ISO15693 Functions.
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_Inventory(
                                                  HANDLE commHandle, int deviceAddress,
                                                  unsigned char flag, unsigned char afi,unsigned char datalen,
                                                  const unsigned char *pData,unsigned char *nrOfCard,
                                                  unsigned char *pBuffer);

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_Read(
	                                            HANDLE commHandle,int DeviceAddress,unsigned char flags,
                                                   unsigned char blk_add,unsigned char num_blk,
                                                   unsigned char *uid, unsigned char *returnlen, unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_Write(
	                                            HANDLE commHandle,int DeviceAddress,unsigned char flags,
                                                   unsigned char blk_add,unsigned char num_blk,
                                                   unsigned char *uid, unsigned char *data);


extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_Lock(
	                                            HANDLE commHandle,int DeviceAddress,unsigned char flags,
                                                   unsigned char num_blk,
                                                   unsigned char *uid,unsigned char  *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_StayQuiet(
	                                            HANDLE commHandle,int DeviceAddress,unsigned char flags,
                                                   unsigned char *uid,  unsigned char  *buffer );

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_Select(
	                                           HANDLE commHandle,int DeviceAddress,unsigned char flags,
                                                  unsigned char *uid,  unsigned char  *buffer );

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_ResetToReady(
	                                           HANDLE commHandle,int DeviceAddress,unsigned char flags,
                                                  unsigned char *uid,  unsigned char  *buffer );

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_WriteAFI(
	                                           HANDLE commHandle,int DeviceAddress,unsigned char flags,
	                                           unsigned char  afi,unsigned char *uid,  unsigned char  *buffer );

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_LockAFI(
	                                          HANDLE commHandle,int DeviceAddress,unsigned char flags,
                                                 unsigned char *uid,  unsigned char  *buffer );

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_WriteDSFID(
	                                          HANDLE commHandle,int DeviceAddress,unsigned char flags,
	                                          unsigned char  DSFID,unsigned char *uid,  unsigned char  *buffer );

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_LockDSFID(
	                                          HANDLE commHandle,int DeviceAddress,unsigned char flags,
                                                 unsigned char *uid,  unsigned char  *buffer );

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_GetSysInfo(
	                                          HANDLE commHandle, int deviceAddress,
                                                 unsigned char flag, unsigned char *uid, unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_GetMulSecurity(
	                                          HANDLE commHandle, int deviceAddress,
                                                 unsigned char flag, unsigned char blkAddr, unsigned char blkNum,
                                                 const unsigned char *uid, unsigned char *flags, unsigned char *returnlen, 
                                                 unsigned char *pBuffer);
 
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_TransCmd(
	                                          HANDLE commHandle, int DeviceAddress, int cmdSize, 
	                                          unsigned char *cmd, unsigned char *returnlen, unsigned char *pbuffer);

//iso15693 NXP SL@ ICS53 secret command  by level

extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_SetPWS(HANDLE commHandle, int deviceAddress,
                                unsigned char flag, const unsigned char *uid, 
								unsigned char PWS_Identifier, unsigned char *PassWordS, 
								unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_WritePWS(HANDLE commHandle, int deviceAddress,
                                unsigned char flag, const unsigned char *uid, 
								unsigned char PWS_Identifier, unsigned char *PassWordS, 
								unsigned char pws_flag,unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_ProtectPage(HANDLE commHandle, int deviceAddress,
                                unsigned char flag, const unsigned char *uid, 
								unsigned char Page_number, unsigned char Protect_Mode,
								unsigned char Mode_State, unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_PWS64Protect(HANDLE commHandle, int deviceAddress,
                                unsigned char flag, const unsigned char *uid, unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_ProtectStatus(HANDLE commHandle, int deviceAddress,
                                unsigned char flag, const unsigned char *uid, 
								unsigned char first_number, unsigned char number_block,
								 unsigned char *pBuffer);
extern "C" __declspec(dllexport)  int __stdcall API_USBISO15693_DestroySLI(HANDLE commHandle, int deviceAddress,unsigned char flag, 
						const unsigned char *uid, unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_EnablePrivacy(HANDLE commHandle, int deviceAddress,
                                unsigned char flag, const unsigned char *uid, unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_PageRead(HANDLE commHandle, int deviceAddress,
                                unsigned char flag, const unsigned char afi, 
								unsigned char first_number, unsigned char number_block,
								 unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_OperateEAS(HANDLE commHandle, int deviceAddress,
                                unsigned char flag, const unsigned char *uid, unsigned char mode,unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBISO15693_AlarmEAS(HANDLE commHandle, int deviceAddress,
                  unsigned char flag, const unsigned char *uid, unsigned char mask_length,
				  const unsigned char *mask_value,unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBWriteEASID(HANDLE commHandle, int deviceAddress,
                  unsigned char flag, const unsigned char *uid,
				  const unsigned char *mask_value,unsigned char *pBuffer);
extern "C" __declspec(dllexport) int __stdcall API_USBReadEPC(HANDLE commHandle, int deviceAddress,
                  unsigned char flag, const unsigned char *uid, unsigned char *pBuffer);

extern "C" __declspec(dllexport) int __stdcall API_SetDeviceAddress( HANDLE commHandle, int deviceAddress, unsigned char newAddr, unsigned char *buffer);

extern "C" __declspec(dllexport) int __stdcall API_SetSerNum(HANDLE commHandle, int DeviceAddress, unsigned char *newValue, unsigned char *buffer);
/////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////UL
extern  "C" __declspec(dllexport) int __stdcall API_USBUL_ReadPage(HANDLE commHandle, int DeviceAddress, unsigned char mode, 
																   unsigned char num_blk, unsigned char blk_add,unsigned char *buffer);

extern  "C" __declspec(dllexport) int __stdcall API_USBUL_WritePage(HANDLE commHandle, int DeviceAddress,unsigned char mode, 
													unsigned char num_blk, unsigned char blk_add, unsigned char *buffer);
///////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDDLL_H__9923E160_6337_4385_8102_40E09E0E4410__INCLUDED_)
