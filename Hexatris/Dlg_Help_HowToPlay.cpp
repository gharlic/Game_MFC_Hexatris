// Dlg_Help_HowToPlay.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "hextris.h"
#include "Dlg_Help_HowToPlay.h"
#include "afxdialogex.h"


// Dlg_Help_HowToPlay 대화 상자입니다.

IMPLEMENT_DYNAMIC(Dlg_Help_HowToPlay, CDialogEx)

Dlg_Help_HowToPlay::Dlg_Help_HowToPlay(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg_Help_HowToPlay::IDD, pParent)
{
}

Dlg_Help_HowToPlay::~Dlg_Help_HowToPlay()
{
}

void Dlg_Help_HowToPlay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlg_Help_HowToPlay, CDialogEx)
	ON_BN_CLICKED(IDOK, &Dlg_Help_HowToPlay::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Dlg_Help_HowToPlay::OnBnClickedCancel)
END_MESSAGE_MAP()


// Dlg_Help_HowToPlay 메시지 처리기입니다.


BOOL Dlg_Help_HowToPlay::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowPos(NULL, 0, 0, 530, 500, SWP_NOMOVE | SWP_NOZORDER);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void Dlg_Help_HowToPlay::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	::SendMessageA(this->m_hWnd, WM_CLOSE, NULL, NULL);
	CDialogEx::OnOK();
}


void Dlg_Help_HowToPlay::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	::SendMessageA(this->m_hWnd, WM_CLOSE, NULL, NULL);
	CDialogEx::OnCancel();
}
