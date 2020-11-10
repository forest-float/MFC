// Public.h: interface for the CPublic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUBLIC_H__EC72675A_345F_48BD_8858_C0335D74DEED__INCLUDED_)
#define AFX_PUBLIC_H__EC72675A_345F_48BD_8858_C0335D74DEED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HIDdll.h"

class CPublic  
{
public:
	CPublic();
	virtual ~CPublic();
public:
	void init_StatusBar(void);
   // typedef HANDLE(_stdcall *Connect)(int, int); //��������//_stdcall��Pascal�����ȱʡ���÷�ʽ
	static HANDLE comhald; //����ȫ�ֶ˿ھ��
	static int s_address; //ȫ�ֱ��� 
	static char * xtsz_tille;
	static CPropertySheet *pSheet;
	static CTabCtrl * pTab ;
	static unsigned char *buff;//�������ݴ��λ��
	static char * temp300;
	static char * temp50;
	static char flag_from_buze; //��� ���� ��/�ر��¼������ڴ���(0)/���ò�����(1)
	static int cur_buze;
	static int  language_flag ;//
	static COLORREF m_bkEdit_Color;
	static CStatusBarCtrl *  m_StatusBar;   

	static char * api_error( int api_return);//��̬��api�������س���ֵת��
	static char * return_code_error(unsigned char * buff);//��д��״̬������ת��
	static CString time_use(void);
	static char * strtohexstr(char * str);//ȥ���ַ��з�16���Ƶ��ַ�
	static void uctoc(unsigned char * str, int n);//ת��16��������Ϊ�ַ�
	static unsigned char * ctouc(char * str);
	static void inti(void);
	//static int f(int y); //ȫ�ֺ��� 

protected:

private:
	
};

#endif // !defined(AFX_PUBLIC_H__EC72675A_345F_48BD_8858_C0335D74DEED__INCLUDED_)
