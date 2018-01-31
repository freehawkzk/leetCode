#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
/************************************************************************/
/*
 * Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
 * 
 * The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
 * 
 * Example 1:
 * 
 * Input: "UD"
 * Output: true
 * 
 * Example 2:
 * 
 * Input: "LL"
 * Output: false
 * 
* 分析
* 本题要求分析输入字符串中UDLR四种字符的数目关系。由于U表示上移一步，D表示下移一步，
* L表示左移一步，R表示右移一步，当最终形成圈时及在原点位置，那么U的数目等于D的数目，
* L的数目等于R的数目，因此，可以通过扫描一遍字符串得出四种字符的数目，再比较数目是否
* 相等，得出结果。
*/
/************************************************************************/
bool judgeCircle(string moves) {

	int nCountU = 0, nCountD = 0, nCountL = 0, nCountR = 0;
	if (moves.length() <= 0)//有效性检验
	{
		return true;
	}
	for (int i = 0; i < moves.length(); i++)//统计四种字符数目
	{
		switch (moves[i])
		{
		case 'U':
			nCountU++;
			break;
		case 'D':
			nCountD++;
			break;
		case 'L':
			nCountL++;
			break;
		case 'R':
			nCountR++;
			break;
		default:
			break;
		}
	}

	return nCountU == nCountD && nCountL == nCountR;
}
int main()
{
	string moves("UDULLDDRRU");
	bool x = judgeCircle(moves);

	return 0;
}