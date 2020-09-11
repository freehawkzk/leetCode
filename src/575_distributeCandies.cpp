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
 * Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
 * 
 * Example 1:
 * 
 * Input: candies = [1,1,2,2,3,3]
 * Output: 3
 * Explanation:
 * There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
 * Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too.
 * The sister has three different kinds of candies.
 * 
 * Example 2:
 * 
 * Input: candies = [1,1,2,3]
 * Output: 2
 * Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1].
 * The sister has two different kinds of candies, the brother has only one kind of candies.
 * 
 * Note:
 * 
 * The length of the given array is in range [2, 10,000], and will be even.
 * The number in given array is in range [-100,000, 100,000].

 * 分析
 * 题干意思：数组中每个不同的数表示一种糖果。给出的数组是偶数项的。要求将数组平均分成两份，分别给sister和brother，
 * 要求sister最多能得到几种糖果。
 * 意思是：
 * 将一个偶数项数组，按照项数平均分成两份，要求其中一份最多有多少个不同的项。
 *
 * 思路：
 * 1、总项数为n的数组，分成两份，每份项数为n/2，那么最多可以有n/2种；
 * 2、由于涉及到要对项的相同和不同信息进行记录，因此可以考虑采用map或bitset进行记录
 * 3、遍历数组时，先检查该项是否在数据记录中出现过，没出现过的话，种类+1并记录，出现过则跳过；
 * 4、最终总类数为该数组中所有的元素种类；
 * 5、若总类数大于n/2，则输出n/2；否则输出总类数。

 * 后记
 * 经过实验比较，本题中使用map的效率远低于使用bitset。
*/
/************************************************************************/
int distributeCandies(vector<int>& candies) {
	//map<int, int> mCandies;
	//for (int i = 0; i < candies.size(); i++)
	//{
	//	if (mCandies.find(candies[i]) == mCandies.end())
	//	{
	//		mCandies.insert(map<int, int>::value_type(candies[i], 0));
	//	}
	//}

	//if (mCandies.size() >= candies.size() / 2)
	//{
	//	return candies.size() / 2;
	//}
	//else
	//{
	//	return mCandies.size();
	//}

	bitset<200001> bs;//数值取值范围为-100000 到 +100000
	int nKind = 0;
	for (auto x : candies)//遍历输入数组
	{
		nKind += !bs.test(x + 100000);//查找并累加新出现的类别
		bs.set(x + 100000);//记录信息
	}
	return nKind>candies.size() / 2 ? candies.size()/2 : nKind;
}
int main()
{
	vector<int> candies = {1,1,2,3};
	int x = distributeCandies(candies);
	return 0;
}