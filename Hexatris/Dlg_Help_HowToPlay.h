#pragma once


// Dlg_Help_HowToPlay ��ȭ �����Դϴ�.

class Dlg_Help_HowToPlay : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Help_HowToPlay)

public:
	Dlg_Help_HowToPlay(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Dlg_Help_HowToPlay();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Help_HowtoPlay };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
