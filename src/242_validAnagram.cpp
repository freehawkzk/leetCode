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
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 * 
 * ����
 * �ж������ַ���s,t��t�ǲ�����s�е���ĸ�������
 *
 * ע��
 * �����޷�ʹ�����ķ������н����Ϊδ�涨t��s�Ĺ�ϵ������s=aa,t=bb�����ʹ�����ķ������ó�����Ľ�
 * ����ʹ���ַ�ͳ�Ʒ������ɡ�
*/
/************************************************************************/


bool isAnagram(string s, string t)
{
	if (s.length() != t.length())
		return false;
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != t[i])
			return false;
	}
	return true;
}
int main()
{

	return 0;
}