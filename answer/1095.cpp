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