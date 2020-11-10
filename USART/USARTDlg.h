
// USARTDlg.h: 头文件
//

#pragma once


// CUSARTDlg 对话框
class CUSARTDlg : public CDialogEx
{
// 构造
public:
	CUSARTDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USART_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_cb1;
	CComboBox m_cb2;
	CComboBox m_cb3;
	CComboBox m_cb4;
	CComboBox m_cb5;
	CRect oldrect;
	unsigned char flag = 0;

	afx_msg void Alert(void);

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void ChangeSize(UINT nID, int x, int y);
	afx_msg void OnStnClickedStatic1();
	afx_msg void OnStnClickedStatic2();
	afx_msg void OnStnClickedStatic3();
	afx_msg void OnStnClickedStatic4();
	afx_msg void OnStnClickedStatic5();
	afx_msg void OnEnChangeSpin1();
	void OpenLED(unsigned char num);
	void Receive();
	void HexToStr(unsigned char receive[], int len);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeCombo5();
	afx_msg void OnCbnSelchangeCombofz();
	afx_msg void OnCbnSelchangeComboch();
	afx_msg void OnBnClickedButtonFound();
	afx_msg void OnBnClickedButtonSet();
	CComboBox c_fz;
	CComboBox c_ch;
	afx_msg void OnBnClickedButtonLed1();
	afx_msg void OnBnClickedButtonLed2();
	afx_msg void OnBnClickedButtonLed3();
	afx_msg void OnBnClickedButtonLed4();
	afx_msg void OnBnClickedButtonLed5();
	afx_msg void OnBnClickedButtonLed6();
	afx_msg void OnBnClickedButtonLed7();
	afx_msg void OnBnClickedButtonLed8();
	afx_msg void OnBnClickedButtonLed9();
	afx_msg void OnBnClickedButtonLed10();
	afx_msg void OnBnClickedButtonLed11();
	afx_msg void OnBnClickedButtonled12();
	afx_msg void OnBnClickedButtonSetfz();
};


