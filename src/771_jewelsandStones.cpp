#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int numJewelsInStones(string J, string S);
/************************************************************************/
/* 
 * 思路
 * 此题要求从字符串S中统计字符串J中所有字符出现的次数。由于题目保证字符串J中
 * 字符出现的次数是唯一的，因此不需要对字符串J进行排序。
 * 1、对输入进行有效性判断；
 * 2、对字符串S进行排序，使字符串中所有相同字符是连续的；
 * 3、在排序后的字符串中，通过左查查找字符第一次出现位置；
 * 4、在排序后的字符串中，通过右查查找字符第一次出现位置；
 * 5、左右两次位置之差+1记为该字符出现的次数；
 * 6、将各个字符出现次数相加即可。
*/
/************************************************************************/
int numJewelsInStones(string J, string S) 
{
	//输入有效性判断
	if (J.length() <= 0 || S.length() <= 0)
	{
		return 0;
	}
	//排序S字符串
	sort(S.begin(), S.end());
	int nCount = 0;
	int nLeft = -1;
	int nRight = -1;
	for (int i = 0; i < J.length(); i++)//在S中查找J中每一个字符
	{
		nLeft = S.find(J[i]);//左查查找
		if (nLeft != std::string::npos)//左查找到了，才进行右查
		{
			nRight = S.rfind(J[i]);//右查查找
			nCount += (nRight - nLeft + 1);//累加字符数
			nRight = -1;//现场清理
			nLeft = -1;//现场清理
		}
	}

	return nCount;
}
int main()
{
	string J(" ");
	string S("azzAAZZ");
	int x = numJewelsInStones(J, S);
	return 0;
}