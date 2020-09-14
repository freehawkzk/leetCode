
/************************************************************************/
/*
1095. ɽ�������в���Ŀ��ֵ

������һ�� ����ʽ���� ��

����һ�� ɽ������ mountainArr�����㷵���ܹ�ʹ�� mountainArr.get(index) ���� target ��С ���±� index ֵ��

����������������±� index�����뷵�� -1��



��νɽ�����飬������ A ������һ��ɽ������Ļ�����Ҫ��������������

���ȣ�A.length >= 3

��Σ��� 0 < i < A.length - 1 �����£����� i ʹ�ã�

A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]



�㽫 ����ֱ�ӷ��ʸ�ɽ�����飬����ͨ�� MountainArray �ӿ�����ȡ���ݣ�

MountainArray.get(k) - �᷵������������Ϊk ��Ԫ�أ��±�� 0 ��ʼ��
MountainArray.length() - �᷵�ظ�����ĳ���



ע�⣺

�� MountainArray.get ���𳬹� 100 �ε��õ��ύ������Ϊ����𰸡����⣬�κ���ͼ�������ϵͳ�Ľ�����������ᵼ�±����ʸ�ȡ����

Ϊ�˰�����Ҹ��õ����⽻��ʽ���⣬����׼����һ������ ���𰸡���https://leetcode-cn.com/playground/RKhe3ave����ע���� ����һ����ȷ�𰸡�



ʾ�� 1��

���룺array = [1,2,3,4,5,3,1], target = 3
�����2
���ͣ�3 �������г��������Σ��±�ֱ�Ϊ 2 �� 5�����Ƿ�����С���±� 2��

ʾ�� 2��

���룺array = [0,1,2,4,2,1], target = 3
�����-1
���ͣ�3 ��������û�г��֣����� -1��



��ʾ��

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