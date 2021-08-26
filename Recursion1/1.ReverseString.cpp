#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(!s)
            return;
        reverseString(s + 1);
        putchar(s);
    }
};