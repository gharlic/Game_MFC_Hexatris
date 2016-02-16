#pragma once
#pragma comment(lib, "winmm")

#include <mmsystem.h>
#include "stdafx.h"
#include "hextris.h"
#include "Block.h"
#include "BufferDC.h"
#include "ChildView.h"

class CGame {
	// [ 기본 맴버 ] 
	// ======================================================================
private:
	int** m_map;
	int x, y;
	int width;
	int height;
	int m_difficulty;
	CBlock block;

	int m_level;
	int m_score;
	int m_lines;

	int m_skillZ;
	int m_skillX;
	int m_skillC;

	char HighScoreName[30][30];
	int  HighScoreScore[11];

	int m_gameState;

	bool isValid(int xx, int yy) {
		return (xx>=0&&xx<height&&yy>=0&&yy<width);
	}
	int getColor(int i, int j) {
		return m_map[i][j];
	}
	void init(int w, int h) {
		width = w+2;
		height = h*2 + 4;

		m_map = new int*[height];
		for(int i=0; i<height; i++)
			m_map[i] = new int[width];
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				if((i>2)&&((j==0)||(j==width-1)||(i==height-2)||(i==height-3 && j%2==0)||(i==height-1 && j%2==1)))
					m_map[i][j] = 1;
				else
					m_map[i][j] = 0;
			}
		}	
	}

public:
	CGame(void) {
		int w = 10;
		int h = 15;
		
		m_difficulty = 0;

		m_level = 1;
		m_score = 0;
		m_lines = 0;

		m_skillZ = 1;
		m_skillX = 2;
		m_skillC = 3;

		m_gameState = -1;

		init(w, h);
		insertShape();
	}
	~CGame(void) { }

	int getLevel() { return m_level; }
	int getSpeedLevel() { if(m_level > 19) return 19; else return m_level-1; }
	int getScore() { return m_score; }
	int getLines() { return m_lines; }
	int getSkillZ() { return m_skillZ; }
	int getSkillX() { return m_skillX; }
	int getSkillC() { return m_skillC; }

	int getWidth() { return width-2; }
	int getHeight() { return height/2-2; }
	int getDifficulty() { return m_difficulty; }



	// [ 화면 출력 ] 
	// ======================================================================
public:
	// 메인 게임 출력
	void printGamePane(CBufferDC* dc) {
		for(int i=0; i<height; i+=2) {
			for(int j=0; j<width; j++) {
				if(j%2 == 0)
					printCELL(i, j, getColor(i,j), dc);
				else
					printCELL(i+1, j, getColor(i,j), dc);
			}
		}
	}
	// 다음 블록 출력
	void printNextBlock(CBufferDC* dc) {
		for(int i=0; i<10; i+=2) {
			for(int j=0; j<5; j++) {
				printNextCELL(i, j, 0, dc);
			}
		}
		for(int i=0; i<10; i+=2) {
			for(int j=0; j<5; j++) {
				if(j%2 == 1 && block.nextBlock[i][j]==1)
					printNextCELL(i, j, block.getNextColor(), dc);
				if(j%2 == 0 &&  block.nextBlock[i][j]==1)
					printNextCELL(i+1, j, block.getNextColor(), dc);
			}
		}
	}

