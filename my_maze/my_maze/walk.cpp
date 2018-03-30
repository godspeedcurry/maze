#include "maze.h"
#include "stdafx.h"
#include "graphics.h"
#include <stdio.h>
extern int a[][100];
void walk(int i, int j)
{
	if (a[i][j] == 2)
	{
		setfillcolor(EGERGB(0, 121, 215));
		bar(j * 50, i * 50, j * 50 + 50, i * 50 + 50);
		setcolor(EGERGB(0x00, 0x00, 0x00));
		setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
		fillellipse(j * 50 + 25, i * 50 + 25, 18, 18);
		delay_fps(5);
		a[i][j] = 3;
		if (a[i - 1][j] == 2){
			walk(i - 1, j);
		}
		else if (a[i + 1][j] == 2) {
			walk(i + 1, j);
		}
		else if (a[i][j + 1] == 2) {
			walk(i, j+1);
		}
		else if (a[i][j - 1] == 2) {
			walk(i, j-1);
		}
		else return;

	}
	

}
