#pragma once


// Dlg_Game_HighScore ��ȭ �����Դϴ�.

class Dlg_Game_HighScore : public CDialog
{
	DECLARE_DYNAMIC(Dlg_Game_HighScore)

public:
	Dlg_Game_HighScore(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Dlg_Game_HighScore();

	char HighScoreName[11][5];
	int  HighScoreScore[11];

	void loadDate();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Game_HighScore };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:

//	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
};