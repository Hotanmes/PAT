#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;
struct node
{
	string card;
	int score;
};
bool cmp(const node &a, const node &b)//与sort的应用
{
	return a.score != b.score ? a.score>b.score : a.card<b.card;//>为从大到小,<为从小到大
}
int main()
{
	int n, m, type;
	string term;
	cin >> n >> m;
	vector<node> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].card >> v[i].score;
	}
	for (int i = 1; i <= m; ++i)//从1开始，为了case%d方便输出
	{
		vector<node> ans;
		int num = 0, tscore = 0;
		cin >> type >> term;
		printf("Case %d: %d %s\n", i, type, term.c_str());//string的c_str的应用
		if (1 == type)
		{
			for (int j = 0; j < n; ++j)
			{
				if (term[0] == v[j].card[0])
				{
					ans.push_back(v[j]);
				}
			}
		}
		else if (2 == type)
		{
			for (int j = 0; j < n; ++j)
			{
				if (term == v[j].card.substr(1, 3))//string的substr的应用
				{
					++num;
					tscore += v[j].score;
				}
			}
			if(num!=0)
			{
				printf("%d %d\n", num, tscore);
			}
		}
		else if (3 == type)
		{
			unordered_map<string, int> m;//map的应用
			for (int j = 0; j < n; ++j)
			{
				if (term == v[j].card.substr(4, 6))
				{
					m[v[j].card.substr(1, 3)]++;
				}
			}
			for (auto it : m)//基于范围的for循环
			{
				ans.push_back({ it.first,it.second });//键值对压入到vector数组
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		for (int j = 0; j < ans.size(); ++j)
		{
			printf("%s %d\n", ans[j].card.c_str(), ans[j].score);
		}
		if ((1 == type || 3 == type) && ans.size() == 0 || (2 == type && num == 0))
		{
			printf("NA\n");
		}
	}
	return 0;
}
