#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> letterCombinations(string digits);
/************************************************************************/
/* 
 * 1、电话机按键每个数字对应的字符是固定的；
 * 2、在输入合法的情况下，输出字符串数组至少有1个字符串；
 * 3、分解步骤：
 * 3.1、 对输入字符串的每个数字进行处理；
 * 3.2、 处理的过程是：将现有结果字符串数组中所有字符串，在末尾添加该数字所
 *       对应的字母字符，也就是该数字所对应的字母字符串中的一位；
 * 3.3、 将结果存入新的结果字符串数组
*/
/************************************************************************/
vector<string> letterCombinations(string digits)
{
	//输入合法性测试
	if (digits.length() == 0)
	{
		return vector<string>();
	}
	//数字按键对应的字母字符串
	std::string sKey[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> vRes({ "" });//输入合法至少有一个字符串
	for (int i = 0; i < digits.length(); i++)//处理输入的每一个数字字符
	{
		vector<string> vtemp;
		for (int j = 0; j < vRes.size(); j++)//对当前结果字符串中的每一个字符串进行处理
		{
			for (int k = 0; k < sKey[digits[i] - '0'].length(); k++)//在字符串末尾添加数字键对应的字母字符串的一位
			{
				vtemp.push_back(vRes[j] + sKey[digits[i] - '0'][k]);
			}
		}
		vRes = vtemp;//更新结果字符串数组
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