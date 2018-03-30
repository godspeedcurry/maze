#include "maze.h"
#include "stdafx.h"
#include "graphics.h"
extern int a[][100];
extern void walk(int, int);
void draw(int m, int n, int start_x, int start_y, int end_x, int end_y) {
	setrendermode(RENDER_MANUAL);
	//�����������ͼ�ν���
	//��ʼ��������ɫ
	initgraph((n + 2) * 50, (m + 2) * 50);
	//���ñ���ɫΪ��ɫ
	setbkcolor(EGERGB(0xFF, 0xFF, 0xFF));

	int x, y;
	//��imgƽ������Ļ�ϣ�ʹ��һ������ѭ��

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
				//������ɫ
				setcolor(EGERGB(0x0, 0x00, 0x00));
				setfontbkcolor(EGERGB(255, 255, 255));
				//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
				//����߶�Ϊ12�����൱��С����֣�����9���֣�ʵ�ʵĻ�����Լ���ɰ�
				setfont(12, 0, "����");
				//д���֣�ע�⣺outtextxy��֧��\t \n�����ʽ���õ������ַ��������ַ��ᱻ����
				//Ҫʹ�������ʽ���ַ�����outtextrect
				outtextxy(x * 50 + 19, y * 50 + 19, "��");
			}
			else if (y == end_x && x == end_y) {
				setfillcolor(EGERGB(91, 198, 255));
				bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
				setcolor(EGERGB(0x00, 0x00, 0x00));
				setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
				fillellipse(x * 50 + 25, y * 50 + 25, 18, 18);
				//������ɫ
				setcolor(EGERGB(0x0, 0x00, 0x00));
				setfontbkcolor(EGERGB(255, 255, 255));
				//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
				//����߶�Ϊ12�����൱��С����֣�����9���֣�ʵ�ʵĻ�����Լ���ɰ�
				setfont(12, 0, "����");
				//д���֣�ע�⣺outtextxy��֧��\t \n�����ʽ���õ������ַ��������ַ��ᱻ����
				//Ҫʹ�������ʽ���ַ�����outtextrect
				outtextxy(x * 50 + 19, y * 50 + 19, "��");
			}
			else if (a[y][x] == 1) {//������ɫΪ��ɫ��ǽ�ڣ�

				setfillcolor(EGERGB(198, 42, 0));
				bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
				if ((y == 0 && x >= 1 && x <= n)) {
					//������ɫ
					setcolor(EGERGB(0x0, 0x00, 0x00));
					//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
					//����߶�Ϊ12�����൱��С����֣�����9���֣�ʵ�ʵĻ�����Լ���ɰ�
					setfont(18, 0, "����");
					setfontbkcolor(EGERGB(198, 42, 0));
					//д���֣�ע�⣺outtextxy��֧��\t \n�����ʽ���õ������ַ��������ַ��ᱻ����
					//Ҫʹ�������ʽ���ַ�����outtextrect
					char str[5];
					sprintf(str, "%d", x);
					outtextxy(x * 50 + 19, y * 50 + 19, str);
				}
				else if ((x == 0 && y >= 1 && y <= m)) {
					//������ɫ
					setcolor(EGERGB(0x0, 0x00, 0x00));
					//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
					//����߶�Ϊ12�����൱��С����֣�����9���֣�ʵ�ʵĻ�����Լ���ɰ�
					setfont(18, 0, "����");
					setfontbkcolor(EGERGB(198, 42, 0));
					//д���֣�ע�⣺outtextxy��֧��\t \n�����ʽ���õ������ַ��������ַ��ᱻ����
					//Ҫʹ�������ʽ���ַ�����outtextrect
					char str[5];
					sprintf(str, "%d", y);
					outtextxy(x * 50 + 19, y * 50 + 19, str);
				}
			}
			else if (a[y][x] == 0) {//�����ߵ�·
				setfillcolor(EGERGB(91, 198, 255));
				bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
			}
			else if (a[y][x] == 2) {//���ǵ�·
				setfillcolor(EGERGB(91, 198, 255));
				bar(x * 50, y * 50, x * 50 + 50, y * 50 + 50);
				setcolor(EGERGB(0x00, 0x00, 0x00));
				setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
				fillellipse(x * 50 + 25, y * 50 + 25, 18, 18);
			}

		}
	}
	int k = 0;
	for (; k != key_esc; ) // key_esc��ege����İ�������
	{
		char str[32];
		//�ȴ��û����������ѵõ��İ�����k
		//����㲻��ȴ��������ڵ���getch֮ǰ��ʹ��kbhit����Ƿ��а�������
		//�� if ( kbhit() ) k = getch();
		k = getch();
		if (k == 'w') {
			walk(1, 1);
		}
		//��ʽ�����Ϊ�ַ��������ں������

	}
	closegraph();

}