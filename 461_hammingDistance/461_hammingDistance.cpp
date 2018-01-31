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
 * 0 ≤ x, y < 231.
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
 *       ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are different.
 * 分析
 * 本题实际上是要求x和y的二进制表示中不相同位的数目。
 * 因此，可以采用先将x和y异或，再统计结果中1的位数来求解。
*/
/************************************************************************/
int hammingDistance(int x, int y)
{
	int c = x^y;//异或
	int nCount = 0;
	while (c)//统计结果中1的位数
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