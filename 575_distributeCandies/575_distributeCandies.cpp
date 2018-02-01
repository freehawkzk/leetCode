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

 * ����
 * �����˼��������ÿ����ͬ������ʾһ���ǹ���������������ż����ġ�Ҫ������ƽ���ֳ����ݣ��ֱ��sister��brother��
 * Ҫ��sister����ܵõ������ǹ���
 * ��˼�ǣ�
 * ��һ��ż�������飬��������ƽ���ֳ����ݣ�Ҫ������һ������ж��ٸ���ͬ���
 *
 * ˼·��
 * 1��������Ϊn�����飬�ֳ����ݣ�ÿ������Ϊn/2����ô��������n/2�֣�
 * 2�������漰��Ҫ�������ͬ�Ͳ�ͬ��Ϣ���м�¼����˿��Կ��ǲ���map��bitset���м�¼
 * 3����������ʱ���ȼ������Ƿ������ݼ�¼�г��ֹ���û���ֹ��Ļ�������+1����¼�����ֹ���������
 * 4������������Ϊ�����������е�Ԫ�����ࣻ
 * 5��������������n/2�������n/2�����������������

 * ���
 * ����ʵ��Ƚϣ�������ʹ��map��Ч��Զ����ʹ��bitset��
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

	bitset<200001> bs;//��ֵȡֵ��ΧΪ-100000 �� +100000
	int nKind = 0;
	for (auto x : candies)//������������
	{
		nKind += !bs.test(x + 100000);//���Ҳ��ۼ��³��ֵ����
		bs.set(x + 100000);//��¼��Ϣ
	}
	return nKind>candies.size() / 2 ? candies.size()/2 : nKind;
}
int main()
{
	vector<int> candies = {1,1,2,3};
	int x = distributeCandies(candies);
	return 0;
}