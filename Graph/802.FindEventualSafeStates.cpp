#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;




int main()
{

    // adjacency matrix
    // vector<vector<int>> richer = { 
    // };

    // // vector
    // vector<int> quiet = {
    //     0
    // };

    // adjacency matrix
    vector<vector<int>> richer = { 
        {1,0},
        {2,1},
        {3,1},
        {3,7},
        {4,3},
        {5,3},
        {6,3}
    };

    // vector
    vector<int> quiet = {
        3,2,5,4,6,1,7,0
    };

    Solution sl;

    for(auto it: sl.loudAndRich(richer, quiet))
        std::cout << it << ",";
}