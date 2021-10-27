#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {

    int find(int v, vector<int>& parent){

        if(v == parent[v])
            return v;
        return parent[v] = find(parent[v],parent);
    }

public:
    bool equationsPossible(vector<string>& equations){

        vector<int> parent(26,0);

        for (int i = 1; i < 26; i++)
            parent[i] = i;

        for (auto str: equations)
            if(str[1] == '=')
                parent[find(str[0] - 'a', parent)] = find(str[3] - 'a', parent);

        for (auto str: equations)
            if(str[1] == '!' && find(str[0] - 'a') == find(str[3] - 'a'))
                return false;        
        return true;       
    }
};

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