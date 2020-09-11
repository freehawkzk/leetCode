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
 * ����
 * ����Ҫ�����һ��������[L,R]�����������ڵ�ÿһ������ͳ�Ƹ����Ķ����Ʊ�ʾ����nλ1��
 * �ټ��n�Ƿ�Ϊ��������������������������ͳ�ƽ�������򲻼��롣
 *
 * ˼·
 * 1����������
 * 2��ʹ��bitsetͳ�Ƹ�����1��λ��
 * 3���������������ʵ�֡�
*/
/************************************************************************/
bool isPrime(int num)
{
	if (num == 1)
	{
		return false;
	}
	//������С�����⴦��  
	if (num == 2 || num == 3)
		return 1;
	//����6�ı��������һ����������  
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	//��6�ı��������Ҳ���ܲ�������  
	for (int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	//�ų����У�ʣ���������  
	return 1;
}
int countPrimeSetBits(int L, int R)
{
	int nTotal = 0;
	for (int i = L; i <= R;i++)
	{
		bitset<32> bts(i);
		int nCount = bts.count();//ͳ��1��λ��
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