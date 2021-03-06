#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/************************************************************************/
/*
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
 *
 * Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 *
 *
 * Example 1:
 *
 * Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * Output: True
 * Explanation:
 * 1234
 * 5123
 * 9512
 *
 * In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
 *
 * Example 2:
 *
 * Input: matrix = [[1,2],[2,2]]
 * Output: False
 * Explanation:
 * The diagonal "[1, 2]" has different elements.
 *
 * Note:
 *
 * matrix will be a 2D array of integers.
 * matrix will have a number of rows and columns in range [1, 20].
 * matrix[i][j] will be integers in range [0, 99].
 * 分析
 * 从二维数组左下角开始，要求，每一个斜列都是全部相同的数。
 * 实际上，只要每一行的前n-1个数与下一行的都n-1个数相同即可。

*/
/************************************************************************/
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
	for (int i = 0; i < matrix.size()-1; i++)
	{
		for (int j = 0; j < matrix[i].size() - 1; j++)
		{
			if (matrix[i][j] != matrix[i+1][j+1])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{

	int x = 1, y = 22;
	//vector<int> c = isToeplitzMatrix(x, y);
	return 0;
}