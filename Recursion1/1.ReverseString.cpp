#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(!s.size())
            return;
        reverseString(s);
        //putchar(s[1]);
    }
};

int main(){
    vector<char> s {'h','e','l','l','o'};

    Solution sl;
    sl.reverseString(s);

}