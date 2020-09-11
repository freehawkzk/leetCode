#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/************************************************************************/
/*
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
 * 
 * Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * 
 * Input:
 * [[0,0],[1,0],[2,0]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 * 
*/
/************************************************************************/
int numberOfBoomerangs(vector<pair<int, int>>& points) 
{
	return 0;
}

//约定8位二进制一个字符，之后跟随一个空格
char* binaryTdec(char* pbinary)
{
	std::string str = std::string(pbinary);
	std::string res;
	
	for (int i = 0; i < str.length(); i+=9)//i += 9是为了跳过一个字符和之后的空格
	{
		std::bitset<8> bs(str,i,8);//8位二进制一个字符
		res.push_back(bs.to_ulong());//将bitset转成字符输出
	}
	//将string转成char*输出
	char* pRes = new char[res.length()+1];
	memcpy(pRes, res.c_str(), res.length());
	pRes[res.length()] = '\0';
	return pRes;
}

int main()
{
	char p[] = "01110011 01101000 01110101 01110100 01100100 01101111 01110111 01101110 00100000 00101101 01110011 00100000 00101101 01110100 00100000 00110000 ";
	char* pRes = binaryTdec(p);
	std::cout << pRes << std::endl;
	delete[] pRes;
	pRes = NULL;
	return 0;
}