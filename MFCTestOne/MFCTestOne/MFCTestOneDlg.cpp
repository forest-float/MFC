
// MFCTestOneDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCTestOne.h"
#include "MFCTestOneDlg.h"
#include "afxdialogex.h"
#include "Public.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCTestOneDlg 对话框



CMFCTestOneDlg::CMFCTestOneDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCTESTONE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTestOneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, ide_edit1);//将文本框与变量联系起来
	DDV_MaxChars(pDX, ide_edit1, 23);//设置变量的最大元素个数
	DDX_Control(pDX, IDC_COMBO1, box1);//选择列表
	DDX_Control(pDX, IDC_COMBO2, box2);//选择列表
	DDX_Control(pDX, IDC_COMBO3, box3);//选择列表
	DDX_Control(pDX, IDC_EDIT2, cedit);//显示框，只读属性
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


// CMFCTestOneDlg 消息处理程序

BOOL CMFCTestOneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
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
	
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCTestOneDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCTestOneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTestOneDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFCTestOneDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMFCTestOneDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ide_edit1 = _T("00 00 00 00 00 00");
	NotOpencom(2);
	ul_update();
	AfxMessageBox(_T("寻卡成功"));
}

////CString 使用方法示例
//CString strTemp = _T("MFC Tutorial");
////(1)获取字符串的长度
////结果： iLength=12,中间的空格也算一个字符
//int iLength = strTemp.GetLength();
////(2)获取字符串strTemp的第三个字符
////结果：cFlag=‘C’
//char cFlag = strTemp.GetAt(2);
////(3)数据类型转换 将char型字符转换为CString类型 数据类型的转换内容较多，后面会单独讨论
////结果：strS=_T("C");
//CString strS = _T("");
//strS.Format(_T("%c"), cFlag);
////(4)字符串比较 Compare方法，如果两个一致，返回0;不一致，返回-1
////结果：iResult0==0；iResult1==-1；iResult2=1
//int iResult0 = strTemp.Compare(_T("MFC Tutorial"));
//int iResult1 = strTemp.Compare(_T("MFC TutorialX"));
//int iResult2 = strTemp.Compare(_T("MFC TutoRiaL"));
////(5)字符串比较 CompareNoCase方法，如果两个不区分大小写一致，返回0;
////结果：iResult3==0；iResult4==0；iResult5==-120
//int iResult3 = strTemp.CompareNoCase(_T("MFC Tutorial"));
//int iResult4 = strTemp.CompareNoCase(_T("MFC TutoRiaL"));
//int iResult5 = strTemp.CompareNoCase(_T("MFC TutoRiaLX"));
////(5)改为小写
////结果mfc tutorial
//CString strLower = strTemp.MakeLower();
////(6)改为大写
////结果MFC TUTORIAL
//CString strUpper = strTemp.MakeUpper();
////(6)获取逆序的字符串
////结果LAIROTUT CFM
//CString strReverse = strTemp.MakeReverse();


void CMFCTestOneDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	

}


void CMFCTestOneDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCTestOneDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	NotOpencom(0);
	AfxMessageBox(_T("发卡成功"));
}


void CMFCTestOneDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMFCTestOneDlg::ul_update(void)
{
	UpdateData(FALSE);
	//GetLineCount得到总行数
	//滚动视图的滚动行数    行数  字节数
	cedit.LineScroll(cedit.GetLineCount() - 1, 0);
}

void CMFCTestOneDlg::NotOpencom(int i)
{
	
	switch (i) {
	case 0:		
		message += "请先在\"参数设置\"中打开串口\r\n";
		break;
	case 1:		
		message += "动态库没有找到\n";		
		break;
	case 2:		
		message += "\r\n返回数据为:\n";		
		break;
	}
	message += CPublic::time_use();
	ul_update();
	//
	//ul_update();
}



void CMFCTestOneDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	message = _T("");
	ul_update();
}


void CMFCTestOneDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCTestOneDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCTestOneDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	NotOpencom(2);
	ul_update();
}


void CMFCTestOneDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	NotOpencom(2);
	ul_update();
	AfxMessageBox("充值成功");
	AfxMessageBox("充值失败");
}


void CMFCTestOneDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCTestOneDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCTestOneDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
