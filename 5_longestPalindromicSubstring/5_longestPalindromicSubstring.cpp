#include <string>

#include <iostream>
using namespace std;
string longestPalindrome(string s);
string preProcess(string s) {
	int n = s.length();
	if (n == 0) return "^$";
	string ret = "^";
	for (int i = 0; i < n; i++)
		ret += "#" + s.substr(i, 1);

	ret += "#$";
	return ret;
}
string longestPalindrome(string s) {
	string T = preProcess(s);
	int n = T.length();
	int *P = new int[n];
	int C = 0, R = 0;
	for (int i = 1; i < n - 1; i++) {
		int i_mirror = 2 * C - i; // equals to i' = C - (i-C)  

		P[i] = (R > i) ? fmin(R - i, P[i_mirror]) : 0;

		// Attempt to expand palindrome centered at i  
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;

		// If palindrome centered at i expand past R,  
		// adjust center based on expanded palindrome.  
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}

	// Find the maximum element in P.  
	int maxLen = 0;
	int centerIndex = 0;
	for (int i = 1; i < n - 1; i++) {
		if (P[i] > maxLen) {
			maxLen = P[i];
			centerIndex = i;
		}
	}
	delete[] P;

	return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}
//string longestPalindrome(string s)
//{
//	int nSize = s.size();
//	if (nSize <=1)
//	{
//		return s;
//	}
//	else if (nSize == 2)
//	{
//		if (s[0] == s[1])
//		{
//			return s;
//		}
//		else
//		{
//			return string("");
//		}
//	}
//	else
//	{
//		int nL = 0;
//		int nR = nSize - 1;
//		int nLength = 0;
//		for (int i = 0; i < nSize - 1;i++)
//		{
//			if (s[i] == s[i+1])
//			{
//				int k = 0;
//				for (; i - k >= 0 && i+1 + k < nSize;k++)
//				{
//					if (s[i - k] == s[i+1+k])
//					{
//						if (i - k == 0)
//						{
//							if (nLength < 2*k+2)
//							{
//								nL = 0;
//								nR = i + 1 + k;
//								nLength = 2 * k + 2;
//							}
//							
//						}
//						else if (i + k +1== nSize - 1)
//						{
//							if (nLength < 2*k+2)
//							{
//								nL = i - k;
//								nR = nSize - 1;
//								nLength = 2 * k + 2;
//							}
//							
//						}
//						continue;
//					}
//					else
//					{	
//						if (nLength < 2*k)
//						{
//							nL = i - k+1;
//							nR = i + 1+1 + k;
//							nLength = 2 * k;
//						}
//						break;
//					}
//				}
//			}
//			if (i > 0 && s[i-1] == s[i+1])
//			{
//				int k = 0;
//				for (; i -k >= 0 && i + k < nSize; k++)
//				{
//					if (s[i- k] == s[i + k])
//					{
//						if (i-k ==0)
//						{
//							
//							if (nLength < 2*k+1)
//							{
//								nL = 0;
//								nR = i + k;
//								nLength = 2 * k + 1;
//							}
//							
//						}
//						else if (i + k == nSize - 1)
//						{
//							if (nLength < 2 * k + 1)
//							{
//								nL = i - k;
//								nR = nSize - 1;
//								nLength = 2 * k + 1;
//							}
//						}
//						continue;
//					}
//					else
//					{
//						if (nLength < 2 * k-1)
//						{
//							nL = i - k+1;
//							nR = i +  k;
//							nLength = 2 * k-1;
//						}
//						break;
//					}
//				}
//			}
//		}
//		return s.substr(nL, nLength);
//	}
//}
int main()
{
	string s = "aaaa";

	string strResult = longestPalindrome(s);
	cout << strResult << endl;
	return 0;
}