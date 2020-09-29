#include<iostream>
using namespace std;
//【例2.5】用递归法求一个整数数组a的最大元素。
//解：设f(a，i)求解数组a中前i个元素即a[0..i - 1]中的最大元素，则f(a，i - 1)求解数组a中前i - 1个元素即a[0..i - 2]中的最大元素，
//前者为“大问题”，后者为“小问题”。
//假设f(a，i - 1)已求出，则有f(a，i) = MAX{ f(a，i - 1)，a[i - 1] }。
//递推方向是朝a中元素减少的方向推进，当a中只有一个元素时，该元素就是最大元素，所以f(a，1) = a[0]。
//f(a，i) = a[0]					当i = 1时
//f(a，i) = MAX{ f(a，i - 1)，a[i - 1] }		当i > 1时


int fmax(int a[],int i)
{
	if (i == 1)
		return a[0];
	else
		return(fmax(a,i - 1)>a[i - 1])? fmax(a, i - 1): a[i - 1];
}



//int main() {
//	int A[] = { 10,2,3,4,5,8 };
//
//	cout << fmax(A,6);
//	return 0;
//
//}
