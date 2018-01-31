#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/************************************************************************/
/*
 * Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 * 
 * Example 1:
 * 
 * Input: [1,4,3,2]
 * 
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
 * 
 * Note:
 * 
 * n is a positive integer, which is in the range of [1, 10000].
 * All the integers in the array will be in the range of [-10000, 10000].
 * ����
 * ��������2n���������飬�ֳ�n�飬��ÿ����ȥ��С������������С���ĺͣ�Ҫ����С��֮�����
 * ������������2n���鰴��С��������󣬰���2����һ�飬��ʱ����С��֮�����
*/
/************************************************************************/
int __cdecl cmp(const void* pa, const void* pb)//�ȽϺ���
{
	int* a = (int*)pa;
	int* b = (int*)pb;

	if (*a > *b)
		return 1;
	else if (*a == *b)
	{
		return 0;
	}
	else
		return -1;
}
int arrayPairSum(vector<int>& nums) {
	if (nums.size()==0)//�Ϸ����ж�
	{
		return 0;
	}
	qsort(&nums[0], nums.size(), sizeof(int), cmp);//����
	//sort(nums.begin(), nums.end());
	int nMinSum = 0;
	for (int i = 0; i < nums.size(); i+=2)//������С��֮��
	{
		nMinSum += nums[i];
	}
	return nMinSum;
}
int main()
{

	vector<int> nums = { 1, 4, 3, 2 };
	int c = arrayPairSum(nums);
	return 0;
}