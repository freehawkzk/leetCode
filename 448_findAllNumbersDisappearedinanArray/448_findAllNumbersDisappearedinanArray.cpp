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
 * Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
*/
/************************************************************************/
vector<int> findDisappearedNumbers(vector<int>& nums)
{
	for (auto x : nums)
	{
		if (nums[abs(x) - 1] > 0)
			nums[abs(x) - 1] *= -1;
	}
	vector<int> vRes;
	for (int i = 0; i < nums.size();i++)
	{
		if (nums[i] > 0)
		{
			vRes.push_back(i+1);
		}
	}
	return vRes;
}
int main()
{
	vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> vRes = findDisappearedNumbers(nums);
	return 0;
}