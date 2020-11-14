
// USARTDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "USART.h"
#include "USARTDlg.h"
#include "afxdialogex.h"
#include "Transer.h"

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


// CUSARTDlg 对话框



CUSARTDlg::CUSARTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USART_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUSARTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_cb1);
	DDX_Control(pDX, IDC_COMBO2, m_cb2);
	DDX_Control(pDX, IDC_COMBO3, m_cb3);
	DDX_Control(pDX, IDC_COMBO4, m_cb4);
	DDX_Control(pDX, IDC_COMBO5, m_cb5);
	DDX_Control(pDX, IDC_COMBOFZ, c_fz);
	DDX_Control(pDX, IDC_COMBOCH, c_ch);
}

BEGIN_MESSAGE_MAP(CUSARTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CUSARTDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CUSARTDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUSARTDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CUSARTDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT2, &CUSARTDlg::OnEnChangeEdit2)
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_STN_CLICKED(IDC_STATIC1, &CUSARTDlg::OnStnClickedStatic1)
	ON_STN_CLICKED(IDC_STATIC2, &CUSARTDlg::OnStnClickedStatic2)
	ON_STN_CLICKED(IDC_STATIC3, &CUSARTDlg::OnStnClickedStatic3)
	ON_STN_CLICKED(IDC_STATIC4, &CUSARTDlg::OnStnClickedStatic4)
	ON_STN_CLICKED(IDC_STATIC5, &CUSARTDlg::OnStnClickedStatic5)
	ON_EN_CHANGE(IDC_SPIN1, &CUSARTDlg::OnEnChangeSpin1)
	ON_BN_CLICKED(IDOK, &CUSARTDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CUSARTDlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CUSARTDlg::OnCbnSelchangeCombo5)
	ON_CBN_SELCHANGE(IDC_COMBOFZ, &CUSARTDlg::OnCbnSelchangeCombofz)
	ON_CBN_SELCHANGE(IDC_COMBOCH, &CUSARTDlg::OnCbnSelchangeComboch)
	ON_BN_CLICKED(IDC_BUTTON_FOUND, &CUSARTDlg::OnBnClickedButtonFound)
	ON_BN_CLICKED(IDC_BUTTON_SET, &CUSARTDlg::OnBnClickedButtonSet)
	ON_BN_CLICKED(IDC_BUTTON_LED1, &CUSARTDlg::OnBnClickedButtonLed1)
	ON_BN_CLICKED(IDC_BUTTON_LED2, &CUSARTDlg::OnBnClickedButtonLed2)
	ON_BN_CLICKED(IDC_BUTTON_LED3, &CUSARTDlg::OnBnClickedButtonLed3)
	ON_BN_CLICKED(IDC_BUTTON_LED4, &CUSARTDlg::OnBnClickedButtonLed4)
	ON_BN_CLICKED(IDC_BUTTON_LED5, &CUSARTDlg::OnBnClickedButtonLed5)
	ON_BN_CLICKED(IDC_BUTTON_LED6, &CUSARTDlg::OnBnClickedButtonLed6)
	ON_BN_CLICKED(IDC_BUTTON_LED7, &CUSARTDlg::OnBnClickedButtonLed7)
	ON_BN_CLICKED(IDC_BUTTON_LED8, &CUSARTDlg::OnBnClickedButtonLed8)
	ON_BN_CLICKED(IDC_BUTTON_LED9, &CUSARTDlg::OnBnClickedButtonLed9)
	ON_BN_CLICKED(IDC_BUTTON_LED10, &CUSARTDlg::OnBnClickedButtonLed10)
	ON_BN_CLICKED(IDC_BUTTON_LED11, &CUSARTDlg::OnBnClickedButtonLed11)
	ON_BN_CLICKED(IDC_BUTTONLED12, &CUSARTDlg::OnBnClickedButtonled12)
	ON_BN_CLICKED(IDC_BUTTON_SETFZ, &CUSARTDlg::OnBnClickedButtonSetfz)
END_MESSAGE_MAP()


// CUSARTDlg 消息处理程序

