#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> a(100001);//注意数组大小，否则会产生段错误
	vector<int> b(100001);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		++b[a[i]];//下标代表赌注数字，值为该数字出现的次数
	}
	for (int i = 0; i < n; ++i)
	{
		if (b[a[i]]==1)//只有出现一次才可以
		{
			printf("%d", a[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}
