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
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * 分析
 * 保持原数组中非0元素的位置顺序，将0元素全部集中到数组尾部。
*/
/************************************************************************/
void moveZeroes(vector<int>& nums) 
{
	int nCount = 0;
	for (int i = nums.size() - 2; i >= 0; i--)
	{
		if (nums[i] == 0)
		{
			for (int k = i; k <= nums.size() - 2; k++)
				nums[k] = nums[k + 1];

			nums[nums.size() - 1 - nCount] = 0;
			nCount++;
		}
	}

}
int main()
{
	vector<int> nums = { 0, 1,0,3,12 };
	moveZeroes(nums);
	return 0;
}