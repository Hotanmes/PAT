#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
struct node
{
	string id;
	int gp, gm, gf, g;
};
bool cmp(node a, node b)
{
	return a.g != b.g ? a.g > b.g:a.id < b.id;
}
int main()
{
	int p, m, n, score, cnt = 0;
	string s;
	cin >> p >> m >> n;
	vector<node> v, ans;//v当中介，ans储存结果
	unordered_map<string, int> mv;//map记录id与对应的v数组中的下标加1（加1是为了与不存在相区分，0代表不存在）
	for (int i = 0; i < p; ++i)
	{
		cin >> s >> score;
		if (score >= 200)
		{
			v.push_back(node{ s,score,-1,-1,0 });//题目要求输出规范分数不存在就输出-1，因此初始化就为-1
			mv[s] = ++cnt;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> score;
		if (mv[s] != 0)
			v[mv[s] - 1].gm = score;//记得mv[s]-1
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> score;
		if (mv[s] != 0)
		{
			int temp = mv[s] - 1;
			v[temp].gf = v[temp].g = score;
			if (v[temp].gm > v[temp].gf)
				v[temp].g = int(v[temp].gm*0.4 + v[temp].gf*0.6+0.5);
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].g >= 60)
			ans.push_back(v[i]);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
	}
	return 0;
}
