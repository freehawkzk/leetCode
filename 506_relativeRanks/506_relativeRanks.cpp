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
 * Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
 * For the left two athletes, you just need to output their relative ranks according to their scores.
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 分析
 * 给定分数数组，要求输出名次，其中分数最高的输出Gold Medal，第二名输出Silver Medal,第三名输出Bronze Medal，其余的输出名次。
 * 
 * 思路
 * 利用map会自动将key排序的特性，使用map<分数，次序>，得出分数排序后的名次和次序对应的关系，再转换成字符串即可。
*/
/************************************************************************/
vector<string> findRelativeRanks(vector<int>& nums)
{
	map<int, int> m;
	for (int i = 0; i < nums.size();i++)
	{
		m.insert(map<int, int>::value_type(nums[i], i));
	}
	vector<string> vRes(nums.size());
	int nCount = 0;
	for (map<int, int>::iterator itor = m.begin(); itor != m.end(); itor++)
	{
		int nPos = nums.size() - nCount;
		if (nPos == 1)
		{
			vRes[itor->second] = "Gold Medal";
		}
		else if (nPos == 2)
		{
			vRes[itor->second] = "Silver Medal";
		}
		else if (nPos == 3)
		{
			vRes[itor->second] = "Bronze Medal";
		}
		else
		{
			vRes[itor->second] = std::to_string(nPos);
		}
		nCount++;
	}
	return vRes;
}

int main()
{
	vector<int> nums = { 5, 4,6, 3, 2, 1 ,7};
	vector<string> vRes = findRelativeRanks(nums);
	return 0;
}