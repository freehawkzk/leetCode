#include <string>
#include <iostream>
#include <stack>

bool isValid(std::string s) 
{
    std::stack<char> ss;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')' || s[i] =='}'||s[i]==']')
        {
            if (!ss.empty())
            {
                char c = ss.top();
                if ((c != '('&&s[i]==')') || (c != '['&&s[i] == ']') || (c != '{'&&s[i] == '}'))
                    return false;
                else
                {
                    ss.pop();
                }
            }
            else
                return false;
        }
        else
            ss.push(s[i]);
    }
    if (ss.empty())
        return true;
    return true;
}

int main()
{
    std::string s = "([{([)}])";
    bool b = isValid(s);
    std::cout << b << std::endl;
    return 0;
}