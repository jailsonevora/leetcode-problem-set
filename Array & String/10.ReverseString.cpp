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
    // Two Pointers
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size()-1; i < j; ++i,--j)
            std::swap(s[i],s[j]);
    }

    // with built-in
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    vector<char> v = {'H','a','n','n','a','h'};
    //vector<char> v = {'h','e','l','l','o'};

    sl.reverseString(v);
    for(char c: v)
        cout << c << "\n"; 
}