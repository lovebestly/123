#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;


void dijkstra(int v0);
int main()
{
	int n = 0;
	while (1) {
		printf ("\t*********** MENU ************" );
		printf ( "\t欢迎使用路由表生成程序，请输入您的指令:");
		printf ( "\t1  生成路由表并打印        \n" );
		printf("\t2  删除节点         ");
		printf("\t3  删除边        ");
		printf("\t4  增加节点     ");
		printf("\t5  增加边    ");
		printf("     请输入您的指令: ");
		scanf_s("&d", n);
		if (n < 1 || n>5)   n = 6;
		switch (n) {
		case 1:;           break;
		case 2:;     break;
		case 3:;             break;
		case 4:;            break;
		case 5:;             break;
		case 6:; ;
		default: printf("输入指令有误，已为您返回上一级"); break;
		}

	}
	return 0;
}
