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
 * ����
 * �����������飬Ҫ��������Σ����з�����ߵ����Gold Medal���ڶ������Silver Medal,���������Bronze Medal�������������Ρ�
 * 
 * ˼·
 * ����map���Զ���key��������ԣ�ʹ��map<����������>���ó��������������κʹ����Ӧ�Ĺ�ϵ����ת�����ַ������ɡ�
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