BOOL CUSARTDlg::OnInitDialog()
{
	
	CDialogEx::OnInitDialog();
	
	m_font.CreateFont(0, 10, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_ROMAN, "宋体");
	m_font1.CreateFont(0, 0, 0, 0, 1000, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_ROMAN, "宋体");

	m_cb1.SetFont(&m_font);
	m_cb2.SetFont(&m_font);
	m_cb3.SetFont(&m_font);
	m_cb4.SetFont(&m_font);
	m_cb5.SetFont(&m_font);

	c_fz.SetFont(&m_font);
	c_ch.SetFont(&m_font);

	GetDlgItem(IDC_BUTTON3)->SetFont(&m_font);	
	GetDlgItem(IDC_BUTTON2)->SetFont(&m_font);
	GetDlgItem(IDC_EDIT1)->SetFont(&m_font);		
	GetDlgItem(IDC_COMBO1)->SetFont(&m_font);	
	GetDlgItem(IDC_COMBO2)->SetFont(&m_font);	
	GetDlgItem(IDC_COMBO3)->SetFont(&m_font);	
	GetDlgItem(IDC_COMBO4)->SetFont(&m_font);
	GetDlgItem(IDC_COMBO5)->SetFont(&m_font);	
	GetDlgItem(IDC_STATIC1)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC2)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC3)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC4)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC5)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC7)->SetFont(&m_font);
	GetDlgItem(IDC_BUTTON1)->SetFont(&m_font);	
	GetDlgItem(IDC_COMBO1)->SetFont(&m_font);
	GetDlgItem(IDC_COMBO2)->SetFont(&m_font);
	GetDlgItem(IDOK)->SetFont(&m_font);

	GetDlgItem(IDC_BUTTON_SET)->SetFont(&m_font);
	GetDlgItem(IDC_BUTTON_SETFZ)->SetFont(&m_font);
	

	((CButton*)GetDlgItem(IDC_BUTTON_LED1))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED2))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED3))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED4))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED5))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED6))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED7))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED8))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED9))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED10))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTON_LED11))->SetFont(&m_font);
	((CButton*)GetDlgItem(IDC_BUTTONLED12))->SetFont(&m_font);

	//串口
	m_cb1.AddString(_T("COM1"));
	m_cb1.AddString(_T("COM2"));
	m_cb1.AddString(_T("COM3"));
	m_cb1.AddString(_T("COM4"));
	m_cb1.AddString(_T("COM5"));
	//m_cb1.SelectedIndex = m_cb1.Items.IndexOf(_T("COM1");
	//SetDlgItemText(IDC_COMBO1, "COM1");
	m_cb1.SetCurSel(0);
	//波特率
	/*m_cb2.AddString(_T("1382400"));
	m_cb2.AddString(_T("921600"));
	m_cb2.AddString(_T("460800"));
	m_cb2.AddString(_T("256000"));
	m_cb2.AddString(_T("230400"));
	m_cb2.AddString(_T("128000"));*/
	m_cb2.AddString(_T("115200"));
	/*m_cb2.AddString(_T("76800"));
	m_cb2.AddString(_T("57600"));
	m_cb2.AddString(_T("43000"));
	m_cb2.AddString(_T("38400"));
	m_cb2.AddString(_T("19200"));
	m_cb2.AddString(_T("14400"));*/
	m_cb2.AddString(_T("9600"));
	/*m_cb2.AddString(_T("4800"));
	m_cb2.AddString(_T("4800"));
	m_cb2.AddString(_T("2400"));
	m_cb2.AddString(_T("1200"));*/
	//SetDlgItemText(IDC_COMBO2, "115200");
	m_cb2.SetCurSel(0);
	//停止位
	m_cb3.AddString(_T("1"));
	//SetDlgItemText(IDC_COMBO3, "1");
	m_cb3.SetCurSel(0);
	//m_cb3.AddString(_T("1.5"));
	//m_cb3.AddString(_T("2"));
	//数据位
	m_cb4.AddString(_T("8"));
	//SetDlgItemText(IDC_COMBO4, "8");
	m_cb4.SetCurSel(0);
	//m_cb4.AddString(_T("7"));
	//m_cb4.AddString(_T("6"));
	//m_cb4.AddString(_T("5"));
	//奇偶校验
	m_cb5.AddString(_T("无"));
	m_cb5.SetCurSel(0);
	//SetDlgItemText(IDC_COMBO5, "无");
	//m_cb5.AddString(_T("奇校验"));
	//m_cb5.AddString(_T("偶校验"));
	//轮询频率
	c_fz.AddString(_T("100"));
	c_fz.AddString(_T("200"));
	c_fz.AddString(_T("300"));
	c_fz.AddString(_T("400"));
	c_fz.AddString(_T("500"));
	c_fz.AddString(_T("600"));
	c_fz.AddString(_T("700"));
	c_fz.AddString(_T("800"));
	c_fz.AddString(_T("900"));
	c_fz.AddString(_T("1000"));
	c_fz.SetCurSel(9);
	//SetDlgItemText(IDC_COMBOFZ, "800ms");
	//信道
	c_ch.AddString(_T("1"));
	c_ch.AddString(_T("2"));
	c_ch.AddString(_T("3"));
	c_ch.AddString(_T("4"));
	c_ch.AddString(_T("5"));
	c_ch.AddString(_T("6"));
	c_ch.AddString(_T("7"));
	c_ch.AddString(_T("8"));
	c_ch.AddString(_T("9"));
	c_ch.AddString(_T("10"));
	c_ch.AddString(_T("11"));
	c_ch.AddString(_T("12"));
	c_ch.AddString(_T("FF"));
	c_ch.SetCurSel(12);
	//SetDlgItemText(IDC_COMBOCH, "FF");

	SetTimer(1, 100, NULL); //参数：定时器标号，定时时间（ms）。启动定时器1，每隔1s刷新一次，



	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CUSARTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUSARTDlg::OnPaint()
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
HCURSOR CUSARTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUSARTDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::Alert(void)
{

}

void CUSARTDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

		static bool flag = false;
		// TODO: 在此添加控件通知处理程序代码
		if (!flag)
		{
			int comport = m_cb1.GetCurSel() + 1;//获取串口号
			if (comport == 0)
			{
				Alert();
				return;
			}


			//int baud, stop,data, parity;
			DWORD baud;
			BYTE stop, data, parity;

			int index;
			CString text;

			index = m_cb2.GetCurSel();		// 获取选定项的序号
			if (index == -1)
			{
				Alert();
				return;
			}
			else
			{
				m_cb2.GetLBText(index, text);  // 获取波特率
				baud = _ttoi(text);
			}


			index = m_cb3.GetCurSel();
			if (index == -1)
			{
				Alert();
				return;
			}
			else
			{
				m_cb3.GetLBText(index, text);  // 获取停止位
				if (text == "1")
					stop = 0;
				else if (text == "1.5")
					stop = 1;
				else if (text == "2")
					stop = 2;
			}


			index = m_cb4.GetCurSel();
			if (index == -1)
			{
				Alert();
				return;
			}
			else
			{
				m_cb4.GetLBText(index, text);  // 获取数据位
				data = _ttoi(text);
			}

			index = m_cb5.GetCurSel();
			if (index == -1)
			{
				Alert();
				return;
			}
			else
			{
				m_cb5.GetLBText(index, text);  // 获取奇偶校验位
				if (text == "无")
					parity = 0;
				else if (text == "奇校验")
					parity = 1;
				else if (text == "偶校验")
					parity = 2;

			}

			com.OpenPort(comport);
			com.SetPort(baud, stop, data, parity);
			GetDlgItem(IDC_BUTTON1)->SetWindowText("关闭串口");
			flag = true;
		}
		else
		{
			com.ClosePort();
			GetDlgItem(IDC_BUTTON1)->SetWindowText("打开串口");
			flag = false;
		}
	

}


void CUSARTDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

		// TODO: 在此添加控件通知处理程序代码
		CString sendText;
		GetDlgItemText(IDC_BUTTON2, sendText);
		sendText += "\r\n";
		//在多字符集模式下
		unsigned char* send;
		//send = (unsigned char*)(LPCTSTR)sendText;
		send = (unsigned char*)sendText.GetBuffer(sendText.GetLength());


		//unsigned char send[100];
		//memcpy(send, LPCTSTR(sendText), sendText.GetLength() * sizeof(TCHAR));
		//send[sendText.GetLength()] = '\0';

		com.WriteDate(send, sendText.GetLength());


		//AfxMessageBox(sendText);


}


void CUSARTDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_SPIN1, _T(""));
}


void CUSARTDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	//static int h = 0;
	int static h = 0;
	// TODO: 在此添加控件通知处理程序代码
	static int i = 0;
	unsigned char receive[1024] = "";
	DWORD len = 0;
	CString s;
	com.ReadDate(receive, len);
	CString receiveText(receive);
	/*s.Format(_T(":%d"), i++);
	receiveText += s;
	receiveText += "\r\n";*/
	GetDlgItemText(IDC_EDIT2, s);
	receiveText = s + receiveText;
	SetDlgItemText(IDC_EDIT2, receiveText);
	SendDlgItemMessage(IDC_EDIT2, WM_VSCROLL, SB_BOTTOM, 0); //滚动条始终在底部
