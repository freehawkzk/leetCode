#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/************************************************************************/
/* 
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 �� x, y < 231.
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *       ��   ��
 * 
 * The above arrows point to positions where the corresponding bits are different.
 * ����
 * ����ʵ������Ҫ��x��y�Ķ����Ʊ�ʾ�в���ͬλ����Ŀ��
 * ��ˣ����Բ����Ƚ�x��y�����ͳ�ƽ����1��λ������⡣
*/
/************************************************************************/
int hammingDistance(int x, int y)
{
	int c = x^y;//���
	int nCount = 0;
	while (c)//ͳ�ƽ����1��λ��
	{
		c &= (c - 1);
		nCount++;
	}
	return nCount;
}
int main()
{

	int x = 1, y = 1;
	int c = hammingDistance(x, y);
	return 0;
}