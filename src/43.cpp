#include <vector>
#include <string>
#include <iostream>
const int mulval0[10][10] = { {0,0,0,0,0,0,0,0,0,0},
                            {0,1,2,3,4,5,6,7,8,9},
                            {0,2,4,6,8,0,2,4,6,8},
                            {0,3,6,9,2,5,8,1,4,7},
                            {0,4,8,2,6,0,4,8,2,6},
                            {0,5,0,5,0,5,0,5,0,5},
                            {0,6,2,8,4,0,6,2,8,4},
                            {0,7,4,1,8,5,2,9,6,3},
                            {0,8,6,4,2,0,8,6,4,2},
                            {0,9,8,7,6,5,4,3,2,1} };

const int mulval1[10][10] = { {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,1,1,1,1,1},
                            {0,0,0,0,1,1,1,2,2,2},
                            {0,0,0,1,1,2,2,2,3,3},
                            {0,0,1,1,2,2,3,3,4,4},
                            {0,0,1,1,2,3,3,4,4,5},
                            {0,0,1,2,2,3,4,4,5,6},
                            {0,0,1,2,3,4,4,5,6,7},
                            {0,0,1,2,3,4,5,6,7,8} };
std::string multiply(std::string num1, std::string num2)
{
    if (num1.length()==0 || num2.length()==0)
        return std::string("0");
    if (num1[0] == '0' || num2[0] == '0')
        return std::string("0");

    std::string v(num1.length() + num2.length(), 0);
    for (int i = 0;i< num1.length();i++)
        num1[i] -= '0';
    for (int i = 0; i< num2.length();i++)
        num2[i] -= '0';

    for (int r2 = num2.length()-1; r2>=0;r2--)
    {
        for (int r1 = num1.length()-1; r1>=0;r1--)
        {
            int vmul1 = mulval1[num1[r1]][num2[r2]];
            int vmul0 = mulval0[num1[r1]][num2[r2]];
            int ni = r1 + 1 + r2;
            v[ni] += vmul0;
            v[ni-1] += vmul1;
            for (int i = ni;i>0;i--)
            {
                if (v[i] >= 10)
                {
                    v[i - 1] += (v[i] / 10);
                    v[i] = v[i] % 10;
                    if(v[i-1]<10)
                        break;
                }
            }
        }
    }
    std::string res;
    for (int i = 0;i< v.size();i++)
    {
        if (res.empty() && v[i] == 0)
            continue;
        else
            res.push_back(v[i] + '0');
    }

    return res;
}

int main()
{
    std::string num1 = { "1244444444443" };
    std::string num2 = { "4444" };
    std::string res = multiply(num1, num2);
    std::cout << res << std::endl;
    return 0;
}