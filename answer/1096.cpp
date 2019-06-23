#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <iostream>
void matchfirstbrace(std::vector<std::string>& strs)
{
    for (int index = 0; index < strs.size() ; index++)
    {
        std::string& str = strs[index];
        size_t posleft = str.find('{');
        if(posleft == std::string::npos)
            continue;

        int nl = 0;
        int nr = 0;
        std::stack<char> s;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != '}')
            {

                s.push(str[i]);
            }
            else
            {
                nr = i;
                nl = nr - 1;
                char c = s.top();
                while (c != '{')
                {
                    s.pop();
                    nl--;
                    c = s.top();
                }
                nl++;
                break;
            }
        }

        std::string stemp = str.substr(nl, nr - nl);
        std::string pre = str.substr(0, nl - 1);
        std::string post = str.substr(nr + 1, str.length() - nr);
        strs.erase(strs.begin() + index);
        std::vector<std::string > res;
        size_t pos = stemp.find(',');
        while (pos != std::string::npos)
        {
            std::string s1 = stemp.substr(0, pos);
            res.push_back(s1);
            stemp = stemp.substr(pos + 1, stemp.length());
            pos = stemp.find(',');
        }
        res.push_back(stemp);
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = pre + res[i] + post;
            strs.push_back(res[i]);
        }
        index--;
    }
    
}

std::vector<std::string> braceExpansionII(std::string expression) 
{
    std::vector<std::string> res;//
    size_t nSize = 1;
    while (1)
    {
        size_t pos = expression.find(" ");    //  尤其是这里
        if (pos != std::string::npos)
        {
            expression.erase(pos, nSize);
        }
        else
            break;
       
    }
    res.push_back(expression);
    matchfirstbrace(res);
    std::sort(res.begin(), res.end());
    std::map<std::string,int> mmap;
    for (int i = 0;i< res.size();i++)
    {
        mmap[res[i]] = 1;
    }
    std::vector<std::string> res1;
    for (std::map<std::string,int>::iterator itor = mmap.begin();itor!=mmap.end();itor++)
    {
        res1.push_back(itor->first);
    }
    return res1;
}

int main()
{
    //std::string expression("{{c,b,a}{a,bbbbbb}{c{d,e}}}");
//    std::string expression("{{a,z}, a{b,c}, {ab,z}}");
    std::string expression("{}");
    std::vector<std::string> res = braceExpansionII(expression);
    for (int i = 0;i< res.size(); i++)
    {
        std::cout << res[i] << std::endl;
    }
    return 0;
}