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
 * ����
 * Ҫ�󣬴�ֻ���ڵ�һ���ַ���������д��Сд�����䣬�����κ�λ�÷������䣬�����Ǵ�С��Сд����Сд����д���ǲ��ϸ�Ĵʡ�
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

	//if (bFirstCap)//��һ���ַ���д
	//{
	//	bool bCap = false;
	//	if (word[1] >='a')//�ڶ����ַ�֮��������ַ���Сд״̬��ڶ����ַ���ͬ
	//		bCap = true;
	//	for (int i = 2; i < word.length(); i++)//�ӵ������ַ���ʼ����
	//	{
	//		if (bCap)//�ڶ����ַ��Ǵ�д
	//		{
	//			if (word[i] < 'a')//�������Сд�ַ����򷵻�false
	//				return false;
	//		}
	//		else
	//		{
	//			if (word[i] >='a')//�ڶ����ַ���Сд�ַ���������ִ�д�ַ��򷵻�false
	//				return false;
	//		}
	//	}
	//	return true;
	//}
	//else//��һ���ַ�Сд���Ժ����е��ַ�������Сд
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