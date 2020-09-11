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
 * In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
 * 
 * You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
 * 
 * The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
 * 
 * If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
 * 
 * Example 1:
 * 
 * Input:
 * nums =
 * [[1,2],
 * [3,4]]
 * r = 1, c = 4
 * Output:
 * [[1,2,3,4]]
 * Explanation:
 * The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
 * 
 * Example 2:
 * 
 * Input:
 * nums =
 * [[1,2],
 * [3,4]]
 * r = 2, c = 4
 * Output:
 * [[1,2],
 * [3,4]]
 * Explanation:
 * There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
 *
 * ����
 * ����Ҫ��ʵ�־������ţ�
 * 1�����������С�����������ȫ��ԭ�����Ԫ���������߲���������ԭ���������Ԫ��ʱ������ԭ����
 * 2����ԭ���󣬰��ո������С��������ţ���������ԭ���ԭ������ȡ����
 *
 * ����
 * ����ʵ������������ά����֮�������ϵ��ת�����⡣
*/
/************************************************************************/
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	if (nums.size()== 0)//
	{
		return nums;
	}
	if (r*c != nums.size() * nums[0].size())//ȷ����������
	{
		return nums;
	}

	vector<vector<int>> vRes;
	for (int i = 0; i < r; i++)
	{
		vRes.push_back(vector<int>());
	}
	int nR0 = nums.size();
	int nC0 = nums[0].size();
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums[0].size(); j++)
		{
			int nR = (i*nC0+j) / c;
			vRes[nR].push_back(nums[i][j]);//����
		}
	}
	return vRes;
}
int main()
{
	vector<vector<int>> nums = { { 1, 1,1 }, { 2, 2,2 } };
	vector<vector<int>> vRes = matrixReshape(nums, 3, 2);
	return 0;
}