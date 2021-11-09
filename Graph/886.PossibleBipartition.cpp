#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
    }
};

int main()
{
    vector<vector<int>> dislikes = { 
        "a==b",
        "b!=a"
    };

    Solution sl;
    std::cout << sl.possibleBipartition(2, dislikes);
}