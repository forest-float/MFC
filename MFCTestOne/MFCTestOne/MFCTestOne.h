
// MFCTestOne.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCTestOneApp: 
// �йش����ʵ�֣������ MFCTestOne.cpp
//

class CMFCTestOneApp : public CWinApp
{
public:
	CMFCTestOneApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCTestOneApp theApp;