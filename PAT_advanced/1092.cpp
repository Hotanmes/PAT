#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>//关于string定义的字符串用cin输入的问题
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	int v[100] = {0};
	int n = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		++v[a[i]];//颜色作为下标，值为该颜色出现的次数
	}
	for (int i = 0; i < b.length(); ++i)
	{
		if (v[b[i]] > 0) --v[b[i]];
		else ++n;//每有一个颜色未出现，n加1
	}
	if (n > 0) printf("No %d\n", n);
	else printf("Yes %d\n", a.length() - b.length());
	return 0;
}
