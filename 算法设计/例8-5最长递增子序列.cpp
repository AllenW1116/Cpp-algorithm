#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
����������������һ���������������a[0..n - 1]������������������еĳ��ȡ�
���磬a[] = { 2��1��5��3��6��4��8��9��7 }��n = 9���������������Ϊ{ 1��3��4��8��9 }�����Ϊ5��
��������⡿��ƶ�̬�滮����Ϊһά����dp��dp[i]��ʾa[0..i]����a[i]��β������������еĳ��ȡ�

//�����ʾ
int a[] = { 2,1,5,3,6,4,8,9,7 };
int n = sizeof(a) / sizeof(a[0]);
//�������ʾ
int ans = 0;
int dp[MAX];
void solve(int a[],int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i],dp[j] + 1); //��i��j��ߣ��Ǿ���dp[i]����i��j�ұߣ��Ǿ���dp[j]+1
        }
    }
    ans = dp[0];
    for (i = 1; i < n; i++)  //�𰸾���dp�����е����ֵ
        ans = max(ans,dp[i]);
}
