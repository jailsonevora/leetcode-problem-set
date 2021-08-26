#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (!rowIndex)
            return {1};
        
        auto prevRow = getRow(rowIndex - 1);
        vector<int> res(rowIndex + 1, 1);
        
        for (int i = 1; i < rowIndex; i++)
            res[i] = prevRow[i-1] + prevRow[i];
        
        return res;
    }
};