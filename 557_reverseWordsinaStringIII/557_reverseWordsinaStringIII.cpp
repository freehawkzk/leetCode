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
 * ����
 * ��ĿҪ�󱣳ֿո��λ�ò��䣬��ת�����е�ÿһ���ʡ�
 * �ɷ�ת�����뵽ջ���Ƚ������
 * �����ո�֮ǰ�������ַ��������ַ���ջ��
 * �����ո񣬾ͽ�ջ�������ַ���ջ����ӵ�����ַ����У�
 * �������һ���ʣ����ڽ�β�޿ո����Ե���������ջ�������ַ���ջ�������ַ���ĩβ���ɡ�
*/
/************************************************************************/
string reverseWords(string s) {
	string sRes;
	stack<char> sStack;
	for (int i = 0; i < s.length(); i++)//�����ַ���
	{
		if (s[i] != ' ')//���ҿո�
		{
			sStack.push(s[i]);//�ǿո��ַ���ջ
		}
		else//�����ո�
		{
			while (!sStack.empty())//ջ�������ַ���ջ
			{
				char t = sStack.top();
				sStack.pop();
				sRes.push_back(t);
			}
			sRes.append(" ");//��ӿո�
		}
	}
	if (!sStack.empty())//�������һ����
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