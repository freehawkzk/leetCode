#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/************************************************************************/
/*
 * A self-dividing number is a number that is divisible by every digit it contains.
 *
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 *
 * Also, a self-dividing number is not allowed to contain the digit zero.
 *
 * Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
 *
 * Example 1:
 *
 * Input:
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 *
 * Note:
 * The boundaries of each input argument are 1 <= left <= right <= 10000.
 * 思路
 * self-dividing number是指该数除以它自身的每一位都能除尽。
 * 因此，可以采用遍历区间内的所有整数，分别除以它自己的每一位求余数。
*/
/************************************************************************/
vector<int> selfDividingNumbers(int left, int right)
{
	vector<int> vRes;
	int temp;
	for (int i = left; i <= right; i++)
	{
		temp = i;
		while (temp)//该数对它的各位求余
		{
			int n1 = temp % 10;
			if (n1 == 0)
			{
				break;
			}
			if (i % n1 != 0)
			{
				break;
			}
			temp /= 10;
		}
		if (temp == 0)
		{
			vRes.push_back(i);
		}

	}
	return vRes;
}
int main()
{

	int x = 1, y = 22;
	vector<int> c = selfDividingNumbers(x, y);
	return 0;
}