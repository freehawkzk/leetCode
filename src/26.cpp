#include<vector>
#include <iostream>
#include <algorithm>
int removeDuplicates(std::vector<int>& nums) 
{
    if (nums.size() <= 0)
        return 0;
    int temp = 0;
    int l = 0;
    int r = nums.size() - 1;
    int n = nums.size();
    for (; l <nums.size();l++)
    {
        for (int l1 = l+1;l1<nums.size();l1++)
        {
            if (nums[l1]==nums[l])
            {
                for (; r >= l1; r--)
                {
                    if (nums[r]==nums[r-1])
                    {
                        n--;
                        continue;
                    }
                    if(nums[r]==nums[l1])
                    {
                        n--;
                        continue;
                    }
                    else
                    {
                        temp = nums[l1];
                        nums[l1] = nums[r];
                        nums[r] = temp;
                        n--;
                        r--;
                        break;
                    }
                }
            }
            else
                break;
        }
    }
    std::sort(nums.begin(), nums.begin() + n);
    return n;
}
int main()
{
    std::vector<int> nums = { 1 };
    //std::vector<int> nums = { 1,2,3,3,4,5,5,6,6,6,6,7,8,9,9,9,9,9,9 };
    //std::vector<int> nums = { 1,2,3,3,4,5,5,6,6,6,6,7,8,9,9,9,9,9,9 };
    //std::vector<int> nums = { 1,2,3,3,4,5,5,6,6,6,6,7,8,9,9,9,9,9,9 };
    //std::vector<int> nums = { 1,2,3,3,4,5,5,6,6,6,6,7,8,9,9,9,9,9,9 };
    int n = removeDuplicates(nums);
    for (int i = 0;i < n; i++)
    {
        std::cout << nums[i] << std::endl;
    }
    return 0;
}