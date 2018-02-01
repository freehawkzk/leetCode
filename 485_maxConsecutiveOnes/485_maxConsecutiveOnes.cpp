// 485_maxConsecutiveOnes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 * 
 * Example 1:
 * 
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 * The maximum number of consecutive 1s is 3.
 * 
 * Note:
 * 
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 *
 * 分析
 * 给定0-1数组，搜索数组中由1组成的连续子串的最大长度
 *
 * 分析
 * 遍历数组，记录当前连续1的子串长度，同时记录连续1子串的最大长度
 *
*/
/************************************************************************/
int findMaxConsecutiveOnes(vector<int>& nums) 
{
	int nMaxLength = 0;
	int nCurLength = 0;
	bool bIsConsecutive = false;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i])
		{
			bIsConsecutive = true;
			nCurLength++;
			if (nMaxLength < nCurLength)
			{
				nMaxLength++;
			}
		}
		else
		{
			bIsConsecutive = false;
			nCurLength = 0;
		}
	}
	return nMaxLength;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = { 1, 1, 0, 1, 1, 1 };
	int l = findMaxConsecutiveOnes(nums);
	return 0;
}

