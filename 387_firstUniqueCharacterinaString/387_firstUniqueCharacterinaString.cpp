#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;
/************************************************************************/
/*
 * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 * ����
 * �����ַ����������ַ����е�һ��ֻ������һ�ε��ַ����±�
 *
 * ˼·
 * ͳ�Ƹ��ַ����ֵĴ�������һ�γ���ʱ�����±꣬�ڶ��γ���֮���ų�
 * ������β鿴���ַ����ֵĴ���
*/
/************************************************************************/


int firstUniqChar(string s)
{
	vector<int> v(26, -1);
	for (int i = 0; i < s.length(); i++)
	{
		char x = s[i];
		if (v[x - 'a'] == -1)
			v[x - 'a'] = i;
		else
			v[x - 'a'] = -2;
	}
	for (const char x : s)
	{
		if (v[x - 'a'] >= 0)
			return v[x-'a'];
	}
	return -1;
}
int main()
{
	string s = "loveleetcode";
	int n = firstUniqChar(s);
	return 0;
}