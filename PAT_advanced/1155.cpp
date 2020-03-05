#define _CRT_SECURE_NO_WARNINGS//对scanf免报错的宏定义，必须加在程序最开头（头文件之前）
#include<iostream>
#include<vector>
using namespace std;
int n,a[1010];
vector<int> v;
void dfs(int index)
{
	if (index * 2 + 1 > n&&index * 2 > n)//如总共8个，对第4个还不能输出，仍需遍历
	{
		if (index <= n)//对只有左叶节点的特判（调试查看）
		{
			for (int i = 0; i < v.size(); ++i)
			{
				printf("%d%s", v[i],i == v.size() - 1 ? "\n" : " ");
			}
		}
	}
	else//先右后左，理解递归（调试查看）
	{
		v.push_back(a[index * 2 + 1]);
		dfs(index * 2 + 1);
		v.pop_back();
		v.push_back(a[index * 2]);
		dfs(index * 2);
		v.pop_back();
	}
}
int main()
{
	int i, isMin = 1, isMax = 1;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	v.push_back(a[1]);
	dfs(1);
	for (i = 2; i <= n; ++i)//从第二个节点开始遍历，与父节点做比较
	{
		if (a[i] > a[i / 2])
		{
			isMax = 0;
		}
		if (a[i] < a[i / 2])
		{
			isMin = 0;
		}
	}
	if (isMax)
	{
		printf("Max Heap");//题目要求最后不能有多余空格
	}
	else
	{
		printf("%s", isMin ? "Min Heap" : "Not Heap");
	}
	return 0;
}
