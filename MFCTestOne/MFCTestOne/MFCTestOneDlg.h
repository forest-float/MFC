
// MFCTestOneDlg.h : ͷ�ļ�
//

#pragma once


// CMFCTestOneDlg �Ի���
class CMFCTestOneDlg : public CDialogEx
{
// ����
public:
	CMFCTestOneDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTESTONE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	CString ide_edit1;
	CString ide_edit3;
	CString ide_edit4;
	CComboBox box1;
	CComboBox box2;
	CComboBox box3;
	CEdit cedit;
	CString message;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
