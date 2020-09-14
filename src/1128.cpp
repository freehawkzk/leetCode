/*
1128. 等价多米诺骨牌对的数量

给你一个由一些多米诺骨牌组成的列表 dominoes。
如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。
形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。
在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

示例：

输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
输出：1

提示：
    1 <= dominoes.length <= 40000
    1 <= dominoes[i][j] <= 9
*/
#include <vector>
#include <map>
using std::vector;
using std::map;

//
class Solution1 {
public:
    std::vector<int> adj(std::vector<int>& a){
        if(a[0]>a[1]){
            int temp = a[0];
            a[0] = a[1];
            a[1] = temp;
        }
        return a;
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        if(dominoes.size()<=1)
            return 0;
        std::map<std::vector<int>,int> temp;
        for(int i=0;i<dominoes.size();i++){
            auto a = adj(dominoes[i]);
            if(temp.find(a)!=temp.end())
                temp[a]+=1;
            else
                temp[a]=1;
        }
        int result = 0;
        for(auto it = temp.begin(); it != temp.end(); it++){
            if(it->second>=2)
                result += (it->second*(it->second-1)/2);
        }
        return result;
    }
};

class Solution2 {
//执行用时：96 ms, 在所有 C++ 提交中击败了67.70% 的用户
//内存消耗：17.3 MB, 在所有 C++ 提交中击败了86.74% 的用户
public:
    int adj(std::vector<int>& a){
        if(a[0]>a[1]){
            return a[1]*10+a[0];
        }
        return a[0]*10+a[1];
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        if(dominoes.size()<=1)
            return 0;
        std::unordered_map<int,int> temp;
        for(int i=0;i<dominoes.size();i++){
            auto a = adj(dominoes[i]);
            if(temp.find(a)!=temp.end())
                temp[a]+=1;
            else
                temp[a]=1;
        }
        int result = 0;
        for(auto it = temp.begin(); it != temp.end(); it++){
            if(it->second>=2)
                result += (it->second*(it->second-1)/2);
        }
        return result;
    }
};

class Solution3 {
    //执行用时：76 ms, 在所有 C++ 提交中击败了93.26% 的用户
    //内存消耗：17.4 MB, 在所有 C++ 提交中击败了83.98% 的用户
public:
    int adj(std::vector<int>& a){
        if(a[0]>a[1]){
            return a[1]*10+a[0];
        }
        return a[0]*10+a[1];
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        if(dominoes.size()<=1)
            return 0;
        int result = 0;
        std::vector<int> res(100,0);
        for(int i=0;i<dominoes.size();i++){
            res[adj(dominoes[i])]++;
        }
        for(int i=0;i<res.size();i++){
            result += (res[i]*(res[i]-1)/2);
        }
        return result;
    }
};