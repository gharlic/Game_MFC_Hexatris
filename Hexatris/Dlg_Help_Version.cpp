// Dlg_Help_Version.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "hextris.h"
#include "Dlg_Help_Version.h"
#include "afxdialogex.h"


// Dlg_Help_Version 대화 상자입니다.

IMPLEMENT_DYNAMIC(Dlg_Help_Version, CDialogEx)

Dlg_Help_Version::Dlg_Help_Version(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg_Help_Version::IDD, pParent)
{
}

Dlg_Help_Version::~Dlg_Help_Version()
{
}

void Dlg_Help_Version::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlg_Help_Version, CDialogEx)
	ON_BN_CLICKED(IDOK2, &Dlg_Help_Version::OnClickedIdok2)
	ON_BN_CLICKED(IDCANCEL2, &Dlg_Help_Version::OnClickedIdcancel2)
END_MESSAGE_MAP()


// Dlg_Help_Version 메시지 처리기입니다.


BOOL Dlg_Help_Version::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetWindowPos(NULL, 0, 0, 530, 500, SWP_NOMOVE | SWP_NOZORDER);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void Dlg_Help_Version::OnClickedIdok2()
{
	::SendMessageA(this->m_hWnd, WM_CLOSE, NULL, NULL);
}


void Dlg_Help_Version::OnClickedIdcancel2()
{
	::SendMessageA(this->m_hWnd, WM_CLOSE, NULL, NULL);
}
