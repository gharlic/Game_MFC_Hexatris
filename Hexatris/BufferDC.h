#pragma once

#include "stdafx.h"
#include "hextris.h"

class CBufferDC : public CDC
{
public:
	CBufferDC() {}
	CBufferDC(const CBufferDC &src) {}
	CBufferDC& operator=(const CBufferDC &src) {}

protected:
	BOOL Attach(HDC hDC);
	HDC	Detach();

private:
	CWnd*		m_pParent;							// 대상 윈도우 포인터
	CDC*		m_pTarget;							// 대상 윈도우 DC 포인터
	PAINTSTRUCT	m_PaintStruct;						
	CRect		m_RcClient, m_RcWindow;				// 대상 윈도우 크기 정보

	CDC			m_MemoryDC;							// 버퍼 DC
	CBitmap		m_MemoryBmp, *m_pOldMemoryBmp;		// 버퍼링 비트맵

public:
	CBufferDC(CWnd *pParent);
	~CBufferDC(void);

public:
	inline CRect ClientRect() const { return m_RcClient; }
	inline CRect WindowRect() const { return m_RcWindow; }
	inline CRect UpdateRect() const { return m_PaintStruct.rcPaint; }

	operator HDC() const { return m_MemoryDC.m_hDC; }
};

