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
 * ����
 * ransomNote���ɴ�magazie��ѡȡ��ĸ��ɵģ�Ҳ����˵ransomNote��magazine���Ӽ���
 *
 * ˼·
 * ͳ��magazine�и�����ĸ���ֵĴ������ٱ���ransomNote��ֻҪ�������Ҫ�󣬼�����true�����򷵻�false
 *
 * ��ע
 * �ӽ�𿴣�����δ��ȷֻ��Ҫ����Сд��ĸ�����
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