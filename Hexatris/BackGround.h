#pragma once

#include "stdafx.h"
#include "hextris.h"
#include "BufferDC.h"
#include "Game.h"

class CBackGround
{
private:
	CGame* game;

public:

	CBackGround(CGame* g = NULL) {
		game = g;
	}
	~CBackGround(void) { }

	// 배경 출력
	void printBackGround(CBufferDC* dc) {

	}

public:
	// 메뉴 출력
	void printMenu(CBufferDC* dc) {
		printMainMenu(dc);
		printNextBlockPanel(dc);
		printState(dc);
		printSkillIconZ(dc);
		printSkillIconX(dc);
		printSkillIconC(dc);
	}
	void printStartScreen(CBufferDC* dc, int swt) {
		CBitmap bitmap;
		if(swt == 0) bitmap.LoadBitmapW(IDB_STARTSCREEN);
		else bitmap.LoadBitmapW(IDB_STARTSCREEN2);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, 
			dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}
	void printSkillZ(CBufferDC* dc, int n) {
		CBitmap bitmap;
		switch(n) {
		case 0 :bitmap.LoadBitmapW(IDB_ICON0); break;
		case 1 :bitmap.LoadBitmapW(IDB_ICON1); break;
		case 2 :bitmap.LoadBitmapW(IDB_ICON2); break;
		case 3 :bitmap.LoadBitmapW(IDB_ICON3); break;
		}

		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 100, 500, bmpinfo.bmWidth, bmpinfo.bmHeight, 
			dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}
	void printSkillX(CBufferDC* dc, int n) {
		CBitmap bitmap;
		switch(n) {
		case 0 :bitmap.LoadBitmapW(IDB_ICON0); break;
		case 1 :bitmap.LoadBitmapW(IDB_ICON1); break;
		case 2 :bitmap.LoadBitmapW(IDB_ICON2); break;
		case 3 :bitmap.LoadBitmapW(IDB_ICON3); break;
		}
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 100, 560, bmpinfo.bmWidth, bmpinfo.bmHeight, 
			dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}
	void printSkillC(CBufferDC* dc, int n) {
		CBitmap bitmap;
		switch(n) {
		case 0 :bitmap.LoadBitmapW(IDB_ICON0); break;
		case 1 :bitmap.LoadBitmapW(IDB_ICON1); break;
		case 2 :bitmap.LoadBitmapW(IDB_ICON2); break;
		case 3 :bitmap.LoadBitmapW(IDB_ICON3); break;
		}

		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 100, 620, bmpinfo.bmWidth, bmpinfo.bmHeight, 
			dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}

private:
	// 메뉴 테두리
	void printMainMenu(CBufferDC* dc) {
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_MENU_panel);

		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, 
			dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}
	// 다음 블록 창
	void printNextBlockPanel(CBufferDC* dc) {
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_MENU_nextBlock);

		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 50, 40, bmpinfo.bmWidth, bmpinfo.bmHeight, 
			dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}

	void printState(CBufferDC* dc) {
		dc->SetTextColor(RGB(255,255,255));
		dc->SetBkColor(RGB(0,0,0));

		TCHAR* msg = _T("    레벨  : ");
		TCHAR str[21];
		_stprintf_s(str, _countof(str), _T("%20d"), game->getLevel()); 
		dc->TextOut(50, 300, msg, lstrlen(msg));
		dc->TextOut(150, 300, str, 20);

		msg = _T("    점수  : ");
		_stprintf_s(str, _countof(str), _T("%20d"), game->getScore()); 
		dc->TextOut(50, 350, msg, lstrlen(msg));
		dc->TextOut(150, 350, str, 20);

		msg = _T("    라인  : ");
		_stprintf_s(str, _countof(str), _T("%20d"), game->getLines()); 
		dc->TextOut(50, 400, msg, lstrlen(msg));
		dc->TextOut(150, 400, str, 20);
	}
	void printSkillIconZ(CBufferDC* dc) {
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_ICONZ);

		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 50, 500, bmpinfo.bmWidth, bmpinfo.bmHeight, 
			dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}
	void printSkillIconX(CBufferDC* dc) {
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_ICONX);

		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 50, 560, bmpinfo.bmWidth, bmpinfo.bmHeight, 
			dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}
	void printSkillIconC(CBufferDC* dc) {
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_ICONC);

		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 50, 620, bmpinfo.bmWidth, bmpinfo.bmHeight, 
			dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}
};

