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
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 *
 * 分析
 * 查找数组中是否有重复的元素
 */
/************************************************************************/
bool containsDuplicate(vector<int>& nums)
{
	unordered_map<int, int> udm;
	for (const int x : nums)
	{
		if (udm.find(x) != udm.end())
		{
			return true;
		}
		else
			udm[x] = 1;
	}
	return false;
}

int main()
{
	vector<int> nums = { 1};
	bool b = containsDuplicate(nums);
	return 0;
}