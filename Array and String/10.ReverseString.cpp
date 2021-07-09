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
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    //vector<string> v = {"flower","flow","flight"};
    //vector<string> v = {"dog","racecar","car"};
    //vector<string> v = {""};
    vector<string> v = {"flower","flawer","flvwer","flower"};

    cout << sl.longestCommonPrefix(v);
}