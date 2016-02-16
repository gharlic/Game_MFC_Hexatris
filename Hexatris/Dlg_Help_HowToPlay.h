#pragma once


// Dlg_Help_HowToPlay 대화 상자입니다.

class Dlg_Help_HowToPlay : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Help_HowToPlay)

public:
	Dlg_Help_HowToPlay(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Dlg_Help_HowToPlay();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Help_HowtoPlay };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
