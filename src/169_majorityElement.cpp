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
 * 
 * 分析
 * 从数组中搜索出现次数不小于数组长度一半的元素
*/
/************************************************************************/
int majorityElement(vector<int>& nums)
{
	std::unordered_map<int,int> st;
	for (const int x : nums)
	{
		if (st.find(x) == st.end())
		{
			st[x] = 1;
		}
		else
			st[x] += 1;
		if (st[x] > nums.size()/2)
		{
			return x;
		}
	}
	return nums[0];
}
int main()
{
	vector<int> nums = {1,2,2};
	int s = majorityElement(nums);
	return 0;
}