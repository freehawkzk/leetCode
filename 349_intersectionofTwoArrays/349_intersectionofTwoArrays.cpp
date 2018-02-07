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
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * 
 * Note:
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 分析
 * 求两个集合的交集，要求结果集合中元素不重复，可以乱序。
 *
 * 思路
 * 要求不重复，可乱序，因此可以引入map、set之类的进行快速查找。
*/
/************************************************************************/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> vRes;
	unordered_map<int, bool> udm1;
	unordered_map<int, bool> udm2;
	for (const int x : nums1)
		udm1[x] = true;
	for (const int x :nums2)
		udm2[x] = true;
	unordered_map<int, bool>* pShort = &udm1;
	unordered_map<int, bool>* pLong = &udm2;
	if (udm1.size() > udm2.size())
	{
		pShort = &udm1;
		pLong = &udm2;
	}

	for (auto x : *pShort)
	{
		if (pLong->find(x.first) != pLong->end())
		{
			vRes.push_back(x.first);
		}
	}
	
	return vRes;
}
int main()
{
	vector<int> nums1 = {  };
	vector<int> nums2 = { 2, 2,1 };
	vector<int> vRes = intersection(nums1, nums2);
	return 0;
}