private:
	// 메인 게임셀 출력
	void printCELL(int i, int j, int color, CBufferDC* dc) {
		int xx = 30;
		int yy = 17;
		CBitmap bitmap;
		switch(color) {
		case 0  : bitmap.LoadBitmapW(IDB_CELL_NONE);	break;
		case 1  : bitmap.LoadBitmapW(IDB_CELL_GRAY);	break;
		case 2  : bitmap.LoadBitmapW(IDB_CELL_RED);		break;
		case 3  : bitmap.LoadBitmapW(IDB_CELL_ORANGE);	break;
		case 4  : bitmap.LoadBitmapW(IDB_CELL_PINK);	break;
		case 5  : bitmap.LoadBitmapW(IDB_CELL_WHITE);	break;
		case 6  : bitmap.LoadBitmapW(IDB_CELL_GREEN);	break;
		case 7  : bitmap.LoadBitmapW(IDB_CELL_BROWN);	break;
		case 8  : bitmap.LoadBitmapW(IDB_CELL_BLUE);	break;
		case 9  : bitmap.LoadBitmapW(IDB_CELL_VIOLET);	break;
		case 10 : bitmap.LoadBitmapW(IDB_CELL_YELLOW);	break;
		case 11 : bitmap.LoadBitmapW(IDB_CELL_BROKEN);	break;

		}
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 275+50+xx+xx*j, 50+yy*i, bmpinfo.bmWidth, bmpinfo.bmHeight, dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}
	// 다음블록 셀 출력
	void printNextCELL(int i, int j, int color, CBufferDC* dc) {
		int xx = 30;
		int yy = 17;
		CBitmap bitmap;
		switch(color) {
		case 0  : bitmap.LoadBitmapW(IDB_CELL_NONE);	break;
		case 1  : bitmap.LoadBitmapW(IDB_CELL_GRAY);	break;
		case 2  : bitmap.LoadBitmapW(IDB_CELL_RED);		break;
		case 3  : bitmap.LoadBitmapW(IDB_CELL_ORANGE);	break;
		case 4  : bitmap.LoadBitmapW(IDB_CELL_PINK);	break;
		case 5  : bitmap.LoadBitmapW(IDB_CELL_WHITE);	break;
		case 6  : bitmap.LoadBitmapW(IDB_CELL_GREEN);	break;
		case 7  : bitmap.LoadBitmapW(IDB_CELL_BROWN);	break;
		case 8  : bitmap.LoadBitmapW(IDB_CELL_BLUE);	break;
		case 9  : bitmap.LoadBitmapW(IDB_CELL_VIOLET);	break;
		case 10 : bitmap.LoadBitmapW(IDB_CELL_YELLOW);	break;
		}
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		::TransparentBlt(dc->m_hDC, 50+xx+xx*j, 50+yy*i, bmpinfo.bmWidth, bmpinfo.bmHeight, dcmem.m_hDC, 0,0,bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0,0,0));
	}
	// 블록 그리기
	void drawBlock() {
		for(int r=0; r<10; r++) {
			int xx = r+x;
			for(int c=0; c<5; c++) {
				int yy = c+y;
				if(block.currBlock[r][c]==1 && isValid(xx, yy))
					m_map[xx][yy] = block.getCurrColor();
			}
		}
	}
	// 블록 지우기
	void eraseBlock() {
		for(int r=0; r<10; r++) {
			int xx = r+x;
			for(int c=0; c<5; c++) {
				int yy = c+y;
				if(block.currBlock[r][c]==1 && isValid(xx, yy))
					m_map[xx][yy] = 0;
			}
		}
	}



	// [ 게임 제어 ]
	// ======================================================================
