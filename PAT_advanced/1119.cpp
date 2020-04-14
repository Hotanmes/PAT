#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector<int> pre, in, post;
bool unique = true;//判别树是否唯一
void getIn(int prel, int prer, int postl, int postr)
{
	if (prel == prer)//树只有一个结点
	{
		in.push_back(pre[prel]);
		return;
	}
	if (pre[prel] == post[postr])//先序遍历第一个结点与后序遍历序列最后一个结点相等（根结点）
	{
		int i = prel + 1;//i保存为先序遍历序列中根结点的下一个结点（即左子树根结点）的坐标
		while (i <= prer && pre[i] != post[postr - 1])//以后序的根结点的前面一个结点作为参考，寻找这个结点在先序的位置，就可以根据这个位置来划分左右孩⼦，递归处理
			++i;
		if (i == prel + 1)//此结点只有左孩子或右孩子，则中序遍历序列不唯一
			unique = false;
		getIn(prel + 1, i - 1, postl, postl + (i - prel - 1) - 1);//i-prel-1为左子树结点个数
		in.push_back(post[postr]);//因为题目只需要输出一个方案，可以假定这个不可确定的孩子的状态是右孩⼦
		getIn(i, prer, postl + i - prel - 1, postr - 1);
	}
}
int main()
{
	int n;
	cin >> n;
	pre.resize(n), post.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &pre[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &post[i]);
	getIn(0, n - 1, 0, n - 1);//根据先序和后序遍历序列得到中序遍历序列
	printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
	for (int i = 1; i < in.size(); ++i)
		printf(" %d", in[i]);//题目要求最后不能有多余空格
	printf("\n");
	return 0;
}
