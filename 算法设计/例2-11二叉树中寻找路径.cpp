#include<iostream>
#include<vector>
using namespace std;
//����2.11��������������ö������洢�ṹ�����һ���ݹ��㷨����Ӹ���㵽ֵΪx�Ľ���·������������������н��ֵ��ͬ��

//��vector<int>����path��ŴӸ���㵽x��������·����
//f(b��x��path)���������ǣ�
//��bΪ����������false��
//����b���ֵ���뵽path�У����b->data = x�����ҳɹ�����true��
//���b->data��x�����������в��ң������������ҵ�ֵΪx�Ľ�㣬����true������������û���ҵ�ֵΪx�Ľ�㣬�������������еĲ��ҽ����
//���������в��Ҷ��ǡ�С���⡱��
typedef struct BNode
{
	int data;
	struct BNode *lchild, *rchild;
} BTNode;		//������������� ,�����ǵݹ��

bool Findxpath2(BTNode *bt, int x, vector<int> tmppath,vector<int> &path) 		//�����㵽x���ģ�����·��;path��Ϊȫ�ֱ�����Ž�
{
	if (bt == NULL)			//��������false
		return false;
	tmppath.push_back(bt->data);	//��ǰ������path
	if (bt->data == x)			//��ǰ���ֵΪx������true
	{
		path = tmppath;			//·������
		return true;
	}
	bool find = Findxpath2(bt->lchild, x, tmppath, path); //���������в���
	if (find)				//�������гɹ��ҵ�
		return true;
	else				//��������û���ҵ������������в���
		return Findxpath2(bt->rchild, x, tmppath, path);
}

