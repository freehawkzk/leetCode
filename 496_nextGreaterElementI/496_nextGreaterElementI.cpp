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
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 * 
 * The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
 * 
 * Example 1:
 * 
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 * Explanation:
 * For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
 * For number 1 in the first array, the next greater number for it in the second array is 3.
 * For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
 * 
 * Example 2:
 * 
 * Input: nums1 = [2,4], nums2 = [1,2,3,4].
 * Output: [3,-1]
 * Explanation:
 * For number 2 in the first array, the next greater number for it in the second array is 3.
 * For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 * 
 * Note:
 * 
 * All elements in nums1 and nums2 are unique.
 * The length of both nums1 and nums2 would not exceed 1000.
 * 
 * 分析
 * 给定两个数组a1,a2，a1是a2的子集，a1，a2中的元素不重复，对于a1中的每一个元素c，要求在a2中查找符合以下条件的元素：
 * 1、位置在a2中c元素的右边；
 * 2、值大于c；
 * 3、如果找不到，则返回-1；否则返回第一个满足条件1、2的值。
 *
 * 思路
 * 由于最后结果是和位置相关的，所以不能对a1，a2排序。
 * 可以使用map记录a2中每个元素对应的满足条件的值，输出是只需要查找map即可。
*/
/************************************************************************/
int findNextGreater(vector<int>& nums, int loc)
{
	//查找满足条件的值
	if (loc == nums.size()-1)
	{
		return -1;
	}
	for (int i = loc + 1; i < nums.size(); i++)
	{
		if (nums[i] > nums[loc])
			return nums[i];
	}
	return -1;
}
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	map<int, int> mNextGreater;
	for (int i = 0; i < nums.size(); i++)//生成记录map
	{
		mNextGreater.insert(map<int, int>::value_type(nums[i], findNextGreater(nums, i)));
	}
	vector<int> vRes;
	for (int i = 0; i < findNums.size(); i++)//查表
	{
		vRes.push_back(mNextGreater[findNums[i]]);
	}
	return vRes;
}
int main()
{
	vector<int> findNums = { 2,4 };
	vector<int> nums = { 1,2,3,4 };
	vector<int> vRes = nextGreaterElement(findNums, nums);
	return 0;
}