#pragma once

#include "time.h"
#include "stdlib.h"

class CBlock {
private:
	int redBlock[6][10][5];
	int orangeBlock[6][10][5];
	int pinkBlock[6][10][5];
	int whiteBlock[6][10][5];
	int greenBlock[6][10][5];
	int brownBlock[6][10][5];
	int blueBlock[6][10][5];
	int violetBlock[6][10][5];
	int yellowBlock[6][10][5];

	int m_currColor;
	int m_nextColor;
	int m_rotateIndex;
	int m_rotatePrev;
	int m_currBlockNumb;
	int m_nextBlockNumb;

	int m_skillX;
	int m_skillC;

	// 블록 정의
	void initBlock() {
		const int red[6][10][5] = {
			{
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,1},
				{0,0,0,1,1},
				{0,0,1,1,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,1,0},
				{0,0,0,1,1},
				{0,0,0,0,1},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,1,1,0},
				{0,1,1,0,0},
				{1,1,0,0,0},
				{1,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{1,0,0,0,0},
				{1,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,1,0},
				{0,0,0,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}

		};
		const int orange[6][10][5] = {
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{1,0,0,0,0},
				{1,1,0,0,0},
				{0,1,1,0,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{1,0,1,0,0},
				{1,1,1,0,0},
				{1,1,0,0,0},
				{1,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,1,1,0,0},
				{1,1,1,0,0},
				{1,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}
		};
		const int pink[6][10][5] = {
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,1,1,0},
				{0,1,1,0,0},
				{0,1,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
				{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,1,1,1,0},
				{0,1,0,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,1,1,0,0},
				{0,1,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,0,1,1,0},
				{0,0,1,1,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,0,1,0},
				{0,1,1,1,0},
				{0,0,1,1,0},
				{0,0,0,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,1,0},
				{0,0,1,1,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}
		};
		const int white[6][10][5] = {
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{1,0,0,0,0},
				{1,0,0,0,0},
				{1,0,1,0,0},
				{1,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{1,1,0,0,0},
				{1,0,0,0,0},
				{1,0,0,0,0},
				{1,1,0,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{1,1,1,0,0},
				{1,0,1,0,0},
				{1,0,0,0,0},
				{1,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{1,1,1,0,0},
				{1,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{1,0,1,0,0},
				{1,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}
		};
		const int green[6][10][5] = {
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,0,1,0},
				{0,0,0,1,0},
				{0,0,1,1,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,1},
				{0,0,1,1,1},
				{0,0,0,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,1,0},
				{0,0,0,1,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,1,1,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,0,0,0},
				{1,1,1,0,0},
				{1,0,1,1,0},
				{0,0,0,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}
		};
		const int brown[6][10][5] = {
			{
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,1,1,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,1,1,1},
				{0,1,1,0,1},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,1,0},
				{0,0,0,1,0},
				{0,0,0,1,0},
				{0,0,0,1,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0}
			},
			{	
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,1,0},
				{1,0,1,1,0},
				{1,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,1,0},
				{0,0,0,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}
		};
		const int blue[6][10][5] = {
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{1,1,1,0,0},
				{1,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{1,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{1,0,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{1,1,1,0,0},
				{1,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{1,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{1,0,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{1,1,0,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}
		};
		const int violet[6][10][5] = {
			{
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,1,1,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,0,1,0},
				{0,1,1,1,1},
				{0,0,1,0,1},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,1,0},
				{0,0,0,1,0},
				{0,0,0,1,0},
				{0,0,0,1,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,1,1,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{1,0,1,0,0},
				{1,1,1,1,0},
				{0,1,0,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}
		};
		const int yellow[6][10][5] = {
			{
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,1,0},
				{0,0,0,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,0,1,0},
				{0,0,0,1,0},
				{0,0,1,1,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,1},
				{0,1,1,1,1},
				{0,1,0,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,0,0,0},
				{0,1,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,1,0},
				{0,0,0,1,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,1,1,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{0,0,0,0,0}
			},
			{
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,0,1,0},
				{1,1,1,1,0},
				{1,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}
		};
		for(int i=0; i<6; i++) {
			for(int j=0; j<10; j++) {
				for(int k=0; k<5; k++) {
					redBlock[i][j][k]		= red[i][j][k];
					orangeBlock[i][j][k]	= orange[i][j][k];
					pinkBlock[i][j][k]		= pink[i][j][k];
					whiteBlock[i][j][k]		= white[i][j][k];
					greenBlock[i][j][k]		= green[i][j][k];
					brownBlock[i][j][k]		= brown[i][j][k];
					blueBlock[i][j][k]		= blue[i][j][k];
					violetBlock[i][j][k]	= violet[i][j][k];
					yellowBlock[i][j][k]	= yellow[i][j][k];
				}
			}
		}


	}
	// 블록 회전
	void rotate() {
		for(int i=0; i<10; i++) {
			for(int j=0; j<5; j++) {
				switch(m_currBlockNumb) {
				case 0: currBlock[i][j] = redBlock[m_rotateIndex][i][j];	break;
				case 1: currBlock[i][j] = orangeBlock[m_rotateIndex][i][j]; break;
				case 2: currBlock[i][j] = pinkBlock[m_rotateIndex][i][j];	break;
				case 3: currBlock[i][j] = whiteBlock[m_rotateIndex][i][j];	break;
				case 4: currBlock[i][j] = greenBlock[m_rotateIndex][i][j];	break;
				case 5: currBlock[i][j] = brownBlock[m_rotateIndex][i][j];	break;
				case 6: currBlock[i][j] = blueBlock[m_rotateIndex][i][j];	break;
				case 7: currBlock[i][j] = violetBlock[m_rotateIndex][i][j]; break;
				case 8 :currBlock[i][j] = yellowBlock[m_rotateIndex][i][j]; break;
				} 
			}
		}
	}

public:
	CBlock(void) {
		srand((unsigned)time(NULL));
		initBlock();
		m_rotateIndex = 0;
		m_skillX = 0;
		changeBlock();
		changeBlock();
	}
	~CBlock(void) { }

	int currBlock[10][5];
	int nextBlock[10][5];

	int getCurrColor() {
		return m_currColor;
	}
	int getNextColor() {
		return m_nextColor;
	}

	void setSkillX(int n) {
		m_skillX = n+1;
	}
	void setSkillC(int n) {
		m_skillC = n;
	}

	// 블록 생성
	void changeBlock() {
		int random = rand()%18;
		switch(random) {
		case 0:
		case 1:
		case 2:		random = 0; break;
		case 3:
		case 4:		random = 1; break;
		case 5: 
		case 6:		random = 2; break;
		case 7:		random = 3; break;
		case 8:
		case 9:		random = 4; break;
		case 10:
		case 11:	random = 5; break;
		case 12:
		case 13:	random = 6; break;
		case 14:
		case 15:	random = 7; break;
		case 16:
		case 17:	random = 8; break;
		}

		m_currBlockNumb = m_nextBlockNumb;
		m_nextBlockNumb = random;
		m_currColor = m_nextColor;
		switch(random) {
		case 0: m_nextColor = 2; break;
		case 1: m_nextColor = 3; break;
		case 2: m_nextColor = 4; break;
		case 3: m_nextColor = 5; break;
		case 4: m_nextColor = 6; break;
		case 5: m_nextColor = 7; break;
		case 6: m_nextColor = 8; break;
		case 7: m_nextColor = 9; break;
		case 8: m_nextColor = 10;  break;
		}
		for(int i=0; i<10; i++)
			for(int j=0; j<5; j++)
				currBlock[i][j] = nextBlock[i][j];
		for(int i=0; i<10; i++) {
			for(int j=0; j<5; j++) {
				switch(random) {
				case 0: nextBlock[i][j] = redBlock[0][i][j]; break;
				case 1: nextBlock[i][j] = orangeBlock[0][i][j]; break;
				case 2: nextBlock[i][j] = pinkBlock[0][i][j]; break;
				case 3: nextBlock[i][j] = whiteBlock[0][i][j]; break;
				case 4: nextBlock[i][j] = greenBlock[0][i][j]; break;
				case 5: nextBlock[i][j] = brownBlock[0][i][j]; break;
				case 6: nextBlock[i][j] = blueBlock[0][i][j]; break;
				case 7: nextBlock[i][j] = violetBlock[0][i][j]; break;
				case 8: nextBlock[i][j] = yellowBlock[0][i][j]; break;
				} 
			}
		}
		skillX();
		

	}
	void skillX() {

		if(m_skillX != 0) {
			m_skillX--;
			m_currBlockNumb = m_nextBlockNumb = 0;
			m_currColor = m_nextColor = 2;

			for(int i=0; i<10; i++)
				for(int j=0; j<5; j++)
					currBlock[i][j] = redBlock[0][i][j];
			for(int i=0; i<10; i++)
				for(int j=0; j<5; j++)
					nextBlock[i][j] = redBlock[0][i][j];
		}
	}
	void skillC() {
		if(m_skillC != 0) {
			m_skillC--;
			int random = rand()%18;
			switch(random) {
			case 0:
			case 1:
			case 2:		random = 0; break;
			case 3:
			case 4:		random = 1; break;
			case 5: 
			case 6:		random = 2; break;
			case 7:		random = 3; break;
			case 8:
			case 9:		random = 4; break;
			case 10:
			case 11:	random = 5; break;
			case 12:
			case 13:	random = 6; break;
			case 14:
			case 15:	random = 7; break;
			case 16:
			case 17:	random = 8; break;
			}

			m_currBlockNumb = m_nextBlockNumb;
			m_nextBlockNumb = random;
			m_currColor = m_nextColor;
			switch(random) {
			case 0: m_nextColor = 2; break;
			case 1: m_nextColor = 3; break;
			case 2: m_nextColor = 4; break;
			case 3: m_nextColor = 5; break;
			case 4: m_nextColor = 6; break;
			case 5: m_nextColor = 7; break;
			case 6: m_nextColor = 8; break;
			case 7: m_nextColor = 9; break;
			case 8: m_nextColor = 10;  break;
			}
			for(int i=0; i<10; i++)
				for(int j=0; j<5; j++)
					currBlock[i][j] = nextBlock[i][j];
			for(int i=0; i<10; i++) {
				for(int j=0; j<5; j++) {
					switch(random) {
					case 0: nextBlock[i][j] = redBlock[0][i][j]; break;
					case 1: nextBlock[i][j] = orangeBlock[0][i][j]; break;
					case 2: nextBlock[i][j] = pinkBlock[0][i][j]; break;
					case 3: nextBlock[i][j] = whiteBlock[0][i][j]; break;
					case 4: nextBlock[i][j] = greenBlock[0][i][j]; break;
					case 5: nextBlock[i][j] = brownBlock[0][i][j]; break;
					case 6: nextBlock[i][j] = blueBlock[0][i][j]; break;
					case 7: nextBlock[i][j] = violetBlock[0][i][j]; break;
					case 8: nextBlock[i][j] = yellowBlock[0][i][j]; break;
					} 
				}
			}
		}
	}
	// 블록 회전
	void rotateBlock() {
		m_rotatePrev = m_rotateIndex;
		m_rotateIndex = (m_rotateIndex+1) % 6;
		rotate();
	}
	void rotateBack() {
		m_rotateIndex = m_rotatePrev;
		rotate();
	}
};

