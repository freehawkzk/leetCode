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
 * 分析
 * 由于允许买卖在同一天，因此，只需要考虑低买高卖即可，可以保证在价格即将下跌的时候即时卖出，
 * 因此，最大收益就是价格上涨时持有，在最高时卖出。
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