#pragma once


// Dlg_Game_HighScore 대화 상자입니다.

class Dlg_Game_HighScore : public CDialog
{
	DECLARE_DYNAMIC(Dlg_Game_HighScore)

public:
	Dlg_Game_HighScore(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Dlg_Game_HighScore();

	char HighScoreName[11][5];
	int  HighScoreScore[11];

	void loadDate();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Game_HighScore };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

//	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
};