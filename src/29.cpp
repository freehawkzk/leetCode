#include <vector>
#include <iostream>

int divide(int dividend, int divisor)
{
    std::vector<int> v,v1;
    bool s0 = dividend > 0;
    bool s1 = divisor > 0;
    if (!s0)
    {
        dividend = dividend & 0x7fffffff;
        dividend = dividend - 1;
        dividend = ~dividend;
    }
    if (!s1)
    {
        divisor = divisor & 0x7fffffff;
        divisor = (divisor - 1) & 0x7fffffff;
        divisor = ~divisor;
    }
    bool sign = (dividend&(0x0001 << 31)) ^ (divisor&(0x0001 << 31));
    dividend = fabs(dividend);
    divisor = fabs(divisor);
    if (dividend < divisor)
        return 0;
    v.push_back(divisor);
    v1.push_back(1);
    int a = v[v.size() - 1] + v[v.size() - 1];
    while ( a< dividend)
    {
        v.push_back(v[v.size() - 1] + v[v.size() - 1]);
        v1.push_back(v1[v1.size() - 1] + v1[v1.size() - 1]);
        a = a + a;
        if(a < 0)
            break;
    }
    int res = 0;
    for (int i=v.size()-1;i>=0;i--)
    {
        
        if (dividend - v[i] >= 0)
        {
            res += v1[i];
            dividend = dividend - v[i];
        }
    }
    return sign?-res:res;
}

int main()
{
        

    signed int dividend = 0xbfffffff;
    signed int divisor = 0x80000000;
    int h = divide(dividend, divisor);
    std::cout << h << std::endl;
    return 0;
}