// 485_maxConsecutiveOnes.cpp : �������̨Ӧ�ó������ڵ㡣
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
 * ����
 * ����0-1���飬������������1��ɵ������Ӵ�����󳤶�
 *
 * ����
 * �������飬��¼��ǰ����1���Ӵ����ȣ�ͬʱ��¼����1�Ӵ�����󳤶�
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

