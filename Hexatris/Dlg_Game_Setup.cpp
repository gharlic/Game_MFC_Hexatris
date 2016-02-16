// Dlg_Game_Setup.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "hextris.h"
#include "Dlg_Game_Setup.h"
#include "afxdialogex.h"


// Dlg_Game_Setup 대화 상자입니다.

IMPLEMENT_DYNAMIC(Dlg_Game_Setup, CDialogEx)

Dlg_Game_Setup::Dlg_Game_Setup(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg_Game_Setup::IDD, pParent)
{
}

Dlg_Game_Setup::~Dlg_Game_Setup()
{
}

void Dlg_Game_Setup::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, slider1);
	DDX_Control(pDX, IDC_SLIDER2, slider2);

	slider1.SetRange(7,20);
	slider2.SetRange(13,20);

	DDX_Control(pDX, IDC_Game_Setup_Level, comboBox);
}


BEGIN_MESSAGE_MAP(Dlg_Game_Setup, CDialogEx)
//	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Dlg_Game_Setup::OnCustomdrawSlider1)
//	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &Dlg_Game_Setup::OnCustomdrawSlider2)
	ON_WM_HSCROLL()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &Dlg_Game_Setup::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Dlg_Game_Setup::OnBnClickedCancel)
END_MESSAGE_MAP()


// Dlg_Game_Setup 메시지 처리기입니다.


BOOL Dlg_Game_Setup::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	slider1.SetPos(wPos);
	slider2.SetPos(hPos);
	tempW = wPos;
	tempH = hPos;
	slider1.SetLineSize(2);
	slider2.SetLineSize(2);
	slider1.SetPageSize(2);
	slider2.SetPageSize(2);
	chooseOK = false;

	comboBox.InsertString(0, _T("쉬움"));
	comboBox.InsertString(1, _T("보통"));
	comboBox.InsertString(2, _T("어려움"));
	comboBox.SetCurSel(difficulty);
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void Dlg_Game_Setup::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if(pScrollBar) {
		if(pScrollBar == (CScrollBar*)&slider1) { 
			tempW =slider1.GetPos();
		}
		if(pScrollBar == (CScrollBar*)&slider2) { 
			tempH =slider2.GetPos();
		}
	}
	Invalidate();
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void Dlg_Game_Setup::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	if(tempW) {
		TCHAR str[4];
		_stprintf_s(str, _countof(str), _T("%3d"), tempW); 
		dc.TextOut(230, 40, str, 3);
	}
	if(tempH) {
		TCHAR str[4];
		_stprintf_s(str, _countof(str), _T("%3d"), tempH); 
		dc.TextOut(230, 70, str, 3);
	}
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
}

void Dlg_Game_Setup::setValue(int w, int h, int diffi) {
	wPos = w;
	hPos = h;
	difficulty = diffi;
}

void Dlg_Game_Setup::OnBnClickedOk()
{
	difficulty = comboBox.GetCurSel();
	wPos = tempW;
	hPos = tempH;
	chooseOK = true;
	CDialogEx::OnOK();
}


void Dlg_Game_Setup::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	chooseOK = false;
	CDialogEx::OnCancel();
}
