
// MFCtest01.h : MFCtest01 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCtest01App:
// �йش����ʵ�֣������ MFCtest01.cpp
//
//������������������
class CMFCtest01App : public CWinApp
{
public:
	CMFCtest01App();


// ��д
public:
	virtual BOOL InitInstance();//�ú������ڳ�������֮�󣬴�����ʾ֮ǰ����
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	// ���� GDIPlus ����Ҫ�ı���
	ULONG_PTR m_tokenGdiplus;//unsigned long ==ULONG_PTR
	Gdiplus::GdiplusStartupInput input;//��ͼ�������
	Gdiplus::GdiplusStartupOutput output;//��ͼ������
};

extern CMFCtest01App theApp;
