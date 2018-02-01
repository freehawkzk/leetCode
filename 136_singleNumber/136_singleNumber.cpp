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
 * ����
 * �����е���Ϊ2*n+1����Ҫ���ҳ�����Ψһ��һ��ֻ������һ�ε������������������������Ρ�
 *
 * ˼·
 * ����һ�����������õ�0,0����κ��������κ�����
 * ����ֻ��Ҫ�������ڵ������������һ�Σ��õ��ľ���ֻ������һ�ε�����
*/
/************************************************************************/

int singleNumber(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++)//�������鲢������򣬽�������������һ��λ�á�
	{
		nums[0] = nums[0] ^ nums[i];
	}
	return nums[0];
}
int main()
{

	return 0;
}