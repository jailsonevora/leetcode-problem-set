#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
    }
};

int main()
{
    // adjacency edges
    vector<string> equations = { 
        "a==b",
        "b!=a"
    };

    Solution sl;
    std::cout << sl.equationsPossible(equations);
}