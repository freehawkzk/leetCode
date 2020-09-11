#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> vResult;
	////思路1
	//if (nums.size() < 2)
	//{
	//	return vResult;
	//}

	////从头开始遍历数组，判断两数之和是否等于target
	//for (int i = 0; i < nums.size() - 1; i++)
	//{
	//	for (int j = i+1; j < nums.size();j++)
	//	{
	//		if (nums[i] + nums[j] == target)
	//		{
	//			vResult.push_back(i);
	//			vResult.push_back(j);
	//			return vResult;
	//		}
	//	}
	//}

	////思路2
	//if (nums.size() < 2)
	//{
	//	return vResult;
	//}
	//int nSize = nums.size();
	//int nSize_1 = nSize - 1;
	////从头开始遍历数组，判断两数之和是否等于target
	//for (int i = 0; i < nSize_1; i++)
	//{
	//	for (int j = i + 1; j <nSize; j++)
	//	{
	//		if (nums[i] + nums[j] == target)
	//		{
	//			vResult.push_back(i);
	//			vResult.push_back(j);
	//			return vResult;
	//		}
	//	}
	//}

	////思路3
	//if (nums.size() < 2)
	//{
	//	return vResult;
	//}
	//int nSize = nums.size();

	//map<int, int> hmap;
	//for (int i = 0; i < nSize;i++)
	//{
	//	if (!hmap.count(nums[i])) //检查nums[i]是否在map中，不在的话将nums[i]作为key,i作为value插入map中
	//	{
	//		hmap.insert(pair<int, int>(nums[i], i));//添加
	//	}
	//	//检查target-nums[i]是否在map中
	//	if (hmap.count(target-nums[i]))
	//	{
	//		int n = hmap[target - nums[i]]; //找到target-nums[i]所在的位置
	//		if (n < i)
	//		{
	//			vResult.push_back(n);
	//			vResult.push_back(i);
	//			return vResult;
	//		}

	//	}
	//}

	//思路4
	int n = nums.size();
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		if (mp.find(target - nums[i]) != mp.end())
		{
			vResult.push_back(mp[target - nums[i]]);
			vResult.push_back(i);
			return vResult;
		}
		mp[nums[i]] = i;
	}
	return vResult;
}

int main()
{
	int inputs[] = { 1, 2, 3, 4, 5, 10 };
	vector<int> nums;
	int nSize = sizeof(inputs) / sizeof(inputs[0]);
	int target = 8;
	for (int i = 0; i < nSize; i++)
	{
		nums.push_back(inputs[i]);
	}

	vector<int> vResult = twoSum(nums, target);

	for (int i = 0; i < vResult.size(); i++)
	{
		cout << vResult[i];
		if (i == vResult.size() -1)
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}
	}

	return 0;
}