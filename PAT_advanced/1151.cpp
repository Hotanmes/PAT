#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> in, pre;
unordered_map<int, int> mi;
void lca(int inl, int inr, int preroot, int u, int v)//前三个参数意义分别为中序遍历序列最左端结点下标、最右端结点下标、先序遍历序列根节点下标
{         
	if (inl > inr)
		return;
	int inroot = mi[pre[preroot]], inu = mi[u], inv = mi[v];//inroot代表根节点在中序遍历序列中的下标
	if (inu < inroot&&inv < inroot)//两结点都在根节点的左子树
		lca(inl, inroot - 1, preroot + 1, u, v);
	else if (inu > inroot&&inv > inroot)
		lca(inroot + 1, inr, preroot + inroot - inl + 1, u, v);//inroot-inl+1代表左子树结点的数量
	else if ((inu<inroot&&inv>inroot) || (inu > inroot&&inv < inroot))
		printf("LCA of %d and %d is %d.\n", u, v, in[inroot]);
	else if (inu == inroot)
		printf("%d is an ancestor of %d.\n", u, v);
	else if (inv == inroot)
		printf("%d is an ancestor of %d.\n", v, u);
}
int main()
{
	int m, n, u, v;
	cin >> m >> n;
	in.resize(n + 1), pre.resize(n + 1);//令中序、后序遍历序列下标都从1开始
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &in[i]);
		mi[in[i]] = i;//令中序遍历的结点值与其序列下标（从1开始，与结点不存在相区分，不存在为0）相对应
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &u, &v);
		if (mi[u] == 0 && mi[v] == 0)//u、v两结点在中序遍历序列中都不存在
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if (mi[u] == 0 || mi[v] == 0)
			printf("ERROR: %d is not found.\n", mi[u] == 0 ? u : v);
		else//两者都存在
			lca(1, n, 1, u, v);
	}
	return 0;
}
