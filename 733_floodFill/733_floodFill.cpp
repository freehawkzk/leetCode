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
 * An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
 *
 * Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
 *
 * To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
 *
 * At the end, return the modified image.
 *
 * Example 1:
 *
 * Input:
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation:
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
 * by a path of the same color as the starting pixel are colored with the new color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally connected
 * to the starting pixel.
 *
 * Note:
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
 * The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
 *
 * 分析
 * 在图像中，从给定像素开始，按照4邻域的方式，将像素值等于初始位置像素值的像素改为给定像素值。
 *
 * 思路
 * 递归，注意递归退出条件是边界判断 + 像素值判断。
 * 注意，如果给定像素值与初始位置像素值相同，实际上不用处理，直接返回即可。
*/
/************************************************************************/
vector<vector<int>> myFloodFill(vector<vector<int>>& image, int sr, int sc, int startPixelColor, int newColor)
{
	if (sr < 0 || sc < 0 || sr >= image.size() || sc>= image[0].size())
	{
		return image;
	}
	if (image[sr][sc] == startPixelColor)
	{
		image[sr][sc] = newColor;
		image = myFloodFill(image, sr - 1, sc, startPixelColor, newColor);
		image = myFloodFill(image, sr , sc + 1, startPixelColor, newColor);
		image = myFloodFill(image, sr + 1, sc, startPixelColor, newColor);
		image = myFloodFill(image, sr , sc - 1, startPixelColor, newColor);
	}
	return image;
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
	int startPixelColor = image[sr][sc];
	if (startPixelColor == newColor)
	{
		return image;
	}
	return myFloodFill(image, sr, sc, startPixelColor, newColor);
}
int main()
{
	vector<vector<int>> image = { { 0,0 ,0}, { 0, 1,1 } };
	vector<vector<int>> image1 = floodFill(image, 1, 1, 1);
	return 0;
}