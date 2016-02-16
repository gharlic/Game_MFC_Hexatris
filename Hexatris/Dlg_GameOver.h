#pragma once
#include "afxwin.h"


// Dlg_GameOver ��ȭ �����Դϴ�.

class Dlg_GameOver : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_GameOver)

public:
	Dlg_GameOver(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Dlg_GameOver();

	int level;
	int lines;
	int score;

	char name[21];

	bool bFirstFocus;
	bool chooseOK;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GameOver };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CEdit TextBox;
//	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnSetfocusEdit1();
};
