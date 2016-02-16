
// ChildView.h : CChildView Ŭ������ �������̽�
//

#pragma once

#include "Game.h"
#include "BackGround.h"

//static UINT ThreadFunc(LPVOID lParam);

// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	CGame* game;
	CBackGround* m_bgr;
	CBufferDC* m_dc;
	int downSpeed[3][20];
	int tick;
	int tick2;
	int tick3;
	int swt2;
	bool gameStart;
	void reStart();

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnGameHighscore();
	afx_msg void OnUpdateGameHighscore(CCmdUI *pCmdUI);
	afx_msg void OnGameSetup();
	afx_msg void OnAppAbout();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnGameQuit();
	afx_msg void OnGameNew();
	afx_msg void OnHelpHowtoplay();
};

