// my_maze.cpp: 定义控制台应用程序的入口点。
#include "maze.h"
extern int a[100][100];
extern int m, n;
extern int flag;
extern Point start, end;
extern void dfs(int, int);
extern void draw(int,int,int,int,int,int);
extern int create(int, int);
int main() {
	flag = 0;//0 means we can't find the route
			 //input data
			 //1 represents wall | 0 represents road
	//FILE *fp = fopen("maze1.txt", "r");

	//if (fp == NULL) {//读取文件 
	//	printf("Error!");
	//	return 0;
	//}
	//int t = 0;
	int i;
	int j;
	//fscanf(fp, "%d", &m);
	//fscanf(fp, "%d", &n);
	//printf("%d %d\n", m, n);
	//fscanf(fp, "%d%d%d%d", &start.x, &start.y, &end.x, &end.y);


	//for (i = 0; i <= m + 1; i++) {//rows 
	//	for (j = 0; j <= n + 1; j++) {//columns 
	//		if (i == 0 || i == m + 1 || j == 0 || j == n + 1) {
	//			a[i][j] = 1;
	//		}
	//		else {
	//			fscanf(fp, "%d", &a[i][j]);
	//		}
	//	}
	//}
	m = 13;
	n = 13;
	create(m,n);
	start.x = 1;
	start.y = 1;
	end.x = m;
	end.y = n;
	for (i = 0; i <= m + 1; i++) {
		for (j = 0; j <= n + 1; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}//输出地图 
	//fclose(fp);
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

	}
	return 0;
}
