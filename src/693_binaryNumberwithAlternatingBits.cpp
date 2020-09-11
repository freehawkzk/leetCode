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
 * Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
 *
 * Example 1:
 *
 * Input: 5
 * Output: True
 * Explanation:
 * The binary representation of 5 is: 101
 *
 * Example 2:
 *
 * Input: 7
 * Output: False
 * Explanation:
 * The binary representation of 7 is: 111.
 *
 * Example 3:
 *
 * Input: 11
 * Output: False
 * Explanation:
 * The binary representation of 11 is: 1011.
 *
 * Example 4:
 *
 * Input: 10
 * Output: True
 * Explanation:
 * The binary representation of 10 is: 1010.
 *
 * 分析
 * 将给定数字转换成二进制，如果二进制相邻的两位有相同的，则不合格。
 *
 * 注意
 * 二进制高位为0， 不能考虑。
*/
/************************************************************************/
bool hasAlternatingBits(int n)
{
	//bitset<32> bt(n);
	//int nCount = 31;
	//bool bStart = false;
	//for (int i = 31; i > 0; i--)
	//{
	//	if (!bStart && bt[i] == 1)
	//		bStart = true;
	//	if (bStart)
	//	{
	//		if (bt[i] == bt[i-1])
	//		{
	//			return false;
	//		}
	//	}
	//}
	//return true;
	int lastBit = -1;
	while (n)
	{
		int bit = n % 2;
		if (bit == lastBit)
		{
			return false;
		}
		lastBit = bit;
		n = n >> 1;
	}
	return true;
}

int main()
{
	bool b = hasAlternatingBits(5);
	return 0;
}