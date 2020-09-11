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
 * 分析
 * 判断两个字符串s,t，t是不是由s中的字母乱序组成
 *
 * 注意
 * 本题无法使用异或的方法进行解答，因为未规定t和s的关系，比如s=aa,t=bb，如果使用异或的方法将得出错误的解
 * 本题使用字符统计方法即可。
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