#include <string>
#include<vector>
#include <algorithm>
#include <iostream>
std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
    if (s.length() == 0)
        return std::vector<int>();
    if (words.size() == 0)
        return std::vector<int>();
    std::string s0 = s;
    std::vector<int> res;
    std::string t;
    std::sort(words.begin(), words.end());
    for (int i = 0;i< words.size();i++)
    {
        t += words[i];
    }
    size_t pos = std::string::npos;
    int n = 0;
    while (( pos = s.find(t))!=std::string::npos)
    {
        if (res.size() == 0)
            res.push_back(pos);
        else
            res.push_back(pos + n);
        n=n+pos+1;
        s = s.substr(pos+1, s.length());
    }
    while (std::next_permutation(words.begin(),words.end()))
    {
        std::string t;
        for (int i = 0; i < words.size(); i++)
        {
            t += words[i];
        }
        size_t pos = std::string::npos;
        
        s = s0;
        std::vector<int> res1;
        int n = 0;
        while ((pos = s.find(t)) != std::string::npos)
        {
            if (res1.size() == 0)
                res1.push_back(pos);
            else
                res1.push_back(pos +n);
            n=n+pos+1;
            s = s.substr(pos+1, s.length());
        }
        for (int i = 0;i<res1.size();i++)
        {
            res.push_back(res1[i]);
        }
    }
    return res;
}
int main()
{

    std::string s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
    std::vector<std::string> words = { "dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb" };
    std::vector<int> v = findSubstring(s, words);
    for (int i = 0;i<v.size();i++)
    {
        std::cout << v[i] << std::endl;
    }
    return 0;
}