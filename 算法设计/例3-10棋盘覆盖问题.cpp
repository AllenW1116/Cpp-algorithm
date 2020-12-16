#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//��������������һ��2k��2k��k > 0�������̣�ǡ����һ����������������ͬ����֮Ϊ���ⷽ��
//����Ҫ�����µ�L�͹��Ƹ��ǳ������ⷽ���������ȫ�����񣬹��ƿ���������ת�������κ��������Ʋ����ص��������һ�ָ��Ƿ�����
//��������ô���ǵ���Ҫ��һ��ppt chap3 80ҳ
//�ã�tr��tc����ʾһ���������ϽǷ�������꣨�����Ͻǣ�����dr��dc�������ⷽ�����ڵ����꣬size�����̵�������������
//�ö�ά����board��Ÿ��Ƿ�������tileȫ�ֱ�����ʾL�͹��Ƶı�ţ�������1��ʼ����board��3����ͬ��������ʾһ��L�͹��ơ�

#define MAX 1025
//�����ʾ
int k;				//���̴�С
int x, y;				//���ⷽ���λ��
//��������ʾ
int board[MAX][MAX];
int tile = 1;   //���Ʊ�� ��1��ʼ


void ChessBoard(int tr, int tc, int dr, int dc, int size) //tr tc�������Ͻǣ�Դ�㣩 dr dc���ⷽ������
{
	if (size == 1) return;			//�ݹ����
	int t = tile++;			//ȡһ��L�͹ǣ����ƺ�Ϊtile
	int s = size / 2;			//�ָ�����
	//�������Ͻ�����
	if (dr < tr + s && dc < tc + s)		//���ⷽ���ڴ�������
		ChessBoard(tr, tc, dr, dc, s);
	else					//�������������ⷽ��
	{
		board[tr + s - 1][tc + s - 1] = t;		//��t��L�͹��Ƹ������½ǣ����ⷽ���ڵ�һ���ޣ�ȱ�ǿ϶������⣬�ȸ������ϣ�
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
		//�����½���Ϊ���ⷽ�������������ޣ������������ˣ�������Ϊ������޵����ⷽ��
	}
	//�������Ͻ�����
	if (dr < tr + s && dc >= tc + s)
		ChessBoard(tr, tc + s, dr, dc, s);	//���ⷽ���ڴ������� 
	else					//�������������ⷽ��
	{
		board[tr + s - 1][tc + s] = t;		//��t��L�͹��Ƹ������½�
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
		//�����½���Ϊ���ⷽ��������������
	}
	//�������½�����
	if (dr >= tr + s && dc < tc + s)		//���ⷽ���ڴ�������
		ChessBoard(tr + s, tc, dr, dc, s);
	else					//�������������ⷽ��
	{
		board[tr + s][tc + s - 1] = t;  		//��t��L�͹��Ƹ������Ͻ�
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
		//�����Ͻ���Ϊ���ⷽ��������������
	}
	//�������½�����
	if (dr >= tr + s && dc >= tc + s)	//���ⷽ���ڴ�������
		ChessBoard(tr + s, tc + s, dr, dc, s);
	else				//�������������ⷽ��
	{
		board[tr + s][tc + s] = t;  	//��t��L�͹��Ƹ������Ͻ�
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
		//�����Ͻ���Ϊ���ⷽ��������������
	}
}

