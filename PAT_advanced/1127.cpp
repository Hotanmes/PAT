#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, root, tree[35][2];//tree二维数组行代表某结点在后序遍历序列中的下标，此行第一列的值代表该结点左孩子在后序遍历序列中的下标，第二列同理
vector<int> in, post, result[35];//result[i]保存第i层所有结点的序列;35是因为要求输入的结点数小于等于30，如果每个结点一层，则有三十层
struct node//结点信息
{
	int index;//结点在后序遍历序列中的下标
	int depth;//结点所处层次
};
void dfs(int &index, int inl, int inr, int postl, int postr)//注意引用传参
{
	if (inl > inr)
		return;
	index = postr;//根结点在后序遍历序列中的下标赋给index
	int i = 1;
	while (in[i] != post[index])//找到根结点在中序遍历序列中的下标
		++i;
	dfs(tree[index][0], inl, i - 1, postl, postl + i - inl - 1);//遍历左子树，i-inl为左子树结点的数量，postl + i - inl - 1为左子树最后一个值在后序遍历序列中的下标
	dfs(tree[index][1], i + 1, inr, postl + i - inl, postr-1);//遍历右子树
}
void bfs()
{
	queue<node> q;
	q.push(node{ root,0 });//先把根结点入队（根据后序遍历序列）
	while (!q.empty())
	{
		node temp = q.front();//temp保存队头结点
		q.pop();
		result[temp.depth].push_back(post[temp.index]);//队头结点信息存入result数组
		if (tree[temp.index][0] != 0)//队头结点左孩子不空
			q.push(node{ tree[temp.index][0],temp.depth + 1 });//左孩子入队
		if (tree[temp.index][1] != 0)//队头结点右孩子不空
			q.push(node{ tree[temp.index][1],temp.depth + 1 });//右孩子入队
	}
}
int main()
{
	cin >> n;
	in.resize(n + 1);
	post.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> in[i];
	for (int i = 1; i <= n; ++i)
		cin >> post[i];
	dfs(root, 1, n, 1, n);//根据中序和后序遍历序列建树，保存在tree二维数组中;root恒为该树根结点在后序遍历序列中的下标
	bfs();//层序遍历，保存在result二维数组中
	printf("%d", result[0][0]);//根结点
	for (int i = 1; i < 35; ++i)//从第一层到最后一层遍历（从第0层开始）
	{
		if (i % 2 == 1)//奇数层从左到右遍历
		{
			for (int j = 0; j < result[i].size(); ++j)//result[i].size为第i层结点的数量
				printf(" %d", result[i][j]);//题目要求最后没有多余空格
		}
		else//偶数层从右到左遍历
		{
			for (int j = result[i].size() - 1; j >= 0; --j)
				printf(" %d", result[i][j]);
		}
	}
	return 0;
}
