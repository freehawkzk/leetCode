#include <string>
#include <iostream>

using namespace std;

int myAtoi(string str);

int myAtoi(string str)
{
	int nLength = str.length();
	if (nLength == 0)
		return 0;

	long long lResult = 0;
	bool bStarted = false;
	int nSign = 1;
	int nChar = 0;
	for (int i = 0; i < nLength; i++)
	{
		nChar = str[i];
		if (nChar == ' '&& bStarted == false)
		{
			continue;
		}
		else
		{
			if (nChar == '-' || nChar == '+' || (nChar >= '0' && nChar <= '9'))
			{
				if (bStarted == false)
				{
					if (nChar == '-')
					{
						nSign = -1;
						bStarted = true;
					}
					else if (nChar == '+')
					{
						nSign = 1;
						bStarted = true;
					}
					else
					{
						lResult = nChar - '0';
						bStarted = true;
					}
				}
				else
				{
					if (nChar == '-')
					{
						break;
					}
					else if (nChar == '+')
					{
						break;
					}
					else
					{
						lResult = lResult * 10 + nChar - '0';
						if (lResult > INT_MAX)
						{
							if (nSign == 1)
								return INT_MAX;
							else
								return INT_MIN;
						}
					}
				}
			}
			else
			{
				break;
			}
		}
	}

	lResult *= nSign;
	if (lResult > INT_MAX)
	{
		return INT_MAX;
	}
	else if (lResult < INT_MIN)
	{
		return INT_MIN;
	}
	else
	{
		return int(lResult);
	}
	
}

int main()
{
	string str = "-1";
	int nResult = myAtoi(str);

	cout << nResult << endl;
	return 0;
}