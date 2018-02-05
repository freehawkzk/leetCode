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
 * Given a word, you need to judge whether the usage of capitals in it is right or not.
 * 
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one letter, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * Example 1:
 * 
 * Input: "USA"
 * Output: True
 * 
 * Example 2:
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
 * 
 * 分析
 * 要求，词只能在第一个字符处发生大写到小写的跳变，其余任何位置发生跳变，无论是大小到小写还是小写到大写都是不合格的词。
*/
/************************************************************************/
bool detectCapitalUse(string word)
{
	//if (word.length() <= 1)
	//{
	//	return true;
	//}


	//bool bFirstCap = false;
	//if (word[0] >='A' && word[0] <= 'Z')
	//	bFirstCap = true;

	//if (bFirstCap)//第一个字符大写
	//{
	//	bool bCap = false;
	//	if (word[1] >='a')//第二个字符之后的所有字符大小写状态与第二个字符相同
	//		bCap = true;
	//	for (int i = 2; i < word.length(); i++)//从第三个字符开始遍历
	//	{
	//		if (bCap)//第二个字符是大写
	//		{
	//			if (word[i] < 'a')//如果出现小写字符，则返回false
	//				return false;
	//		}
	//		else
	//		{
	//			if (word[i] >='a')//第二个字符是小写字符，如果出现大写字符则返回false
	//				return false;
	//		}
	//	}
	//	return true;
	//}
	//else//第一个字符小写，以后所有的字符都必须小写
	//{
	//	for (int i = 1; i < word.length(); i++)
	//		if (word[i] >= 'a' )
	//			return false;
	//	return true;
	//}

	for (int i = 1; i < word.length(); i++)
	{
		if (isupper(word[i]) && islower(word[i - 1]))
			return false;
		if (islower(word[i]) && isupper(word[i - 1]) && i != 1)
			return false;
	}
	return true;
}

int main()
{
	bool b = detectCapitalUse("USA");
	return 0;
}