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
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 *
 * ����
 * 26��������ת������
*/
/************************************************************************/
int titleToNumber(string s) 
{
	int sum = 0;
	char xx = 'A' - 1;
	for (auto x : s)
	{
		sum = sum * 26 + x -xx;
	}
	return sum;
}
int main()
{
	string s = "AB";
	int c = titleToNumber(s);
	return 0;
}