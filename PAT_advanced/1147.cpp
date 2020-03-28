#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> v;
void postorder(int index)
{
	if (index > n)//注意不能等于，因为index从1开始取
		return;
	postorder(2 * index);
	postorder(2 * index + 1);
	printf("%d%s", v[index], index == 1 ? "\n" : " ");//判断的为index是否等于1，即根节点
}
int main()
{
	int m;
	scanf("%d%d", &m, &n);
	v.resize(n + 1);//注意v的大小为n+1
	for (int i = 0; i < m; ++i)
	{
		int isMin = 1, isMax = 1;//注意应放在循环内
		for (int j = 1; j <= n; ++j)//v下标从0到n,所以大小为n+1
		{
			scanf("%d", &v[j]);
		}
		for (int j = 2; j <= n; ++j)
		{
			if (v[j] > v[j / 2])
			{
				isMax = 0;
			}
			if (v[j] < v[j / 2])
			{
				isMin = 0;
			}
		}
		if (isMax)
		{
			printf("Max Heap\n");//勿忘换行
		}
		else
		{
			printf("%s\n", isMin ? "Min Heap" : "Not Heap");
		}
		postorder(1);//传入的为1
	}
	return 0;
}
