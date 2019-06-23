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