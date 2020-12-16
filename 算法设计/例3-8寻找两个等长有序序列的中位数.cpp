#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//例如，若序列a = (11，13，15，17，19)，其中位数是15，
//若b = (2，4，6，8，20)，其中位数为6。
//两个等长有序序列的中位数是含它们所有元素的有序序列的中位数，例如a、b两个有序序列的中位数为11。
//合并后c = (2，4，6，8，11，12，15，17，19，20)
//采用二分法求含有n个有序元素的序列a、b的中位数的过程如下：
//若n = 1，较小者为中位数。
//其他又分为3种情况
//分别求出a、b的中位数a[m1]和b[m2]：
//① 若a[m1] = b[m2]，则a[m1]或b[m2]即为所求中位数，算法结束
//② 若a[m1] < b[m2]，则舍弃序列a中前半部分（较小的一半），同时舍弃序列b中后半部分（较大的一半）要求舍弃的长度相等。
//	1，3，4，6，9 and 2，3，5，8，10 => 4，6，9 and 2，3，5
//③ 若a[m1] > b[m2]，则舍弃序列a中后半部分（较大的一半），同时舍弃序列b中前半部分（较小的一半），要求舍弃的长度相等。舍弃一半即n / 2个元素。

void prepart(int &s, int &t) { //a[s..t]prepart
	s = s;
	t = (t-s)/2+s;
}
void postpart(int &s, int &t) { //a[s..t]postpart
	s = t-((t-s) / 2);
	t = t;
}

int midnum(int a[],int s1,int t1,int b[],int s2,int t2)
{  //求两个有序序列a[s1..t1]和b[s2..t2]的中位数
	int m1,m2;
	if (s1 == t1 && s2 == t2)     //两序列只有一个元素时返回较小者
		return a[s1] < b[s2] ? a[s1] : b[s2];
	else
	{
		m1 = (s1 + t1) / 2;		//求a的中位数
		m2 = (s2 + t2) / 2;		//求b的中位数
		if (a[m1] == b[m2])	//两中位数相等时返回该中位数
			return a[m1];
		if (a[m1] < b[m2])	//当a[m1]<b[m2]时
		{
			postpart(s1,t1);	//a取后半部分
			prepart(s2,t2);	//b取前半部分
			return midnum(a,s1,t1,b,s2,t2);
		}
		else			//当a[m1]>b[m2]时
		{
			prepart(s1,t1);	//a取前半部分
			postpart(s2,t2);	//b取后半部分
			return midnum(a,s1,t1,b,s2,t2);
		}
	}
}
//int main() {
//	int A[] = { 1,3,4,6,9 };
//	int B[] = { 2,3,5,8,10 };
//	cout<<midnum(A, 0, 4, B, 0, 4);
//
//	return 0;
//}