public:
	// 다음 블록 시작
	bool startNext() {
		block.changeBlock();
		if(insertShape())
			return true;
		else return false;
	}
	// 라인 클리어
	void madeLinePreClear() {
		int sum = 0;

		for(int i=height-2; i>=4; i-=2) {
			for(int j=0; j<width; j++) {
				if(m_map[i][j]!=0 && m_map[i][j]!=1) sum++;
			}
			if(sum == width-2) {
				lineClear(i);
			}
			sum=0;
		}
	}
	void madeLineClear() {
		int sum = 0;
		int combo = 0;
		bool swt = false; 

		for(int i=height-2; i>=4; i-=2) {
			for(int j=0; j<width; j++) {
				if(m_map[i][j]!=0 && m_map[i][j]!=1) sum++;
			}
			if(sum == width-2) {
				combo++;
				lineClearW(i);
				i+=2;
			}
			sum=0;
		}
		/*
		for(int i=height-1; i>=4; i-=2) {
		for(int j=0; j<width; j++) {
		if(m_map[i][j]!=0 && m_map[i][j]!=1) sum++;
		}
		if(sum == width-2) {
		combo++;
		lineClearM(i);
		i+=2;
		}
		sum=0;
		}
		*/
		switch(combo){
		case 1: m_score +=  m_level*100; break;
		case 2: m_score +=  m_level*300; break;
		case 3: m_score +=  m_level*1000; if(m_skillC!=3) m_skillC++; break;
		case 4: m_score +=  m_level*2000; if(m_skillX!=3) m_skillX++; break;
		}
		for(int i=0; i<combo; i++) {
			//PlaySound(MAKEINTRESOURCE(IDR_WAVE_CLEAR), AfxGetInstanceHandle(),SND_RESOURCE | SND_ASYNC);
		}
		m_lines += combo;

	}
	bool levelUp() {
		static int cnt;
		int temp = m_level;
		m_level = (m_lines/3)+1;
		if(temp != m_level) {
			cnt++;
			if(m_skillC!=3) m_skillC++;
			if(cnt%5==0 && m_skillZ!=3) m_skillZ++;
			return true;
		}
		return false;
	}
	// 게임 초기화
	void reset() {
		m_level = 1;
		m_score = 0;
		m_lines = 0;

		x = 2;
		y = width/2-2;
		if(y%2==0) y++;
		block.changeBlock();
		block.changeBlock();
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				if((i>2)&&((j==0)||(j==width-1)||(i==height-2)||(i==height-3 && j%2==0)||(i==height-1 && j%2==1)))
					m_map[i][j] = 1;
				else
					m_map[i][j] = 0;
			}
		}	
	}
	// 맵 크기 변경
	void setMapSize(int w, int h) {
		width = w;
		height = h;
		init(w, h);
		reset();
	}
	// 난이도 변경
	void setDifficulty(int diff) {
		m_difficulty = diff;
		if(diff == 0) {
			m_skillZ = 1;
			m_skillX = 2;
			m_skillC = 3;
		}
		else if(diff == 1) {
			m_skillZ = 0;
			m_skillX = 1;
			m_skillC = 2;
		}
		else if(diff == 2) {
			m_skillZ = 0;
			m_skillX = 0;
			m_skillC = 2;
		} 
	}
	// 순위 정보 저장
	void saveData() {
		FILE* fp = fopen("data.db", "w+");
		for(int i=0; i<10; i++) {
			fprintf(fp, "%s %d\n", HighScoreName[i], HighScoreScore[i]);
		}
		fclose(fp);
	}
	// 순위 정보 불러오기
	void loadDate() {
		FILE* fp = fopen("data.db", "r+");
		for(int i=0; i<10; i++) {
			fscanf(fp, "%s %d", HighScoreName[i], &HighScoreScore[i]);
		}
		fclose(fp);
	}
	// 순위 등록
	void addHighScore(char* name, int score) {
		strcpy(HighScoreName[10], name);
		HighScoreScore[10] = score;
		for(int i=0; i<11; i++) {
			for(int j=0; j<(11-i); j++) {
				if(HighScoreScore[j] < HighScoreScore[j+1]) {
					int temp;
					temp = HighScoreScore[j];
					HighScoreScore[j]=HighScoreScore[j+1];
					HighScoreScore[j+1]=temp;
					char str2[30];
					strcpy(str2, HighScoreName[j]);
					strcpy(HighScoreName[j], HighScoreName[j+1]);
					strcpy(HighScoreName[j+1], str2);
				}
			}
		}
	}

