#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// Dlg_Game_Setup ��ȭ �����Դϴ�.

class Dlg_Game_Setup : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Game_Setup)
private:
	int tempW;
	int tempH;

public:
	Dlg_Game_Setup(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Dlg_Game_Setup();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Game_Setup };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl slider1;
	CSliderCtrl slider2;
	virtual BOOL OnInitDialog();
	CStatic setUp_width;
	CStatic setUp_Height;
	int wPos;
	int hPos;
	int difficulty;
	bool chooseOK;

	void setValue(int w, int h, int diffi);

//	afx_msg void OnCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint();
	CComboBox comboBox;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
