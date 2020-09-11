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
 * You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
 * 
 * Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
 * 
 * For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
 *
 * 分析
 * 取石子游戏，每次能拿1,2,3个石子。谁最后取石子谁赢。
 * 给定石子数之后，快速判断先取得人能够赢得游戏。
 *
 * 思路
 * 由于4个石子时，先取的人必输，所以对于先取的人只要保证取完之后剩下4*n个石子即可赢得游戏。
 * 所以，只要给定的石子数m%4!=0,那么先取的人就能赢得游戏。
*/
/************************************************************************/

bool canWinNim(int n) {
	return n % 4 != 0;
}
int main()
{
	bool b = canWinNim(4);
	return 0;
}