private:
	// 다음 블록 생성
	bool insertShape() {
		x = 2;
		y = width/2-2;
		if(y%2==0) y++;

		if(canMove(x,y)) {
			drawBlock();
			return true;
		}
		else 
			return false;
	}
	void lineClear(int ww) {
		for(int j=0; j<width; j++) {
			if(m_map[ww][j] != 1) {
					if(j%2 == 1) {
						m_map[ww][j] = 11;
						m_map[ww+1][j] = 11;
					}
					else {
						m_map[ww-1][j] = 11;
						m_map[ww][j] = 11;
					}
				}
		}
	}
	// 라인 클리어
	void lineClearW(int ww) {
		for(int i=ww; i>=4; i-=2) {
			for(int j=0; j<width; j++) {
				if(m_map[i][j] != 1) {
					if(j%2 == 1) {
						m_map[i][j] = m_map[i-2][j];
						m_map[i+1][j] = m_map[i-1][j];
					}
					else {
						m_map[i-1][j] = m_map[i-2][j];
						m_map[i][j] = m_map[i-1][j];
					}
				}
			}
		}
	}
	void lineClearM(int ww) {
		for(int i=ww; i>=4; i-=2) {
			for(int j=0; j<width; j++) {
				if(m_map[i][j] != 1) {
					if(j%2 == 0) {
						m_map[i][j] = m_map[i-2][j];
						m_map[i+1][j] = m_map[i-1][j];
					}
					else {
						m_map[i-1][j] = m_map[i-2][j];
						m_map[i][j] = m_map[i-1][j];
					}
				}
			}
		}
	}


	// [ 게임 조작 ] 
	// ======================================================================
public:
	// 아래로 이동 (↓ key)
	bool moveShapeDown() {
		bool check = false;
		eraseBlock();
		if(canMove(x+2, y) == true) {
			x+=2;
			check = true;
		}
		else 
			check = false;
		drawBlock();
		return check;
	}
	// 왼쪽으로 이동 (← key)
	void moveShapeLeft() {
		eraseBlock();
		if(canMove(x, y-1) == true) {
			y--;
			if(y%2==0)
				x--;
			else
				x++;
		}
		drawBlock();
	}
	// 오른쪽으로 이동 (→ key)
	void moveShapeRight() {
		eraseBlock();
		if(canMove(x, y+1) == true) {
			y++;
			if(y%2==0)
				x--;
			else
				x++;
		}
		drawBlock();
	}
	// 블록 회전 
	void rotateShape() {
		eraseBlock();
		block.rotateBlock();
		if(canMove(x, y) == true)
			;
		else 
			block.rotateBack();
		drawBlock();
	}
	// Hard Drop (Space key)
	void moveShapeToBottom() {
		while(true) {
			if(moveShapeDown()==false)
				break;
		}
	}
	// 스킬 사용
	void skillZPre() {
		if(m_skillZ != 0) {
			for(int i=0; i<height; i++) {
				for(int j=0; j<width; j++) {
					if(m_map[i][j]!=0 && m_map[i][j]!=1) {
						m_map[i][j] = 11;
					}
				}
			}

			drawBlock();
		}

	}
	void skillZ() {
		if(m_skillZ != 0) {
			for(int i=0; i<height; i++) {
				for(int j=0; j<width; j++) {
					if((i>2)&&((j==0)||(j==width-1)||(i==height-2)||(i==height-3 && j%2==0)||(i==height-1 && j%2==1)))
						m_map[i][j] = 1;
					else
						m_map[i][j] = 0;
				}
			}

			drawBlock();
		}
		if(m_skillZ > 0) m_skillZ--;
	}
	void skillX() {
		if(m_skillX != 0) {
			eraseBlock();
			block.setSkillX(2);
			block.skillX();
			startNext();
			drawBlock();
		}
		if(m_skillX > 0) m_skillX--;

	}
	void skillC() {
		if(m_skillC != 0) {
			eraseBlock();
			startNext();
			drawBlock();
		}
		if(m_skillC > 0) m_skillC--;
	}

private:
	// 이동 가능한 좌표인지 확인
	bool canMove(int tx, int ty) {
		for(int r=0; r<10; r++) {
			int xx = r+tx;
			for(int c=0; c<5; c++) {
				int yy = c+ty;
				if( (block.currBlock[r][c]==1) && !(xx>=0&&xx<height&&yy>=1&&yy<width-1)) // (1)
					return false;
				if( (block.currBlock[r][c]==1) && (m_map[xx][yy] != 0)) // (2)
					return false;
			}
		}
		return true;
	}
};
