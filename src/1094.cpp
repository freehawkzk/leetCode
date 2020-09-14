
/************************************************************************/
/*
1094. ƴ��

��������һλ˳�糵˾������������� capacity ������λ���������ؿ͡����ڵ�·�����ƣ��� ֻ�� ��һ��������ʻ��Ҳ����˵����������ͷ��ı䷽������Խ�������Ϊһ����������

�����һ���г̼ƻ��� trips[][]������ trips[i] = [num_passengers, start_location, end_location] ��������ĵ� i ���г���Ϣ��

������͵ĳ˿�������
�˿͵��ϳ��ص㣻
�Լ��˿͵��³��ص㡣

��Щ�����ĵص�λ���Ǵ���� ��ʼ ����λ����ǰ��ʻ����Щ�ص�����ľ��루����һ���������ʻ�����ϣ���

������ݸ������г̼ƻ����ͳ��ӵ���λ�������ж���ĳ��Ƿ����˳����ɽ������ó˿͵����񣨵��ҽ�������������и������г��н������г˿�ʱ������ true�������뷵�� false����



ʾ�� 1��

���룺trips = [[2,1,5],[3,3,7]], capacity = 4
�����false

ʾ�� 2��

���룺trips = [[2,1,5],[3,3,7]], capacity = 5
�����true

ʾ�� 3��

���룺trips = [[2,1,5],[3,5,7]], capacity = 3
�����true

ʾ�� 4��

���룺trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
�����true



��ʾ��

����Լ���˿ͻ��Ծ����� �����º��ϡ� ����������
trips.length <= 1000
trips[i].length == 3
1 <= trips[i][0] <= 100
0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000


*/
/************************************************************************/

#include <vector>
#include <iostream>

bool carPooling(std::vector<std::vector<int>>& trips, int capacity)
{
    std::vector<int> vCurInCar(1001, 0);
    for (int i = 0;i < trips.size();i++)
    {
        for (int j = trips[i][1]; j < trips[i][2]; j++)
        {
            if (vCurInCar[j] + trips[i][0] > capacity)
                return false;
            else
                vCurInCar[j] += trips[i][0];
        }

    }
    return true;
}
int main()
{
    //std::vector<std::vector<int>> trips = { {2,1,5},{3,3,7} }; int capacity = 4;
     std::vector<std::vector<int>> trips = { { 2,1,5 },{ 3,3,7 } }; int capacity = 5;
     //std::vector<std::vector<int>> trips = { { 2,1,5 },{ 3,5,7 } }; int capacity = 3;
     //std::vector<std::vector<int>> trips = { { 3,2,7},{ 3,7,9 } ,{ 8,3,9 } }; int capacity = 11;
     //std::vector<std::vector<int>> trips = { { 7,5,6 },{ 6,7,8 } ,{ 10,1,6 } }; int capacity = 16;
    bool b = carPooling(trips, capacity);
    std::cout << b << std::endl;
    return 0;
}