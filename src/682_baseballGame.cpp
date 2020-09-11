#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
using namespace std;
/************************************************************************/
/*
 * You're now a baseball game point recorder.
 * 
 * Given a list of strings, each string can be one of the 4 following types:
 * 
 * Integer (one round's score): Directly represents the number of points you get in this round.
 * "+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
 * "D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
 * "C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
 * 
 * Each round's operation is permanent and could have an impact on the round before and the round after.
 * 
 * You need to return the sum of the points you could get in all the rounds.
 * 
 * Example 1:
 * 
 * Input: ["5","2","C","D","+"]
 * Output: 30
 * Explanation:
 * Round 1: You could get 5 points. The sum is: 5.
 * Round 2: You could get 2 points. The sum is: 7.
 * Operation 1: The round 2's data was invalid. The sum is: 5.
 * Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
 * Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
 * 
 * Example 2:
 * 
 * Input: ["5","-2","4","C","D","9","+","+"]
 * Output: 27
 * Explanation:
 * Round 1: You could get 5 points. The sum is: 5.
 * Round 2: You could get -2 points. The sum is: 3.
 * Round 3: You could get 4 points. The sum is: 7.
 * Operation 1: The round 3's data is invalid. The sum is: 3.
 * Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
 * Round 5: You could get 9 points. The sum is: 8.
 * Round 6: You could get -4 + 9 = 5 points. The sum is 13.
 * Round 7: You could get 9 + 5 = 14 points. The sum is 27.
 * 
 * Note:
 * The size of the input list will be between 1 and 1000.
 * Every integer represented in the list will be between -30000 and 30000.
 * 分析
 * 计算垒球得分
 * 规则如下：
 * 1、数字，表示当前轮得分
 * 2、"C"，表示取消上一轮的成绩，需要从总成绩中进行相应的操作；
 * 3、"D"，本轮得分是上一个有效成绩的2倍；
 * 4、"+"，本轮得分是上两轮有效成绩之和。
 *
 * 思路
 * 由于存在取消成绩并回退成绩的操作，所以考虑采用栈存储每轮有效得分。
 * 数字，转换成分数入栈，总分累加；
 * C，栈顶分数出栈，总分扣减；
 * D，栈顶元素二倍入栈，总分累加；
 * +，栈顶两个元素入栈，总分累加。
*/
/************************************************************************/
int calPoints(vector<string>& ops)
{
	if (ops.size() == 0)//输入有效性检测
	{
		return 0;
	}
	int nPoints = 0;
	stack<int> nStackPoint;
	int nSum = 0;
	for (int i = 0; i < ops.size(); i++)//遍历操作数组
	{
		if (ops[i]=="C")
		{
			if (!nStackPoint.empty())
			{
				int nTop = nStackPoint.top();//栈顶出栈
				nStackPoint.pop();
				nSum -= nTop;//分数扣减
			}
			
		}
		else if (ops[i] == "D")
		{
			if (!nStackPoint.empty())
			{
				int nTop = nStackPoint.top();
				nSum += 2 * nTop;
				nStackPoint.push(2 * nTop);//栈顶2倍入栈
			}
		}
		else if (ops[i] == "+")
		{
			if (nStackPoint.size()>= 2)
			{
				int nTop1 = nStackPoint.top();
				nStackPoint.pop();
				int nTop2 = nStackPoint.top();
				nSum += (nTop1 + nTop2);
				nStackPoint.push(nTop1);
				nStackPoint.push(nTop1 + nTop2);//栈顶2次有效分数之和入栈
			}
			
		}
		else
		{
			int nTemp = std::stoi(ops[i]);
			nStackPoint.push(nTemp);//入栈
			nSum += nTemp;
		}
	}
	return nSum;
}
int main()
{
	vector<string> s = { "-27276", "D", "+", "+", "C", "D", "+", "-12178", "+", "+", "-20323", "-7421", "+", "C", "-10993", "+", "-9879", "-14593", "D", "8677", "C", "-17939", "17437", "-2684", "-23038", "D", "D", "-4392", "+", "C", "+", "-4750", "6731", "D", "21137", "D", "-16560", "-20500", "D", "+", "1861", "C", "-2627", "C", "D", "12210", "C", "-19271", "-9873", "-18831", "-20978", "+", "4228", "559", "-24728", "+", "-7746", "-6307", "23606", "C", "26513", "D", "13166", "+", "26096", "D", "-14110", "15671", "9599", "-21122", "+", "-5263", "+", "C", "+", "C", "9395", "14881", "2429", "D", "C", "D", "C", "+", "C", "7876", "+", "C", "14808", "-9801", "-16149", "D", "-4979", "-4227", "C", "C", "+", "-12441", "-13190", "D", "C", "25907", "810", "C", "D", "28586", "-12823", "D", "D", "6482", "D", "-85", "-519", "+", "D", "12750", "4140", "+", "C", "-4366", "D", "+", "20343", "+", "+", "20059", "+", "D", "-13480", "D", "-24672", "D", "C", "2865", "+", "C", "C", "+", "+", "C", "-8555", "-22539", "-15141", "-22613", "23415", "D", "19591", "6585", "C", "18754", "25246", "-25166", "C", "15185", "D", "+", "-9715", "-2997", "-4851", "-5425", "-28275", "12429", "23908", "-11980", "22831", "1041", "+", "D", "C", "D", "-5400", "+", "-14046", "-23895", "C", "11968", "D", "D", "-2228", "C", "-27389", "+", "+", "-20200", "D", "C", "28942", "-23540", "D", "-9557", "-24297", "-9587", "-29781", "D", "C", "21967", "D", "+", "+", "-7065" };
	int n = calPoints(s);
	return 0;
}