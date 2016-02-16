// Dlg_Game_Setup.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "hextris.h"
#include "Dlg_Game_Setup.h"
#include "afxdialogex.h"


// Dlg_Game_Setup ��ȭ �����Դϴ�.

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


// Dlg_Game_Setup �޽��� ó�����Դϴ�.


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

	comboBox.InsertString(0, _T("����"));
	comboBox.InsertString(1, _T("����"));
	comboBox.InsertString(2, _T("�����"));
	comboBox.SetCurSel(difficulty);
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void Dlg_Game_Setup::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	chooseOK = false;
	CDialogEx::OnCancel();
}
