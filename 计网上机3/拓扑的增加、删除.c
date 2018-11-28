#include<stdio.h>
#include<stdlib.h>

typedef struct {
	DataType list[Max];
	int size;
}List;

//顺序表初始化
void Initialization(List*list) {
	list->size = 0;
}

//求顺序表中的个数
int Length(List list) {
	return list.size;
}

//插入顺序表
int Insert(List*list, int i, DataType a) {         //在顺序表的第i个位置插入a
	int j;
	if (list->size >= Max) {
		printf("顺序表已满 无法操作\n");
		return 0;
	}
	else if (i<0 || i>list->size) {
		printf("数据不合理 请重新输入\n");
		return 0;
	}
	else {
		for (j = list->size; j > i; j--) {
			list->list[j] = list->list[j - 1];
			list->list[i] = a;
			list->size++;
		}
		return 1;
	}
}

//删除顺序表
int Delete(List*list, int i, DataType *a) {        //删除顺序表i位置的数据并存放到地址a中
	int j;
	if (list->size <= 0) {
		printf("顺序表为空 无法操作\n");
		return 0;
	}
	else if (i<0 || i>list->size - 1) {
		printf("数据不合理 请重新输入\n");
		return 0;
	}
	else {
		a = list->list[i];    //将删除的数据保存到地址a
		for (j = i + 1; j <= list->size - 1; j++) {
			list->list[j - 1] = list->list[j];
			list->size--;
		}
		return 1;
	}
}

//取出顺序表中的数据
int Putout(List*list, int i, DataType *a) {           //将顺序表中的第i个数据取出存放在地址a
	if (i<0 || i>list->size - 1) {
		printf("数据不合理 请重新输入\n");
		return 0;
	}
	else {
		a = list->list[i];
		return 1;
	}
}