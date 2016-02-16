#pragma comment(lib, "winmm")

#include <mmsystem.h>
#include "stdafx.h"
#include "hextris.h"
#include "ChildView.h"
#include "Game.h"
#include "BackGround.h"
#include "BufferDC.h"
#include "Dlg_Game_HighScore.h"
#include "Dlg_Game_Setup.h"
#include "Dlg_Help_Version.h"
#include "Dlg_Help_HowToPlay.h"
#include "Dlg_GameOver.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinThread* m_pThread;
bool m_bUsed;
static UINT ThreadFunc(LPVOID lParam) {
	bool first = true;
	while(m_bUsed) {
		//PlaySound(MAKEINTRESOURCE(IDR_WAVE_DOWN), AfxGetInstanceHandle(),SND_RESOURCE | SND_ASYNC | SND_LOOP);
		if(first) {
			first = false;
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_BGM), AfxGetInstanceHandle(),SND_RESOURCE | SND_ASYNC | SND_LOOP);
		}
		//Sleep(1);
	}
	//PlaySound(NULL, AfxGetInstanceHandle(),  NULL); 
	return 0;
}

// CChildView

CChildView::CChildView()
{
	game = new CGame();
	m_bgr = new CBackGround(game);
	int easySpeed[20] = {50,50,49,49,48,48,47,47,46,46,45,45,44,44,43,43,42,42,41,40};
	int normalSpeed[20] = {47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,33,32,31,30};
	int hardSpeed[20] = {44,42,40,38,36,34,32,30,28,26,25,24,23,22,21,20,19,18,17,16};
	for(int i=0; i<20; i++) {
		downSpeed[0][i] = easySpeed[i];	
		downSpeed[1][i] = normalSpeed[i];
		downSpeed[2][i] = hardSpeed[i];
	}
	tick = 0;
	tick2 = 0;
	tick3 = 0;
	swt2 = 0;
	gameStart = false;

	m_pThread = NULL;
	m_bUsed = true;
	AfxBeginThread(ThreadFunc,this);
}

CChildView::~CChildView()
{
	m_bUsed = false;
	DWORD dwCode = 0;
	if(m_pThread) {
		GetExitCodeThread(m_pThread->m_hThread, &dwCode);
		WaitForSingleObject(m_pThread->m_hThread, INFINITE);
		GetExitCodeProcess(m_pThread->m_hThread, &dwCode);
	}
}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_GAME_HIGHSCORE, &CChildView::OnGameHighscore)
	ON_COMMAND(ID_GAME_SETUP, &CChildView::OnGameSetup)
	ON_COMMAND(ID_APP_ABOUT, &CChildView::OnAppAbout)
	ON_COMMAND(ID_GAME_QUIT, &CChildView::OnGameQuit)
	ON_COMMAND(ID_GAME_NEW, &CChildView::OnGameNew)
	ON_COMMAND(ID_HELP_HOWTOPLAY, &CChildView::OnHelpHowtoplay)
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	static int swt = 0;
	if(tick%5 == 0) swt = 1 - swt;

	CBufferDC dc(this);

	if(gameStart) {
		m_bgr->printMenu(&dc);
		game->printGamePane(&dc);
		game->printNextBlock(&dc);
		m_bgr->printSkillX(&dc, game->getSkillX());
		m_bgr->printSkillZ(&dc, game->getSkillZ());
		m_bgr->printSkillC(&dc, game->getSkillC());
	}
	else {
		m_bgr->printStartScreen(&dc, swt);
	}
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
	static int pauseSwt = 0;

	if(gameStart && tick2==0 ) {
		if(tick%1 == 0) {	// 키 입력 - 1프레임
			if(pauseSwt==0) {
				if(nChar == VK_LEFT)
					game->moveShapeLeft();
				if(nChar == VK_RIGHT)
					game->moveShapeRight();
				if(nChar == VK_DOWN)
					game->moveShapeDown();
				if(nChar == VK_UP) {
					game->rotateShape();
					//PlaySound(MAKEINTRESOURCE(IDR_WAVE_ROTATE), AfxGetInstanceHandle(),SND_RESOURCE | SND_ASYNC);
				}
				if(nChar == VK_SPACE)
					game->moveShapeToBottom(); 
				if(nChar == VK_SPACE)
					game->moveShapeToBottom(); 
				if(nChar == 'z' || nChar == 'Z') {
					game->skillZPre();
					swt2 = 1;
				}
				if(nChar == 'x' || nChar == 'X')
					game->skillX();
				if(nChar == 'c' || nChar == 'C')
					game->skillC();
			}

			if(nChar == 'p' || nChar == 'P') {
				pauseSwt = 1 - pauseSwt;
				if(pauseSwt==1) KillTimer(0);
				else SetTimer(0,downSpeed[game->getDifficulty()][game->getSpeedLevel()],NULL);
			}
		}
	}
	gameStart = true;
	Invalidate(); 
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(0,downSpeed[game->getDifficulty()][game->getSpeedLevel()],NULL);
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.


	return 0;

}



