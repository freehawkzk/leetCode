#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;


int maxArea(vector<int>& height);

int maxArea(vector<int>& height)
{
	int nSize = height.size();
	if (nSize < 2)
	{
		return 0;
	}
	else if (nSize == 2)
	{
		return fmin(height[0], height[1]);
	}
	else
	{
		int nMaxArea = -1;
		int nL = 0;
		int nR = nSize - 1;
		for (; nL < nR;)
		{
			if (height[nL] < height[nR])
			{
				int nArea = height[nL] * (nR - nL);
				if (nArea > nMaxArea)
					nMaxArea = nArea;
				int k = nL;
				while (k < nR && height[k] <= height[nL])
					k++;
				nL = k;
			}
			else
			{
				int nArea = height[nR] * (nR - nL);
				if (nArea > nMaxArea)
					nMaxArea = nArea;
				int k = nR;
				while (k > nL && height[k] <= height[nR])
					k--;
				nR = k;
			}
		}
		return nMaxArea;


	}
}

int main()
{
	int inputs[] = { 1, 2, 3, 4, 5, 3, 21, 5, 6, 20, 2, 1 };
	vector<int> height;
	vector<int> vResult;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]);i++)
	{
		height.push_back(inputs[i]);
	}

	int nMaxArea = maxArea(height);
	cout << nMaxArea << endl;
	return 0;
}