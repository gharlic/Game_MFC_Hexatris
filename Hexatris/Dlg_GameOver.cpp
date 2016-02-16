// Dlg_GameOver.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "hextris.h"
#include "Dlg_GameOver.h"
#include "afxdialogex.h"


// Dlg_GameOver 대화 상자입니다.

IMPLEMENT_DYNAMIC(Dlg_GameOver, CDialogEx)

Dlg_GameOver::Dlg_GameOver(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg_GameOver::IDD, pParent)
{
	bFirstFocus=FALSE;
	chooseOK=FALSE;
}

Dlg_GameOver::~Dlg_GameOver()
{
}

void Dlg_GameOver::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, TextBox);
}


BEGIN_MESSAGE_MAP(Dlg_GameOver, CDialogEx)
	ON_WM_PAINT()
//	ON_WM_SETFOCUS()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, &Dlg_GameOver::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Dlg_GameOver::OnBnClickedCancel)
	ON_EN_SETFOCUS(IDC_EDIT1, &Dlg_GameOver::OnEnSetfocusEdit1)
END_MESSAGE_MAP()


// Dlg_GameOver 메시지 처리기입니다.


void Dlg_GameOver::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_GameOver);

	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	::TransparentBlt(dc.m_hDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, 
		dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(125,125,125));

	dc.SetTextColor(RGB(0,121,176));
	dc.SetBkMode(TRANSPARENT);
	CFont font, *pOldFont;
	font.CreateFont(18, 7, 0, 0, 1, FALSE, FALSE, 0, 0, 0, 0, 0, 0, _T("Tahoma")); 
	pOldFont = dc.SelectObject(&font);

	TCHAR str[21];
	TCHAR str2[21];
	_stprintf_s(str, _countof(str), _T("%20d"), level); 
	dc.TextOut(150, 100, str, 20);
	_stprintf_s(str, _countof(str), _T("%20d"), score); 
	dc.TextOut(150, 120, str, 20);
	_stprintf_s(str, _countof(str), _T("%20d"), lines); 
	dc.TextOut(150, 140, str, 20);
	_stprintf_s(str, _countof(str), _T("이니셜")); 
	dc.TextOut(50, 200, str, 3);

	if (bFirstFocus!=TRUE)
		TextBox.SetWindowText(TEXT("ABC"));
}

HBRUSH Dlg_GameOver::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (bFirstFocus)
	{
		pDC->SetTextColor(RGB(0,0,0));
	}else{
		pDC->SetTextColor(RGB(128,128,128));
	}
	return hbr;
}


void Dlg_GameOver::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
	TCHAR str[21];
	TextBox.GetLine(0, str, 21);
	for(int i=0; i<20; i++) {
		name[i] = str[i];
	}

	chooseOK=TRUE;
}


void Dlg_GameOver::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
	chooseOK=FALSE;
}


void Dlg_GameOver::OnEnSetfocusEdit1()
{
	if (bFirstFocus!=TRUE)
	{
		TextBox.SetWindowText(TEXT(""));
		bFirstFocus=TRUE;
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
