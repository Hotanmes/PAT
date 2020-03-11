#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i*i <= n; ++i)//理解（见算法笔记）
	{
		if (n%i == 0) return false;
	}
	return true;
}
int main()
{
	int tsize, n, m;
	scanf("%d%d%d", &tsize, &n, &m);
	while (!isPrime(tsize)) ++tsize;
	vector<int> v(tsize);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		int flag = 0;
		for (int j = 0; j < tsize; ++j)
		{
			int pos = (a + j * j) % tsize;//平方探测法
			if (v[pos] == 0)
			{
				v[pos] = a;
				flag = 1;
				break;
			}
		}
		if (!flag) printf("%d cannot be inserted.\n",a);
	}
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		int b;
		scanf("%d", &b);
		for (int j = 0; j <= tsize; ++j)//为什么=？，每次查找退出此次循环之前的j就是该数字的查找长度
		{
			++ans;//累计搜寻次数
			int pos = (b + j * j) % tsize;
			if (b == v[pos] || 0 == v[pos]) break;//为0表示不存在此数字，也退出循环
		}
	}
	printf("%.1lf\n", ans*1.0 / m);//精确到小数点后一位
	return 0;
}
