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
 * But for multiples of three it should output ��Fizz�� instead of the number and for the multiples of five output ��Buzz��. For numbers which are multiples of both three and five output ��FizzBuzz��.
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
 * ����
 * ��ĿҪ������1��nת�����ַ������������Ҫ��
 * 1���ܱ�3���������"Fizz";
 * 2���ܱ�5���������"Buzz";
 * 3��ͬʱ��3��5���������"FizzBuzz";
 * 4�������������
 *
 * ˼·
 * 1������ת�ַ��� std::to_string()��
 * 2�����޸������ַ�����ʹ�ò��
 * 3������ͬʱ��3��5��������Ҫ���FizzBuzz��������Ҫ�ȴ���3�����ٴ���5������
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