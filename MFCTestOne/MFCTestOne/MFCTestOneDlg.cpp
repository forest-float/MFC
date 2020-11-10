
// MFCTestOneDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCTestOne.h"
#include "MFCTestOneDlg.h"
#include "afxdialogex.h"
#include "Public.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCTestOneDlg �Ի���



CMFCTestOneDlg::CMFCTestOneDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCTESTONE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTestOneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, ide_edit1);//���ı����������ϵ����
	DDV_MaxChars(pDX, ide_edit1, 23);//���ñ��������Ԫ�ظ���
	DDX_Control(pDX, IDC_COMBO1, box1);//ѡ���б�
	DDX_Control(pDX, IDC_COMBO2, box2);//ѡ���б�
	DDX_Control(pDX, IDC_COMBO3, box3);//ѡ���б�
	DDX_Control(pDX, IDC_EDIT2, cedit);//��ʾ��ֻ������
	DDX_Text(pDX, IDC_EDIT2, message);
	DDX_Text(pDX, IDC_EDIT3, ide_edit3);
	DDX_Text(pDX, IDC_EDIT4, ide_edit4);
}

BEGIN_MESSAGE_MAP(CMFCTestOneDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCTestOneDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCTestOneDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCTestOneDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCTestOneDlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCTestOneDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCTestOneDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCTestOneDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCTestOneDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCTestOneDlg::OnCbnSelchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCTestOneDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCTestOneDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCTestOneDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCTestOneDlg::OnBnClickedButton6)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CMFCTestOneDlg::OnCbnSelchangeCombo3)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCTestOneDlg::OnEnChangeEdit4)
END_MESSAGE_MAP()


// CMFCTestOneDlg ��Ϣ�������

BOOL CMFCTestOneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	{
		SetDlgItemText(IDC_EDIT1, _T(""));
		ide_edit1 = _T("");
		ide_edit3 = _T("");
		ide_edit4 = _T("");
	}
	{
		box1.ResetContent();
		box1.InsertString(0, _T("COM1"));
		box1.InsertString(1, _T("COM2"));
		box1.InsertString(2, _T("COM3"));
		box1.SetCurSel(0);
	}
	{
		CString str1;
		box2.ResetContent();
		for (int i = 0; i < 16; i++)
		{
			str1.Format("%02x ", i);
			box2.InsertString(i, str1);
		}		
		box2.SetCurSel(0);
	}
	{
		box3.ResetContent();
		box3.InsertString(0, _T("14443A"));
		box3.InsertString(1, _T("15693"));
		box3.InsertString(2, _T("CPUA"));
		box3.InsertString(3, _T("CPUB"));
		box3.SetCurSel(0);
	}
	{
		message = _T("");
	}
	
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCTestOneDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCTestOneDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCTestOneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTestOneDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMFCTestOneDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CMFCTestOneDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ide_edit1 = _T("00 00 00 00 00 00");
	NotOpencom(2);
	ul_update();
	AfxMessageBox(_T("Ѱ���ɹ�"));
}

////CString ʹ�÷���ʾ��
//CString strTemp = _T("MFC Tutorial");
////(1)��ȡ�ַ����ĳ���
////����� iLength=12,�м�Ŀո�Ҳ��һ���ַ�
//int iLength = strTemp.GetLength();
////(2)��ȡ�ַ���strTemp�ĵ������ַ�
////�����cFlag=��C��
//char cFlag = strTemp.GetAt(2);
////(3)��������ת�� ��char���ַ�ת��ΪCString���� �������͵�ת�����ݽ϶࣬����ᵥ������
////�����strS=_T("C");
//CString strS = _T("");
//strS.Format(_T("%c"), cFlag);
////(4)�ַ����Ƚ� Compare�������������һ�£�����0;��һ�£�����-1
////�����iResult0==0��iResult1==-1��iResult2=1
//int iResult0 = strTemp.Compare(_T("MFC Tutorial"));
//int iResult1 = strTemp.Compare(_T("MFC TutorialX"));
//int iResult2 = strTemp.Compare(_T("MFC TutoRiaL"));
////(5)�ַ����Ƚ� CompareNoCase������������������ִ�Сдһ�£�����0;
////�����iResult3==0��iResult4==0��iResult5==-120
//int iResult3 = strTemp.CompareNoCase(_T("MFC Tutorial"));
//int iResult4 = strTemp.CompareNoCase(_T("MFC TutoRiaL"));
//int iResult5 = strTemp.CompareNoCase(_T("MFC TutoRiaLX"));
////(5)��ΪСд
////���mfc tutorial
//CString strLower = strTemp.MakeLower();
////(6)��Ϊ��д
////���MFC TUTORIAL
//CString strUpper = strTemp.MakeUpper();
////(6)��ȡ������ַ���
////���LAIROTUT CFM
//CString strReverse = strTemp.MakeReverse();


void CMFCTestOneDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	

}


void CMFCTestOneDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCTestOneDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NotOpencom(0);
	AfxMessageBox(_T("�����ɹ�"));
}


void CMFCTestOneDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CMFCTestOneDlg::ul_update(void)
{
	UpdateData(FALSE);
	//GetLineCount�õ�������
	//������ͼ�Ĺ�������    ����  �ֽ���
	cedit.LineScroll(cedit.GetLineCount() - 1, 0);
}

void CMFCTestOneDlg::NotOpencom(int i)
{
	
	switch (i) {
	case 0:		
		message += "������\"��������\"�д򿪴���\r\n";
		break;
	case 1:		
		message += "��̬��û���ҵ�\n";		
		break;
	case 2:		
		message += "\r\n��������Ϊ:\n";		
		break;
	}
	message += CPublic::time_use();
	ul_update();
	//
	//ul_update();
}



void CMFCTestOneDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	message = _T("");
	ul_update();
}


void CMFCTestOneDlg::OnCbnSelchangeCombo2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCTestOneDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCTestOneDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NotOpencom(2);
	ul_update();
}


void CMFCTestOneDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NotOpencom(2);
	ul_update();
	AfxMessageBox("��ֵ�ɹ�");
	AfxMessageBox("��ֵʧ��");
}


void CMFCTestOneDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCTestOneDlg::OnCbnSelchangeCombo3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCTestOneDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
