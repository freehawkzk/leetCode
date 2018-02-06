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
 * Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
*/
/************************************************************************/
int minMoves(vector<int>& nums)
{
	int minnum = INT_MAX;
	for (const int x : nums)
	{
		if (minnum > x)
			minnum = x;
	}
	int sum = 0;
	for (const int x : nums)
	{
		sum += x - minnum;
	}
	return sum;
}
int main()
{

	vector<int> nums = { 1, 1,1 };
	int x = minMoves(nums);
	return 0;
}