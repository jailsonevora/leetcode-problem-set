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
    vector<string> equations = { 
        "a==b",
        "b!=a"
    // };

    // vector<string> equations = { 
    //     "b==a",
    //     "a==b"
    // };

    // vector<string> equations = { 
    //     "a==b",
    //     "b==c",
    //     "a==c"
    // };

    // vector<string> equations = { 
    //     "a==b",
    //     "b!=c",
    //     "c==a"
    // };

    // vector<string> equations = { 
    //     "c==c",
    //     "b==d",
    //     "x!=z"
    // };

    Solution sl;
    std::cout << sl.equationsPossible(equations);
}