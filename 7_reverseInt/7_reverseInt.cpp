#include <iostream>

using namespace std;

int reverseint(int x)
{
	if (x > -10 && x < 10)
	{
		return x;
	}
	long long result = 0;
	int nSign = x >= 0 ? 1 : -1;
	if (nSign < 0)
	{
		x = -x;
	}
	while (x)
	{
		result = result * 10 + x % 10;

		x = x / 10;
	}
	if (result > INT_MAX)
	{
		return 0;
	}
	return nSign > 0 ?result : -result;
}

int main()
{
	int x = 1534236469;
	cout << reverseint(x) << endl;
	return 0;
}