#include <vector>

#include <iostream>

std::vector<int> searchRange(std::vector<int>& nums, int target) 
{
    int li = 0;
    int ri = nums.size() - 1;
    int l = 0;
    int r = nums.size() - 1;
    for (; l <= r; )
    {
        int n = (l + r) / 2;
        if (nums[n] < target)
            l = n+1;
        else if (nums[n] == target)
        {
            int l = 0;
            int r = n ;
            for (;l<=r;)
            {
                int n = (l + r) / 2;
                if (nums[n] < target)
                    l = n + 1;
                else if (nums[n] == target)
                    r = n - 1;
            }
            li = r+1;
            l = n ;
            r = nums.size() - 1;
            for (;l<=r;)
            {
                int n = (l + r) / 2;
                if (nums[n] == target)
                    l = n + 1;
                else if (nums[n] > target)
                    r = n - 1;
            }
            ri = l - 1;
            break;
        }
        else
        {
            r = n - 1;
        }
    }
    std::vector<int> res(2, 0);
    if (l > r)
    {
        res[0] = -1;
        res[1] = -1;
    }
    else
    {
        res[0] = li;
        res[1] = ri;
    }

    return res;
}

int main()
{
    std::vector<int> nums;// = { 5,7,7,8,8,8,8 };
    int target = 8;
    std::vector<int> res = searchRange(nums, target);
    for (int i = 0;i< res.size();i++)
    {
        std::cout << res[i] << std::endl;
    }
    return 0;
}