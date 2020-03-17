#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m, value;
	vector<int> v(1001);//为什么数组大小取五百多会发生段错误？
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &value);
		++v[value];//下标代表面值（不超过500），值代表该面值出现的次数
	}
	for (int i = 0; i < 1001; ++i)//遍历每个面值
	{
		if (v[i])
		{
			--v[i];//标志对该面值进行处理，处理完再加回来
			if (m - i > 0 && v[m - i])//先遍历到i，可以保证i<=m-i
			{
				printf("%d %d", i, m - i);
				return 0;
			}
			++v[i];
		}
	}
	printf("No Solution");//注意位置
	return 0;
}
