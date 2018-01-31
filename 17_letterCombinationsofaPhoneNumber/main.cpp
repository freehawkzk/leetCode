#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> letterCombinations(string digits);
/************************************************************************/
/* 
 * 1���绰������ÿ�����ֶ�Ӧ���ַ��ǹ̶��ģ�
 * 2��������Ϸ�������£�����ַ�������������1���ַ�����
 * 3���ֽⲽ�裺
 * 3.1�� �������ַ�����ÿ�����ֽ��д���
 * 3.2�� ����Ĺ����ǣ������н���ַ��������������ַ�������ĩβ��Ӹ�������
 *       ��Ӧ����ĸ�ַ���Ҳ���Ǹ���������Ӧ����ĸ�ַ����е�һλ��
 * 3.3�� ����������µĽ���ַ�������
*/
/************************************************************************/
vector<string> letterCombinations(string digits)
{
	//����Ϸ��Բ���
	if (digits.length() == 0)
	{
		return vector<string>();
	}
	//���ְ�����Ӧ����ĸ�ַ���
	std::string sKey[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> vRes({ "" });//����Ϸ�������һ���ַ���
	for (int i = 0; i < digits.length(); i++)//���������ÿһ�������ַ�
	{
		vector<string> vtemp;
		for (int j = 0; j < vRes.size(); j++)//�Ե�ǰ����ַ����е�ÿһ���ַ������д���
		{
			for (int k = 0; k < sKey[digits[i] - '0'].length(); k++)//���ַ���ĩβ������ּ���Ӧ����ĸ�ַ�����һλ
			{
				vtemp.push_back(vRes[j] + sKey[digits[i] - '0'][k]);
			}
		}
		vRes = vtemp;//���½���ַ�������
	}
	return vRes;
}

int main()
{

	std::string digits("2113234");
	vector<string> vRes = letterCombinations(digits);
	for (int i = 0; i < vRes.size(); i++)
	{
		std::cout << vRes[i] << std::endl;
	}
	return 0;
}