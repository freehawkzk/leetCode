#include<string>
#include <iostream>

int strStr(std::string haystack, std::string needle)
{
    if (needle.length() == 0)
        return 0;

    if (haystack.length() < needle.length())
        return -1;

    int nindex = 0;
    for (;nindex <= haystack.length()-needle.length();nindex++)
    {
        if(haystack[nindex]!=needle[0])
            continue;
        int nmatch = 0;
        for (int i = 0;i<needle.length(); i++)
        {
            if (needle[i] == haystack[nindex + i])
            {
                nmatch++;
                continue;
            }
        }
        if (nmatch == needle.length())
            return nindex;
    }
    return -1;
}

int main()
{


    std::string haystack = { "mississippi" };
    std::string needle = { "issip" };
    int nindex = strStr(haystack, needle);
    std::cout << nindex << std::endl;
    return 0;
}