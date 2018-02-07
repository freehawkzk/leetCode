#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;
/************************************************************************/
/*
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 * 分析
 * 在已排序的数组中查找两个数，使他们的和等于给定值
 *
*/
/************************************************************************/


vector<int> twoSum(vector<int>& numbers, int target) 
{
	vector<int> vRes(2);
	std::unordered_multimap<int, int> udm;
	for (int i = 0; i < numbers.size();i++)
	{
		udm.insert(unordered_multimap<int, int>::value_type(numbers[i], i));
	}
	for (int i = 0; i < numbers.size();i++)
	{
		unordered_multimap<int, int>::iterator itor = udm.find(target - numbers[i]);
		if (itor != udm.end() && itor->second != i)
		{
			vRes[0] = min(i + 1, itor->second + 1);
			vRes[1] = max(i + 1, itor->second + 1);
			break;
		}
	}
	return vRes;
}
int main()
{
	vector<int> numbers = { 2, 7, 8, 9 };
	vector<int> vRes = twoSum(numbers, 10);
	return 0;
}