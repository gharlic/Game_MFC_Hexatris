#pragma once


// Dlg_Help_Version ��ȭ �����Դϴ�.

class Dlg_Help_Version : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Help_Version)

public:
	Dlg_Help_Version(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Dlg_Help_Version();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Help_Version };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
//	virtual void OnOK();
//	virtual void OnCancel();
	afx_msg void OnClickedIdok2();
	afx_msg void OnClickedIdcancel2();
};
