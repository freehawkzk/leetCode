#include <vector>
#include <iostream>
#include <algorithm>


std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
  
    std::vector<std::vector<int>> result;
            int i = 0, j = 0, k = 0, target = 0;
            sort(nums.begin(), nums.end());  //对数组进行排序
            for (i = 0; i < nums.size(); i++) {
                if (nums[i] > 0)
                    break;
                else if (i > 0 && nums[i] == nums[i - 1])     //跳过重复元素
                    continue;
                target = -nums[i];  //更新target，转换为两数之和为target的问题
                j = i + 1;
                k = nums.size() - 1;
                while (j < k) {
                    if (nums[j] + nums[k] == target) {
                        result.push_back({ nums[i],nums[j],nums[k] });
                        while (j < k&&nums[j + 1] == nums[j]  ) ++j; //跳过重复元素
                        while (j < k&&nums[k - 1] == nums[k]  ) --k;  //跳过重复元素
                        ++j, --k;
                    }
                    else if (nums[j] + nums[k] > target)
                        --k;
                    else
                        ++j;
                }
            }
            return result;
        
}

int main()
{
    std::vector<int> nums = { 0,0,0    };
    std::vector<std::vector<int>> res = threeSum(nums);
    for each (auto var in res)
    {
        for each (auto var1 in var)
        {
            std::cout << var1<<" ";
        }
        std::cout << std::endl;
    }
    return 0;
}