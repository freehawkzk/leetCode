#include <vector>
#include <iostream>
#include <algorithm>
void nextPermutation(std::vector<int>& nums)
{
    if (nums.size() <= 1)
        return;

    int r = nums.size() - 1;
    bool bset = false;
    for (; r > 0; r--)
    {
        if (nums[r] > nums[r - 1])
        {
            bset = true;
            for (int r1 = nums.size() - 1; r1 > 0; r1--)
            {
                if (nums[r1] > nums[r - 1])
                {
                    int temp = nums[r1];
                    nums[r1] = nums[r - 1];
                    nums[r - 1] = temp;
                    break;
                }
            }
            for (int k = r, m = nums.size() - 1; k < m; k++, m--)
            {
                int temp = nums[k];
                nums[k] = nums[m];
                nums[m] = temp;
            }
            break;
        }
    }
    if (!bset)
        std::sort(nums.begin(), nums.end());

}

int main()
{
    std::vector<int> nums =  { 2,3,1 ,4,4,2,3,4};
    std::vector<int> nums1 = nums;
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << std::endl;
    }
    std::cout << std::endl;
    std::next_permutation(nums1.begin(), nums1.end());
    for (int i = 0; i < nums1.size(); i++)
    {
        std::cout << nums1[i] << std::endl;
    }
    return 0;
}