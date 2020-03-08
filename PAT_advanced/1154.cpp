#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct node
{
	int v1;
	int v2;
};//边上两个顶点的序号
int main()
{
	int n, m, k;
	scanf("%d%d", &n, &m);
	vector<node> v(m);//存放边
	for (int i = 0; i < m; ++i) scanf("%d%d", &v[i].v1, &v[i].v2);
	cin >> k;
	while (k--)
	{
		set<int> cl;//记录有几种颜色
		bool flag = true;
		int a[10010];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			cl.insert(a[i]);
		}
		for (int i = 0; i < m; ++i)//枚举每条边
		{
			if (a[v[i].v1] == a[v[i].v2])//数组a下标为顶点序号，值为颜色
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			printf("%d-coloring\n", cl.size());
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
