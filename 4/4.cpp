#include<iostream>
#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
{

    return 0;
}

int main()
{
    std::vector<int> nums1;
    std::vector<int> nums2;

    nums1.push_back(0);
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(4);
    nums1.push_back(5);
    nums1.push_back(9);


    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(5);
    nums2.push_back(6);
    nums2.push_back(8);
    nums2.push_back(10);

    double mid = findMedianSortedArrays(nums1, nums2);
    std::cout << mid << std::endl;
    return 0;
}