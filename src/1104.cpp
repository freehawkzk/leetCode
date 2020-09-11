#include <vector>
#include <iostream>

std::vector<int> distributeCandies(int candies, int num_people) 
{
    std::vector<int> res(num_people, 0);
    int nSum = 0;
    int k = 0;
    for (int i=0;;)
    {
        if (nSum < candies)
        {
            if (k*num_people + i +1> candies - nSum)
            {
                res[i] = res[i]+candies - nSum;
                break;
            }
            else
            {
                int temp = res[i];
                res[i] = res[i]+ k*num_people + i+1;
                nSum = nSum - temp+ res[i];
                
            }
        }
        else
        {
            break;
        }
        if (i==num_people-1)
        {
            i = 0;
            k++;
        }
        else
        {
            i++;
        }
    }
    return res;
}

int main()
{
    int candies = 60;
    int num_people = 4;
    std::vector<int> res = distributeCandies(candies, num_people);
    for each (auto var in res)
    {
        std::cout << var << std::endl;
    }
    return 0;
}