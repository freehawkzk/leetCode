#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/************************************************************************/
/*
 * Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.
 * 
 * You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.
 * 
 * Example 1:
 * 
 * Input:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
 * Output: ["Shogun"]
 * Explanation: The only restaurant they both like is "Shogun".
 * 
 * Example 2:
 * 
 * Input:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["KFC", "Shogun", "Burger King"]
 * Output: ["Shogun"]
 * Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
 * 
 * Note:
 * 
 * The length of both lists will be in the range of [1, 1000].
 * The length of strings in both lists will be in the range of [1, 30].
 * The index is starting from 0 to the list length minus 1.
 * No duplicates in both lists.
 * 
*/
/************************************************************************/
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
{
	unordered_map<string, int> udm;
	for (int i = 0; i < list1.size();i++)
	{
		udm.insert(unordered_map<string, int>::value_type(list1[i], i));
	}

	vector<string> vRes;
	int nMinIndexSum = INT_MAX;
	for (int i = 0; i < list2.size();i++)
	{
		
		if (udm.find(list2[i])!= udm.end())
		{
			int n = i + udm[list2[i]];
			if (nMinIndexSum > n)
			{
				vRes.clear();
				vRes.push_back(list2[i]);
				nMinIndexSum = n;
			}
			else if (nMinIndexSum == n)
			{
				vRes.push_back(list2[i]);
			}
		}
	}
	return vRes;
}

int main()
{
	vector<string> list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string> list2 = { "KFC", "Shogun", "Burger King" };
	vector<string> vRes = findRestaurant(list1, list2);
	return 0;
}