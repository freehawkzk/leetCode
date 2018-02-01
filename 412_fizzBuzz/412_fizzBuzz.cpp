#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
using namespace std;
/************************************************************************/
/*
 * Write a program that outputs the string representation of numbers from 1 to n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 * "1",
 * "2",
 * "Fizz",
 * "4",
 * "Buzz",
 * "Fizz",
 * "7",
 * "8",
 * "Fizz",
 * "Buzz",
 * "11",
 * "Fizz",
 * "13",
 * "14",
 * "FizzBuzz"
 * ]
 * 分析
 * 题目要求将数字1到n转换成字符串输出，其中要求：
 * 1、能被3整除的输出"Fizz";
 * 2、能被5整除的输出"Buzz";
 * 3、同时被3和5整除的输出"FizzBuzz";
 * 4、其余输出数字
 *
 * 思路
 * 1、数字转字符串 std::to_string()；
 * 2、有限个特殊字符串，使用查表；
 * 3、由于同时被3和5整除的需要输出FizzBuzz，所以需要先处理被3整除再处理被5整除；
*/
/************************************************************************/
vector<string> fizzBuzz(int n) {
	vector<string> vRes;
	string sTemp[3] = { "Fizz", "Buzz", "FizzBuzz" };
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			vRes.push_back(sTemp[2]);
		}
		else if (i % 3 == 0)
		{
			vRes.push_back(sTemp[0]);
		}
		else if (i % 5 == 0)
		{
			vRes.push_back(sTemp[1]);
		}
		else
		{
			vRes.push_back(std::to_string(i));
		}
	}
	return vRes;
}
int main()
{
	vector<string> vRes = fizzBuzz(15);
	return 0;
}