#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m, a, b, k, nv, vx;
	scanf("%d%d", &n, &m);
	vector<int> v[n];//定义n个一维数组，第几个（0~n-1）一维数组就是第几个顶点
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(i);//表示某个顶点属于哪几条边
		v[b].push_back(i);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &nv);
		vector<int> hash(m);//大小为m，下标为边的序号
		int flag = 1;
		for (int j = 0; j < nv; ++j)
		{
			scanf("%d", &vx);
			for (int t = 0; t < v[vx].size(); ++t)//v[vx].size()表示包含vx号顶点的边数有几条
			{
				hash[v[vx][t]] = 1;//v[vx][t]表示包含vx号顶点的边的序号，把这条边在hash数组中标识为1
			}
		}
		for (int j = 0; j < m; ++j)
		{
			if (0 == hash[j])//只要有一条边的两个顶点都不属于集合，就输出No
			{
				printf("No\n");
				flag = 0;
				break;
			}
		}
		if (1 == flag)
		{
			printf("Yes\n");
		}
	}
	return 0;
}
