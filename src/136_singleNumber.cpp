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
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 * 分析
 * 数组中的数为2*n+1个，要求找出其中唯一的一个只出现了一次的数，其他的数都出现了两次。
 *
 * 思路
 * 由于一个数异或自身得到0,0异或任何数还是任何数。
 * 所以只需要将数组内的所有数都异或一次，得到的就是只出现了一次的数。
*/
/************************************************************************/

int singleNumber(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++)//遍历数组并进行异或，结果保存在数组第一个位置。
	{
		nums[0] = nums[0] ^ nums[i];
	}
	return nums[0];
}
int main()
{

	return 0;
}