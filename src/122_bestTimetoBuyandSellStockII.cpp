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
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 * ����
 * ��������������ͬһ�죬��ˣ�ֻ��Ҫ���ǵ���������ɣ����Ա�֤�ڼ۸񼴽��µ���ʱ��ʱ������
 * ��ˣ����������Ǽ۸�����ʱ���У������ʱ������
 */
/************************************************************************/
int maxProfit(vector<int>& prices) {
	int sum = 0;
	int nSize = prices.size() - 1;
	for (int i = 0; i < nSize; i++)
	{
		if (prices[i] < prices[i+1])
		{
			sum += prices[i + 1] - prices[i];
		}
	}
	return sum;
}

int main()
{
	vector<int> prices = {};
	int s = maxProfit(prices);
	return 0;
}