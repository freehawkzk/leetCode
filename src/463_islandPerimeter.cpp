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
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 * 
 * Example:
 * 
 * [[0,1,0,0],
 * [1,1,1,0],
 * [0,1,0,0],
 * [1,1,0,0]]
 * 
 * Answer: 16
 *
 * ����
 * �������⣺
 * ������ά����0��ʾˮ��1��ʾ½�أ�������1���Ӷ��ɵĵ�����ܳ�����ν�ܳ���Ҳ����1��0�ķֽ����γɱߵı߳�֮�ͣ�ÿ���߳���Ϊ1��
 * 
 * ˼·��
 * ÿ��1��4���ߣ���4�����ڿ飬������ڿ�Ϊ1��������߲��������ܳ���
 * ���Էֱ���Ϊ1�Ŀ�����������ĸ��飬�ó���ǰΪ1�Ŀ��м����߿��Լ����ܳ���
*/
/************************************************************************/
int checkLeft(vector<vector<int>>& grid,int r, int c)
{
	if (c == 0)
		return 1;
	if (grid[r][c - 1] == 1)
		return 0;
	else
		return 1;
}
int checkRight(vector<vector<int>>& grid, int r, int c)
{
	if (c == grid[0].size()-1)
		return 1;
	if (grid[r][c + 1] == 1)
		return 0;
	else
		return 1;
}
int checkUp(vector<vector<int>>& grid, int r, int c)
{
	if (r == 0)
		return 1;
	if (grid[r-1][c] == 1)
		return 0;
	else
		return 1;
}
int checkDown(vector<vector<int>>& grid, int r, int c)
{
	if (r == grid.size()-1)
		return 1;
	if (grid[r+1][c] == 1)
		return 0;
	else
		return 1;
}
int islandPerimeter(vector<vector<int>>& grid) {
	int nSum = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 1)
			{
				nSum += (checkUp(grid, i, j) + checkLeft(grid, i, j) + checkDown(grid, i, j) + checkRight(grid, i, j));
			}
		}
	}
	return nSum;
}
int main()
{
	vector<vector<int>> grid = { { 0, 1, 0, 0 }, { 1, 1, 1, 0 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 0, 0 } };
	int nSum = islandPerimeter(grid);
	return 0;
}