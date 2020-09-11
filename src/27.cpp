#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val)
{
    if (nums.size() == 0)
        return 0;
    int l = 0, r = nums.size() - 1;
    int temp = nums[r];
    int nCount = nums.size();
    for (l = 0; l <= r; l++)
    {
        if (nums[l] != val)
            continue;
        else
        {
            nCount--;
            while (r > l&&nums[r] == val&&nCount >= 0)
            {
                nCount--;
                r--;
            }

            temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            r--;


        }
    }
    return nCount;
}

int main()
{
    std::vector<int> nums = { 1 };
    int val = 1;
    int n = removeElement(nums, val);
    for (int i = 0; i < n; i++)
    {
        std::cout << nums[i] << std::endl;
    }
    return 0;
}