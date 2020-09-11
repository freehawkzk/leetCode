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
 * Given an m * n matrix M initialized with all 0's and several update operations.
 *
 * Operations are represented by a 2D array, and each operation is represented by an array with two positive integers a and b, which means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.
 *
 * You need to count and return the number of maximum integers in the matrix after performing all the operations.
 *
 * Example 1:
 *
 * Input:
 * m = 3, n = 3
 * operations = [[2,2],[3,3]]
 * Output: 4
 * Explanation:
 * Initially, M =
 * [[0, 0, 0],
 * [0, 0, 0],
 * [0, 0, 0]]
 *
 * After performing [2,2], M =
 * [[1, 1, 0],
 * [1, 1, 0],
 * [0, 0, 0]]
 *
 * After performing [3,3], M =
 * [[2, 2, 1],
 * [2, 2, 1],
 * [1, 1, 1]]
 *
 * So the maximum integer in M is 2, and there are four of it in M. So return 4.
 *
 * Note:
 *
 * The range of m and n is [1,40000].
 * The range of a is [1,m], and the range of b is [1,n].
 * The range of operations size won't exceed 10,000.
 *
 * ����
 * ����һ��ȫ0��������M������һ������[a,b],��ʾ������M������p[0,0]��p[a,b]֮�������ֵ+1��
 * ����������M�У�ֵ�������ֵ�ĸ�����
 *
 * ˼·
 * �������в�������һ����[0,0]��ʼ���������ԣ�ֻ��Ҫͳ�����в����У��ص�����С���򼴿ɡ�
 * ת���ɲ���ops[i].x��Сֵ*ops[i].y��Сֵ���ó����
*/
/************************************************************************/
int maxCount(int m, int n, vector<vector<int>>& ops) {
	for (auto v : ops)
	{
		if (m > v[0])
			m = v[0];
		if (n > v[1])
			n = v[1];
	}
	return m*n;
}
int main()
{

	return 0;
}