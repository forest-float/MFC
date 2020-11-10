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
   // typedef HANDLE(_stdcall *Connect)(int, int); //函数声明//_stdcall是Pascal程序的缺省调用方式
	static HANDLE comhald; //定义全局端口句柄
	static int s_address; //全局变量 
	static char * xtsz_tille;
	static CPropertySheet *pSheet;
	static CTabCtrl * pTab ;
	static unsigned char *buff;//返回数据存放位置
	static char * temp300;
	static char * temp50;
	static char flag_from_buze; //标记 调用 打开/关闭事件来自于窗口(0)/设置波特率(1)
	static int cur_buze;
	static int  language_flag ;//
	static COLORREF m_bkEdit_Color;
	static CStatusBarCtrl *  m_StatusBar;   

	static char * api_error( int api_return);//动态库api函数返回出错值转换
	static char * return_code_error(unsigned char * buff);//读写器状态返回码转换
	static CString time_use(void);
	static char * strtohexstr(char * str);//去掉字符中非16进制的字符
	static void uctoc(unsigned char * str, int n);//转换16进制数据为字符
	static unsigned char * ctouc(char * str);
	static void inti(void);
	//static int f(int y); //全局函数 

protected:

private:
	
};

#endif // !defined(AFX_PUBLIC_H__EC72675A_345F_48BD_8858_C0335D74DEED__INCLUDED_)
