#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/************************************************************************/
/*
 * Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 * 
 * Example 1:
 * 
 * Input: [1,4,3,2]
 * 
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
 * 
 * Note:
 * 
 * n is a positive integer, which is in the range of [1, 10000].
 * All the integers in the array will be in the range of [-10000, 10000].
 * 分析
 * 给定含有2n个数的数组，分成n组，从每组中去最小的数，再求最小数的和，要求最小数之和最大。
 * 经过分析，将2n数组按从小到大排序后，按照2个数一组，此时，最小数之和最大。
*/
/************************************************************************/
int __cdecl cmp(const void* pa, const void* pb)//比较函数
{
	int* a = (int*)pa;
	int* b = (int*)pb;

	if (*a > *b)
		return 1;
	else if (*a == *b)
	{
		return 0;
	}
	else
		return -1;
}
int arrayPairSum(vector<int>& nums) {
	if (nums.size()==0)//合法性判断
	{
		return 0;
	}
	qsort(&nums[0], nums.size(), sizeof(int), cmp);//快排
	//sort(nums.begin(), nums.end());
	int nMinSum = 0;
	for (int i = 0; i < nums.size(); i+=2)//计算最小数之和
	{
		nMinSum += nums[i];
	}
	return nMinSum;
}
int main()
{

	vector<int> nums = { 1, 4, 3, 2 };
	int c = arrayPairSum(nums);
	return 0;
}