#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<string> equations = { 
        "a==b",
        "b!=a"
    };

    // vector<string> equations = { 
    //     "b==a",
    //     "a==b"
    // };

    // vector<string> equations = { 
    //     "a==b",
    //     "b==c",
    //     "a==c"
    // };


    Solution sl;
    std::cout << sl.equationsPossible(equations);
}