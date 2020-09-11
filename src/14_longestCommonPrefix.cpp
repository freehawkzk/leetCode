#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
	return a.length() < b.length();
}

string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0)
	{
		return string("");
	}
	else if (strs.size() == 1)
	{
		return strs[0];
	}
	sort(strs.begin(), strs.end());

	int nLastStr = strs.size() - 1;
	int nLastPos = 0;
	if (strs[0] == "" || strs[nLastStr] == "")
	{
		return string("");
	}
	else
	{
		while (strs[0][nLastPos] == strs[nLastStr][nLastPos])
		{
			nLastPos++;
		}
	}
	return strs[0].substr(0, nLastPos);
	/*stable_sort(strs.begin(), strs.end(), cmp);
	
	if (strs[0].length() == 0)
	{
		return string("");
	}
	else
	{		
		int nLastPos = strs[0].length();
		int nStrsNum = strs.size();
		for (int i = 1; i < nStrsNum; i++)
		{
			for (int j = 0; j < nLastPos; j++)
			{
				if (strs[0][j] != strs[i][j])
				{
					nLastPos = j;
					break;
				}
			}
		}
		return strs[0].substr(0, nLastPos);
	}*/
}


int main()
{
	vector<string> vStrs;
	vStrs.push_back("");
	vStrs.push_back("");

	string res = longestCommonPrefix(vStrs);
	cout << res << endl;
	return 0;
}