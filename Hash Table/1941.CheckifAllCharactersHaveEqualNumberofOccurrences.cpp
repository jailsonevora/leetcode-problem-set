#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {

        unordered_map<char, int> tmp;

        for(auto& str: s){
            if(s.find(str))
                ++tmp[str];
            else
                --tmp[str];
        }

        if (!tmp.size())
            return true;
        else
            return false;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    string s = "abacbc";
    Solution sl;
    cout << sl.areOccurrencesEqual(s);
}