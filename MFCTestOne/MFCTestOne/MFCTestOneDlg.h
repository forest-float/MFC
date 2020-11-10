
// MFCTestOneDlg.h : 头文件
//

#pragma once


// CMFCTestOneDlg 对话框
class CMFCTestOneDlg : public CDialogEx
{
// 构造
public:
	CMFCTestOneDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTESTONE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	CString ide_edit1;
	CString ide_edit3;
	CString ide_edit4;
	CComboBox box1;
	CComboBox box2;
	CComboBox box3;
	CEdit cedit;
	CString message;

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton3();
public:
	void ul_update(void);
	void NotOpencom(int i);
	
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnEnChangeEdit4();
};
