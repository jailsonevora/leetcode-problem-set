#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int r = 0; r < numRows; r++){
            result[r].resize(r+1);
            result[r][0] = result[r][r] = 1;
            for (int c = 1; c < r; ++c)
                result[r][c] = result[r-1][c-1] + result[r-1][c];
        }
        return result;      
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    sl.generate(5);
}