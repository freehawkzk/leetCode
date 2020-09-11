/************************************************************************/
/* 
1096. 花括号展开 II

如果你熟悉 Shell 编程，那么一定了解过花括号展开，它可以用来生成任意字符串。

花括号展开的表达式可以看作一个由 花括号、逗号 和 小写英文字母 组成的字符串，定义下面几条语法规则：

如果只给出单一的元素 x，那么表达式表示的字符串就只有 "x"。
例如，表达式 {a} 表示字符串 "a"。
而表达式 {ab} 就表示字符串 "ab"。
当两个或多个表达式并列，以逗号分隔时，我们取这些表达式中元素的并集。
例如，表达式 {a,b,c} 表示字符串 "a","b","c"。
而表达式 {a,b},{b,c} 也可以表示字符串 "a","b","c"。
要是两个或多个表达式相接，中间没有隔开时，我们从这些表达式中各取一个元素依次连接形成字符串。
例如，表达式 {a,b}{c,d} 表示字符串 "ac","ad","bc","bd"。
表达式之间允许嵌套，单一元素与表达式的连接也是允许的。
例如，表达式 a{b,c,d} 表示字符串 "ab","ac","ad"​​​​​​。
例如，表达式 {a{b,c}}{{d,e}f{g,h}} 可以代换为 {ab,ac}{dfg,dfh,efg,efh}，表示字符串 "abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"。

给出表示基于给定语法规则的表达式 expression，返回它所表示的所有字符串组成的有序列表。

假如你希望以「集合」的概念了解此题，也可以通过点击 “显示英文描述” 获取详情。



示例 1：

输入："{a,b}{c{d,e}}"
输出：["acd","ace","bcd","bce"]

示例 2：

输入："{{a,z}, a{b,c}, {ab,z}}"
输出：["a","ab","ac","z"]
解释：输出中 不应 出现重复的组合结果。



提示：

1 <= expression.length <= 50
expression[i] 由 '{'，'}'，',' 或小写英文字母组成
给出的表达式 expression 用以表示一组基于题目描述中语法构造的字符串


*/
/************************************************************************/

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