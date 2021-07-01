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
            mp[stones[i]]++;        
        return 0;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    
}