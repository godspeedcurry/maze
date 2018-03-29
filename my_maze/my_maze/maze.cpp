#include "maze.h"
Point start, end;
int m;
int n;
int a[100][100];
int flag; //0 means we can't find the route ,1 means we can find the route
void dfs(int x, int y) {
	a[x][y] = 2;//mark the road
	if (x == end.x&&y == end.y) {
		flag = 1;
		return;
	}
	//-> turn right
	//condition:have the road and won't step out the maze max:n
	if (y + 1 <= n && a[x][y + 1] == 0) {
		dfs(x, y + 1);
	}
	if (flag)return;

	//¡ýgo down
	//condition: have the road and won't step out the maze max: m
	if (x + 1 <= m && a[x + 1][y] == 0) {
		dfs(x + 1, y);
	}
	if (flag)return;

	//<- turn left
	//condition: have the road and won't step out the maze min: 1
	if ((y - 1 >= 1) && (a[x][y - 1] == 0)) {
		dfs(x, y - 1);
	}
	if (flag)return;

	//¡ügo up
	if (x - 1 >= 1 && a[x - 1][y] == 0) {
		dfs(x - 1, y);
	}
	if (flag)return;
	a[x][y] = 0;//restore the value
}
