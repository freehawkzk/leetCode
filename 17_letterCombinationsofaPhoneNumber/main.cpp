#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> letterCombinations(string digits);

vector<string> letterCombinations(string digits)
{
	std::string sKey[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> vRes({ "" });
	for (int i = 0; i < digits.length(); i++)
	{
		vector<string> vtemp;
		for (int j = 0; j < vRes.size(); j++)
		{
			for (int k = 0; k < sKey[digits[i] - '0'].length(); k++)
			{
				vtemp.push_back(vRes[j] + sKey[digits[i] - '0'][k]);
			}
		}
		vRes = vtemp;
	}
	return vRes;
}
int main()
{
	std::string digits("234");
	vector<string> vRes = letterCombinations(digits);
	for (int i = 0; i < vRes.size(); i++)
	{
		std::cout << vRes[i] << std::endl;
	}
	return 0;
}