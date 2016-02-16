
// ChildView.h : CChildView 클래스의 인터페이스
//

#pragma once

#include "Game.h"
#include "BackGround.h"

//static UINT ThreadFunc(LPVOID lParam);

// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

// 작업입니다.
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

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
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

