#pragma once
#include "afxwin.h"


// Dlg_GameOver 대화 상자입니다.

class Dlg_GameOver : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_GameOver)

public:
	Dlg_GameOver(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Dlg_GameOver();

	int level;
	int lines;
	int score;

	char name[21];

	bool bFirstFocus;
	bool chooseOK;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_GameOver };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
