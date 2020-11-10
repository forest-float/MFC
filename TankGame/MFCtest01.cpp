
// MFCtest01.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCtest01.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtest01App

BEGIN_MESSAGE_MAP(CMFCtest01App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMFCtest01App::OnAppAbout)
END_MESSAGE_MAP()


// CMFCtest01App ����

CMFCtest01App::CMFCtest01App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���: 
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCtest01.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CMFCtest01App ����

CMFCtest01App theApp;


// CMFCtest01App ��ʼ��

BOOL CMFCtest01App::InitInstance()
{
	
	CWinApp::InitInstance();
	//Gdiplus+��ʼ��
	Status s = GdiplusStartup(&m_tokenGdiplus, &input, &output);

	CMainFrame * pFrame = new CMainFrame;
	if (!pFrame)
	{
		return FALSE;
	}
	
	m_pMainWnd = pFrame;//�ó�Ա�����洢�߳������ڶ���
	//û����һ�д���ᵼ�³���һ���Ӿ͹ر���

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CMFCtest01App::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CMFCtest01App ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CMFCtest01App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMFCtest01App ��Ϣ�������





void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
