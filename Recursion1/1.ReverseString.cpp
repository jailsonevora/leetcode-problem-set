#include<iostream>
#include<vector>

using namespace std;

// recursive
class Solution {
    void reverseString(vector<char>& s, int i) {
        if(i == s.size()/2)
            return;
        swap(s[i], s[s.size() - i - 1]);
        reverseString(s, i + 1);
    }
public:
    void reverseString(vector<char>& s) {
        int i;
        reverseString(s, i = 0);
    }
};

int main(){
    vector<char> s {'h','e','l','l','o'};

    Solution sl;
    sl.reverseString(s);
}