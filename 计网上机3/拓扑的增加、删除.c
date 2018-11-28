#include<stdio.h>
#include<stdlib.h>

typedef struct {
	DataType list[Max];
	int size;
}List;

//˳����ʼ��
void Initialization(List*list) {
	list->size = 0;
}

//��˳����еĸ���
int Length(List list) {
	return list.size;
}

//����˳���
int Insert(List*list, int i, DataType a) {         //��˳���ĵ�i��λ�ò���a
	int j;
	if (list->size >= Max) {
		printf("˳������� �޷�����\n");
		return 0;
	}
	else if (i<0 || i>list->size) {
		printf("���ݲ����� ����������\n");
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

//ɾ��˳���
int Delete(List*list, int i, DataType *a) {        //ɾ��˳���iλ�õ����ݲ���ŵ���ַa��
	int j;
	if (list->size <= 0) {
		printf("˳���Ϊ�� �޷�����\n");
		return 0;
	}
	else if (i<0 || i>list->size - 1) {
		printf("���ݲ����� ����������\n");
		return 0;
	}
	else {
		a = list->list[i];    //��ɾ�������ݱ��浽��ַa
		for (j = i + 1; j <= list->size - 1; j++) {
			list->list[j - 1] = list->list[j];
			list->size--;
		}
		return 1;
	}
}

//ȡ��˳����е�����
int Putout(List*list, int i, DataType *a) {           //��˳����еĵ�i������ȡ������ڵ�ַa
	if (i<0 || i>list->size - 1) {
		printf("���ݲ����� ����������\n");
		return 0;
	}
	else {
		a = list->list[i];
		return 1;
	}
}