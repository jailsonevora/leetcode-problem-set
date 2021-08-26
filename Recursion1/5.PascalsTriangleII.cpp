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

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

   
    int rowIndex = 3;
    //int rowIndex = 0;
    //int rowIndex = 1;

   sl.getRow(rowIndex);
}