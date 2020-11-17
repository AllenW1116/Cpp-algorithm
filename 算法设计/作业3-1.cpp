#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#define N 3
using namespace std;
//1. 求解会议安排问题。
//有一组【会议A】和一组【会议室B】，A[i]表示第i个会议的参加人数，B[j]表示第j个会议室最多可以容纳的人数。
//当且仅当A[i]≤B[j]时，第j个会议室可以用于举办第i个会议。
//给定数组A和数组B，试问最多可以同时举办多少个会议。
//例如，A[] = { 1，2，3 }，B[] = { 3，2，4 }，结果为3；
//若A[] = { 3，4，3，1 }，B[] = { 1，2，2，6 }，结果为2.

//采用贪心算法。贪心策略：优先安排人数较少的会议；对于每一个会议，采用【尽可能小】的会议室来举办它。
int A[N];  //一组会议
int B[N];  //一组会议室
bool isused[N];
int countt=0; //可以举办的会议数目


void Assign(int* A, int* B, int count) {
	memset(isused, false, sizeof(isused));
	sort(A, A + N);
	sort(B, B + N);// AB均递增排列
	for (int i = 0; i < N; i++) {
		int j = 0;
		while (j < N) {
			if (B[j] >= A[i] && isused[j] == false) {
				countt++;
				cout << "第" << i + 1 << "个会议在第" << j + 1 << "会议室举行！" << endl;
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
	return 0; //测试成功
}









