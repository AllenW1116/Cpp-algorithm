#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#define N 3
using namespace std;
//1. �����鰲�����⡣
//��һ�顾����A����һ�顾������B����A[i]��ʾ��i������Ĳμ�������B[j]��ʾ��j�����������������ɵ�������
//���ҽ���A[i]��B[j]ʱ����j�������ҿ������ھٰ��i�����顣
//��������A������B������������ͬʱ�ٰ���ٸ����顣
//���磬A[] = { 1��2��3 }��B[] = { 3��2��4 }�����Ϊ3��
//��A[] = { 3��4��3��1 }��B[] = { 1��2��2��6 }�����Ϊ2.

//����̰���㷨��̰�Ĳ��ԣ����Ȱ����������ٵĻ��飻����ÿһ�����飬���á�������С���Ļ��������ٰ�����
int A[N];  //һ�����
int B[N];  //һ�������
bool isused[N];
int countt=0; //���Ծٰ�Ļ�����Ŀ


void Assign(int* A, int* B, int count) {
	memset(isused, false, sizeof(isused));
	sort(A, A + N);
	sort(B, B + N);// AB����������
	for (int i = 0; i < N; i++) {
		int j = 0;
		while (j < N) {
			if (B[j] >= A[i] && isused[j] == false) {
				countt++;
				cout << "��" << i + 1 << "�������ڵ�" << j + 1 << "�����Ҿ��У�" << endl;
				isused[j] = true;
				break;
			}
			j++;
		}
	}
}

int main() {
	int A1[] = { 1,2,3 };
	int B1[] = { 3,2,4 };
	Assign(A1, B1, countt);
	cout << countt;
	return 0; //���Գɹ�
}









