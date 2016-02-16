// Dlg_Game_HighScore.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "hextris.h"
#include "Dlg_Game_HighScore.h"
#include "afxdialogex.h"


// Dlg_Game_HighScore ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Dlg_Game_HighScore, CDialog)

Dlg_Game_HighScore::Dlg_Game_HighScore(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_Game_HighScore::IDD, pParent)
{
}

Dlg_Game_HighScore::~Dlg_Game_HighScore()
{
}

void Dlg_Game_HighScore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlg_Game_HighScore, CDialog)
//	ON_BN_CLICKED(IDCANCEL, &Dlg_Game_HighScore::OnBnClickedCancel)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Dlg_Game_HighScore �޽��� ó�����Դϴ�.


void Dlg_Game_HighScore::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_HighScore);

	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	::TransparentBlt(dc.m_hDC, 10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight, 
		dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(125,125,125));

	dc.SetTextColor(RGB(255,255,255));
	dc.SetBkMode(TRANSPARENT);
	CFont font, *pOldFont;
	font.CreateFont(13, 0, 0, 0, 0, FALSE, FALSE, 0, 0, 0, 0, 0, 0, _T("Tahoma")); 
	pOldFont = dc.SelectObject(&font);

	loadDate();
	for(int i=0; i<10; i++) { 
		CString str;
		str.Format(_T("%20d"), HighScoreScore[i]);
		dc.TextOut(190, 53+(i*25), str, 20);
	}
	for(int i=0; i<10; i++) {
		TCHAR str[5];
		for(int j=0; j<5; j++) str[j] = HighScoreName[i][j];
		dc.TextOut(100, 53+(i*25), str, 3);
	}
}

// ���� ���� �ҷ�����
void Dlg_Game_HighScore::loadDate() {
	FILE* fp = fopen("data.db", "r+");
	for(int i=0; i<10; i++) {
		fscanf(fp, "%s %d", HighScoreName[i], &HighScoreScore[i]);
	}
	fclose(fp);
}


BOOL Dlg_Game_HighScore::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
