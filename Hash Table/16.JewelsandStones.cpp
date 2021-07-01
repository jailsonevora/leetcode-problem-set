#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char,int> mp;

        for (int i = 0; i < jewels.size(); i++)
            mp.insert(make_pair(jewels[i],0));

        for (int i = 0; i < stones.size(); i++)
            if(mp.count(stones[i]))
                mp[stones[i]]++;
        int sum = 0;
        for (auto& val : mp)
            sum +=val.second;
        return sum;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string jewels = {"aA"}, stones = {"aAAbbbb"};
    Solution s;
    s.numJewelsInStones(jewels,stones);

}