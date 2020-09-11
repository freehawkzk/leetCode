#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
/************************************************************************/
/*
 * Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
 *
 * Note:
 *
 * The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * You could assume no leading zero bit in the integer’s binary representation.
 *
 * Example 1:
 *
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 *
 * Example 2:
 *
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 *
 * 分析
 * 将输入数字表示成二进制，该二进制从第一个1的位置为n，求一个数，该数的二进制与输入的二进制相加之后等于0001。。。1，共n个1.
 * 将输入表示成32为bitset，
 * 寻找第一个不为0的位
 * 翻转该位之后的所有位。
 *
 * 备注
 * bitset表示之后，第0位表示的是二进制的第0位，因此，需要从高往低遍历。
*/
/************************************************************************/
int findComplement(int num) {
	std::bitset<32> bts32(num);//将输入表示成32位bitset
	int nRes = 0;
	bool bStart = false;
	for (int i = bts32.size()-1; i>=0; i--)
	{
		if (bStart == false && bts32[i] == 1)//寻找第一个为1的位
		{
			bStart = true;
		}
		if (bStart)//翻转之后的所有位
		{
			bts32.flip(i);
		}
	}
	nRes = (int)bts32.to_ulong();//输出结果
	return nRes;
}
int main()
{

	int x = 1;
	int y = findComplement(x);
	return 0;
}