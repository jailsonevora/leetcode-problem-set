#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {

        unordered_map<char, int> tmp;

        for(auto str: s)
            tmp[str]++;

        int val = tmp[s[0]];
        for (auto [key, value] : tmp) 
            if (value != val) 
                return false;
        return true; 
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    //string s = "abacbc";
    string s = "aaabb";

    Solution sl;
    cout << sl.areOccurrencesEqual(s);
}