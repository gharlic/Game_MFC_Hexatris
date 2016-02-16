#pragma once


// Dlg_Help_Version 대화 상자입니다.

class Dlg_Help_Version : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Help_Version)

public:
	Dlg_Help_Version(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Dlg_Help_Version();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Help_Version };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
//	virtual void OnOK();
//	virtual void OnCancel();
	afx_msg void OnClickedIdok2();
	afx_msg void OnClickedIdcancel2();
};
