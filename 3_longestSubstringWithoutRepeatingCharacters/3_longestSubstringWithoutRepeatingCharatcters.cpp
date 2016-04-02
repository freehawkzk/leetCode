#include <string>
#include <iostream>
using namespace std;
int lengthOfLongestSubstring(string s);
int lengthOfLongestSubstring(string s)
{
	int nSize = s.size();
	if (nSize == 0)
		return 0;
	else if (nSize == 1)
		return 1;
	else
	{
		int locs[256];
		memset(locs, -1, sizeof(locs));

		int idx = -1, max = 0;
		for (int i = 0; i < nSize; i++)
		{
			if (locs[s[i]] > idx)
			{
				idx = locs[s[i]];
			}

			if (i - idx > max)
			{
				max = i - idx;
			}

			locs[s[i]] = i;
		}
		return max;
	}
}
int main()
{
	string str = "abcabcbb";

	int nSize = lengthOfLongestSubstring(str);

	cout << nSize << endl;

	return 0;
}