#include <iostream>
using namespace std;

bool isPalindrome(int x);

bool isPalindrome(int x)
{
	if (x < 0)
		return false;
	else if (x < 10)
		return true;

	int nBase = 1;
	while (x / nBase >=10)
		nBase *= 10;

	int nLeft = 0;
	int nRight = 0;

	while (x)
	{
		nLeft = x % 10;
		nRight = x / nBase;
		if (nLeft != nRight)
			return false;

		x -= (nRight*nBase);
		x = x / 10;
		nBase /= 100;
	}
	return true;
}

int main()
{
	int x = 1000000001;
	cout << isPalindrome(x) << endl;
	return 0;
}