void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	tick++;
	if(tick2 > 0) tick2++;
	if(tick3 > 0) tick3++;
	static bool first = true;
	static int swt = 0;
	if(gameStart) {
		if(first) {
			OnHelpHowtoplay();
			first = false;
		}
		if(tick%10 == 0) {
			if(!game->moveShapeDown()) {
				//PlaySound(MAKEINTRESOURCE(IDR_WAVE_DOWN), AfxGetInstanceHandle(),SND_RESOURCE | SND_ASYNC);
				game->madeLinePreClear();
				swt = 1;
			}
		}
		if(swt == 1) {
			swt = 2;
			tick2 = 1;
		}
		if(swt == 2 && tick2 == 7) {
			game->madeLineClear();
			tick2 = 0;
			swt = 0;
			// 게임 오버
			if(!game->startNext()) {
				reStart();
			}
			// 레벨 업
			if(game->levelUp()) {
				KillTimer(0);
				//PlaySound(MAKEINTRESOURCE(IDR_WAVE_LEVELUP), AfxGetInstanceHandle(),SND_RESOURCE | SND_ASYNC);
				SetTimer(0,downSpeed[game->getDifficulty()][game->getSpeedLevel()],NULL);
			}
		}
		if(swt2 == 1) {
			swt2 = 2;
			tick3 = 1;
		}
		if(swt2 == 2 && tick3 == 7) {
			game->skillZ();
			tick3 = 0;
			swt2 = 0;
		}
	}
	Invalidate();


	CWnd::OnTimer(nIDEvent);
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return true;
}


void CChildView::OnGameHighscore()
{
	KillTimer(0);
	Dlg_Game_HighScore dlg;
	dlg.DoModal();
	SetTimer(0,downSpeed[game->getDifficulty()][game->getSpeedLevel()],NULL);
}

void CChildView::OnGameSetup()
{
	KillTimer(0);
	Dlg_Game_Setup dlg;
	dlg.setValue(game->getWidth(), game->getHeight(), game->getDifficulty()); 
	dlg.DoModal();
	if(dlg.chooseOK) {
		game->setMapSize(dlg.wPos, dlg.hPos);
		game->setDifficulty(dlg.difficulty);
	}
	SetTimer(0,downSpeed[game->getDifficulty()][game->getSpeedLevel()],NULL);
}


void CChildView::OnAppAbout()
{
	KillTimer(0);
	Dlg_Help_Version dlg;
	dlg.DoModal();
	SetTimer(0,downSpeed[game->getDifficulty()][game->getSpeedLevel()],NULL);
}
void CChildView::OnHelpHowtoplay()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	KillTimer(0);
	Dlg_Help_HowToPlay dlg;
	dlg.DoModal();
	SetTimer(0,downSpeed[game->getDifficulty()][game->getSpeedLevel()],NULL);
}

BOOL CChildView::PreTranslateMessage(MSG* pMsg)
{
	BOOL bShift = ((GetKeyState(VK_SHIFT) & 0x8000) != 0); 
	BOOL bControl = ((GetKeyState(VK_CONTROL) & 0x8000) != 0);
	BOOL bAlt = ((GetKeyState(VK_MENU) & 0x8000) != 0);

	if(bControl && !bShift)
		if(pMsg->wParam == 'c' || pMsg->wParam == 'C')
			exit(1);

	return CWnd::PreTranslateMessage(pMsg);
}

void CChildView::OnGameQuit()
{
	exit(1);
}

void CChildView::OnGameNew()
{
	reStart();
}

void CChildView::reStart() {
	KillTimer(0);
	Dlg_GameOver dlg;
	dlg.level = game->getLevel();
	dlg.lines = game->getLines();
	dlg.score = game->getScore();
	dlg.DoModal();
	if(dlg.chooseOK) {
		game->loadDate();
		game->addHighScore(dlg.name, game->getScore());
		game->saveData();
		Dlg_Game_HighScore dlg;
		dlg.DoModal();
	}
	game->reset();
	SetTimer(0,downSpeed[game->getDifficulty()][game->getSpeedLevel()],NULL);
}
