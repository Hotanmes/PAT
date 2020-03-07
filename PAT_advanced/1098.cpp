#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void downAdjust(vector<int> &b, int low, int high)//注意数组b的形式
{
	int i = 1, j = 2 * i;
	while (j <= high)
	{
		if (j + 1 <= high && b[j] < b[j + 1]) j = j + 1;//左右孩子比较，取大
		if (b[i] >= b[j]) break;
		swap(b[i], b[j]);
		i = j;
		j = 2 * i;
	}
}
int main()
{
	int n,p=2,index;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);//从1开始输入，因此大小取n+1
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	while (p <= n && b[p - 1] <= b[p]) ++p;//勿忘第二个等号
	index = p;
	while (p <= n && a[p] == b[p]) ++p;//用于判别是何种排序
	if (p == n + 1)
	{
		printf("Insertion Sort\n");
		sort(b.begin() + 1, b.begin() + index + 1);//排序的尾部取要排序最后的元素的下一个位置
	}
	else
	{
		printf("Heap Sort\n");
		p = n;
		while (p > 2 && b[p] >= b[1]) --p;//p不能等于2，如p为3，接着循环满足条件，p就变为2；勿忘第二个等号
		swap(b[1], b[p]);
		downAdjust(b, 1, p - 1);//注意传入的参数形式（数组名和下标）
	}
	printf("%d", b[1]);
	for (int i = 2; i <= n; ++i)
	{
		printf(" %d", b[i]);
	}
	return 0;
}
