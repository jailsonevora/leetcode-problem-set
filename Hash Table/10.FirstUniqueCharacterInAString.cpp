#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> chrCount, chrPosition;
        for (int i = 0; i < s.size(); i++)
                chrCount[s[i]]  = chrCount[s[i]] + 1;

        for (int i = 0; i < s.size(); i++){
            //if(chrCount[s[i]] > 1){
                chrCount[s[i]] = chrCount[s[i]] - 1;
                chrPosition.insert(make_pair(s[i],i));
            //}
            }

        pair<char,int> min = *min_element(chrPosition.begin(), chrPosition.end(), 
            [](const pair<char,int>& lhs, const pair<char,int>& rhs) {
            return lhs.second < rhs.second;    
        });

        return 0;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string s = "leetcode";

    Solution sl;
    sl.firstUniqChar(s);
}