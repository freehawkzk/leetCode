#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
using namespace std;
/************************************************************************/
/*
 * Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
 * 
 * A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
 * 
 * The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
 * 
 * Example 1:
 * 
 * Input: "aba", "cdc"
 * Output: 3
 * Explanation: The longest uncommon subsequence is "aba" (or "cdc"),
 * because "aba" is a subsequence of "aba",
 * but not a subsequence of any other strings in the group of two strings.
 * 
 * Note:
 * 
 * Both strings' lengths will not exceed 100.
 * Only letters from a ~ z will appear in input strings.
 * 
 * 分析
 * 从两个字符串中，查找最长的不寻常子串；
 * 最长不寻常子串的定义：
 * 1、是其中一个串的子串；
 * 2、不是另一个串的子串；
 * 3、如果存在这样的子串，则返回子串长度，否则返回-1.
 *
 * 思路
 * 由于字符串本身是自己的子串，所以串的最长子串就是它自己。
 * 1、两个字符串不一样时，最长不一般子串就是它们中的长串；
 * 2、两个字符串相同时，没有最长不一般子串；
 * 3、返回最长不一般子串的长度。
 *
 * 备注
 * WTF FCUK THIS PROBLEM!
*/
/************************************************************************/
int findLUSlength(string a, string b) 
{
	return a == b ? -1 : max(a.length(), b.length());
}

int main()
{
	int c = findLUSlength("aaa", "abcc");
	return 0;
}