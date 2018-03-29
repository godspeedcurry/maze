#include "maze.h"
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
#define down 1
#define right 2
#define left 4
#define up 8
vector <int> block_row;
vector <int> block_column;
vector <int> block_direct;
extern int a[][100];
void init(int,int);
void push(int x, int y, int direct);
int count(int, int);
int x_num = 1;
int y_num = 1;
int create(int m,int n) {

	init(m,n);
	srand((unsigned)time(NULL));//���������
	count(m,n);
	a[1][1] = 0;
	while (block_row.size()) {//��һ��ѹ������ǽ������ұߺ�������棩����ѭ��
		int num = block_row.size();
		int randnum = rand() % num;//����0-num-1֮����������ͬʱҲ��vector����±�
		x_num = block_row[randnum];//���������п��Բ�д
		y_num = block_column[randnum];
		switch (block_direct[randnum]) {//ѡ��һ��������к�����������ʼ�� �ڿ� Ŀ��� ����������ͬһֱ���� ����ƶ���Ŀ����λ��
		case down: {
			x_num = block_row[randnum] + 1;
			y_num = block_column[randnum];
			break;
		}
		case right: {
			x_num = block_row[randnum];
			y_num = block_column[randnum] + 1;
			break;
		}
		case left: {
			x_num = block_row[randnum];
			y_num = block_column[randnum] - 1;
			break;
		}
		case up: {
			x_num = block_row[randnum] - 1;
			y_num = block_column[randnum];
			break;
		}
		}
		if (a[x_num][y_num] == 1) {//Ŀ��������ǽ
			a[block_row[randnum]][block_column[randnum]] = 0;//��ͨǽ
			a[x_num][y_num] = 0;//��ͨĿ���
			count(m,n);//�ٴμ��㵱ǰλ����Χ����ǽ�����������vector
		}
		block_row.erase(block_row.begin() + randnum);//ɾ�����ǽ(���ò��˵�ǽɾ�ˣ�������Щ�Ѿ�ʩ�����˲�����ʩ���ˣ�ͬʱҲ��ȷ������������ѭ��)
		block_column.erase(block_column.begin() + randnum);
		block_direct.erase(block_direct.begin() + randnum);
	}
	return 0;
}
void init(int m,int n) {//����ͼȫ����1=wall
	for (int i = 0; i <= m + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			a[i][j] = 1;//wall
		}
	}
}
void push(int x, int y, int direct) {//��һ�����ݴ�Ž�����vector������
	block_row.push_back(x);
	block_column.push_back(y);
	block_direct.push_back(direct);
}
int count(int m,int n) {//���㵱ǰλ����Χ ǽ�ĸ���
	int cnt = 0;
	if (x_num + 1 <= m) {
		push(x_num + 1, y_num, down);
		cnt++;
	} //down
	if (y_num + 1 <= n) {
		push(x_num, y_num + 1, right);
		cnt++;
	} //right
	if (x_num - 1 >= 1) {
		push(x_num - 1, y_num, up);
		cnt++;
	} //up
	if (y_num - 1 >= 1) {
		push(x_num, y_num - 1, left);
		cnt++;
	} //left
	return cnt;
}