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

	stable_sort(strs.begin(), strs.end(), cmp);
	
	if (strs[0].length() == 0)
	{
		return string("");
	}
	else
	{
		vector<string>::iterator itorSortBeg = strs.begin();
		vector<string>::iterator itorSortEnd = itorSortBeg++;
		int nFirstStrLength = (*itorSortBeg).length();
		while (itorSortEnd != strs.end() && (nFirstStrLength == (*itorSortEnd).length()))
		{
			itorSortEnd++;
		}
		if (itorSortEnd - itorSortBeg == 1)
		{
			return strs[0];
		}
		else
		{
			stable_sort(itorSortBeg, itorSortEnd);
			int nSize = itorSortEnd - itorSortBeg;
			int nStopPos = nFirstStrLength;
			for (int i = 1; i < nSize; i++)
			{
				for (int j = 0; j < nFirstStrLength && j <= nStopPos; j++)
				{
					if ((strs[0])[j] == (strs[i])[j])
					{
						continue;
					}
					else
					{
							nStopPos = j;	
					}
				}
			}
			return strs[0].substr(0, nStopPos);
		}
		

	}

	//return strs[0];
}


int main()
{
	vector<string> vStrs;
	vStrs.push_back("aa");
	vStrs.push_back("a");

	string res = longestCommonPrefix(vStrs);
	cout << res << endl;
	return 0;
}