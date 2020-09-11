
/************************************************************************/
/* 
1095. 山脉数组中查找目标值

（这是一个 交互式问题 ）

给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。

如果不存在这样的下标 index，就请返回 -1。



所谓山脉数组，即数组 A 假如是一个山脉数组的话，需要满足如下条件：

首先，A.length >= 3

其次，在 0 < i < A.length - 1 条件下，存在 i 使得：

A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]



你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：

MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
MountainArray.length() - 会返回该数组的长度



注意：

对 MountainArray.get 发起超过 100 次调用的提交将被视为错误答案。此外，任何试图规避判题系统的解决方案都将会导致比赛资格被取消。

为了帮助大家更好地理解交互式问题，我们准备了一个样例 “答案”：https://leetcode-cn.com/playground/RKhe3ave，请注意这 不是一个正确答案。



示例 1：

输入：array = [1,2,3,4,5,3,1], target = 3
输出：2
解释：3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。

示例 2：

输入：array = [0,1,2,4,2,1], target = 3
输出：-1
解释：3 在数组中没有出现，返回 -1。



提示：

3 <= mountain_arr.length() <= 10000
0 <= target <= 10^9
0 <= mountain_arr.get(index) <= 10^9


*/
/************************************************************************/

#include <vector>
#include <iostream>


class MountainArray
{
    public:
        MountainArray() :nCount(0) {};
        int nCount;
        int get(int index)
        {
            nCount++;
            return v[index];
        };
        int length()
        {
            return v.size();

        };
        std::vector<int> v;
};

int findhelper(int target, MountainArray& mountainArr, int l, int r)
{
    return -1;
}
int checktype(int index, MountainArray &mountainArr)
{
    if (index == 0)
        return -1;
    else if (index == mountainArr.length() - 1)
        return 1;
    bool bl = mountainArr.get(index - 1) < mountainArr.get(index);
    bool br = mountainArr.get(index) > mountainArr.get(index + 1);
    if (bl&&br)
        return 0;
    else if (bl && !br)
        return -1;
    else
        return 1;
}
int findInMountainArray(int target, MountainArray &mountainArr) 
{
    int nLargestIndex = -1;
    int l = 0;
    int r = mountainArr.length();
    for (l =0;l<=r;)
    {
        int mid = (l + r) / 2;
        int hr = checktype(mid, mountainArr);
        if (hr == 0)
        {
            nLargestIndex = mid;
            break;
        }
        else if (hr < 0)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    l = 0;
    r = nLargestIndex;
    int hr = -1;
    for (;l<=r;)
    {
        int mid = (l + r) / 2;
        if (mountainArr.get(mid) == target)
            return mid;
        else if (mountainArr.get(mid) < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    l = nLargestIndex;
    r = mountainArr.length() - 1;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (mountainArr.get(mid) == target)
            return mid;
        else if (mountainArr.get(mid) > target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    //std::vector<int> v = { 1,2,3,4,5,10,8,4,3,2,1,-1 };
    std::vector<int> v = { 0,5,3,1 };
    MountainArray m;
    for (int i = 0;i< v.size();i++)
    {
        m.v.push_back(v[i]);
    }
    int target = 9;
    int nindex = findInMountainArray(target, m);
    std::cout << nindex <<"  "<<m.nCount<< std::endl;
    return 0;
}