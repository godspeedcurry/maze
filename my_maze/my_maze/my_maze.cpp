// my_maze.cpp: 定义控制台应用程序的入口点。
#include "maze.h"
extern int a[100][100];
extern int m, n;
extern int flag;
extern Point start, end;
extern void dfs(int, int);
extern void draw(int,int,int,int,int,int);
int main() {
	flag = 0;//0 means we can't find the route
			 //input data
			 //1 represents wall | 0 represents road
	FILE *fp = fopen("maze1.txt", "r");

	if (fp == NULL) {//读取文件 
		printf("Error!");
		return 0;
	}
	int t = 0;
	int i;
	int j;
	fscanf(fp, "%d", &m);
	fscanf(fp, "%d", &n);
	printf("%d %d\n", m, n);
	fscanf(fp, "%d%d%d%d", &start.x, &start.y, &end.x, &end.y);


	for (i = 0; i <= m + 1; i++) {//rows 
		for (j = 0; j <= n + 1; j++) {//columns 
			if (i == 0 || i == m + 1 || j == 0 || j == n + 1) {
				a[i][j] = 1;
			}
			else {
				fscanf(fp, "%d", &a[i][j]);
			}
		}
	}

	for (i = 0; i <= m + 1; i++) {
		for (j = 0; j <= n + 1; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}//输出地图 
	fclose(fp);
	printf("Please give the start point and the end point. x1 y1 x2 y2\n");
	//scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);//input the point
															 //use the algorithm
	dfs(start.x, start.y);
	if (flag == 0)printf("CAN'T FIND THE ROUTE!\n");//failed
	else {
		printf("FIND THE ROUTE!!\n");
		for (i = 0; i <= m + 1; i++) {
			for (j = 0; j <= n + 1; j++) {
				if (i == start.x&&j == start.y) {
					printf("■");//start point
				}
				else if (i == end.x&&j == end.y) {
					printf("■");//end point
				}
				else if (a[i][j] == 1) {
					printf("1 ");//blocked by the wall
				}
				else if (a[i][j] == 0) {
					printf("0 ");//here is the road!
				}
				else if (a[i][j] == 2) {
					printf("□");//our route
				}
			}
			printf("\n");
		}
		draw(m,n,start.x,start.y,end.x,end.y);
		////根据数组绘制图形界面
		////初始化画布颜色
		//initgraph((n + 2) * 50, (m + 2) * 50);
		////设置背景色为白色
		//setbkcolor(EGERGB(0xFF, 0xFF, 0xFF));

		//int x, y;
		////把img平铺在屏幕上，使用一个二重循环

		//for (y = 0; y <= m + 1; ++y)
		//{
		//	for (x = 0; x <= n + 1; ++x)
		//	{
		//		setcolor(BLACK);
		//		if (y >= 1) {
		//			line(50, 50 * y, (n + 2) * 50, 50 * y);
		//		}
		//		setcolor(BLACK);
		//		line(50 * x, 50, 50 * x, (m + 2) * 50);
		//		if (y == start.x&&x == start.y) {
		//			setfillcolor(EGERGB(91, 198, 255));
		//			bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
		//			setcolor(EGERGB(0x00, 0x00, 0x00));
		//			setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
		//			fillellipse(x * 50 + 25, y * 50 + 25, 18, 18);
		//			//文字颜色
		//			setcolor(EGERGB(0x0, 0x00, 0x00));
		//			setfontbkcolor(EGERGB(255,255, 255));
		//			//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
		//			//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
		//			setfont(12, 0, "宋体");
		//			//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
		//			//要使用特殊格式化字符请用outtextrect
		//			outtextxy(x * 50 + 19, y * 50 + 19, "起");
		//		}
		//		else if (y == end.x&&x == end.y) {
		//			setfillcolor(EGERGB(91, 198, 255));
		//			bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
		//			setcolor(EGERGB(0x00, 0x00, 0x00));
		//			setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
		//			fillellipse(x * 50 + 25, y * 50 + 25, 18, 18);
		//			//文字颜色
		//			setcolor(EGERGB(0x0, 0x00, 0x00));
		//			setfontbkcolor(EGERGB(255, 255, 255));
		//			//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
		//			//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
		//			setfont(12, 0, "宋体");
		//			//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
		//			//要使用特殊格式化字符请用outtextrect
		//			outtextxy(x * 50 + 19, y * 50 + 19, "终");
		//		}
		//		else if (a[y][x] == 1) {//设置颜色为红色（墙壁）
		//			
		//			setfillcolor(EGERGB(198, 42, 0));
		//			bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
		//			if ((y == 0&&x>=1&&x<=n) ) {
		//				//文字颜色
		//				setcolor(EGERGB(0x0, 0x00, 0x00));
		//				//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
		//				//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
		//				setfont(18, 0, "宋体");
		//				setfontbkcolor(EGERGB(198,42, 0));
		//				//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
		//				//要使用特殊格式化字符请用outtextrect
		//				char str[5];
		//				sprintf(str, "%d", x);
		//				outtextxy(x * 50 + 19, y * 50 + 19, str);
		//			}
		//			else if ((x == 0 && y >= 1 && y <= m)) {
		//				//文字颜色
		//				setcolor(EGERGB(0x0, 0x00, 0x00));
		//				//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
		//				//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
		//				setfont(18, 0, "宋体");
		//				setfontbkcolor(EGERGB(198, 42, 0));
		//				//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
		//				//要使用特殊格式化字符请用outtextrect
		//				char str[5];
		//				sprintf(str, "%d", y);
		//				outtextxy(x * 50 + 19, y * 50 + 19, str);
		//			}
		//		}
		//		else if (a[y][x] == 0) {//可以走的路
		//			setfillcolor(EGERGB(91, 198, 255));
		//			bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
		//		}
		//		else if (a[y][x] == 2) {//我们的路
		//			setfillcolor(EGERGB(91, 198, 255));
		//			bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
		//			setcolor(EGERGB(0x00, 0x00, 0x00));
		//			setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
		//			fillellipse(x * 50 + 25, y * 50 + 25, 18, 18);
		//		}

		//	}
		//}

		//getch();
		///*delimage(pathway);*/
		//closegraph();
	}
	return 0;
}
