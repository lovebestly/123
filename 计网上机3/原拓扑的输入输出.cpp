#define Max 10
#define Maxvertices 10
#define Maxweight 10000
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct {
	DataType list[Max];
	int size;
}List;
int Insert(List*L, int i, DataType a);
int Delete(List*L, int i, DataType a);
int Putout(List*L, int i, DataType a);
void Initialization(List*L);
int Length(List*L);

//�����ڽӾ���Ĵ�������
typedef struct {
	List vertices;//�����Ŷ����˳���
	int edge[Maxvertices][Maxvertices];//�����űߵľ���
	int num;//����ߵ���Ŀ
}Adjaency;

//����ߵĽṹ��
typedef struct {
	int row;//�������±�
	int col;//�������±�
	int weight;//����Ȩֵ
}rowcolweight;

//ͼΪ��
void Initiate(Adjaency*A) {
	int i, j;
	for (i = 0; i < Maxvertices; i++) {
		for (j = 0; j < Maxvertices; j++) {
			if (i == j) {
				A->edge[i][j] = 0;
			}
			else {
				A->edge[i][j] = Maxvertices;
			}
		}
	}
	A->num = 0;
	Initialization(&A->vertices);//�����˳����ʼ��
}

void Insertvertices(Adjaency*A, DataType vertices) {
	if (Insert(&A->vertices, A->vertices.size, vertices) == 0) {
		printf("���붥�� �ռ�����\n");
		exit(1);
	}
}

void Insertedge(Adjaency*A, int n1, int n2, int weight) {
	DataType a;
	if (n1 != n2) {
		if (Putout(&A->vertices, n1, a) == 0 || Putout(&A->vertices, n2, a) == 0) {
			printf("�����ʱ ��������\n");
			exit(1);
		}
		A->edge[n1][n2] = weight;
		A->edge[n2][n1] = weight;
		A->num++;
	}
}

void Deleteedge(Adjaency*A, int n1, int n2) {
	A->edge[n1][n2] = Maxweight;
	A->edge[n2][n1] = Maxweight;
	A->num--;
}

void Deletevertices(Adjaency*A, int b) {
	int m, i, j;
	m = b - 1;
	{
		if (m < 0 || m >= A->vertices.size) {
			printf("·�ɽ�㲻����\n");
			exit(0);
		}
		else {
			for (i = m; i < A->vertices.size; i++) {
				for (j = 0, i = m; j < A->vertices.size; j++) {
					A->edge[j][i] = Maxweight;

				}
			}
			for (i = m; i < A->vertices.size; i++) {
				for (i = m, j = 0; j < A->vertices.size; j++) {
					A->edge[i][j] = Maxweight;
				}
			}
			for (i = m; i < A->vertices.size; i++) {
				A->vertices.list[i] = A->vertices.list[i] - 1;
			}
			A->vertices.size--;
			printf("ɾ�����ɹ�\n");
		}
	}
}
	
int GetFirstvertices(Adjaency*A, int m){
	int col;
	DataType a;
	m = m - 1;
	if (Putout(&A->vertices, m, a) == 0){
		printf("ȡ��һ���ڽӶ���ʱ �������\n");
		exit(1);
	}
	for (col = 0; col < A->vertices.size; col++) {
		if (A->edge[m][col] > 0 && A->edge[m][col] < Maxweight) {
			return col;
		}
	}
	return -1;
}

int GetNextvertices(Adjaency*A, int n1, int n2) {
	int col;
	DataType a;
	if ((Putout(&A->vertices, n1, a) == 0) || (Putout(&A->vertices, n2, a) == 0)) {
		printf("ȡ��һ�ڽӶ��� ���ݳ���\n");
		exit(1);
	}
	if (A->edge[n1][n2] == 0){
		printf("v2����v1���ڽӶ���\n");
		exit(1);
	}
	for (col = n2 + 1; col < A->vertices.size; col++) {
		if (A->edge[n1][col] > 0 && A->edge[n1][col] < Maxweight){
			return col;
	    }
    }
	return -1;
}

	void CreatGraph(Adjaency*A, DataType v[], int n, rowcolweight w[], int e)
	{
		int i, k;
		Initiate(A);
		for (i = 0; i < n; i++)
		{
			Insertvertices(A, v[i]);
		}
		for (k = 0; k < e; k++)
			Insertedge(A, w[k].row, w[k].col, w[k].weight);
	}