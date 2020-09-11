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
 * Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.
 *
 * (Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)
 *
 * Example 1:
 *
 * Input: L = 6, R = 10
 * Output: 4
 * Explanation:
 * 6 -> 110 (2 set bits, 2 is prime)
 * 7 -> 111 (3 set bits, 3 is prime)
 * 9 -> 1001 (2 set bits , 2 is prime)
 * 10->1010 (2 set bits , 2 is prime)
 *
 * Example 2:
 *
 * Input: L = 10, R = 15
 * Output: 5
 * Explanation:
 * 10 -> 1010 (2 set bits, 2 is prime)
 * 11 -> 1011 (3 set bits, 3 is prime)
 * 12 -> 1100 (2 set bits, 2 is prime)
 * 13 -> 1101 (3 set bits, 3 is prime)
 * 14 -> 1110 (3 set bits, 3 is prime)
 * 15 -> 1111 (4 set bits, 4 is not prime)
 *
 * Note:
 *
 * L, R will be integers L <= R in the range [1, 10^6].
 * R - L will be at most 10000.
 *
 * 分析
 * 本题要求给定一个闭区间[L,R]，对于区间内的每一个数，统计该数的二进制表示共有n位1，
 * 再检查n是否为素数，如果是素数，则计入最后的统计结果，否则不计入。
 *
 * 思路
 * 1、遍历区间
 * 2、使用bitset统计各数的1的位数
 * 3、检查素数，快速实现。
*/
/************************************************************************/
bool isPrime(int num)
{
	if (num == 1)
	{
		return false;
	}
	//两个较小数另外处理  
	if (num == 2 || num == 3)
		return 1;
	//不在6的倍数两侧的一定不是质数  
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	//在6的倍数两侧的也可能不是质数  
	for (int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	//排除所有，剩余的是质数  
	return 1;
}
int countPrimeSetBits(int L, int R)
{
	int nTotal = 0;
	for (int i = L; i <= R;i++)
	{
		bitset<32> bts(i);
		int nCount = bts.count();//统计1的位数
		if (isPrime(nCount))
		{
			nTotal++;
		}
	}
	return nTotal;
}
int main()
{
	int nSum = countPrimeSetBits(10,15);
	return 0;
}