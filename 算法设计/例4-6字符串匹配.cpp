#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//�����㷨��s��ԭ����t���Ӵ�
int BF(string s, string t)	//�ַ���ƥ��
{
	int i = 0, j = 0;
	while (i < s.length() && j < t.length())
	{
		if (s[i] == t[j])		//�Ƚϵ������ַ���ͬʱ
		{
			i++;
			j++;
		}
		else			//�Ƚϵ������ַ�����ͬʱ
		{
			i = i - j + 1;		//i���ˣ�i-j���ǻص��˱���ƥ��Ŀ�ʼ�ַ����´�ƥ��Ӧ�ô�������һ���ַ���ʼ��
			j = 0;			//j��0��ʼ
		}
	}
	if (j == t.length())		//t���ַ��Ƚ����
		return i - j;		//t��s���Ӵ�,����λ��
	else				//t����s���Ӵ�
		return -1;		//����-1
}
