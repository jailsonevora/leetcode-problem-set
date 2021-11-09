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

    Solution sl;
    std::cout << sl.equationsPossible(equations);
}