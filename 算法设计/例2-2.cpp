#include<iostream>
using namespace std;
//����2.2�������������Ķ������洢�ṹ�ĵݹ��ԣ������ǿն�����bt�����н��ֵ֮�͵ĵݹ��㷨�������������data��Ϊint�͡�
typedef struct BNode
{
	int data;
	struct BNode *lchild,*rchild;
} BTNode;		//������������� ,�����ǵݹ��


int Sumbt(BTNode *bt)		//�������bt�����н��ֵ֮��
{
	if (bt->lchild == NULL && bt->rchild == NULL)
		return bt->data;	//ֻ��һ�����ʱ���ظý��ֵ
	else				//���򷵻������������ֵ֮�ͼ��ϸ����ֵ
		return Sumbt(bt->lchild) + Sumbt(bt->rchild) + bt->data;
}

