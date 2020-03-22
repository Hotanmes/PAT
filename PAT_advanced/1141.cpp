#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;
struct node
{
	string school;
	int tws;
	int ns;
};
bool cmp(node a, node b)
{
	if (a.tws != b.tws)
		return a.tws > b.tws;
	else if (a.ns != b.ns)
		return a.ns < b.ns;
	else
		return a.school < b.school;
}
int main()
{
	int n;
	scanf("%d", &n);
	string id;
	double score;//在计算过程中要用浮点型，最后结果转为int
	string school;
	unordered_map<string, int> cnt;
	unordered_map<string, double> sum;//与上对应
	for (int i = 0; i < n; ++i)
	{
		cin >> id >> score >> school;
		for (int j = 0; j < school.length(); ++j)
		{
			school[j] = tolower(school[j]);
		}
		if (id[0] == 'B')
			score /= 1.5;
		else if (id[0] == 'T')
			score *= 1.5;
		++cnt[school];
		sum[school] += score;
	}
	vector<node> ans;
	for (auto it = cnt.begin(); it != cnt.end(); ++it)
	{
		ans.push_back(node{ it->first,(int)sum[it->first],it->second });//形式
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	int rank = 0;
	int pres = -1;//前一个学校的加权总分
	for (int i = 0; i < ans.size(); ++i)
	{
		if (pres != ans[i].tws)
			rank = i + 1;
		pres = ans[i].tws;
		printf("%d %s %d %d\n", rank, ans[i].school.c_str(), ans[i].tws, ans[i].ns);
	}
	return 0;
}
