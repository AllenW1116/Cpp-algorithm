#include<iostream>
using namespace std;
//����2.6����һ������ͷ���ĵ�����L�����һ���㷨�ͷ��������н�㡣
//�⣺��L = { a1��a2������an }��f(L)�Ĺ������ͷ�a1��an�����н�㣬��f(L->next)�Ĺ������ͷ�a2��an�����н�㣬
//ǰ���ǡ������⡱�������ǡ�С���⡱��
//����f(L->next)����ʵ�֣���f(L)�Ϳ��Բ����ȵ���f(L->next)��Ȼ���ͷ�L��ָ�������⡣
//f(L) �Բ����κ��¼�		    ��L = NULLʱ
//f(L) �� f(L->next); �ͷ�L���	    �������
typedef int ElemType;

typedef struct LNode {
	ElemType e;
	struct LNode *next;

}LinkNode;//���ݽṹ�����ǵݹ��

void DestroyList(LinkNode *&L)
//�ͷŵ�����L�����н��
{
	if (L != NULL)
	{
		DestroyList(L->next);
		free(L);
	}
}
