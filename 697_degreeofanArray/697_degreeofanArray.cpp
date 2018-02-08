#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;
/************************************************************************/
/*
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
 * 
 * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
 * 
 * Example 1:
 * 
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * Example 2:
 * 
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * 
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 *
 * 分析
 * 数组的degree是指数组中出现次数最多元素出现的次数。
 * 题目要求找一个最短的子串，并且保证该子串的度和整个数组的度相同。
 * 实际上就是求出现次数最多的元素第一次出现到最后一次出现之间的距离。
 * 由于可能存在多个元素出现次数相同的情况，所以需要求最短。
*/
/************************************************************************/
int findShortestSubArray(vector<int>& nums)
{
	std::unordered_map<int, vector<int>> udmv;
	for (int i = 0; i < nums.size();i++)
	{
		udmv[nums[i]].push_back(i);
	}
	int nMaxF =1;
	int nShortest = INT_MAX;
	for (auto x : udmv)
	{
		if (x.second.size() > nMaxF)
		{
			nShortest = x.second[x.second.size() - 1] - x.second[0] + 1;
			nMaxF = x.second.size();
		}
		else if (x.second.size() == nMaxF)
		{
			if (x.second[x.second.size() - 1] - x.second[0] + 1 < nShortest)
			{
				nShortest = x.second[x.second.size() - 1] - x.second[0] + 1;
			}
		}
	}
	return nShortest;
}

int main()
{
	vector<int> nums = { 1, 2, 2, 3, 1, 4, 2 };
	int c = findShortestSubArray(nums);
	return 0;
}