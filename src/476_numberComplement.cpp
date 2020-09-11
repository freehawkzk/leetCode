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
 * You could assume no leading zero bit in the integer��s binary representation.
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
 * ����
 * ���������ֱ�ʾ�ɶ����ƣ��ö����ƴӵ�һ��1��λ��Ϊn����һ�����������Ķ�����������Ķ��������֮�����0001������1����n��1.
 * �������ʾ��32Ϊbitset��
 * Ѱ�ҵ�һ����Ϊ0��λ
 * ��ת��λ֮�������λ��
 *
 * ��ע
 * bitset��ʾ֮�󣬵�0λ��ʾ���Ƕ����Ƶĵ�0λ����ˣ���Ҫ�Ӹ����ͱ�����
*/
/************************************************************************/
int findComplement(int num) {
	std::bitset<32> bts32(num);//�������ʾ��32λbitset
	int nRes = 0;
	bool bStart = false;
	for (int i = bts32.size()-1; i>=0; i--)
	{
		if (bStart == false && bts32[i] == 1)//Ѱ�ҵ�һ��Ϊ1��λ
		{
			bStart = true;
		}
		if (bStart)//��ת֮�������λ
		{
			bts32.flip(i);
		}
	}
	nRes = (int)bts32.to_ulong();//������
	return nRes;
}
int main()
{

	int x = 1;
	int y = findComplement(x);
	return 0;
}