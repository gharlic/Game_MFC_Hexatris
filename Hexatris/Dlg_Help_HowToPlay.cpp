// Dlg_Help_HowToPlay.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "hextris.h"
#include "Dlg_Help_HowToPlay.h"
#include "afxdialogex.h"


// Dlg_Help_HowToPlay ��ȭ �����Դϴ�.

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


// Dlg_Help_HowToPlay �޽��� ó�����Դϴ�.


BOOL Dlg_Help_HowToPlay::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetWindowPos(NULL, 0, 0, 530, 500, SWP_NOMOVE | SWP_NOZORDER);
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void Dlg_Help_HowToPlay::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	::SendMessageA(this->m_hWnd, WM_CLOSE, NULL, NULL);
	CDialogEx::OnOK();
}


void Dlg_Help_HowToPlay::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	::SendMessageA(this->m_hWnd, WM_CLOSE, NULL, NULL);
	CDialogEx::OnCancel();
}
