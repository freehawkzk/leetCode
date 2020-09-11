#include <vector>
#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	double dSize1 = nums1.size();
	double dSize2 = nums2.size();

	double dMedian = (dSize1 + dSize2) / 2;

	return 0;
}

int main()
{
	vector<int> nums1, nums2;
	
	nums1.push_back(1);
	nums1.push_back(3);
	nums1.push_back(5);
	nums1.push_back(7);

	nums2.push_back(2);
	nums2.push_back(4);
	nums2.push_back(6);
	nums2.push_back(8);

	double dMedian = findMedianSortedArrays(nums1, nums2);

	cout << dMedian << endl;


	return 0;
}