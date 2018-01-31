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
* ����
* ����Ҫ����������ַ�����UDLR�����ַ�����Ŀ��ϵ������U��ʾ����һ����D��ʾ����һ����
* L��ʾ����һ����R��ʾ����һ�����������γ�Ȧʱ����ԭ��λ�ã���ôU����Ŀ����D����Ŀ��
* L����Ŀ����R����Ŀ����ˣ�����ͨ��ɨ��һ���ַ����ó������ַ�����Ŀ���ٱȽ���Ŀ�Ƿ�
* ��ȣ��ó������
*/
/************************************************************************/
bool judgeCircle(string moves) {

	int nCountU = 0, nCountD = 0, nCountL = 0, nCountR = 0;
	if (moves.length() <= 0)//��Ч�Լ���
	{
		return true;
	}
	for (int i = 0; i < moves.length(); i++)//ͳ�������ַ���Ŀ
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