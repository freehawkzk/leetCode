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
 * 分析
 * 给定一个全0矩形区域M，定义一个操作[a,b],表示将矩阵M中区域p[0,0]到p[a,b]之间的所有值+1，
 * 求最终整个M中，值等于最大值的个数。
 *
 * 思路
 * 由于所有操作都是一个从[0,0]开始的区域，所以，只需要统计所有操作中，重叠的最小区域即可。
 * 转换成操作ops[i].x最小值*ops[i].y最小值，得出结果
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