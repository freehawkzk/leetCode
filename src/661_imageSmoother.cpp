#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/************************************************************************/
/*
 * Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.
 *
 * Example 1:
 *
 * Input:
 * [[1,1,1],
 * [1,0,1],
 * [1,1,1]]
 * Output:
 * [[0, 0, 0],
 * [0, 0, 0],
 * [0, 0, 0]]
 * Explanation:
 * For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 * For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 * For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 *
 * Note:
 *
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
 *
 *
*/
/************************************************************************/

vector<vector<int>> imageSmoother(vector<vector<int>>& M)
{
	if (M.size() == 0)
	{
		return M;
	}
	vector<vector<int>> res(M);
	for (int i = 0; i < M.size(); i++)
	{
		for (int j = 0; j < M[i].size();j++)
		{
			float nSum = M[i][j];
			nSum += i - 1 >= 0 ? (j - 1>=0 ? M[i - 1][j - 1] : 0) : 0;
			nSum += i - 1 >= 0 ? (j >= 0 ? M[i - 1][j] : 0) : 0;
			nSum += i - 1 >= 0 ? (j + 1 < M[i].size() ? M[i - 1][j + 1] : 0) : 0;
			nSum += j - 1 >= 0 ? M[i][j - 1] : 0;
			nSum += j + 1 < M[i].size() ? M[i][j + 1] : 0;
			nSum += i + 1 < M.size() ? (j - 1 >= 0 ? M[i + 1][j - 1] : 0) : 0;
			nSum += i + 1 < M.size() ? (j  >= 0 ? M[i + 1][j ] : 0) : 0;
			nSum += i + 1 < M.size() ? (j + 1 < M[i].size() ? M[i + 1][j + 1] : 0) : 0;

			int nCount = 1;
			nCount += i - 1 >= 0 ? (j - 1 >= 0 ? 1 : 0) : 0;
			nCount += i - 1 >= 0 ? (j >= 0 ? 1: 0) : 0;
			nCount += i - 1 >= 0 ? (j + 1 < M[i].size() ? 1 : 0) : 0;
			nCount += j - 1 >= 0 ? 1 : 0;
			nCount += j + 1 < M[i].size() ? 1 : 0;
			nCount += i + 1 < M.size() ? (j - 1 >= 0 ?1 : 0) : 0;
			nCount += i + 1 < M.size() ? (j >= 0 ? 1 : 0) : 0;
			nCount += i + 1 < M.size() ? (j + 1 < M[i].size() ? 1 : 0) : 0;

			res[i][j] = floor(nSum / nCount);
		}
	}
	return res;
}
int main()
{
	vector<vector<int>> M = { { 1, 1, 1 }, { 1, 10, 1 }, { 1, 1, 1 } };
	vector<vector<int>> res = imageSmoother(M);
	return 0;
}