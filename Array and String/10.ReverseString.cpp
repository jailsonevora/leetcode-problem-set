#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = s[0], j = s.size()-1; i < j; ++i,++j)
            std::swap(s[i],s[j]);
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    //vector<string> v = {'H','a','n','n','a','h'};
    vector<char> v = {'h','e','l','l','o'};

    sl.reverseString(v);
}