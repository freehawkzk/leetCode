#include <string>
#include <iostream>
using namespace std;


string convert(string s, int numRows)
{
	if (numRows <=1)
	{
		return s;
	}
	string resStr;
	int nStep = 2 * (numRows - 1);
	int nLength = s.length();
	int nLocate1 = 0;
	int nLocate2 = 0;
	for (int i = 0; i < numRows; i++)
	{	
		if (i == 0 || i == numRows - 1)
		{
			nLocate1 = i;
			while (nLocate1 < nLength)
			{
				resStr += s[nLocate1];
				nLocate1 += nStep;
			}
		}
		else 
		{
			nLocate1 = i;
			nLocate2 = nStep - i;
			while (nLocate1 < nLength)
			{
				resStr += s[nLocate1];
				if (nLocate2 < nLength)
				{
					resStr += s[nLocate2];
				}
				nLocate1 += nStep;
				nLocate2 += nStep;
			}
		}	

	}

	return resStr;
}
int main()
{
	string input = "ABCD";
	int num = 3;
	string resStr = convert(input, num);
	cout << input << endl;
	cout << resStr << endl;
	return 0;
}