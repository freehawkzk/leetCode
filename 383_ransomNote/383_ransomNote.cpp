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
 * Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 *
 * Each letter in the magazine string can only be used once in your ransom note.
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 *
 *
 * 分析
 * ransomNote是由从magazie中选取字母组成的，也就是说ransomNote是magazine的子集。
 *
 * 思路
 * 统计magazine中各个字母出现的次数，再遍历ransomNote，只要满足次数要求，即返回true，否则返回false
 *
 * 备注
 * 从解答看，题中未明确只需要考虑小写字母情况。
*/
/************************************************************************/
bool canConstruct(string ransomNote, string magazine)
{
	int n[1000] = { 0 };
	for (const char x : magazine)
	{
		n[x] += 1;
	}
	for (int i = 0; i < ransomNote.length();i++)
	{
		n[ransomNote[i]]--;
		if (n[ransomNote[i]] < 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string ransonNot = "a";
	string magazine = "b";
	bool c = canConstruct(ransonNot, magazine);
	return 0;
}