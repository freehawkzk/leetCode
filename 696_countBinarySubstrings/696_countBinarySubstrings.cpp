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
 * Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
 *
 * Substrings that occur multiple times are counted the number of times they occur.
 *
 * Example 1:
 *
 * Input: "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 *
 * Notice that some of these substrings repeat and are counted the number of times they occur.
 *
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
 *
 * Example 2:
 *
 * Input: "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 *
 * Note:
 * s.length will be between 1 and 50,000.
 * s will only consist of "0" or "1" characters.
*/
/************************************************************************/
int countBinarySubstrings(string s) {
	int nCount = 0;
	int nPos = s.find("01",0);
	while (nPos != std::string::npos)
	{
		nCount++;
		int nOffset = 1;
		while (nPos-nOffset >= 0  && nPos+1+nOffset < s.length())
		{
			if (s[nPos - nOffset] == '0' && s[nPos + 1 + nOffset]=='1')
			{
				nCount++;
				nOffset++;
			}
			else
				break;
		}
		nPos = s.find("01", nPos + 1);
	}
	nPos = s.find("10", 0);
	while (nPos != std::string::npos)
	{
		nCount++;
		int nOffset = 1;
		while (nPos - nOffset >= 0 && nPos + 1 + nOffset < s.length())
		{
			if (s[nPos - nOffset] == '1' && s[nPos + 1 + nOffset] == '0')
			{
				nCount++;
				nOffset++;
			}
			else
				break;
		}
		nPos = s.find("10", nPos + 1);
	}
	return nCount;
}

int main()
{
	string s = "10101";
	int a = countBinarySubstrings(s);
	return 0;
}