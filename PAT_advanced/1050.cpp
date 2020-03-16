#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);//关于getline函数的使用
	getline(cin, s2);
	bool flag[256] = { false };//下标代表有多少种不同的字符
	for (int i = 0; i < s2.length(); ++i)
	{
		flag[s2[i]] = true;
	}
	for (int i = 0; i < s1.length(); ++i)
	{
		if (!flag[s1[i]]) printf("%c", s1[i]);
	}
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<string.h>
//using namespace std;
//int main()
//{
//	char s1[110],s2[110];
//	cin.getline(s1, 110);
//	cin.getline(s2, 110);
//	bool flag[256] = { false };
//	int len1 = strlen(s1),len2=strlen(s2);
//	for (int i = 0; i < len2; ++i)
//	{
//		flag[s2[i]] = true;
//	}
//	for (int i = 0; i < len1; ++i)
//	{
//		if (!flag[s1[i]]) printf("%c", s1[i]);
//	}
//	return 0;
//}
