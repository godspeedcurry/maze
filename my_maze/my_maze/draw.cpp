#include "maze.h"
#include "stdafx.h"
#include "graphics.h"
extern int a[][100];
extern void walk(int, int);
void draw(int m, int n, int start_x, int start_y, int end_x, int end_y) {
	setrendermode(RENDER_MANUAL);
	//根据数组绘制图形界面
	//初始化画布颜色
	initgraph((n + 2) * 50, (m + 2) * 50);
	//设置背景色为白色
	setbkcolor(EGERGB(0xFF, 0xFF, 0xFF));

	int x, y;
	//把img平铺在屏幕上，使用一个二重循环

	for (y = 0; y <= m + 1; ++y)
	{
		for (x = 0; x <= n + 1; ++x)
		{
			setcolor(BLACK);
			if (y >= 1) {
				line(50, 50 * y, (n + 2) * 50, 50 * y);
			}
			setcolor(BLACK);
			line(50 * x, 50, 50 * x, (m + 2) * 50);
			if (y == start_x && x == start_y) {
				setfillcolor(EGERGB(91, 198, 255));
				bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
				setcolor(EGERGB(0x00, 0x00, 0x00));
				setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
				fillellipse(x * 50 + 25, y * 50 + 25, 18, 18);
				//文字颜色
				setcolor(EGERGB(0x0, 0x00, 0x00));
				setfontbkcolor(EGERGB(255, 255, 255));
				//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
				//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
				setfont(12, 0, "宋体");
				//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
				//要使用特殊格式化字符请用outtextrect
				outtextxy(x * 50 + 19, y * 50 + 19, "起");
			}
			else if (y == end_x && x == end_y) {
				setfillcolor(EGERGB(91, 198, 255));
				bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
				setcolor(EGERGB(0x00, 0x00, 0x00));
				setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
				fillellipse(x * 50 + 25, y * 50 + 25, 18, 18);
				//文字颜色
				setcolor(EGERGB(0x0, 0x00, 0x00));
				setfontbkcolor(EGERGB(255, 255, 255));
				//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
				//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
				setfont(12, 0, "宋体");
				//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
				//要使用特殊格式化字符请用outtextrect
				outtextxy(x * 50 + 19, y * 50 + 19, "终");
			}
			else if (a[y][x] == 1) {//设置颜色为红色（墙壁）

				setfillcolor(EGERGB(198, 42, 0));
				bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
				if ((y == 0 && x >= 1 && x <= n)) {
					//文字颜色
					setcolor(EGERGB(0x0, 0x00, 0x00));
					//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
					//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
					setfont(18, 0, "宋体");
					setfontbkcolor(EGERGB(198, 42, 0));
					//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
					//要使用特殊格式化字符请用outtextrect
					char str[5];
					sprintf(str, "%d", x);
					outtextxy(x * 50 + 19, y * 50 + 19, str);
				}
				else if ((x == 0 && y >= 1 && y <= m)) {
					//文字颜色
					setcolor(EGERGB(0x0, 0x00, 0x00));
					//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
					//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
					setfont(18, 0, "宋体");
					setfontbkcolor(EGERGB(198, 42, 0));
					//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
					//要使用特殊格式化字符请用outtextrect
					char str[5];
					sprintf(str, "%d", y);
					outtextxy(x * 50 + 19, y * 50 + 19, str);
				}
			}
			else if (a[y][x] == 0) {//可以走的路
				setfillcolor(EGERGB(91, 198, 255));
				bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
			}
			else if (a[y][x] == 2) {//我们的路
				setfillcolor(EGERGB(91, 198, 255));
				bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
				setcolor(EGERGB(0x00, 0x00, 0x00));
				setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
				fillellipse(x * 50 + 25, y * 50 + 25, 18, 18);
			}

		}
	}
	int k = 0;
	for (; k != key_esc; ) // key_esc是ege定义的按键常数
	{
		char str[32];
		//等待用户按键，并把得到的按键给k
		//如果你不想等待，可以在调用getch之前，使用kbhit检测是否有按键按下
		//如 if ( kbhit() ) k = getch();
		k = getch();
		if (k == 'w') {
			walk(1, 1);
		}
		//格式化输出为字符串，用于后面输出

	}
	closegraph();

}