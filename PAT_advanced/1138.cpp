#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector<int> pre,in;
bool flag = false;
void postorder(int prel, int inl, int inr)//参数意义分别为先序遍历序列中根结点下标、中序遍历序列中最左端结点下标和最右端结点下标
{
	if (inl > inr || flag == true)
		return;
	int i = inl;
	while (in[i] != pre[prel])//找出根结点在中序遍历序列中的下标
		++i;
	postorder(prel + 1, inl, i - 1);//遍历左子树
	postorder(prel + i - inl + 1, i + 1, inr);//遍历右子树，i-inl+1代表左子树结点个数
	if (flag == false)
	{
		printf("%d\n", in[i]);//最后的i代表后序遍历序列首结点在中序遍历序列中的下标
		flag = true;
	}
}
int main()
{
	int n;
	cin >> n;
	pre.resize(n);
	in.resize(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &in[i]);
	}
	postorder(0, 0, n - 1);
	return 0;
}
