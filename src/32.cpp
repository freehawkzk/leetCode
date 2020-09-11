#include <string>
#include <vector>
#include <iostream>
#include <stack>
int longestValidParentheses(std::string s)
{
    std::stack<char> sstack;
    std::stack<int> nstack;
    std::vector<bool> vbs(s.length(), false);
    int nCurrMax = 0;
    for (int i = 0;i<s.length();i++)
    {
        if (nstack.empty())
        {
            nstack.push(i);
            sstack.push(s[i]);
        }
        else
        {
            if (s[i]==')')
            {
                if (sstack.top() == '(')
                {
                    vbs[nstack.top()] = true;
                    vbs[i] = true;
                    nstack.pop();
                    sstack.pop();
                }
            }
            else
            {
                nstack.push(i);
                sstack.push(s[i]);
            }
        }
    }
    for (int i = 0;i< vbs.size();i++)
    {
        if (vbs[i]==true)
        {
            for (int j=i+1;j<vbs.size();j++)
            {
                if (vbs[j] == true)
                {
                    if (nCurrMax < (j - i))
                        nCurrMax = j - i+1 ;
                    
                }
                else
                {
                    i = j;
                    break;
                }
                
            }
        }
    }
    return nCurrMax;
}

int main()
{
    std::string s = { "()" };
    int n = longestValidParentheses(s);
    std::cout << n << std::endl;
    return 0;
}