/*	if (len != 0)
	{
		if (receive[0] == '1')
			canv.Update(1 * 100);
		else if (receive[0] == '0')
			canv.Update(0 * 100);
	}
*/
	

}


void CUSARTDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Receive();
	CDialogEx::OnTimer(nIDEvent);
	
}


void CUSARTDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (nType != SIZE_MINIMIZED)
	{

		//ChangeSize(IDC_Canvas, cx, cy);
		ChangeSize(IDC_BUTTON3, cx, cy);
		ChangeSize(IDC_BUTTON2, cx, cy);
		ChangeSize(IDC_EDIT1, cx, cy);
		ChangeSize(IDC_EDIT2, cx, cy);
		ChangeSize(IDC_COMBO1, cx, cy);
		ChangeSize(IDC_COMBO2, cx, cy);
		ChangeSize(IDC_COMBO3, cx, cy);
		ChangeSize(IDC_COMBO4, cx, cy);
		ChangeSize(IDC_COMBO5, cx, cy);
		ChangeSize(IDC_STATIC1, cx, cy);
		ChangeSize(IDC_STATIC2, cx, cy);
		ChangeSize(IDC_STATIC3, cx, cy);
		ChangeSize(IDC_STATIC4, cx, cy);
		ChangeSize(IDC_STATIC5, cx, cy);
		ChangeSize(IDC_BUTTON1, cx, cy);
		ChangeSize(IDC_COMBO1, cx, cy);
		ChangeSize(IDC_COMBO2, cx, cy);


		GetClientRect(&oldrect);
	}

}
void CUSARTDlg::ChangeSize(UINT nID, int x, int y)
{
	CWnd* pWnd;
	pWnd = GetDlgItem(nID);
	if (pWnd != NULL)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left = rect.left * x / oldrect.Width();
		rect.right = rect.right * x / oldrect.Width();
		rect.top = rect.top * y / oldrect.Height();
		rect.bottom = rect.bottom * y / oldrect.Height();
		if (nID == IDC_COMBO1)
			rect.bottom += (rect.bottom - rect.top) * (m_cb1.GetCount());
		if (nID == IDC_COMBO2)
			rect.bottom += (rect.bottom - rect.top) * (m_cb2.GetCount());
		if (nID == IDC_COMBO3)
			rect.bottom += (rect.bottom - rect.top) * (m_cb3.GetCount());
		if (nID == IDC_COMBO4)
			rect.bottom += (rect.bottom - rect.top) * (m_cb4.GetCount());
		if (nID == IDC_COMBO5)
			rect.bottom += (rect.bottom - rect.top) * (m_cb5.GetCount());
		pWnd->MoveWindow(rect);

		/*CFont font;
		font.CreatePointFont(fontsize, "Microsoft Sans Serif");
		pWnd->SetFont(&font);*/
	}
}

