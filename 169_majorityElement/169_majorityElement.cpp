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
 * ����
 * ���������������ִ�����С�����鳤��һ���Ԫ��
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