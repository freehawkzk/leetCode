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
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * 
 * For example:
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *
 * 分析
 * 题目本意：当一个数由多位组成时，讲它的各位相加，直到结果只由一位数组成，输出这个结果。
 * 
 * 思路
 * 1、普通思路，按照题意相加各位，循环即可。
 * 2、经过分析，发现结果具有规律，0.1.2.3.4.5.6.7.8.9.1.2.3.3.4.5.6.7.8.9.1.2.3.4.5。。。
 *    从中可以看出，结果实际上是一个9进制的序列，但与普通9进制不同，普通9进制是从0-8，
 *    结果序列中是1-9，可以考虑对num%9做适当的调整。
*/
/************************************************************************/
int addDigits(int num) {
	return 1 + (num - 1) % 9;
}

int main()
{
	int a = addDigits(18);
	return 0;
}