void CUSARTDlg::OnStnClickedStatic1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnStnClickedStatic2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnStnClickedStatic3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnStnClickedStatic4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnStnClickedStatic5()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnEnChangeSpin1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}
void CUSARTDlg::HexToStr(unsigned char receive[], int len)
{
#pragma warning(suppress : 4996)
	unsigned char temp[1024] = "";
	
	memcpy(temp, receive, len);

	UnPcakMessage(receive, buff);

	if (type == 0x01)
	{
		type = 0;
		if (!memcmp(&temp[4], "\x00\x00\x00\x00", 4))
		{
			CloseLED(ch);
		}
		else
		{
			OpenLED(ch);
		}
	}
	
	int i = 0;
	for (i = 0; i < len; i++)
	{
		sprintf((char*)&receive[i*3],"%02X ",temp[i]);
	}
	if (type == 0x04)
	{
		//type = 0;
		/*
		if (buff[0] == 0x08)
		{
			c_fz.SetCurSel(2);
		}
		if (buff[0] == 0x0A)
		{
			c_fz.SetCurSel(0);
		}
		if (buff[0] == 0x0C)
		{
			c_fz.SetCurSel(1);
		}*/
		c_fz.SetCurSel(temp[4] -1);
		flag = 0;
	}
	//sprintf((char*)&receive[i * 3], "\r\n");
}
void  CUSARTDlg::CloseLED(unsigned char num)
{
	static unsigned char temp = 0;

	//if (num == temp)  return;
	//temp = num;
	switch (num)
	{
	case 1:
		((CButton*)GetDlgItem(IDC_BUTTON_LED1))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED1))->SetFont(&m_font);
		break;

	case 2:
		((CButton*)GetDlgItem(IDC_BUTTON_LED2))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED2))->SetFont(&m_font);
		break;

	case 3:
		((CButton*)GetDlgItem(IDC_BUTTON_LED3))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED3))->SetFont(&m_font);
		break;

	case 4:
		((CButton*)GetDlgItem(IDC_BUTTON_LED4))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED4))->SetFont(&m_font);
		break;

	case 5:
		((CButton*)GetDlgItem(IDC_BUTTON_LED5))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED5))->SetFont(&m_font);
		break;

	case 6:
		((CButton*)GetDlgItem(IDC_BUTTON_LED6))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED6))->SetFont(&m_font);
		break;

	case 7:
		((CButton*)GetDlgItem(IDC_BUTTON_LED7))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED7))->SetFont(&m_font);
		break;

	case 8:
		((CButton*)GetDlgItem(IDC_BUTTON_LED8))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED8))->SetFont(&m_font);
		break;

	case 9:
		((CButton*)GetDlgItem(IDC_BUTTON_LED9))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED9))->SetFont(&m_font);
		break;

	case 10:
		((CButton*)GetDlgItem(IDC_BUTTON_LED10))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED10))->SetFont(&m_font);
		break;

	case 11:
		((CButton*)GetDlgItem(IDC_BUTTON_LED11))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTON_LED11))->SetFont(&m_font);
		break;

	case 12:
		((CButton*)GetDlgItem(IDC_BUTTONLED12))->SetState(FALSE);
		((CButton*)GetDlgItem(IDC_BUTTONLED12))->SetFont(&m_font);

		break;
	default:break;
	}

}
void CUSARTDlg::OpenLED(unsigned char num)
{
	static unsigned char temp = 0;
	
	//if (num == temp)  return;
	//temp = num;
	switch (num)
	{
		case 1:    
			((CButton*)GetDlgItem(IDC_BUTTON_LED1))->SetState(TRUE);      
			((CButton*)GetDlgItem(IDC_BUTTON_LED1))->SetFont(&m_font1);
			break;

		case 2:    
			((CButton*)GetDlgItem(IDC_BUTTON_LED2))->SetState(TRUE);      
			((CButton*)GetDlgItem(IDC_BUTTON_LED2))->SetFont(&m_font1);
			break;

		case 3:    
			((CButton*)GetDlgItem(IDC_BUTTON_LED3))->SetState(TRUE);   
			((CButton*)GetDlgItem(IDC_BUTTON_LED3))->SetFont(&m_font1);
			break;

		case 4:    
			((CButton*)GetDlgItem(IDC_BUTTON_LED4))->SetState(TRUE);   
			((CButton*)GetDlgItem(IDC_BUTTON_LED4))->SetFont(&m_font1);
			break;

		case 5:    
			((CButton*)GetDlgItem(IDC_BUTTON_LED5))->SetState(TRUE);   
			((CButton*)GetDlgItem(IDC_BUTTON_LED5))->SetFont(&m_font1);
			break;

		case 6:    
			((CButton*)GetDlgItem(IDC_BUTTON_LED6))->SetState(TRUE);   
			((CButton*)GetDlgItem(IDC_BUTTON_LED6))->SetFont(&m_font1);
			break;

		case 7:    
			((CButton*)GetDlgItem(IDC_BUTTON_LED7))->SetState(TRUE);   
			((CButton*)GetDlgItem(IDC_BUTTON_LED7))->SetFont(&m_font1);
			break;

		case 8:    
			((CButton*)GetDlgItem(IDC_BUTTON_LED8))->SetState(TRUE);   
			((CButton*)GetDlgItem(IDC_BUTTON_LED8))->SetFont(&m_font1);
			break;

		case 9:    
			((CButton*)GetDlgItem(IDC_BUTTON_LED9))->SetState(TRUE);   
			((CButton*)GetDlgItem(IDC_BUTTON_LED9))->SetFont(&m_font1);
			break;

		case 10:   
			((CButton*)GetDlgItem(IDC_BUTTON_LED10))->SetState(TRUE);      
			((CButton*)GetDlgItem(IDC_BUTTON_LED10))->SetFont(&m_font1);
			break;

		case 11:   
			((CButton*)GetDlgItem(IDC_BUTTON_LED11))->SetState(TRUE);      
			((CButton*)GetDlgItem(IDC_BUTTON_LED11))->SetFont(&m_font1);
			break;

		case 12:   
			((CButton*)GetDlgItem(IDC_BUTTONLED12))->SetState(TRUE);      
			((CButton*)GetDlgItem(IDC_BUTTONLED12))->SetFont(&m_font1);

			break;
		default:break;
	}
}
void CUSARTDlg::Receive()
{
	//static int h = 0;
	int static h = 0;
	// TODO: 在此添加控件通知处理程序代码
	static int i = 0;
	unsigned char receive[1024] = "";
	DWORD len = 0;
	CString s;
	if (type == 0x02)
	{
		flag = 1;
	}
	com.ReadDate(receive, len);
	/*
	if (len >= 8)
	{
		((CButton*)GetDlgItem(IDC_BUTTON_LED1))->SetState(TRUE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_BUTTON_LED1))->SetState(FALSE);
	}*/

	HexToStr(receive, len);
	//if (type == 0x01)
	//{
	//	OpenLED(ch);
	//}

	CString receiveText(receive);

	/*s.Format(_T(":%d"), i++);
	receiveText += s;
	receiveText += "\r\n";*/


	if (type == 0x04)
	{
		type = 0;
		receiveText = "";
		SetDlgItemText(IDC_SPIN1, receiveText);
	}
	else
	{
		GetDlgItemText(IDC_SPIN1, s);
		receiveText = s + receiveText;
		SetDlgItemText(IDC_SPIN1, receiveText);
		SendDlgItemMessage(IDC_SPIN1, WM_VSCROLL, SB_BOTTOM, 0); //滚动条始终在底部

	}
															 /*if (len != 0)
	{
		if (receive[0] == '1')
			canv.Update(1 * 100);
		else if (receive[0] == '0')
			canv.Update(0 * 100);
	}*/

}

void CUSARTDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CUSARTDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CUSARTDlg::OnCbnSelchangeCombo5()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnCbnSelchangeCombofz()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnCbnSelchangeComboch()
{
	// TODO: 在此添加控件通知处理程序代码
}

//轮询频率查询
void CUSARTDlg::OnBnClickedButtonFound()
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 1;
	type = 0x02;
	unsigned char send[16] = {0xAA,0x02,0x00,0xFF,0x00,0x00,0x00,0x00,0x3A,0x4C,0xBB};
	com.WriteDate(send, 11);
}





void CUSARTDlg::OnBnClickedButtonLed1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed5()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed6()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed7()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed8()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed9()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed10()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonLed11()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CUSARTDlg::OnBnClickedButtonled12()
{
	// TODO: 在此添加控件通知处理程序代码
}

//轮询频率设置
void CUSARTDlg::OnBnClickedButtonSetfz()
{
	// TODO: 在此添加控件通知处理程序代码
	int index;
	CString text;
	unsigned char results[16] = { 0 };
	unsigned char temp[4] = { 0 };


	index = c_fz.GetCurSel();		// 获取选定项的序号
	c_fz.GetLBText(index, text);  // 获取数据位

	flag = 1;
	type = 0x03;
	len = 0x01;
	ch = 0xFF;
	//if (text == "800ms") temp[0] = 0x08;
	//else if (text == "1000ms") temp[0] = 0x0A;
	//else if (text == "1200ms") temp[0] = 0x0C;
	//else temp[0] = 0x08;
	temp[0] = index + 1;
	PcakMessage(temp, results);//组包
	com.WriteDate(results, 8);
}
//只读信道设置
void CUSARTDlg::OnBnClickedButtonSet()
{
	// TODO: 在此添加控件通知处理程序代码

	int i = 0;
	int index;
	CString text;
	unsigned char results[16] = { 0 };
	unsigned char temp[4] = { 0 };
	//CString text;
	unsigned char chnum;

	index = c_ch.GetCurSel();		// 获取选定项的序号
	c_ch.GetLBText(index, text);  // 获取数据位
	chnum = _ttoi(text);

	type = 0x05;
	len = 0x01;
	ch = 0xFF;
	temp[0] = chnum;
	if (text == "FF") temp[0] = 0xFF;
	PcakMessage(temp, results);//组包
	com.WriteDate(results, 8);
	for (i = 1; i <= 12; i++)
	{
		CloseLED(i);
	}
}
