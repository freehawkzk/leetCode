#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
using namespace std;
/************************************************************************/
/*
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 * 分析
 * 题目要求保持空格的位置不变，翻转句子中的每一个词。
 * 由翻转可以想到栈，先进后出。
 * 遇到空格之前，遍历字符串并将字符入栈；
 * 遇到空格，就将栈中所有字符出栈，添加到结果字符串中；
 * 对于最后一个词，由于结尾无空格，所以单独处理，将栈中所有字符出栈加入结果字符串末尾即可。
*/
/************************************************************************/
string reverseWords(string s) {
	string sRes;
	stack<char> sStack;
	for (int i = 0; i < s.length(); i++)//遍历字符串
	{
		if (s[i] != ' ')//查找空格，
		{
			sStack.push(s[i]);//非空格，字符入栈
		}
		else//遇到空格
		{
			while (!sStack.empty())//栈中所有字符出栈
			{
				char t = sStack.top();
				sStack.pop();
				sRes.push_back(t);
			}
			sRes.append(" ");//添加空格
		}
	}
	if (!sStack.empty())//处理最后一个词
	{
		while (!sStack.empty())
		{
			char t = sStack.top();
			sStack.pop();
			sRes.push_back(t);
		}
	}
	
	return sRes;
}
int main()
{

	string s = "Let's take LeetCode contest";
	string r = reverseWords(s);
	return 0;
}