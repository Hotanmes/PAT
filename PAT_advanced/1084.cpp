#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
	string s1, s2, ans;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); ++i)
	{
		if (s2.find(s1[i]) == string::npos&&ans.find(toupper(s1[i])) == string::npos)//string的find函数
			ans += toupper(s1[i]);
	}
	cout << ans;
	return 0;
}
