
// MFCtest01.h : MFCtest01 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFCtest01App:
// 有关此类的实现，请参阅 MFCtest01.cpp
//
//该类代表的是整个程序
class CMFCtest01App : public CWinApp
{
public:
	CMFCtest01App();


// 重写
public:
	virtual BOOL InitInstance();//该函数会在程序启动之后，窗口显示之前运行
	virtual int ExitInstance();

// 实现

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	// 引入 GDIPlus 所需要的变量
	ULONG_PTR m_tokenGdiplus;//unsigned long ==ULONG_PTR
	Gdiplus::GdiplusStartupInput input;//绘图库的输入
	Gdiplus::GdiplusStartupOutput output;//绘图库的输出
};

extern CMFCtest01App theApp;
